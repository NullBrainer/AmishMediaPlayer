#ifndef VIDEOCONTROLLERSTRATEGY_H
#define VIDEOCONTROLLERSTRATEGY_H
#include "controllerstrategy.h"

class VideoControllerStrategy : public ControllerStrategy
{
public:
    VideoControllerStrategy() = default;
    virtual void play(QMediaPlayer*);
    virtual void pause(QMediaPlayer*) = 0;
    virtual void stop(QMediaPlayer*) = 0;
    virtual void setVolume(int, QMediaPlayer*) = 0;
    virtual void seek(int, QMediaPlayer*) = 0;

    virtual ~VideoControllerStrategy() = default;
};

#endif // VIDEOCONTROLLERSTRATEGY_H
