#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mediaplayerwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MediaPlayerWidget * mpw = new MediaPlayerWidget(this);
    this->setCentralWidget(mpw);
    this->setFixedSize(mpw->width(), mpw->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}
