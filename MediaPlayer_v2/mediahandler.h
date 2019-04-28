#ifndef MEDIAHANDLER_H
#define MEDIAHANDLER_H

#include <QUrl>
#include "controllerstrategy.h"
// CHAIN OF RESPONSIBILITY BASE CLASS

class MediaHandler
{
public:
    MediaHandler();
    virtual ~MediaHandler();
    virtual ControllerStrategy * determineController(const QString);
    void setNext(MediaHandler*);
    void addHandler(MediaHandler*);

private:
    MediaHandler * nextHandler;

protected:
    ControllerStrategy * strategy;
};

#endif // MEDIAHANDLER_H
