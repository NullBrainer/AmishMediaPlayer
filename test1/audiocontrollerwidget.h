#ifndef AUDIOCONTROLLERWIDGET_H
#define AUDIOCONTROLLERWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "icontroller.h"
#include "audiocontroller.h"

namespace Ui {
class AudioControllerWidget;
}

class AudioControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioControllerWidget(QWidget *parent = nullptr, QMediaPlayer * mediaPlayer = nullptr);
    void changeAudio(QString);
    ~AudioControllerWidget();

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

private:
    Ui::AudioControllerWidget *ui;
    IController * audioController;
    QMediaPlayer * mediaPlayer;
};

#endif // AUDIOCONTROLLERWIDGET_H
