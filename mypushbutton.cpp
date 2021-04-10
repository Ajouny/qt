#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImgPath, QString pressImgPath, QWidget *parent)
    :QPushButton(parent), mNormalImgPath(normalImgPath), mPressedImgPath(pressImgPath){
    QPixmap pixmap;
    bool ret = pixmap.load(mNormalImgPath);
    if(!ret){
        qDebug() << mNormalImgPath << "图片加载失败";
    }
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
}
void MyPushButton::paintEvent(QPaintEvent *event){
    QPainter paint(this);
    QPixmap pix=this->icon().pixmap(this->width(), this->height());
    paint.drawPixmap(0,0,this->width(),this->height(),pix);

    paint.drawText(0,0, this->width(), this->height(), Qt::AlignVCenter | Qt::AlignHCenter, this->text());
}

void MyPushButton::moveDown(){
    QPropertyAnimation *animation =
            new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),
                                 this->y()+10,
                                 this->width(),
                                 this->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void MyPushButton::moveUp(){
    QPropertyAnimation *animation =
            new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),
                                 this->y()-10,
                                 this->width(),
                                 this->height()));
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    QPushButton::mousePressEvent(e);//除了换图，其它事情要交给父亲处理
    if(!mPressedImgPath.isEmpty()){
        QPixmap pixmap;
        bool ret = pixmap.load(mPressedImgPath);
        if(!ret){
            qDebug()<<"加载图片"<< mPressedImgPath <<"失败";
        }
        this->setIcon(pixmap);
    }
}

void MyPushButton::mouseReleaseEvent(QMouseEvent* e){
    QPushButton::mouseReleaseEvent(e);
    if(!mNormalImgPath.isEmpty()){
        QPixmap pixmap;
        bool ret = pixmap.load(mNormalImgPath);
        if(!ret){
            qDebug()<<"加载图片"<< mNormalImgPath <<"失败";
        }
        this->setIcon(pixmap);
    }
}
