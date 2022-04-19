#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSoundEffect>
PlayScene::PlayScene(int levelNum){
    QString str = QString("您选择的是第%1关").arg(levelNum);
    qDebug() << str;

    this->levelIndex = levelNum;

    //初始化游戏场景
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币场景");

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮音效
    QSoundEffect * backSound = new QSoundEffect;
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));
    //翻金币按钮音效
    QSoundEffect * flipSound = new QSoundEffect;
    flipSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.wav"));
    //胜利音效
    QSoundEffect * winSound = new QSoundEffect;
    winSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.wav"));


    //返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //点击返回
    connect(closeBtn, &QPushButton::clicked, [=](){
        //触发返回按钮音效
        backSound->play();
        //触发自定义信号， 供主场景接受
        //延时发送信号
        QTimer::singleShot(300, this, [=](){
            emit this->playSceneBack();
        });
    });

    //显示当前的关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    //设置字体和字号
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30, this->height() - 50, 120, 50);   //设置位置和大小

    //用gameArray储存当前关卡的金币状态
    dataConfig config;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片
    QLabel * winLabel = new QLabel;
    QPixmap winPix;
    winPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, winPix.width(), winPix.height());
    winLabel->setPixmap(winPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - winPix.width())*0.5, -winPix.height());

    //显示金币的背景图案
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            QPixmap pix = QPixmap(":/res/BoardNode(1).png");
            QLabel  * label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i * 50, 200 + j * 50);


            //创建金币
            QString str;
            if(this->gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            }else if(this->gameArray[i][j] == 0){
                str = ":/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + 50*i, 204 + 50*j);

            //给硬币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            //将当前金币放入金币二维数组中，以便维护
            coinBtn[i][j] = coin;
            //点击硬币
            connect(coin, &MyCoin::clicked,[=](){
                //点击按钮，将所有按钮暂时锁上 （避免迅速点击其他按钮引起bug）
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        coinBtn[i][j]->isWin = true;
                    }
                }

                //翻金币音效触发
                flipSound->play();

                coin->changFlag();

                //延时翻转周围硬币
                QTimer::singleShot(200, this, [=](){
                    //翻转右侧硬币
                    if(coin->posX+1 <= 3){
                        coinBtn[coin->posX+1][coin->posY]->changFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                    }
                    //翻转左侧硬币
                    if(coin->posX-1 >= 0){
                        coinBtn[coin->posX-1][coin->posY]->changFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    //翻转上侧硬币
                    if(coin->posY-1 >= 0){
                        coinBtn[coin->posX][coin->posY-1]->changFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                    }
                    //翻转下侧硬币
                    if(coin->posY+1 <= 3){
                        coinBtn[coin->posX][coin->posY+1]->changFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                    }

                    //将所有按钮解锁
                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 4; j++){
                            coinBtn[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 4; j++){
                            if(coinBtn[i][j]->flag == false){
                                this->isWin = false;
                                i = 5;
                                break;
                            }
                        }
                    }
                    //关卡胜利，显示胜利信息，并禁止所有按钮翻转
                    if(this->isWin == true){
                        //qDebug() << "游戏胜利";
                        for(int i = 0; i < 4; i++){
                            for(int j = 0; j < 4; j++){
                                coinBtn[i][j]->isWin =true;
                            }
                        }
                        //弹出胜利图片
                        QPropertyAnimation * animation = new QPropertyAnimation(winLabel, "geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(), 115 + winLabel->y(), winLabel->width(), winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();

                        //触发胜利音效
                        winSound->play();
                    }
                });
            });
        }
    }
}


//创建背景
void PlayScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
