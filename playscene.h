#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "mainwindow.h"

class PlayScene : public MainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int level, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
    void backBtnClicked();

private:
    int mLevel;
};

#endif // PLAYSCENE_H
