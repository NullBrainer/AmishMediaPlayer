#ifndef VIDEOWINDOWRENDER_H
#define VIDEOWINDOWRENDER_H
#include <QMultimedia>
#include <QtMultimediaWidgets>
#include <QFileDialog>

#include "RenderStrategy.h"

/*
A Class using the IRender interface used to
render objects used for the video player.
This Class uses QMediaplayer to set up the video player
using QVideoWidget.
*/
class VideoWindowRender : public RenderStrategy
{
 public:
    virtual void Render(QWidget*);

 private:
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
    QGraphicsView* view;
};

#endif // VIDEOWINDOWRENDER_H
