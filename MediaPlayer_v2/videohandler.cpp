#include "videohandler.h"

VideoHandler::VideoHandler()
{
    strategy = new VideoControllerStrategy();
}

ControllerStrategy * VideoHandler::determineController(const QString filename){
    if(isVideo(filename)){
        return strategy;
    }
    else{
        return MediaHandler::determineController(filename);
    }
}

bool VideoHandler::isVideo(const QString filename){
    return filename.toLower().endsWith(".mp4");
}
