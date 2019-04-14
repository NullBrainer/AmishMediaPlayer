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
    explicit VideoControllerWidget(QWidget *parent = nullptr, QVideoWidget* vw = nullptr, QMediaPlayer * mediaPlayer = nullptr);
    VideoWindowRender* MakeWindow();
    void changeVideo(QString);
    ~VideoControllerWidget();

public slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

private slots:
    void on_PlayButton_pressed();

    void on_PauseButton_pressed();

    void on_StopButton_pressed();

private:
    Ui::VideoControllerWidget *ui;
    IController * videoController;
    QMediaPlayer * mediaPlayer;
};

#endif // VIDEOCONTROLLERWIDGET_H
