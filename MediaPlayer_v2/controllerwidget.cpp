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
}

void ControllerWidget::setStrategy(ControllerStrategy * cs){
    this->controllerStrat = cs;
}

void ControllerWidget::moveSlider(qint64 pos){
    ui->durationSlider->setValue(pos);
    QTime displayTime(0, (pos / 60000) % 60, (pos / 1000) % 60);
    ui->timestampLabel->setText(displayTime.toString("mm:ss"));
}

void ControllerWidget::adjustSliderMax(qint64 max){
    ui->durationSlider->setMaximum(max);
}
