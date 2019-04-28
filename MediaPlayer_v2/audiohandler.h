#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H
#include "mediahandler.h"
#include "audiocontrollerstrategy.h"
// CONCRETE HANDLER FOR CHAIN OF RESPONSIBILITY

class AudioHandler : public MediaHandler
{
public:
    AudioHandler();
    virtual ~AudioHandler() = default;

    virtual ControllerStrategy * determineController(const QString);
private:
    bool isAudio(const QString);
};

#endif // AUDIOHANDLER_H
