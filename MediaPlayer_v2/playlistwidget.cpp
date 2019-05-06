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
        mediaPlaylist->next();
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
    QString playlistpath = BASE_PATH + currentPlaylistName;
    mediaPlaylist->save(QUrl::fromLocalFile(playlistpath), "m3u");
    ui->playlistListWidget->addItem(currentPlaylistName);
    loadPlaylist(playlistpath);
    mediaPlaylist->next();

    displayPlaylistContent();
    updateTitle(currentPlaylistName);

}

void PlaylistWidget::deletePlaylist(QString filepath){
    QDir().remove(filepath);
}

void PlaylistWidget::loadPlaylist(QString filepath){
    delete mediaPlaylist;
    mediaPlaylist = new QMediaPlaylist();
    mediaPlaylist->load(QUrl::fromLocalFile(filepath), "m3u");
}

void PlaylistWidget::addContent(QString filepath){
    mediaPlaylist->addMedia(QUrl::fromLocalFile(filepath));
}

void PlaylistWidget::deleteContent(int index){
    mediaPlaylist->removeMedia(index);
    mediaPlaylist->save(QUrl::fromLocalFile(BASE_PATH + currentPlaylistName), "m3u");
}

bool PlaylistWidget::empty(){
    return !(mediaPlaylist->mediaCount() > 0);
}

void PlaylistWidget::on_addPlaylistButton_pressed()
{
    addPlaylist();
}

void PlaylistWidget::on_deletePlaylistButton_pressed()
{
    if(ui->playlistListWidget->currentItem() != nullptr){
        deletePlaylist(BASE_PATH + ui->playlistListWidget->currentItem()->text());
        ui->playlistListWidget->takeItem(ui->playlistListWidget->currentRow());
    }
}

void PlaylistWidget::on_loadPlaylistButton_pressed()
{
    if(ui->playlistListWidget->currentItem() == nullptr){
        qDebug() << "EMPTY";
    }
    else{
        currentPlaylistName = ui->playlistListWidget->currentItem()->text();
    }
    QString path = BASE_PATH + currentPlaylistName;
    loadPlaylist(path);

    mediaPlaylist->next();
    displayPlaylistContent();
    updateTitle(currentPlaylistName);
}

void PlaylistWidget::on_addContentButton_pressed()
{
    if(!empty()){
        QString file = QFileDialog::getOpenFileName(this, "Open Video/Audio File", "", "Video/Audio File (*.mp3 *.mp4)");
        addContent(file);
        QStringList splitFile = file.split("/");
        file = splitFile[splitFile.length() - 1];
        ui->contentListWidget->addItem(file);
        mediaPlaylist->save(QUrl::fromLocalFile(BASE_PATH + currentPlaylistName), "m3u");
    }
}

void PlaylistWidget::on_deleteContentButton_pressed()
{
    if(ui->contentListWidget->currentItem() == nullptr){
        qDebug() << "NOTHING SELECTED FOR DELETION";
    }
    else{
        int index = ui->contentListWidget->currentRow();
        deleteContent(index);
        ui->contentListWidget->takeItem(index);
    }
}
