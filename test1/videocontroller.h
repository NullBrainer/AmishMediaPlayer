#ifndef VIDEOCONTROLLER_H
#define VIDEOCONTROLLER_H
#include "icontroller.h"
#include <QMediaPlayer>

/* Concrete controller for videos */
class VideoController : public IController{
public:
    VideoController(QVideoWidget*);
    virtual void play();
    virtual void pause();
    virtual void stop();
    virtual void change(QString);

    virtual ~VideoController();
private:
    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
};

#endif // VIDEOCONTROLLER_H
