#include "videowindowwidget.h"
#include "ui_videowindowwidget.h"

VideoWindowWidget::VideoWindowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWindowWidget)
{
    ui->setupUi(this);
}

VideoWindowWidget::~VideoWindowWidget()
{
    delete ui;
}
