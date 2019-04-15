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

signals:
    void orderAdvanced();
    void orderPrevious();

public slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

private slots:
    void on_PlayButton_pressed();

    void on_PauseButton_pressed();

    void on_StopButton_pressed();

    void on_NextButton_pressed();

    void on_PreviousButton_pressed();
    void moveSeeker(qint64 pos);
    void adjustMax(qint64 max);

    void on_dial_valueChanged(int value);

    void on_SeekerSlider_sliderMoved(int position);

private:
    Ui::VideoControllerWidget *ui;
    IController * videoController;
    QMediaPlayer * mediaPlayer;
};

#endif // VIDEOCONTROLLERWIDGET_H
