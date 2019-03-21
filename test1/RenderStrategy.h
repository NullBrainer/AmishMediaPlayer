#ifndef RENDERSTRATEGY_H
#define RENDERSTRATEGY_H
#include <QMainWindow>
/*
The Interface used for the Strategy design pattern
This interface will be used for the different rendering behaviors of the media player
The pointer to the main window will be the argument for the QObject.
*/
class RenderStrategy
{
 public:
virtual void Render(QMainWindow*) = 0;
virtual ~RenderStrategy() = default;
 private:

};

#endif // RENDERSTRATEGY_H
