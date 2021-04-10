#include "levelselectscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "playscene.h"
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
    connect(closeBtn, &MyPushButton::clicked, [=](){
        //emit的作用就是发射信号
        emit this->backBtnClicked();

    });


    const int xOffset = 25;
    const int yOffset = 130;

    const int columnWidth = 70;
    const int rowHeight = 70;
    for(int i = 0; i < 20; i++){
        int row = i/4;
        int column = i%4;
        int x = xOffset + column*columnWidth;
        int y = yOffset + row*rowHeight;
        MyPushButton *btn = new MyPushButton(":/res/LevelIcon.png", "", this);
        btn->setText(QString::number(i+1));
        btn->setGeometry(x,y,57,57);

        connect(btn, &MyPushButton::clicked,[=](){
            this->hide();

            //将用户关卡给PlayScene
            PlayScene *playSene = new PlayScene(i+1);
            playSene->show();
            playSene->setAttribute(Qt::WA_DeleteOnClose);

            connect(playSene, &PlayScene::backBtnClicked, [=](){
                this->show();
                playSene->close();
            });

        });
    }


}

void LevelSelectScene::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())* 0.5, 30, pix.width(),pix.height(), pix);
}
