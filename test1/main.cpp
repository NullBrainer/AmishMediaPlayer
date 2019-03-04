#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    /*
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\RJ\\Pictures\\Camera Roll\\WIN_20190226_232622.MP4"));
    vw->setGeometry(100,100,300,400);
    vw->show();
    player->play();
    qDebug() << player->state();
    */
    return a.exec();
}
