#include "mediaplayerwidget.h"
#include "ui_mediaplayerwidget.h"

MediaPlayerWidget::MediaPlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayerWidget)
{
    ui->setupUi(this);
}

MediaPlayerWidget::~MediaPlayerWidget()
{
    delete ui;
}
