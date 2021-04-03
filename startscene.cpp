#include "startscene.h"
#include <QTimer>
StartScene::StartScene(QWidget *parent) : MainWindow(parent)
{
    MyPushButton * button = new MyPushButton(":/res/MenuSceneStartButton.png", "", this);
    button->setFixedSize(QSize(114,114));
    button->move(
                (this->width()-button->width())/2,
                this->height()*3/4-button->height()/2
                );

    connect(button, &MyPushButton::clicked, [=](){
        button->moveDown();

        QTimer::singleShot(100, [=](){button->moveUp();});
        QTimer::singleShot(200, [=](){
        LevelSelectScene * level = new LevelSelectScene;
        level->setAttribute(Qt::WA_DeleteOnClose);
        level->show();
        this->hide();
    });
});

}

void StartScene::paintEvent(QPaintEvent *event){
    QPainter paint(this);
    QPixmap pix(":/res/MenuSceneBg.png");
    paint.drawPixmap(0,0, this->width(), this->height(), pix);
}
