/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
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
    QLabel *Header;
    QLabel *Text;
    QPushButton *Button;

    void setupUi(QMainWindow *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(471, 391);
        InfoWindow->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(InfoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 471, 391));
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        Header = new QLabel(Background);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(0, 20, 471, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Header->setFont(font);
        Header->setTextFormat(Qt::RichText);
        Header->setAlignment(Qt::AlignCenter);
        Text = new QLabel(Background);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(0, 80, 471, 221));
        Text->setFont(font);
        Text->setStyleSheet(QString::fromUtf8("color: white;"));
        Text->setTextFormat(Qt::RichText);
        Text->setAlignment(Qt::AlignCenter);
        Button = new QPushButton(Background);
        Button->setObjectName(QString::fromUtf8("Button"));
        Button->setGeometry(QRect(130, 320, 201, 48));
        QFont font1;
        font1.setPointSize(14);
        Button->setFont(font1);
        Button->setCursor(QCursor(Qt::PointingHandCursor));
        Button->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 10px;"));
        InfoWindow->setCentralWidget(centralwidget);

        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InfoWindow)
    {
        InfoWindow->setWindowTitle(QCoreApplication::translate("InfoWindow", "MainWindow", nullptr));
        Header->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">AutoDrawer</span></p></body></html>", nullptr));
        Text->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p align=\"center\">Program developed by Siydge and AlexCYP</p><p align=\"center\">This program is under the MIT Lisence.</p><p align=\"center\">GitHub Page &quot;autodrawer-roblox&quot; is by AlexCYP. <span style=\" font-size:6pt;\"><br/></span></p><p align=\"center\"><span style=\" font-size:8pt;\">If you have gotten this program from another repository,</span></p><p align=\"center\"><span style=\" font-size:8pt;\">we may not be able to provide support.</span></p></body></html>", nullptr));
        Button->setText(QCoreApplication::translate("InfoWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
