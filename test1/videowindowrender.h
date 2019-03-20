#ifndef VIDEOWINDOWRENDER_H
#define VIDEOWINDOWRENDER_H

#include "RenderStrategy.h"

/*
A Class using the IStrategy interface used to
render objects used for the video player.

*/
class VideoWindowRender : public RenderStrategy
{
 public:
    virtual void Render(QObject*);

 private:

};

#endif // VIDEOWINDOWRENDER_H
