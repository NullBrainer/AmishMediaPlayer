#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "videowindowwidget.h"
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


private:
    Ui::MainWindow *ui;
    VideoWindowWidget* Video;
};

#endif // MAINWINDOW_H
