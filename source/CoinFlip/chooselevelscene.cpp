#include "chooselevelscene.h"
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "playscene.h"
#include <QSoundEffect>
ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(320,588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择关卡按钮音效
    QSoundEffect * chooseSound = new QSoundEffect;
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    //返回按钮音效
    QSoundEffect * backSound = new QSoundEffect;
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //点击返回
    connect(closeBtn, &QPushButton::clicked, [=](){
        //触发自定义信号， 供主场景接受
        //延时发送信号
        //播放返回按钮音效
        backSound->play();

        QTimer::singleShot(300, this, [=](){
            emit this->chooseSceneBack();
        });

    });



    //创建选择关卡的按钮
    for(int i = 0; i < 20; i++){



        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            //播放选择关卡按钮
            chooseSound->play();


            //进入到游戏场景
            play = new PlayScene(i+1);

            play->setGeometry(this->geometry());    //游戏场景窗口位置与上一窗口相同

            play->show();
            this->hide();

            //监听选择关卡的返回按钮信号
            connect(play, &PlayScene::playSceneBack, [=](){

                this->setGeometry(play->geometry());

                this->show();           //选择场景重新显示
                play->hide();    //将选择关卡隐藏
                delete play;
                play = NULL;
            });
        });

        //设置按钮上标签
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i % 4 * 70, 130 + i / 4 * 70);
        //设置label上文本的对齐方式， 水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置label属性，让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
