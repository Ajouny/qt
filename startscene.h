#ifndef STARTSCENE_H
#define STARTSCENE_H
#include "mainwindow.h"
#include "mypushbutton.h"
#include "levelselectscene.h"
#include <QPainter>
#include <QMainWindow>

class StartScene : public MainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // STARTSCENE_H
