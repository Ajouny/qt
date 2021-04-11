#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QPainter>
#include <QWidget>
#include <QPushButton>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);
    int stat() const;
    void setStat(int stat);
    void paintEvent(QPaintEvent *e);
    void flip();
    void setStatWithAnimation(int stat);

private:
    int mFrameNo;
    QTimer *mTimer;
    int mStat;
signals:

};

#endif // COINBUTTON_H
