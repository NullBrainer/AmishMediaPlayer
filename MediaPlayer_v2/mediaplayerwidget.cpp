#include "mediaplayerwidget.h"
#include "ui_mediaplayerwidget.h"

MediaPlayerWidget::MediaPlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayerWidget)
{
    ui->setupUi(this);

    vw = new QVideoWidget(this);
    mp = new QMediaPlayer(this);
    playlistWidget = new PlaylistWidget(this);
    controllerWidget = new ControllerWidget(this);

    controllerWidget->setMediaPlayer(mp);
    buildChain();
    // TESTING PURPOSES
    //controllerWidget->setStrategy(new VideoControllerStrategy()); // TEST STATEMENT

    ui->controllerView->setViewport(controllerWidget);
    ui->mediaDisplayView->setViewport(vw);
    ui->playlistView->setViewport(playlistWidget);
    mp->setVideoOutput(vw);


    connect(mp, SIGNAL(positionChanged(qint64)), controllerWidget, SLOT(moveSlider(qint64)));
    connect(mp, SIGNAL(durationChanged(qint64)), controllerWidget, SLOT(adjustSliderMax(qint64)));

    connect(controllerWidget, SIGNAL(nextPressed()), playlistWidget, SLOT(nextPressed()));

    connect(controllerWidget, SIGNAL(previousPressed()), playlistWidget, SLOT(previousPressed()));
    connect(playlistWidget, SIGNAL(nextContentLoaded()), this, SLOT(onNext()));

    // connect(playlistWidget, SIGNAL(nextContentLoaded()), controllerWidget, SLOT(playNewSong()));

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

void MediaPlayerWidget::on_pushButton_pressed()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open media file", "", "Audio/Video (*.mp4 *mp3)");
    mp->setMedia(QUrl::fromLocalFile(filename));
    chooseStrategy(filename);
}

void MediaPlayerWidget::buildChain(){
    handler = new AudioHandler();
    handler->addHandler(new VideoHandler());
}

void MediaPlayerWidget::chooseStrategy(QString filename){
    controllerWidget->setStrategy(handler->determineController(filename));
}

void MediaPlayerWidget::onNext(){
    QString filepath = playlistWidget->getCurrentSongPath();
    controllerWidget->setStrategy(handler->determineController(filepath));
    qDebug() << "FINISHED DETERMINING CONTROLLER";
    setMedia(filepath);
    qDebug() << "JUST SET MEDIA";
    controllerWidget->playNewMedia();
}

