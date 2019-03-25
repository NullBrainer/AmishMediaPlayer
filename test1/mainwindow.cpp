#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), Video{new VideoWindowWidget(this)}
{
    ui->setupUi(this);
    this->setCentralWidget(Video);
    Video->setFixedSize(800,600);
    this->adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}
