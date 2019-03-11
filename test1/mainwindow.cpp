#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
Main Window will be the encapsulating class that instantiates and uses
the main componenents of the project.
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rendermethod = new VideoWindowRender();
    rendermethod->Render(this);

    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    mediaPlayer->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);
    QString videoFileName = QFileDialog::getOpenFileName(this, "Open Video File", "", "Video File (*.mp4)");

    mediaPlayer->stop();
    mediaPlayer->setMedia(QUrl::fromLocalFile(videoFileName));
    videoWidget->show();
    mediaPlayer->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}
