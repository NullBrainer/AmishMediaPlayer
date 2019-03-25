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
    explicit VideoWindowWidget(QWidget *parent = nullptr);
    ~VideoWindowWidget();

private slots:
    void on_FileButton_pressed();
public slots:
    void on_actiononMediaSwitch_triggered();

private:
    Ui::VideoWindowWidget *ui;
    // RenderStrategy* rendermethod;

    // VidController and videoWidget will interact
    VideoControllerWidget* VidController;
    QVideoWidget* videoWidget;

};

#endif // VIDEOWINDOWWIDGET_H
