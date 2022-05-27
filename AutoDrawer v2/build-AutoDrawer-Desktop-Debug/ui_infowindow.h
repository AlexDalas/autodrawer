/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QLabel *Logo_4;
    QLabel *Logo_5;
    QPushButton *pushButton_6;

    void setupUi(QMainWindow *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(489, 409);
        InfoWindow->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(InfoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(10, 10, 471, 391));
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        Logo_4 = new QLabel(Background);
        Logo_4->setObjectName(QString::fromUtf8("Logo_4"));
        Logo_4->setGeometry(QRect(0, 20, 471, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Logo_4->setFont(font);
        Logo_4->setTextFormat(Qt::RichText);
        Logo_4->setAlignment(Qt::AlignCenter);
        Logo_5 = new QLabel(Background);
        Logo_5->setObjectName(QString::fromUtf8("Logo_5"));
        Logo_5->setGeometry(QRect(0, 80, 471, 221));
        Logo_5->setFont(font);
        Logo_5->setTextFormat(Qt::RichText);
        Logo_5->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(Background);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 320, 201, 48));
        QFont font1;
        font1.setPointSize(14);
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        InfoWindow->setCentralWidget(centralwidget);

        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InfoWindow)
    {
        InfoWindow->setWindowTitle(QCoreApplication::translate("InfoWindow", "MainWindow", nullptr));
        Logo_4->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">AutoDrawer</span></p></body></html>", nullptr));
        Logo_5->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p align=\"center\">Program developed by Siydge and AlexCYP</p><p align=\"center\">This program is under the MIT Lisence.</p><p align=\"center\">GitHub Page &quot;autodrawer-roblox&quot; is by Siydge. <span style=\" font-size:6pt;\"><br/></span></p><p align=\"center\"><span style=\" font-size:8pt;\">If you have gotten this program from another repository,</span></p><p align=\"center\"><span style=\" font-size:8pt;\">we may not be able to provide support.</span></p></body></html>", nullptr));
        pushButton_6->setText(QCoreApplication::translate("InfoWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
