#include "videocontrollerwidget.h"
#include "ui_videocontrollerwidget.h"
VideoControllerWidget::VideoControllerWidget(QWidget *parent, QVideoWidget* vw) :
    QWidget(parent),
    ui(new Ui::VideoControllerWidget)
{
    ui->setupUi(this);
    videoController = new VideoController(vw);
    // For testing purposes
    QString videoFileName = QFileDialog::getOpenFileName(parent, "Open Video File", "", "Video File (*.mp4)");
    this->changeVideo(videoFileName);
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
