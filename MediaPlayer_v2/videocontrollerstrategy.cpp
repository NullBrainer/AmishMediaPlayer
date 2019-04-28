#include "videocontrollerstrategy.h"

void VideoControllerStrategy::play(QMediaPlayer * mp){
    mp->play();
    qDebug() << "VIDEO PLAYING";
}

void VideoControllerStrategy::pause(QMediaPlayer * mp){
    mp->pause();
    qDebug() << "VIDEO PAUSED";
}

void VideoControllerStrategy::stop(QMediaPlayer * mp){
    mp->stop();
    qDebug() << "VIDEO STOPPED";

}

void VideoControllerStrategy::setVolume(int n, QMediaPlayer * mp){
    mp->setVolume(n);
}

void VideoControllerStrategy::seek(int n, QMediaPlayer * mp){
    mp->setPosition(n);
}
