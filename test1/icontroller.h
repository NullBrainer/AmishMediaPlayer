#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <QWidget>
/* Family of behaviors for controllers for media */
class IController{
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void change(QString) = 0;
    virtual ~IController() = default;
private:
};

#endif // ICONTROLLER_H
