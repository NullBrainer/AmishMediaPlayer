#include "audiocontroller.h"

AudioController::AudioController(QMediaPlayer * mediaPlayer)
{
    this->mediaPlayer = mediaPlayer;
}

void AudioController::change(QString audioFile){
    qDebug() << audioFile;
    if(audioFile.startsWith("file:///")){
        audioFile = audioFile.remove(0,8);
    }
    qDebug() << "AFTER" << audioFile;
    mediaPlayer->setMedia(QUrl::fromLocalFile(audioFile));
    qDebug() << QUrl::fromLocalFile(audioFile);
    // For testing reasons, play
    mediaPlayer->play();
}

void AudioController::play(){
    mediaPlayer->play();
}

void AudioController::pause(){
    mediaPlayer->pause();
}

void AudioController::stop(){
    mediaPlayer->stop();
}

AudioController::~AudioController(){
    delete mediaPlayer;
}
