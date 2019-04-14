#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H
#include "icontroller.h"
#include <QMediaPlayer>

class AudioController : public IController
{
public:
    AudioController(QMediaPlayer*);
    virtual void play();
    virtual void pause();
    virtual void stop();
    virtual void change(QString);
    virtual ~AudioController();

private:
    QMediaPlayer* mediaPlayer;
};

#endif // AUDIOCONTROLLER_H
