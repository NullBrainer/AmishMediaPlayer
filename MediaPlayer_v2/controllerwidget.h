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
    void playNewMedia();

private slots:
    void on_playButton_pressed();

    void on_pauseButton_pressed();

    void on_stopButton_pressed();

    void on_previousButton_pressed();

    void on_nextButton_pressed();

signals:

    void nextPressed();
    void previousPressed();

private:
    Ui::ControllerWidget *ui;
    ControllerStrategy * controllerStrat;
    QMediaPlayer * mp;
};

#endif // CONTROLLERWIDGET_H
