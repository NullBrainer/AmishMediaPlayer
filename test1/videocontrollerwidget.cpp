#include "videocontrollerwidget.h"
#include "ui_videocontrollerwidget.h"
VideoControllerWidget::VideoControllerWidget(QWidget *parent, QVideoWidget* vw, QMediaPlayer * mediaPlayer) :
    QWidget(parent),
    ui(new Ui::VideoControllerWidget)
{
    ui->setupUi(this);
    this->mediaPlayer = mediaPlayer;
    videoController = new VideoController(vw, this->mediaPlayer);
    // For testing purposes
    /*QString videoFileName = QFileDialog::getOpenFileName(parent, "Open Video File", "", "Video File (*.mp4)");
    this->changeVideo(videoFileName);*/
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(moveSeeker(qint64)));
    connect(mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(adjustMax(qint64)));
}

void VideoControllerWidget::changeVideo(QString videoFile){

    videoController->change(videoFile);
}

/*A function call unique to controllerwidgets, used to return the desired RenderStrategy*/
VideoWindowRender* VideoControllerWidget::MakeWindow()
{
    return new VideoWindowRender();
}

VideoControllerWidget::~VideoControllerWidget()
{
    delete ui;
}

void VideoControllerWidget::on_actionPlay_triggered()
{
    videoController->play();
}

void VideoControllerWidget::on_actionPause_triggered()
{
    videoController->pause();
}

void VideoControllerWidget::on_actionStop_triggered()
{
    videoController->stop();
}

void VideoControllerWidget::on_PlayButton_pressed()
{
    this->VideoControllerWidget::on_actionPlay_triggered();
}

void VideoControllerWidget::on_PauseButton_pressed()
{
    this->VideoControllerWidget::on_actionPause_triggered();
}

void VideoControllerWidget::on_StopButton_pressed()
{
    this->VideoControllerWidget::on_actionStop_triggered();
}

void VideoControllerWidget::on_NextButton_pressed()
{
    emit orderAdvanced();
}

void VideoControllerWidget::on_PreviousButton_pressed()
{
    emit orderPrevious();
}

void VideoControllerWidget::moveSeeker(qint64 pos){
    ui->SeekerSlider->setValue(pos);
    QTime displayTime(0, (pos / 60000) % 60, (pos / 1000) % 60);
    ui->timeDisplay->setText(displayTime.toString("mm:ss"));
}

void VideoControllerWidget::adjustMax(qint64 max){
    ui->SeekerSlider->setMaximum(max);
}

void VideoControllerWidget::on_dial_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}
