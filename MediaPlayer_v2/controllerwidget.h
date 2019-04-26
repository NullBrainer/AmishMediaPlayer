#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTime>
#include "controllerstrategy.h"

namespace Ui {
class ControllerWidget;
}

class ControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerWidget(QWidget *parent = nullptr);
    void setStrategy(ControllerStrategy*);

    ~ControllerWidget();

public slots:
    void moveSlider(qint64 pos);
    void adjustSliderMax(qint64 max);

private:
    Ui::ControllerWidget *ui;
    ControllerStrategy * controllerStrat;

};

#endif // CONTROLLERWIDGET_H
