#include "levelselectscene.h"
#include <QPainter>
#include "mypushbutton.h"
LevelSelectScene::LevelSelectScene(QWidget *parent) : MainWindow(parent)
{
    this->setWindowTitle(QString::fromUtf16(u"选择关卡"));
    MyPushButton * closeBtn =
            new MyPushButton(
                ":/res/BackButton.png",
                ":/res/BackButtonSelected.png",
                this);

    closeBtn->setFixedSize(72,32);
    closeBtn->move(
                this->width()-closeBtn->width(),
                this->height()-closeBtn->height());
}

void LevelSelectScene::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())* 0.5, 30, pix.width(),pix.height(), pix);
}
