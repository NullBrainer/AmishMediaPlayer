#include "playlistwidget.h"
#include "ui_playlistwidget.h"

PlaylistWidget::PlaylistWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistWidget)
{
    ui->setupUi(this);
    mediaPlaylist = new QMediaPlaylist();

    // Check if playlist folder exists
    if(QDir(PLAYLIST_PATHNAME).exists()){
        qDebug() << "FOLDER EXISTS";
    }
    else{
        QDir().mkdir(PLAYLIST_PATHNAME);
    }

    displayPlaylists();
}

PlaylistWidget::~PlaylistWidget()
{
    delete ui;
}

void PlaylistWidget::next(){
    mediaPlaylist->next();
}

void PlaylistWidget::previous(){
    mediaPlaylist->previous();
}

void PlaylistWidget::displayPlaylists(){
    QStringList files = QDir(PLAYLIST_PATHNAME).entryList(QDir::Files);
    for(QString s : files){
        ui->playlistListWidget->addItem(s);
    }
}

void PlaylistWidget::displayPlaylistContent(){
    ui->contentListWidget->clear();
    qDebug() << mediaPlaylist->mediaCount() << " media items in playlist";
    while(mediaPlaylist->currentIndex() != -1){
        ui->contentListWidget->addItem((QString)this->mediaPlaylist->currentMedia()
                                       .canonicalUrl().fileName());
    }

    // Reset index back to beginning of playlist if not empty
    if(ui->contentListWidget->count() != 0){
        qDebug() << "RESETTING PLAYLIST INDEX";
        mediaPlaylist->setCurrentIndex(0);
    }
}

void PlaylistWidget::updateTitle(QString title){
    ui->contentLabel->setText(title);
}

void PlaylistWidget::addPlaylist(){
    mediaPlaylist->clear();
    bool valid;
    currentPlaylistName = QInputDialog::getText(this, "Playlist Name", "Enter playlist name", QLineEdit::Normal, "", &valid) + ".m3u";
    qDebug() << "CREATING PLAYLIST: " << currentPlaylistName << endl;
    QString file = QFileDialog::getOpenFileName(this, "Open Video/Audio File", "", "Video/Audio File (*.mp3 *.mp4)");
    mediaPlaylist->addMedia(QUrl::fromLocalFile(file));
    mediaPlaylist->save(QUrl::fromLocalFile(BASE_PATH + currentPlaylistName), "m3u");
    ui->playlistListWidget->addItem(currentPlaylistName);
    mediaPlaylist->next();
}

void PlaylistWidget::on_addPlaylistButton_pressed()
{
    addPlaylist();
}
