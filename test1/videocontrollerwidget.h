#ifndef VIDEOCONTROLLERWIDGET_H
#define VIDEOCONTROLLERWIDGET_H
#include <QWidget>
#include <QVideoWidget>
#include "videowindowrender.h"
#include "icontroller.h"
#include "videocontroller.h"

/*The class will used button rendering,
 *  the parent given will be the observers of the
buttons rendered from this class.*/

namespace Ui {
class VideoControllerWidget;
}

class VideoControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoControllerWidget(QWidget *parent = nullptr, QVideoWidget* vw = nullptr);
    VideoWindowRender* MakeWindow();
    void changeVideo(QString);
    ~VideoControllerWidget();

private:
    Ui::VideoControllerWidget *ui;
    IController * videoController;
};

#endif // VIDEOCONTROLLERWIDGET_H
