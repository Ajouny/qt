#include "coinbutton.h"
#include <QTimer>

CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    setStyleSheet("QPushButton{border:None;}");

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, [=](){
        if(mStat){
            --mFrameNo;
        }else{
            ++mFrameNo;
        }
        if(mFrameNo == 1 || mFrameNo == 8){
            mTimer->stop();
        }
        QString iconName =
                QString(":/res/Coin000%1.png").arg(mFrameNo);
        setIcon(QIcon(iconName));
    });

}
int CoinButton::stat() const
{
    return mStat;
}

void CoinButton::setStat(int stat){
    mStat = stat;
    if(mStat){
        setIcon(QIcon(":/res/Coin0001.png"));
    }else{
        setIcon(QIcon(":/res/Coin0008.png"));
    }
    setIconSize(this->size());
}

void CoinButton::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPixmap pix(":/res/BoardNode.png");
    painter.drawPixmap(0,0, this->width(), this->height(),pix);
    QPushButton::paintEvent(e);

}

void CoinButton::flip(){
        setStatWithAnimation(!this->stat());
}

void CoinButton::setStatWithAnimation(int stat){
    mStat = stat;
    if(mStat){
        this->mFrameNo = 8;
    }else{
        this->mFrameNo = 1;
    }
    this->mTimer->start(30);
}
