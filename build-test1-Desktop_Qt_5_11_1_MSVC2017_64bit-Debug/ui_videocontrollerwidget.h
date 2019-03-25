/********************************************************************************
** Form generated from reading UI file 'videocontrollerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOCONTROLLERWIDGET_H
#define UI_VIDEOCONTROLLERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoControllerWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *VideoControllerWidget)
    {
        if (VideoControllerWidget->objectName().isEmpty())
            VideoControllerWidget->setObjectName(QStringLiteral("VideoControllerWidget"));
        VideoControllerWidget->resize(520, 60);
        pushButton = new QPushButton(VideoControllerWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 93, 28));
        pushButton_2 = new QPushButton(VideoControllerWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 20, 93, 28));
        pushButton_3 = new QPushButton(VideoControllerWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 20, 93, 28));
        pushButton_4 = new QPushButton(VideoControllerWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(400, 20, 93, 28));

        retranslateUi(VideoControllerWidget);

        QMetaObject::connectSlotsByName(VideoControllerWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoControllerWidget)
    {
        VideoControllerWidget->setWindowTitle(QApplication::translate("VideoControllerWidget", "Form", nullptr));
        pushButton->setText(QApplication::translate("VideoControllerWidget", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("VideoControllerWidget", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("VideoControllerWidget", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("VideoControllerWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoControllerWidget: public Ui_VideoControllerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOCONTROLLERWIDGET_H
