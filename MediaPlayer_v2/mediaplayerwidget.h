#ifndef MEDIAPLAYERWIDGET_H
#define MEDIAPLAYERWIDGET_H

#include <QWidget>

namespace Ui {
class MediaPlayerWidget;
}

class MediaPlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayerWidget(QWidget *parent = nullptr);
    ~MediaPlayerWidget();

private:
    Ui::MediaPlayerWidget *ui;
};

#endif // MEDIAPLAYERWIDGET_H
