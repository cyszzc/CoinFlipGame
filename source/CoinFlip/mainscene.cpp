#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSoundEffect>
#include <QAudioDevice>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(320, 588);
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
    MyPushButton * starBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    starBtn->setParent(this);
    starBtn->move(this->width() * 0.5 - starBtn->width() * 0.5, this->height() * 0.7);


    //监听选择关卡的返回按钮信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        this->setGeometry(chooseScene->geometry());     //返回到当前窗口的位置与前一个窗口相同
        this->show();           //主场景重新显示
        chooseScene->hide();    //将选择关卡隐藏

    });

    //开始按钮的弹跳特效，点击后延时进入选择关卡界面
    connect(starBtn, &QPushButton::clicked, [=](){

        //播放音效
        startSound->play();
        starBtn->zoom1();
        starBtn->zoom2();

        //
        //延迟0.5秒 进入选择界面
        QTimer::singleShot(300, this, [=](){
            chooseScene->setGeometry(this->geometry());     //设置下一窗口所在位置与当前窗口相同
            chooseScene->show();
            this->hide();
        });
    });

}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画一个背景上的图标
    pix.load(":/res/Title.png");
    //缩放
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix);


}


MainScene::~MainScene()
{
    delete ui;
}

