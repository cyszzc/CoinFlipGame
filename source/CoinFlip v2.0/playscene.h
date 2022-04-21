#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum, int mode);
    int levelIndex; //内部成员属性，记录所选的关卡
    int modIndex;

    void paintEvent(QPaintEvent *);//重写paintEvent  画背景图
    int gameArray[6][6];    //每个关卡的金币状态

    MyCoin * coinBtn[6][6];

    bool isWin;      //当前关卡是否胜利

signals:
    //自定义游戏界面返回按钮信号
    void playSceneBack();
};

#endif // PLAYSCENE_H
