#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)//, Audio{new AudioWindowWidget(this)}
{
    ui->setupUi(this);
    /*
    this->setCentralWidget(Video);
    Video->setFixedSize(800,600);
    this->adjustSize();
    */

    //this->setCentralWidget(Audio);
    //ui->RenderSpace = Audio;
    Audio = nullptr;
    Video = nullptr;
    ui->centralWidget->setFixedSize(1000,800); // 800,600
    ui->RenderSpace->setFixedSize(800,600);
    this->adjustSize();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseVideoPlayer_pressed()
{
    if(Audio != nullptr){
        Audio->on_actiononMediaSwitch_triggered();
    }
    Video = new VideoWindowWidget(this);
    ui->RenderSpace->setViewport(Video);
    Video->show();
}

void MainWindow::on_chooseAudioPlayer_pressed()
{
    if(Video != nullptr){
        Video->on_actiononMediaSwitch_triggered();
    }
    Audio = new AudioWindowWidget(this);
    ui->RenderSpace->setViewport(Audio);
    Audio->show();
}
