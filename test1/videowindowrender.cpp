#include "videowindowrender.h"
/*
 *Video Rendering behavior
 * MediaPlayerWindow - the reference to the parent class that will render the video player
 * It's the MainWindow class
*/
void VideoWindowRender::Render(QWidget* MediaPlayerWindow)
{
        mediaPlayer = new QMediaPlayer(MediaPlayerWindow);
        videoWidget = new QVideoWidget(MediaPlayerWindow);

        view = new QGraphicsView();
        view->setParent(MediaPlayerWindow);
        view->setViewport(videoWidget);

        QString videoFileName = QFileDialog::getOpenFileName(MediaPlayerWindow, "Open Video File", "", "Video File (*.mp4)");

        mediaPlayer->stop();
        mediaPlayer->setMedia(QUrl::fromLocalFile(videoFileName));
        mediaPlayer->setVideoOutput(videoWidget);

        videoWidget->show();
        mediaPlayer->play();
}
