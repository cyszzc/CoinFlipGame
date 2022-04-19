#include "mycoin.h"
#include <QDebug>
//MyCoin::MyCoin(QWidget *parent)
//    : QWidget{parent}
//{

//}

MyCoin::MyCoin(QString btnImg){
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("图片路径 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    //初始化定时器对象
    timer1 = new QTimer;
    timer2 = new QTimer;

    //监听正面翻反面的定时器
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //当翻到反面时，定时器停止
        if(this->min > this->max){
            this->isAnimation = false;
            timer1->stop();
            this->min = 1;
        }
    });

    //监听反面翻正面的定时器
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //当翻到正面时，定时器停止
        if(this->min > this->max){
            this->isAnimation = false;
            timer2->stop();
            this->max = 8;
        }
    });

}

void MyCoin::mousePressEvent(QMouseEvent * ev){
    if(this->isAnimation || this->isWin){
        return;
    }else{
        QPushButton::mousePressEvent(ev);
    }

}
void MyCoin::changFlag(){
    //正面翻成反面
    if(this->flag){
        timer1->start(30);
        this->isAnimation = true;
        flag = false;
    }else{      //反面翻成正面
        timer2->start(30);
        this->isAnimation = true;
        flag = true;
    }
}
