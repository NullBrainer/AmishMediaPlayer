#include "controllerwidget.h"
#include "ui_controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControllerWidget)
{
    ui->setupUi(this);
    buttonSetup();
}

ControllerWidget::~ControllerWidget()
{
    delete ui;
    delete controllerStrat;
}

void ControllerWidget::setStrategy(ControllerStrategy * cs){
    this->controllerStrat = cs;
}

void ControllerWidget::setMediaPlayer(QMediaPlayer * mediaPlayer){
    this->mp = mediaPlayer;
}

void ControllerWidget::moveSlider(qint64 pos){
    ui->durationSlider->setValue(pos);
    QTime displayTime(0, (pos / 60000) % 60, (pos / 1000) % 60);
    ui->timestampLabel->setText(displayTime.toString("mm:ss"));
}

void ControllerWidget::adjustSliderMax(qint64 max){
    ui->durationSlider->setMaximum(max);
}

void ControllerWidget::on_playButton_pressed()
{
    controllerStrat->play(mp);
}

void ControllerWidget::on_pauseButton_pressed()
{
    controllerStrat->pause(mp);
}

void ControllerWidget::on_stopButton_pressed()
{
    controllerStrat->stop(mp);
}

void ControllerWidget::on_previousButton_pressed()
{
    controllerStrat->stop(mp);
    emit previousPressed();
}

void ControllerWidget::on_nextButton_pressed()
{
    controllerStrat->stop(mp);
    emit nextPressed();
}

void ControllerWidget::playNewMedia(){
    controllerStrat->stop(mp);
    controllerStrat->play(mp);
}

void ControllerWidget::buttonSetup(){
    QPixmap pixmapPlay(QDir().absolutePath() + "/player_buttons/play-button.png");
    QPixmap pixmapPause(QDir().absolutePath() + "/player_buttons/rounded-pause-button.png");
    QPixmap pixmapStop(QDir().absolutePath() + "/player_buttons/stop-button.png");
    QPixmap pixmapNext(QDir().absolutePath() + "/player_buttons/next-button.png");
    QPixmap pixmapPrevious(QDir().absolutePath() + "/player_buttons/previous-button.png");

    QIcon playIcon(pixmapPlay);
    QIcon pauseIcon(pixmapPause);
    QIcon stopIcon(pixmapStop);
    QIcon nextIcon(pixmapNext);
    QIcon previousIcon(pixmapPrevious);

    ui->playButton->setIcon(playIcon);
    ui->pauseButton->setIcon(pauseIcon);
    ui->stopButton->setIcon(stopIcon);
    ui->nextButton->setIcon(nextIcon);
    ui->previousButton->setIcon(previousIcon);

    ui->playButton->setIconSize(ui->playButton->size());
    ui->pauseButton->setIconSize(ui->pauseButton->size());
    ui->stopButton->setIconSize(ui->stopButton->size());
    ui->nextButton->setIconSize(ui->nextButton->size());
    ui->previousButton->setIconSize(ui->previousButton->size());

}
