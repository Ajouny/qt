#include "coinbutton.h"

CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    setStyleSheet("QPushButton{border:None;}");
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
        setStat(!mStat);
}
