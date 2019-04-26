#ifndef MEDIAPLAYERWIDGET_H
#define MEDIAPLAYERWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include "controllerwidget.h"

namespace Ui {
class MediaPlayerWidget;
}

class MediaPlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayerWidget(QWidget *parent = nullptr);
    ~MediaPlayerWidget();

private:
    Ui::MediaPlayerWidget *ui;
    ControllerWidget * controllerWidget;
    QVideoWidget * vw;
    QMediaPlayer * mp;
};

#endif // MEDIAPLAYERWIDGET_H
