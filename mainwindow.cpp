#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle(QString::fromUtf16(u"翻金币"));
    this->setFixedSize(320, 580);
}

MainWindow::~MainWindow()
{
    delete ui;
}

