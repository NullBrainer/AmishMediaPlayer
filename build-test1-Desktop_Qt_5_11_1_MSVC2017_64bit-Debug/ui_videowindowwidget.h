/********************************************************************************
** Form generated from reading UI file 'videowindowwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOWWIDGET_H
#define UI_VIDEOWINDOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindowWidget
{
public:
    QGraphicsView *DisplayView;
    QGraphicsView *ButtonController;

    void setupUi(QWidget *VideoWindowWidget)
    {
        if (VideoWindowWidget->objectName().isEmpty())
            VideoWindowWidget->setObjectName(QStringLiteral("VideoWindowWidget"));
        VideoWindowWidget->resize(836, 547);
        DisplayView = new QGraphicsView(VideoWindowWidget);
        DisplayView->setObjectName(QStringLiteral("DisplayView"));
        DisplayView->setGeometry(QRect(10, 10, 631, 451));
        ButtonController = new QGraphicsView(VideoWindowWidget);
        ButtonController->setObjectName(QStringLiteral("ButtonController"));
        ButtonController->setGeometry(QRect(10, 480, 631, 51));

        retranslateUi(VideoWindowWidget);

        QMetaObject::connectSlotsByName(VideoWindowWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWindowWidget)
    {
        VideoWindowWidget->setWindowTitle(QApplication::translate("VideoWindowWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoWindowWidget: public Ui_VideoWindowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOWWIDGET_H
