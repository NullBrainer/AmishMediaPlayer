#include "audiocontrollerwidget.h"
#include "ui_audiocontrollerwidget.h"
#include <QTime>

AudioControllerWidget::AudioControllerWidget(QWidget *parent, QMediaPlayer * mediaPlayer) :
    QWidget(parent),
    ui(new Ui::AudioControllerWidget)
{
    ui->setupUi(this);
    this->mediaPlayer = mediaPlayer;
    audioController = new AudioController(this->mediaPlayer);
    // For testing purposes
    /*
    QString audioFileName = QFileDialog::getOpenFileName(parent, "Open Audio File", "", "Video File (*.mp3)");
    this->changeAudio(audioFileName);
    */
    /*

    */
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(moveSeeker(qint64)));
    connect(mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(adjustMax(qint64)));
}

void AudioControllerWidget::changeAudio(QString audioFile){
    audioController->change(audioFile);
}

AudioControllerWidget::~AudioControllerWidget()
{
    delete ui;
}

void AudioControllerWidget::on_actionPlay_triggered()
{
    audioController->play();
}

void AudioControllerWidget::on_actionPause_triggered()
{
    audioController->pause();
}

void AudioControllerWidget::on_actionStop_triggered()
{
    audioController->stop();
}

void AudioControllerWidget::on_PlayButton_pressed()
{
    this->AudioControllerWidget::on_actionPlay_triggered();
}

void AudioControllerWidget::on_PauseButton_pressed()
{
    this->AudioControllerWidget::on_actionPause_triggered();
}

void AudioControllerWidget::on_StopButton_pressed()
{
    this->AudioControllerWidget::on_actionStop_triggered();
}

void AudioControllerWidget::on_NextButton_pressed()
{
    emit orderAdvanced();
}

void AudioControllerWidget::on_PreviousButton_pressed()
{
    emit orderPrevious();
}

void AudioControllerWidget::moveSeeker(qint64 pos){
    ui->SeekerSlider->setValue(pos);
    QTime displayTime(0, (pos / 60000) % 60, (pos / 1000) % 60);
    ui->timeDisplay->setText(displayTime.toString("mm:ss"));
}
void AudioControllerWidget::adjustMax(qint64 max){
    ui->SeekerSlider->setMaximum(max);
}

void AudioControllerWidget::on_dial_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}

void AudioControllerWidget::on_SeekerSlider_sliderMoved(int position)
{
    mediaPlayer->setPosition(position);
}
