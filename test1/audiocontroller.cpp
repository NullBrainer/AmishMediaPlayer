#include "audiocontroller.h"

AudioController::AudioController(QMediaPlayer * mediaPlayer)
{
    this->mediaPlayer = mediaPlayer;
}

void AudioController::change(QString audioFile){
    mediaPlayer->setMedia(QUrl::fromLocalFile(audioFile));
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
