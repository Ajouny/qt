#include "playscene.h"
#include "mypushbutton.h"
#include "coinbutton.h"
#include <QMenuBar>
#include <QPainter>
#include <QLabel>

PlayScene::PlayScene(QWidget *parent) : MainWindow(parent){}

PlayScene::PlayScene(int level, QWidget* parent) : MainWindow(parent){
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png", this);
    closeBtn->setFixedSize(72, 32);

    closeBtn->move(this->width()-closeBtn->width(), this->height()-closeBtn->height());
    connect(closeBtn, &MyPushButton::clicked, [=](){
        emit this->backBtnClicked();
    });

    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Level: %1").arg(level);
    label->setText(str);
    label->setGeometry(QRect(30, this->height() - 50, 150, 50));

    const int rowCount = 4;
    const int columnCount = 4;

    const int rowHeight = 50;
    const int columnWidth = 50;

    const int xOffset = 57;
    const int yOffset = 200;

    const int coinWidth = 50;
    const int coinHeight = 50;

    for(int row = 0; row < rowCount; ++row){
        for(int column = 0; column < columnCount; ++column){
            int x = column * columnWidth + xOffset;
            int y = row * rowHeight + yOffset;
            CoinButton *btn = new CoinButton(this);
            btn->setGeometry(x, y, coinWidth, coinHeight);
            btn->setStat(1);
            connect(btn, &CoinButton::clicked, [=](){
                btn->flip();
            });
        }
    }



}

void PlayScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.translate(0, this->menuBar()->height());
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0, this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap(0,0,pix.width()*0.5, pix.height()*0.5, pix);
}
