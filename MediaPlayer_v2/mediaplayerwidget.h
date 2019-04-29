#ifndef MEDIAPLAYERWIDGET_H
#define MEDIAPLAYERWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include "controllerwidget.h"
#include "audiocontrollerstrategy.h"
#include "videocontrollerstrategy.h"
#include "mediahandler.h"
#include "audiohandler.h"
#include "videohandler.h"
#include "playlistwidget.h"

/*
 * MEDIATOR
 * Handles interaction between the controller,
 * media player, and playlist widgets
 * */

namespace Ui {
class MediaPlayerWidget;
}

class MediaPlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayerWidget(QWidget *parent = nullptr);
    ~MediaPlayerWidget();


private slots:
    void on_pushButton_pressed();

private:
    Ui::MediaPlayerWidget *ui;
    ControllerWidget * controllerWidget;
    QVideoWidget * vw;
    QMediaPlayer * mp;
    MediaHandler * handler;
    PlaylistWidget * playlistWidget;

    void setMedia(QString);
    void buildChain();
    void chooseStrategy(QString); // change strategy based on filename
};

#endif // MEDIAPLAYERWIDGET_H
