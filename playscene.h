#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int level, QWidget* parent = nullptr);
signals:
    void backBtnClicked();
private:
    int mLevel;
};

#endif // PLAYSCENE_H
