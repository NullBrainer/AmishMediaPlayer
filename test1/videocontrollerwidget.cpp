#include "videocontrollerwidget.h"
#include "ui_videocontrollerwidget.h"
VideoControllerWidget::VideoControllerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoControllerWidget)
{
    ui->setupUi(this);
}

VideoControllerWidget::~VideoControllerWidget()
{
    delete ui;
}
