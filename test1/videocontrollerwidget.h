#ifndef VIDEOCONTROLLERWIDGET_H
#define VIDEOCONTROLLERWIDGET_H

#include <QWidget>

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
    explicit VideoControllerWidget(QWidget *parent = nullptr);
    ~VideoControllerWidget();

private:
    Ui::VideoControllerWidget *ui;
};

#endif // VIDEOCONTROLLERWIDGET_H
