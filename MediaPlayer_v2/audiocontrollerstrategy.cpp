#include "audiocontrollerstrategy.h"

void AudioControllerStrategy::play(QMediaPlayer* mp){
    mp->play();
    qDebug() << "PLAYING";
}

void AudioControllerStrategy::pause(QMediaPlayer* mp){
    mp->pause();
    qDebug() << "PAUSED";
}

void AudioControllerStrategy::stop(QMediaPlayer* mp){
    mp->stop();
    qDebug() << "STOPPED";
}

void AudioControllerStrategy::setVolume(int n, QMediaPlayer* mp){
    mp->setVolume(n);
}

void AudioControllerStrategy::seek(int n, QMediaPlayer* mp){
    mp->setPosition(n);
}
