#ifndef VIDEOHANDLER_H
#define VIDEOHANDLER_H
#include "controllerstrategy.h"
#include "videocontrollerstrategy.h"
#include "mediahandler.h"

class VideoHandler : public MediaHandler
{
public:
    VideoHandler();
    virtual ~VideoHandler() = default;

    virtual ControllerStrategy * determineController(const QString);
private:
    bool isVideo(const QString);
};

#endif // VIDEOHANDLER_H
