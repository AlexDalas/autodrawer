/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background_2;
    QLabel *Logo_6;
    QLabel *Logo_7;
    QPushButton *pushButton_7;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(640, 480);
        SettingsWindow->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background_2 = new QFrame(centralwidget);
        Background_2->setObjectName(QString::fromUtf8("Background_2"));
        Background_2->setGeometry(QRect(10, 10, 621, 461));
        Background_2->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background_2->setFrameShape(QFrame::StyledPanel);
        Background_2->setFrameShadow(QFrame::Raised);
        Logo_6 = new QLabel(Background_2);
        Logo_6->setObjectName(QString::fromUtf8("Logo_6"));
        Logo_6->setGeometry(QRect(0, 20, 621, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Logo_6->setFont(font);
        Logo_6->setTextFormat(Qt::RichText);
        Logo_6->setAlignment(Qt::AlignCenter);
        Logo_7 = new QLabel(Background_2);
        Logo_7->setObjectName(QString::fromUtf8("Logo_7"));
        Logo_7->setGeometry(QRect(-10, 80, 641, 311));
        Logo_7->setFont(font);
        Logo_7->setTextFormat(Qt::RichText);
        Logo_7->setAlignment(Qt::AlignCenter);
        pushButton_7 = new QPushButton(Background_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(210, 390, 201, 48));
        QFont font1;
        font1.setPointSize(14);
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        SettingsWindow->setCentralWidget(centralwidget);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "MainWindow", nullptr));
        Logo_6->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Settings</span></p></body></html>", nullptr));
        Logo_7->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\">Program developed by Siydge and AlexCYP</p><p align=\"center\">This program is under the MIT Lisence.</p><p align=\"center\">GitHub Page &quot;autodrawer-roblox&quot; is by Siydge. <span style=\" font-size:6pt;\"><br/></span></p><p align=\"center\"><span style=\" font-size:8pt;\">If you have gotten this program from another repository,</span></p><p align=\"center\"><span style=\" font-size:8pt;\">we may not be able to provide support.</span></p></body></html>", nullptr));
        pushButton_7->setText(QCoreApplication::translate("SettingsWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
