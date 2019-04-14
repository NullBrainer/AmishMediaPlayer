#include "playlist.h"
#include "ui_playlist.h"
#include <QDebug>

Playlist::Playlist(QWidget *parent) :
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
        //audio = new AudioWindowWidget(parent, mediaPlayer);
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
    currentPlaylistName = QInputDialog::getText(this, "Playlist Name", "Enter playlist name", QLineEdit::Normal, "", &valid) + ".m3u";
    qDebug() << "Playlist name:" << currentPlaylistName << endl;
    qDebug() << QDir().absolutePath();
    QString file = QFileDialog::getOpenFileName(this, "Open Video/Audio File", "", "Video/Audio File (*.mp3 *.mp4)");
    mediaPlaylist->addMedia(QUrl::fromLocalFile(file));
    qDebug() << mediaPlaylist->save(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName), "m3u");
    ui->playlistListWidget->addItem(currentPlaylistName);
    mediaPlaylist->save(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName), "m3u");
    mediaPlaylist->next();
    displayPlaylistContent();
    qDebug() << "CURRENT INDEX RIGHT AFTER CREATING: " << mediaPlaylist->currentIndex();

}

void Playlist::on_loadPlaylistButton_pressed()
{
    delete mediaPlaylist;
    mediaPlaylist = new QMediaPlaylist();
    // reading in name after item is selected
    //QString playlistName = "";
    if(ui->playlistListWidget->currentItem() == nullptr){
        qDebug() << "EMPTY!" << endl;
    }
    else{
        qDebug() << ui->playlistListWidget->currentItem()->text() << endl;
        currentPlaylistName = ui->playlistListWidget->currentItem()->text();
    }
    QUrl path = QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName);
    qDebug() << path;
    // load in playlist
    mediaPlaylist->load(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName), "m3u");


    // then display all the content within the playlist
    qDebug() << mediaPlaylist->errorString();
    qDebug() << mediaPlaylist->currentIndex();

    mediaPlaylist->next(); // Playlist starts at -1, so have to increment by one
    displayPlaylistContent();

    emit playlistLoaded();

}

bool Playlist::empty(){
    return !(mediaPlaylist->mediaCount() > 0);
}

void Playlist::on_addContentButton_pressed()
{
    qDebug() << "GOT HERE TO ADD CONTENT" << mediaPlaylist->mediaCount();

    if(!empty()){

        QString file = QFileDialog::getOpenFileName(this, "Open Video/Audio File", "", "Video/Audio File (*.mp3 *.mp4)");
        mediaPlaylist->addMedia(QUrl::fromLocalFile(file));
        QStringList splitFile = file.split("/");
        file = splitFile[splitFile.length() - 1];
        ui->contentListWidget->addItem(file);
        mediaPlaylist->save(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName), "m3u");
    }
}

int Playlist::currentIndex(){
    return mediaPlaylist->currentIndex();
}

void Playlist::on_deleteContentButton_pressed()
{
    if(ui->contentListWidget->currentItem() == nullptr){
        qDebug() << "NOTHING SELECTED FOR DELETION" << endl;
    }
    else{
        qDebug() << "BEFORE DELETION" << mediaPlaylist->mediaCount();
        int index = ui->contentListWidget->currentRow();
        mediaPlaylist->removeMedia(index);
        ui->contentListWidget->takeItem(index);
        mediaPlaylist->save(QUrl::fromLocalFile(QDir().absolutePath() + "/Playlists/" + currentPlaylistName), "m3u");
        qDebug() << "AFTER DELETION" << mediaPlaylist->mediaCount();
    }
}

void Playlist::on_deletePlaylistButton_pressed()
{
    if(ui->playlistListWidget->currentItem() != nullptr){
        QDir().remove("Playlists/" + ui->playlistListWidget->currentItem()->text());
        ui->playlistListWidget->takeItem(ui->playlistListWidget->currentRow());
    }
}
