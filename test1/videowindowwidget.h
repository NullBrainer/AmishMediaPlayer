#ifndef VIDEOWINDOWWIDGET_H
#define VIDEOWINDOWWIDGET_H

#include <QWidget>
#include "videocontrollerwidget.h"
#include "videowindowrender.h"
#include <QFileDialog>


/*
The widget that be encapsulating render behavior and buttons.
*/
namespace Ui {
class VideoWindowWidget;
}

class VideoWindowWidget : public QWidget
{
    Q_OBJECT

public:
    VideoWindowWidget(QWidget *parent = nullptr, QMediaPlayer *mediaPlayer = nullptr);
    ~VideoWindowWidget();

private slots:
    void on_FileButton_pressed();
public slots:
    void on_actiononMediaSwitch_triggered();

private:
    Ui::VideoWindowWidget *ui;
    QMediaPlayer * mediaPlayer;
    // RenderStrategy* rendermethod;

    // VidController and videoWidget will interact
    VideoControllerWidget* VidController;
    QVideoWidget* videoWidget;

};

#endif // VIDEOWINDOWWIDGET_H
