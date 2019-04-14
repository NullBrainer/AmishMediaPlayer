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
    mediaPlayer = new QMediaPlayer();
    ui->centralWidget->setFixedSize(1000,800); // 800,600
    ui->RenderSpace->setFixedSize(800,600);
    this->adjustSize();
    playlist = new Playlist(this);
    ui->playlistDisplay->setViewport(playlist);

    connect(playlist, SIGNAL(playlistLoaded()), this, SLOT(playlistLoaded()));





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
    Video = new VideoWindowWidget(this, mediaPlayer);
    ui->RenderSpace->setViewport(Video);
    Video->show();
}

void MainWindow::on_chooseAudioPlayer_pressed()
{
    if(Video != nullptr){
        Video->on_actiononMediaSwitch_triggered();
    }
    Audio = new AudioWindowWidget(this, mediaPlayer);
    ui->RenderSpace->setViewport(Audio);
    Audio->show();
}

void MainWindow::on_fileButton_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Audio/Video File", "", "(*.mp3 *mp4)");
    qDebug() << fileName;
    if(isVideo(fileName)){
        loadVideoPlayer();
        Video->changeFile(fileName);
    }
    else{
        loadAudioPlayer();
        Audio->changeFile(fileName);
    }
}

void MainWindow::loadVideoPlayer(){
    if(Audio != nullptr){
        Audio->on_actiononMediaSwitch_triggered();
    }
    Video = new VideoWindowWidget(this, mediaPlayer);
    ui->RenderSpace->setViewport(Video);
    Video->show();
    connect(Video, SIGNAL(orderPushedForward()), this, SLOT(playlistNext()));
    connect(Video, SIGNAL(orderPushedBackward()), this, SLOT(playlistNext()));
}

void MainWindow::loadAudioPlayer(){
    if(Video != nullptr){
        Video->on_actiononMediaSwitch_triggered();
    }
    Audio = new AudioWindowWidget(this, mediaPlayer);
    ui->RenderSpace->setViewport(Audio);
    Audio->show();
    connect(Audio, SIGNAL(orderPushedForward()), this, SLOT(playlistNext()));
    connect(Audio, SIGNAL(orderPushedBackward()), this, SLOT(playlistPrevious()));
}

void MainWindow::playlistLoaded(){
    QString fileName = playlist->currentFileName();
    qDebug() << fileName;
    if(isVideo(fileName)){
        loadVideoPlayer();
        Video->changeFile(fileName);
    }else{
        loadAudioPlayer();
        Audio->changeFile(fileName);
    }
    qDebug() << "SIGNAL SENT";
}

bool MainWindow::isVideo(QString fileName){
    return fileName.toLower().endsWith(".mp4");
}

void MainWindow::playlistNext(){
    playlist->next();
    qDebug("PLAYLIST MOVE FORWARD");
}

void MainWindow::playlistPrevious(){
    playlist->previous();
    qDebug("PLAYLIST MOVE BACKWARD");
}




