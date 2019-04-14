#ifndef AUDIOWINDOWWIDGET_H
#define AUDIOWINDOWWIDGET_H

#include <QWidget>
#include "audiocontrollerwidget.h"

namespace Ui {
class AudioWindowWidget;
}

class AudioWindowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioWindowWidget(QWidget *parent = nullptr, QMediaPlayer * mediaPlayer = nullptr);
    ~AudioWindowWidget();
    void changeFile(QString);
signals:
    void orderPushedForward();
    void orderPushedBackward();
private slots:
    void on_FileButton_pressed();
    void orderAdvanced();
    void orderPrevious();
public slots:
    void on_actiononMediaSwitch_triggered();

private:
    Ui::AudioWindowWidget *ui;
    AudioControllerWidget* AudioController;
    QMediaPlayer * mediaPlayer;
    // Optional display widget for audio

};

#endif // AUDIOWINDOWWIDGET_H
