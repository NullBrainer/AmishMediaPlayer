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
    ui->centralWidget->setFixedSize(1200,800); // 800,600
    ui->RenderSpace->setFixedSize(800,600);
    this->adjustSize();
    playlist = new Playlist(this);
    ui->playlistDisplay->setViewport(playlist);

    connect(playlist, SIGNAL(playlistLoaded()), this, SLOT(playlistLoaded()));
    connect(playlist, SIGNAL(contentDoubleClicked()),
            this, SLOT(audioDoubleClick()));




}

MainWindow::~MainWindow()
{
    delete ui;
    delete mediaPlayer;
    delete Audio;
    delete Video;
    delete playlist;
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
    connect(Video, SIGNAL(orderPushedBackward()), this, SLOT(playlistPrevious()));
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
    checkPlaylistAndChange();
    qDebug() << "SIGNAL SENT";
}

bool MainWindow::isVideo(QString fileName){
    return fileName.toLower().endsWith(".mp4");
}

void MainWindow::playlistNext(){
    playlist->next();
    qDebug() << "CURRENT INDEX" << playlist->currentIndex();
    if(playlist->currentIndex() == -1){
        playlist->next();
    }

    qDebug("PLAYLIST MOVE FORWARD");
    checkPlaylistAndChange();
}

void MainWindow::playlistPrevious(){
    playlist->previous();
    qDebug("PLAYLIST MOVE BACKWARD");
    checkPlaylistAndChange();
}

void MainWindow::checkPlaylistAndChange(){
    if(isVideo(playlist->currentFileName())){
        loadVideoPlayer();
        Video->changeFile(playlist->currentFileName());
    }
    else{
        loadAudioPlayer();
        Audio->changeFile(playlist->currentFileName());
    }
}

void MainWindow::audioDoubleClick(){
    qDebug() << "CONTENT DOUBLE CLICKED";
    checkPlaylistAndChange();
}


