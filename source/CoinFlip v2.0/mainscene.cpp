#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSoundEffect>
#include <QAudioDevice>
#include <QLabel>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(644, 588);
    //设置应用图片
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置窗口标题
    this->setWindowTitle("翻金币");
    //点击退出，退出程序
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    //准备开始按钮的音效
    QSoundEffect * startSound = new QSoundEffect;
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));

    //创建开始按钮
    MyPushButton * starBtn = new MyPushButton(":/res/simpleModButton.png");
    starBtn->setParent(this);
    starBtn->move(this->width() * 0.5 - starBtn->width() * 0.5, this->height() * 0.3);

    //创建困难模式按钮
    MyPushButton * hardBtn = new MyPushButton(":/res/hardModButton.png");
    hardBtn->setParent(this);
    hardBtn->move(this->width() * 0.5 - hardBtn->width() * 0.5, this->height() * 0.5);

    //创建随机模式按钮
    MyPushButton * randomBtn = new MyPushButton(":/res/randomModButton.png");
    randomBtn->setParent(this);
    randomBtn->move(this->width() * 0.5 - hardBtn->width() * 0.5, this->height() * 0.7);

    QLabel * label = new QLabel;    //选择关卡显示模式的标签

    //监听选择关卡的返回按钮信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        label->clear();
        this->setGeometry(chooseScene->geometry());     //返回到当前窗口的位置与前一个窗口相同
        this->show();           //主场景重新显示
        chooseScene->hide();    //将选择关卡隐藏
        starBtn->isAnimation = false;
        hardBtn->isAnimation = false;
        randomBtn->isAnimation = false;
    });




    //开始按钮的弹跳特效，点击后延时进入选择关卡界面
    connect(starBtn, &QPushButton::clicked, [=](){

        //点击后所有按钮锁住，不得再按，避免按的速度快导致按钮位置偏移
        starBtn->isAnimation = true;
        hardBtn->isAnimation = true;
        randomBtn->isAnimation = true;

        //播放音效
        startSound->play();
        starBtn->zoom1();
        starBtn->zoom2();

        //延迟0.5秒 进入选择界面
        QTimer::singleShot(300, this, [=](){

            chooseScene->mod = 0;
            chooseScene->setGeometry(this->geometry());     //设置下一窗口所在位置与当前窗口相同

            //选择关卡界面显示简单模式
            label->setParent(chooseScene);

            //设置字体和字号
            QFont font;
            font.setFamily("华文新魏");
            font.setPointSize(20);
            QString str1 = QString("简单模式");
            //将字体设置到标签控件中
            label->setFont(font);
            label->setText(str1);
            label->setGeometry(30, this->height() - 50, 120, 50);   //设置位置和大小

            chooseScene->show();
            this->hide();
        });
    });

    //困难按钮的弹跳特效，点击后延时进入选择关卡界面
    connect(hardBtn, &QPushButton::clicked, [=](){

        //点击后所有按钮锁住，不得再按，避免按的速度快导致按钮位置偏移
        starBtn->isAnimation = true;
        hardBtn->isAnimation = true;
        randomBtn->isAnimation = true;

        //播放音效
        startSound->play();
        hardBtn->zoom1();
        hardBtn->zoom2();

        //延迟0.5秒 进入选择界面
        QTimer::singleShot(300, this, [=](){
            chooseScene->mod = 1;
            chooseScene->setGeometry(this->geometry());     //设置下一窗口所在位置与当前窗口相同

            //选择关卡界面显示困难模式
            label->setParent(chooseScene);
            //设置字体和字号
            QFont font;
            font.setFamily("华文新魏");
            font.setPointSize(20);
            QString str1 = QString("困难模式");
            //将字体设置到标签控件中
            label->setFont(font);
            label->setText(str1);
            label->setGeometry(30, this->height() - 50, 120, 50);   //设置位置和大小

            chooseScene->show();
            this->hide();
        });
    });

    //随机模式按钮的弹跳特效，点击后延时进入选择关卡界面
    connect(randomBtn, &QPushButton::clicked, [=](){

        randomModScene = new PlayScene(0, 2);
        //监听随机关卡的返回按钮信号
        connect(randomModScene, &PlayScene::playSceneBack, [=](){

            label->clear();
            this->setGeometry(randomModScene->geometry());     //返回到当前窗口的位置与前一个窗口相同
            this->show();           //主场景重新显示
            randomModScene->hide();    //将选择关卡隐藏

            starBtn->isAnimation = false;
            hardBtn->isAnimation = false;
            randomBtn->isAnimation = false;
            delete randomModScene;      //释放随机模式内存空间，防止不断进入随机模式时内存占用越来越大
        });
        //点击后所有按钮锁住，不得再按，避免按的速度快导致按钮位置偏移
        starBtn->isAnimation = true;
        hardBtn->isAnimation = true;
        randomBtn->isAnimation = true;

        //播放音效
        startSound->play();
        randomBtn->zoom1();
        randomBtn->zoom2();


        QTimer::singleShot(300, this, [=](){

            randomModScene->setGeometry(this->geometry());    //游戏场景窗口位置与上一窗口相同
            randomModScene->show();
            this->hide();
        });

    });

}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MenuSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画一个背景上的图标
    pix.load(":/res/Title.png");
    //缩放
    pix = pix.scaled(pix.width(), pix.height());
    painter.drawPixmap(10, 30, pix);


}


MainScene::~MainScene()
{
    delete ui;
}

