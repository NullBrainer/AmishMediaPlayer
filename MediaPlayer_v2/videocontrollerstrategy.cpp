#include "videocontrollerstrategy.h"

void VideoControllerStrategy::play(QMediaPlayer * mp){
    mp->play();
}

void VideoControllerStrategy::pause(QMediaPlayer * mp){
    mp->pause();
}

void VideoControllerStrategy::stop(QMediaPlayer * mp){
    mp->stop();
}

void VideoControllerStrategy::setVolume(int n, QMediaPlayer * mp){
    mp->setVolume(n);
}

void VideoControllerStrategy::seek(int n, QMediaPlayer * mp){
    mp->setPosition(n);
}
