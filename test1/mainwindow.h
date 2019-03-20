#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultimedia>
#include <QtMultimediaWidgets>
#include <QFileDialog>
#include "videowindowrender.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    RenderStrategy* rendermethod;
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
};

#endif // MAINWINDOW_H
