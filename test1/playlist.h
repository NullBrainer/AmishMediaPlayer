#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QDir>
#include <QInputDialog>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QFileDialog>
#include "audiowindowwidget.h"

namespace Ui {
class Playlist;
}

class Playlist : public QWidget
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = nullptr);
    ~Playlist();
    void displayPlaylistContent();
    QString currentFileName();
    void next();
    void previous();
    bool empty();
    int currentIndex();

signals:
    void playlistLoaded();

private slots:
    void on_addPlaylistButton_pressed();

    void on_loadPlaylistButton_pressed();

    void on_addContentButton_pressed();

    void on_deleteContentButton_pressed();

    void on_deletePlaylistButton_pressed();

    void on_ShuffleButton_pressed();

private:
    Ui::Playlist *ui;
    QMediaPlaylist * mediaPlaylist;
    QMediaPlayer * mediaPlayer;
    QGraphicsView * displayPort;
    QWidget * parent;
    AudioWindowWidget * audio; // test
    QString currentPlaylistName;
    bool shuffleToggle;
};

#endif // PLAYLIST_H
