#include "videocontroller.h"
#include <QFileDialog>
VideoController::VideoController(QVideoWidget* vw):videoWidget{vw}{
    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setVideoOutput(videoWidget);

}
void VideoController::change(QString videoFile){
    mediaPlayer->setMedia(QUrl::fromLocalFile(videoFile));
    // For testing reasons, play
    mediaPlayer->play();
}
void VideoController::play(){
    mediaPlayer->play();
}

void VideoController::pause(){
    mediaPlayer->pause();
}

void VideoController::stop(){
    mediaPlayer->stop();
}

VideoController::~VideoController(){
    delete mediaPlayer;
}
