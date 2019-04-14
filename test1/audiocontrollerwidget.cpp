#include "audiocontrollerwidget.h"
#include "ui_audiocontrollerwidget.h"

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
