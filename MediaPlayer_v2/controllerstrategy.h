#ifndef CONTROLLERSTRATEGY_H
#define CONTROLLERSTRATEGY_H
#include <QMediaPlayer>

class ControllerStrategy
{
public:
    ControllerStrategy() = default;
    virtual void play(QMediaPlayer *) = 0;
    virtual void pause(QMediaPlayer *) = 0;
    virtual void stop(QMediaPlayer *) = 0;
    virtual void setVolume(int, QMediaPlayer *) = 0;
    virtual void seek(int, QMediaPlayer*) = 0;

    virtual ~ControllerStrategy() = default;
};

#endif // CONTROLLERSTRATEGY_H
