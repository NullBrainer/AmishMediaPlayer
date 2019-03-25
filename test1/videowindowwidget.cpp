#include "videowindowwidget.h"
#include "ui_videowindowwidget.h"

VideoWindowWidget::VideoWindowWidget(QWidget *parent) : QWidget(parent),ui(new Ui::VideoWindowWidget),VidController{new VideoControllerWidget}
{
    ui->setupUi(this);
    /*
    rendermethod = VidController->MakeWindow();
    rendermethod->Render(this);
    */

    videoWidget = new QVideoWidget(ui->DisplayView);
    VidController = new VideoControllerWidget(ui->ButtonController, videoWidget);
    ui->DisplayView->setViewport(videoWidget);
    ui->ButtonController->setViewport(VidController);
}

VideoWindowWidget::~VideoWindowWidget()
{
    delete ui;
    // delete rendermethod;
    delete VidController;
}
