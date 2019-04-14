#include "videowindowwidget.h"
#include "ui_videowindowwidget.h"

VideoWindowWidget::VideoWindowWidget(QWidget *parent, QMediaPlayer *mediaPlayer) : QWidget(parent),ui(new Ui::VideoWindowWidget)
{
    ui->setupUi(this);
    this->mediaPlayer = mediaPlayer;
    /*
    rendermethod = VidController->MakeWindow();
    rendermethod->Render(this);
    */

    videoWidget = new QVideoWidget(ui->DisplayView);
    VidController = new VideoControllerWidget(ui->ButtonController, videoWidget, this->mediaPlayer);
    ui->DisplayView->setViewport(videoWidget);
    ui->ButtonController->setViewport(VidController);
    connect(VidController, SIGNAL(orderAdvanced()), this, SLOT(orderAdvanced()));
    connect(VidController, SIGNAL(orderPrevious()), this, SLOT(orderPrevious()));
}

void VideoWindowWidget::orderAdvanced(){
    emit orderPushedForward();
    qDebug("VIDEO MOVE FORWARD");
}

void VideoWindowWidget::orderPrevious(){
    emit orderPushedBackward();
    qDebug("VIDEO MOVE BACKWARD");
}

VideoWindowWidget::~VideoWindowWidget()
{
    delete ui;
    // delete rendermethod;
    delete VidController;
}

void VideoWindowWidget::changeFile(QString fileName){
    VidController->changeVideo(fileName);
}

void VideoWindowWidget::on_FileButton_pressed()
{
    QString videoFile = QFileDialog::getOpenFileName(this, "Open Video File", "", "Video File (*.mp4)");
    VidController->changeVideo(videoFile);
}

void VideoWindowWidget::on_actiononMediaSwitch_triggered()
{
    VidController->on_actionStop_triggered();

}
