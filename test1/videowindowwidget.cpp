#include "videowindowwidget.h"
#include "ui_videowindowwidget.h"

VideoWindowWidget::VideoWindowWidget(QWidget *parent) : QWidget(parent),ui(new Ui::VideoWindowWidget),VidController{new VideoControllerWidget}
{
    ui->setupUi(this);
    rendermethod = VidController->MakeWindow();
    rendermethod->Render(this);

}



VideoWindowWidget::~VideoWindowWidget()
{
    delete ui;
}
