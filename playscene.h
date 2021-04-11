#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "coinbutton.h"
#include "mainwindow.h"

class PlayScene : public MainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int level, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void flipCoin(int row, int column);
    int judgeWin();
private:
    CoinButton *mCoinBtns[4][4];
    bool mHasWin = 0;
signals:
    void backBtnClicked();

private:
    int mLevel;
};

#endif // PLAYSCENE_H
