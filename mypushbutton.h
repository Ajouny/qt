#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QPainter>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImgPath, QString pressImgPath = "", QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    QString mNormalImgPath;
    QString mPressedImgPath;
    void moveDown();
    void moveUp();
signals:

};

#endif // MYPUSHBUTTON_H
