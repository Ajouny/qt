#include "playscene.h"
#include "mypushbutton.h"

PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}

PlayScene::PlayScene(int level, QWidget* parent) : QMainWindow(parent){
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png", this);
    closeBtn->setFixedSize(72, 32);

    closeBtn->move(this->width()-closeBtn->width(), this->height()-closeBtn->height());
    connect(closeBtn, &MyPushButton::clicked, [=](){
        emit this->backBtnClicked();
    });
}
