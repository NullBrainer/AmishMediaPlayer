#include "mediaplayerwidget.h"
#include "ui_mediaplayerwidget.h"

MediaPlayerWidget::MediaPlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayerWidget)
{
    ui->setupUi(this);

    vw = new QVideoWidget(this);
    mp = new QMediaPlayer(this);
    controllerWidget = new ControllerWidget(this);

    controllerWidget->setMediaPlayer(mp);

    // TESTING PURPOSES
    controllerWidget->setStrategy(new AudioControllerStrategy()); // TEST STATEMENT

    ui->controllerView->setViewport(controllerWidget);
    ui->mediaDisplayView->setViewport(vw);
    mp->setVideoOutput(vw);


    connect(mp, SIGNAL(positionChanged(qint64)), controllerWidget, SLOT(moveSlider(qint64)));
    connect(mp, SIGNAL(durationChanged(qint64)), controllerWidget, SLOT(adjustSliderMax(qint64)));


}

void MediaPlayerWidget::setMedia(QString media){
    mp->setMedia(QUrl::fromLocalFile(media));
    qDebug() << "MEDIA SET: " << media;
}

MediaPlayerWidget::~MediaPlayerWidget()
{
    delete ui;
    delete vw;
    delete mp;
    delete controllerWidget;
}
