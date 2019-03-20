#ifndef VIDEOCONTROLLERWIDGET_H
#define VIDEOCONTROLLERWIDGET_H

#include <QWidget>

namespace Ui {
class VideoControllerWidget;
}

class VideoControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoControllerWidget(QWidget *parent = nullptr);
    ~VideoControllerWidget();

private:
    Ui::VideoControllerWidget *ui;
};

#endif // VIDEOCONTROLLERWIDGET_H
