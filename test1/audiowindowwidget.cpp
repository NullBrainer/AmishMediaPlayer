#include "audiowindowwidget.h"
#include "ui_audiowindowwidget.h"

AudioWindowWidget::AudioWindowWidget(QWidget *parent, QMediaPlayer *mediaPlayer) :
    QWidget(parent),
    ui(new Ui::AudioWindowWidget)
{
    ui->setupUi(this);
    this->mediaPlayer = mediaPlayer;
    AudioController = new AudioControllerWidget(this, this->mediaPlayer);
    ui->ButtonController->setViewport(AudioController);
}

AudioWindowWidget::~AudioWindowWidget()
{
    delete ui;
    delete AudioController;
}

void AudioWindowWidget::on_FileButton_pressed()
{
    QString audioFile = QFileDialog::getOpenFileName(this, "Open Audio File", "", "Audio File (*.mp3)");
    AudioController->changeAudio(audioFile);
}

void AudioWindowWidget::on_actiononMediaSwitch_triggered()
{
    AudioController->on_actionStop_triggered();
}
