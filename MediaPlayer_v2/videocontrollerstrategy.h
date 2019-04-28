#ifndef VIDEOCONTROLLERSTRATEGY_H
#define VIDEOCONTROLLERSTRATEGY_H
#include "controllerstrategy.h"

class VideoControllerStrategy : public ControllerStrategy
{
public:
    VideoControllerStrategy() = default;
    virtual void play(QMediaPlayer*);
    virtual void pause(QMediaPlayer*);
    virtual void stop(QMediaPlayer*);
    virtual void setVolume(int, QMediaPlayer*);
    virtual void seek(int, QMediaPlayer*);

    virtual ~VideoControllerStrategy() = default;
};

#endif // VIDEOCONTROLLERSTRATEGY_H
