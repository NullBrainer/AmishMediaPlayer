#include "videocontroller.h"
#include <QFileDialog>
VideoController::VideoController(QVideoWidget* vw, QMediaPlayer * mediaPlayer):videoWidget{vw}{
    this->mediaPlayer = mediaPlayer;
    this->mediaPlayer->setVideoOutput(videoWidget);
}
void VideoController::change(QString videoFile){
    mediaPlayer->stop();
    if(videoFile.startsWith("file:///")){
        videoFile = videoFile.remove(0,8);
    }
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
}
