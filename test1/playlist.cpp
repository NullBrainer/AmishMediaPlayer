#include "playlist.h"
#include "ui_playlist.h"
#include <QDebug>

Playlist::Playlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playlist)
{

    ui->setupUi(this);

    // Listwidget testing
    /*
    for(int i = 0; i < 80; i++){
        ui->listWidget->addItem(QString::number(i) + "lasdjfilsadjflasjflksajflksadjflsajflsjaflsjdf");

    }
    */
    if(QDir("Playlists").exists()){
        qDebug() << "FOLDER EXISTS\n";
    }
    else{
        QDir().mkdir("Playlists");
    }
}

Playlist::~Playlist()
{
    delete ui;
}
