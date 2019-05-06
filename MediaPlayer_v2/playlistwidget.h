#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QMediaPlaylist>
#include <QDir>
#include <QInputDialog>
#include <QFileDialog>

namespace Ui {
class PlaylistWidget;
}

class PlaylistWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistWidget(QWidget *parent = nullptr);
    ~PlaylistWidget();

    void next();
    void previous();
    void displayPlaylists();
    void displayPlaylistContent();
    void updateTitle(QString);
    void addPlaylist();
    void deletePlaylist(QString);
    void loadPlaylist(QString);

private slots:
    void on_addPlaylistButton_pressed();

    void on_deletePlaylistButton_pressed();

    void on_loadPlaylistButton_pressed();

private:
    Ui::PlaylistWidget *ui;
    const QString PLAYLIST_PATHNAME = "Playlists";
    QMediaPlaylist * mediaPlaylist;
    QString currentPlaylistName;
    const QString BASE_PATH = QDir().absolutePath() + "/Playlists/";
};

#endif // PLAYLISTWIDGET_H
