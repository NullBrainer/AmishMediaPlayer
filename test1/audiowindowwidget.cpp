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
    connect(AudioController, SIGNAL(orderAdvanced()), this, SLOT(orderAdvanced()));
    connect(AudioController, SIGNAL(orderPrevious()), this, SLOT(orderPrevious()));
}

AudioWindowWidget::~AudioWindowWidget()
{
    delete ui;
    delete AudioController;
}

void AudioWindowWidget::changeFile(QString fileName){
    AudioController->changeAudio(fileName);
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

void AudioWindowWidget::orderAdvanced(){
    emit orderPushedForward();
    qDebug("AUDIO MOVE FORWARD");
}

void AudioWindowWidget::orderPrevious(){
    emit orderPushedBackward();
    qDebug("AUDIO MOVE BACKWARD");
}

