#include "playlist.h"
#include "ui_playlist.h"
#include <QDebug>

Playlist::Playlist(QWidget *parent, QMediaPlayer * mediaPlayer, QGraphicsView * displayPort) :
    QWidget(parent),
    ui(new Ui::Playlist)
{

    ui->setupUi(this);
    this->parent = parent;
    this->mediaPlayer = mediaPlayer;
    this->displayPort = displayPort;
    audio = nullptr; // test
    mediaPlaylist = new QMediaPlaylist();

    // Display playlists



    // Listwidget testing
    /*
    for(int i = 0; i < 80; i++){
        ui->listWidget->addItem(QString::number(i) + "lasdjfilsadjflasjflksajflksadjflsajflsjaflsjdf");

    }
    */

    //Check if playlist folder exists
    if(QDir("Playlists").exists()){
        qDebug() << "FOLDER EXISTS\n";
    }
    else{
        QDir().mkdir("Playlists");
    }

    //Display all playlists in the listview
    QStringList files = QDir("Playlists").entryList(QDir::Files);
    for(QString s : files){
        ui->playlistListWidget->addItem(s);
    }
}

Playlist::~Playlist()
{
    delete ui;
}

QString Playlist::currentFileName(){
    qDebug() << this->mediaPlaylist->currentIndex();
    QString fileName = (QString)(this->mediaPlaylist->currentMedia().canonicalUrl().toString());
    qDebug() << "GOT HERE 4";
    qDebug() << fileName;
    return fileName;
}

void Playlist::next(){
    mediaPlaylist->next();
}

void Playlist::previous(){
    mediaPlaylist->previous();
}

void Playlist::displayPlaylistContent(){
    ui->contentListWidget->clear();
    qDebug() << mediaPlaylist->mediaCount();
    qDebug() << (QString)this->mediaPlaylist->currentMedia().canonicalUrl().fileName();

    while(mediaPlaylist->currentIndex() != -1){
        ui->contentListWidget->addItem((QString)this->mediaPlaylist->currentMedia().canonicalUrl().fileName());
        mediaPlaylist->next();
    }

    // Reset index back to beginning of playlist if not empty
    if(ui->contentListWidget->count() != 0){
        qDebug() << "GOT HERE 1";
        mediaPlaylist->setCurrentIndex(0);
        //Test to see if viewport works
        audio = new AudioWindowWidget(parent, mediaPlayer);
        qDebug() << "GOT HERE 2";
        //displayPort->setViewport(audio);
        qDebug() << "GOT HERE 3";
        //displayPort->show();
        //qDebug() << "GOT HERE 4";
    }
}

void Playlist::on_addPlaylistButton_pressed()
{
    bool valid;
    QString playlistName = QInputDialog::getText(this, "Playlist Name", "Enter playlist name", QLineEdit::Normal, "", &valid);
    qDebug() << "Playlist name:" << playlistName << endl;
    qDebug() << QDir().absolutePath();
    QString vidFile = QFileDialog::getOpenFileName(this, "Open Video File", "", "Video File (*.mp3)");
    mediaPlaylist->addMedia(QUrl::fromLocalFile(vidFile));
    qDebug() << mediaPlaylist->save(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + playlistName + ".m3u"), "m3u");
    ui->playlistListWidget->addItem(playlistName);

}

void Playlist::on_loadPlaylistButton_pressed()
{
    delete mediaPlaylist;
    mediaPlaylist = new QMediaPlaylist();
    // reading in name after item is selected
    QString playlistName = "";
    if(ui->playlistListWidget->currentItem() == nullptr){
        qDebug() << "EMPTY!" << endl;
    }
    else{
        qDebug() << ui->playlistListWidget->currentItem()->text() << endl;
        playlistName = ui->playlistListWidget->currentItem()->text();
    }
    QUrl path = QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + playlistName);
    qDebug() << path;
    // load in playlist
    mediaPlaylist->load(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + playlistName), "m3u");


    // then display all the content within the playlist
    qDebug() << mediaPlaylist->errorString();
    qDebug() << mediaPlaylist->currentIndex();

    mediaPlaylist->next(); // Playlist starts at -1, so have to increment by one
    displayPlaylistContent();

    emit playlistLoaded();

}
