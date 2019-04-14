#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audiowindowwidget.h"
#include "videowindowwidget.h"
#include "playlist.h"
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

private slots:


    void on_chooseVideoPlayer_pressed();

    void on_chooseAudioPlayer_pressed();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * mediaPlayer;
    VideoWindowWidget* Video;
    AudioWindowWidget* Audio;
};

#endif // MAINWINDOW_H
