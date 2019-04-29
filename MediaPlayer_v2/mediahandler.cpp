#include "mediahandler.h"

MediaHandler::MediaHandler()
{
    nextHandler = nullptr;
}

MediaHandler::~MediaHandler(){
    delete nextHandler;
    delete strategy;
}

ControllerStrategy * MediaHandler::determineController(const QString filename){
    return nextHandler->determineController(filename);
}

void MediaHandler::setNext(MediaHandler * handler){
    nextHandler = handler;
}

void MediaHandler::addHandler(MediaHandler * handler){
    qDebug() << "GOT HERE!!!";
    if(nextHandler != nullptr){
        nextHandler->addHandler(handler);
    }
    else{
        nextHandler = handler;
    }
}
