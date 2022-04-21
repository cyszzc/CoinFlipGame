#include "mypushbutton.h"
#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pixmap;
    bool ret = pixmap.load(normalImgPath);
    if(!ret){
        qDebug() << "图片加载失败";
        return;
    }
    //设置图片固定尺寸
    this->setFixedSize(pixmap.width(), pixmap.height());
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1(){
    //创建动画对象
    QPropertyAnimation *ani1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔 单位为毫秒
    ani1->setDuration(200);

    //创建起始位置
    ani1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //创建结束位置
    ani1->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置缓和曲线， QEasingCurse::OutBource为弹跳效果
    ani1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    ani1->start();
}

void MyPushButton::zoom2(){
    QPropertyAnimation *ani1 = new QPropertyAnimation(this,"geometry");

    ani1->setDuration(200);
    ani1->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    ani1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    ani1->setEasingCurve(QEasingCurve::OutBounce);
    ani1->start();
}

void MyPushButton::mousePressEvent(QMouseEvent * e){
    if(this->pressImgPath != "") //选中路径不为空，显示选中图片
        {
            QPixmap pixmap;
            bool ret = pixmap.load(pressImgPath);
            if(!ret)
            {
                qDebug() << "加载图片失败!";
            }

            this->setFixedSize( pixmap.width(), pixmap.height() );
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pixmap);
            this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        }
        //交给父类执行按下事件
        return QPushButton::mousePressEvent(e);

}
void MyPushButton::mouseReleaseEvent(QMouseEvent * e){
    if(this->pressImgPath != "") //选中路径不为空，显示选中图片
        {
            QPixmap pixmap;
            bool ret = pixmap.load(normalImgPath);
            if(!ret)
            {
                qDebug() << "加载图片失败!";
            }

            this->setFixedSize( pixmap.width(), pixmap.height() );
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pixmap);
            this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        }
        //交给父类执行按下事件
        return QPushButton::mouseReleaseEvent(e);
}
