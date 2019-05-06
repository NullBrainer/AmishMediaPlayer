#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QMediaPlaylist>
#include <QDir>
#include <QInputDialog>
#include <QFileDialog>
#include <QPixmap>
#include <QIcon>

namespace Ui {
class PlaylistWidget;
}

class PlaylistWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistWidget(QWidget *parent = nullptr);
    ~PlaylistWidget();

    bool shuffleToggle;
    void next();
    void previous();
    void displayPlaylists();
    void displayPlaylistContent();
    void updateTitle(QString);
    void addPlaylist();
    void deletePlaylist(QString);
    void loadPlaylist(QString);
    void addContent(QString);
    void deleteContent(int);
    QString getCurrentSongPath();
    QString formatPath(QString);
    bool empty();

signals:
    void nextContentLoaded();

public slots:
    void doubleClicked();
    void nextPressed();
    void previousPressed();

private slots:
    void on_addPlaylistButton_pressed();

    void on_deletePlaylistButton_pressed();

    void on_loadPlaylistButton_pressed();

    void on_addContentButton_pressed();

    void on_deleteContentButton_pressed();

    void on_shuffleButton_pressed();

private:
    Ui::PlaylistWidget *ui;
    const QString PLAYLIST_PATHNAME = "Playlists";
    QMediaPlaylist * mediaPlaylist;
    QString currentPlaylistName;
    QString currentSongPath;
    const QString BASE_PATH = QDir().absolutePath() + "/Playlists/";

    void buttonSetup();
};

#endif // PLAYLISTWIDGET_H
