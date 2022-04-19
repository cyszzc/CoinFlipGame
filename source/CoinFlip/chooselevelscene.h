#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    PlayScene * play = NULL;

signals:
    //写一个自定义的信号，告诉主场景点击了返回
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
