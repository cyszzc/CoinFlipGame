#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);

    //normaImg 代表正常显示的图片
    //pressImg 代表按下后显示的图片  默认为空
    MyPushButton(QString normalImg, QString pressImg = "");
    QString normalImgPath;      //默认显示图片路径
    QString pressImgPath;       //按下后显示图片路径

    //按钮按下时的弹跳特效
    void zoom1();
    void zoom2();


    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

};

#endif // MYPUSHBUTTON_H
