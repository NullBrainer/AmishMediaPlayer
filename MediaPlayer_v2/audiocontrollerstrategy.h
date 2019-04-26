#ifndef AUDIOCONTROLLERSTRATEGY_H
#define AUDIOCONTROLLERSTRATEGY_H
#include <QDebug>
#include "controllerstrategy.h"

class AudioControllerStrategy : public ControllerStrategy
{
public:
    AudioControllerStrategy() = default;
    virtual void play(QMediaPlayer*);
    virtual void pause(QMediaPlayer*);
    virtual void stop(QMediaPlayer*);
    virtual void setVolume(int, QMediaPlayer*);
    virtual void seek(int, QMediaPlayer*);

    virtual ~AudioControllerStrategy() = default;
};

#endif // AUDIOCONTROLLERSTRATEGY_H
