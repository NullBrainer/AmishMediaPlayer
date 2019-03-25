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
    explicit AudioWindowWidget(QWidget *parent = nullptr);
    ~AudioWindowWidget();

private slots:
    void on_FileButton_pressed();
public slots:
    void on_actiononMediaSwitch_triggered();

private:
    Ui::AudioWindowWidget *ui;
    AudioControllerWidget* AudioController;
    // Optional display widget for audio

};

#endif // AUDIOWINDOWWIDGET_H
