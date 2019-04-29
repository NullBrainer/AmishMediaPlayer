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
    void setMediaPlayer(QMediaPlayer *);

    ~ControllerWidget();

public slots:
    void moveSlider(qint64 pos);
    void adjustSliderMax(qint64 max);

private slots:
    void on_playButton_pressed();

    void on_pauseButton_pressed();

    void on_stopButton_pressed();

private:
    Ui::ControllerWidget *ui;
    ControllerStrategy * controllerStrat;
    QMediaPlayer * mp;
};

#endif // CONTROLLERWIDGET_H
