#include "playscene.h"
#include "mypushbutton.h"
#include "coinbutton.h"
#include "dataconfig.h"
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QVector>
#include <QTimer>
#include <QMessageBox>
#include <QString>

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
            mCoinBtns[row][column] = btn;
            btn->setGeometry(x, y, coinWidth, coinHeight);
            DataConfig config;
            QVector <QVector<int>> levelData = config.mData[level];
            btn->setStat(levelData[row][column]);
            connect(btn, &CoinButton::clicked, [=](){
                this->flipCoin(row, column);
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

void PlayScene::flipCoin(int row, int col){
    if(mHasWin == 0){
        this->mCoinBtns[row][col]->flip();

        QTimer::singleShot(300,[=](){
            if(row - 1 >= 0){
                this->mCoinBtns[row - 1][col]->flip();
            }
            if(row + 1 <4){
                this->mCoinBtns[row+1][col]->flip();
            }
            if(col + 1 < 4){
                this->mCoinBtns[row][col+1]->flip();
            }
            if(col -1 >= 0){
                this->mCoinBtns[row][col-1]->flip();
            }
            mHasWin = judgeWin();
        });
    }
}

int PlayScene::judgeWin(){
    for(int row = 0; row < 4; ++row){
        for(int col = 0; col < 4; ++col){
            if(mCoinBtns[row][col]->stat() == 0){
                return 0;
            }
        }
    }
    QMessageBox::information(this, QString::fromUtf16(u"恭喜"), QString::fromUtf16(u"你已经胜利了"));
    return 1;
}
