#ifndef ISTRATEGY_H
#define ISTRATEGY_H
#include <QMainWindow>
/*
The Interface used for the Strategy design pattern
This interface will be used for the different rendering behaviors of the media player
The pointer to the main window will be the argument for the QObject.
*/
class IStrategy
{
 public:
virtual void Render(QObject*) = 0;
virtual ~IStrategy() = 0;
 private:

};

#endif // ISTRATEGY_H
