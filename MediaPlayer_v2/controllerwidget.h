#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include <QWidget>

namespace Ui {
class ControllerWidget;
}

class ControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerWidget(QWidget *parent = nullptr);
    ~ControllerWidget();

private:
    Ui::ControllerWidget *ui;
};

#endif // CONTROLLERWIDGET_H
