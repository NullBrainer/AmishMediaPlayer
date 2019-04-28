#include "audiohandler.h"

AudioHandler::AudioHandler()
{
    strategy = new AudioControllerStrategy();
}

ControllerStrategy * AudioHandler::determineController(const QString filename){
    if(isAudio(filename)){
        return strategy;
    }
    else{
        return MediaHandler::determineController(filename);
    }
}

// private functions
bool AudioHandler::isAudio(const QString filename){
    return filename.toLower().endsWith(".mp3");
}
