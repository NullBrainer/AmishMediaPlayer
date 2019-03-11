#ifndef VIDEOWINDOWRENDER_H
#define VIDEOWINDOWRENDER_H

#include "istrategy.h"

/*
A Class using the IStrategy interface used to
render objects used for the video player.

*/
class VideoWindowRender : public IStrategy
{
 public:
    virtual void Render(QObject*);

 private:

};

#endif // VIDEOWINDOWRENDER_H
