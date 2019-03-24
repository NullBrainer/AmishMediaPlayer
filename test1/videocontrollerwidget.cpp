#include "videocontrollerwidget.h"
#include "ui_videocontrollerwidget.h"
VideoControllerWidget::VideoControllerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoControllerWidget)
{
    ui->setupUi(this);

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
