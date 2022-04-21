#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);

    //给每个硬币加属性
    int posX;
    int posY;
    bool flag;  //硬币的状态， 正面为1， 反面为0

    //改变标志的方法
    void changFlag();
    QTimer * timer1;
    QTimer * timer2;
    int min = 1;
    int max = 8;

    //是否在动画
    bool isAnimation = false;
    //重写mousePressEvent，在动画时无法按下
    void mousePressEvent(QMouseEvent *);

    //用于判断胜利状态，使胜利时按钮禁用
    bool isWin = false;

signals:

};

#endif // MYCOIN_H
