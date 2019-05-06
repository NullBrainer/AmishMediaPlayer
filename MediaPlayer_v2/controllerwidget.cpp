#include "controllerwidget.h"
#include "ui_controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControllerWidget)
{
    ui->setupUi(this);
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
