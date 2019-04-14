#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audiowindowwidget.h"
#include "videowindowwidget.h"
#include "playlist.h"
#include <QVector>
#include <string>
namespace Ui {
class MainWindow;
}
/*
Main Window will be the encapsulating class that instantiates and uses
the main componenents of the project.
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isVideo(QString);
    void loadVideoPlayer();
    void loadAudioPlayer();
private slots:

    void playlistNext();
    void playlistPrevious();

    void on_chooseVideoPlayer_pressed();

    void on_chooseAudioPlayer_pressed();

    void on_fileButton_pressed();

    void playlistLoaded();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * mediaPlayer;
    VideoWindowWidget* Video;
    AudioWindowWidget* Audio;
    Playlist * playlist;
};

#endif // MAINWINDOW_H
