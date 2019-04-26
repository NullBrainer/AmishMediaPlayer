#include "audiocontrollerstrategy.h"

void AudioControllerStrategy::play(QMediaPlayer* mp){
    mp->play();
}

void AudioControllerStrategy::pause(QMediaPlayer* mp){
    mp->pause();
}

void AudioControllerStrategy::stop(QMediaPlayer* mp){
    mp->stop();
}

void AudioControllerStrategy::setVolume(int n, QMediaPlayer* mp){
    mp->setVolume(n);
}

void AudioControllerStrategy::seek(int n, QMediaPlayer* mp){
    mp->setPosition(n);
}
