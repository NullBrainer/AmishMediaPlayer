#ifndef VIDEOWINDOWWIDGET_H
#define VIDEOWINDOWWIDGET_H

#include <QWidget>

namespace Ui {
class VideoWindowWidget;
}

class VideoWindowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWindowWidget(QWidget *parent = nullptr);
    ~VideoWindowWidget();

private:
    Ui::VideoWindowWidget *ui;
};

#endif // VIDEOWINDOWWIDGET_H
