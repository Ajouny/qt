#ifndef LEVELSELECTSCENE_H
#define LEVELSELECTSCENE_H

#include "mainwindow.h"

class LevelSelectScene : public MainWindow
{
    Q_OBJECT
public:
    explicit LevelSelectScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
signals:
    void backBtnClicked();
};

#endif // LEVELSELECTSCENE_H
