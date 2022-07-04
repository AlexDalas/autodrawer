/********************************************************************************
** Form generated from reading UI file 'messagewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWINDOW_H
#define UI_MESSAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QLabel *Text;
    QPushButton *pushButton_6;
    QLabel *Header;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QMainWindow *MessageWindow)
    {
        if (MessageWindow->objectName().isEmpty())
            MessageWindow->setObjectName(QString::fromUtf8("MessageWindow"));
        MessageWindow->resize(471, 211);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MessageWindow->setWindowIcon(icon);
        MessageWindow->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(MessageWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 471, 211));
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        Text = new QLabel(Background);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(20, 50, 431, 101));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        Text->setFont(font);
        Text->setStyleSheet(QString::fromUtf8("background:transparent"));
        Text->setTextFormat(Qt::RichText);
        Text->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(Background);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(135, 150, 201, 48));
        QFont font1;
        font1.setPointSize(14);
        pushButton_6->setFont(font1);
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Header = new QLabel(Background);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(0, 6, 471, 71));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(true);
        Header->setFont(font2);
        Header->setAlignment(Qt::AlignCenter);
        pushButton_7 = new QPushButton(Background);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(true);
        pushButton_7->setGeometry(QRect(240, 150, 201, 48));
        pushButton_7->setFont(font1);
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_8 = new QPushButton(Background);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(true);
        pushButton_8->setGeometry(QRect(30, 150, 201, 48));
        pushButton_8->setFont(font1);
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_9 = new QPushButton(Background);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setEnabled(true);
        pushButton_9->setGeometry(QRect(430, 0, 41, 41));
        pushButton_9->setFont(font1);
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 20px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        MessageWindow->setCentralWidget(centralwidget);

        retranslateUi(MessageWindow);

        QMetaObject::connectSlotsByName(MessageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MessageWindow)
    {
        MessageWindow->setWindowTitle(QCoreApplication::translate("MessageWindow", "MainWindow", nullptr));
        Text->setText(QCoreApplication::translate("MessageWindow", "Example text", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MessageWindow", "Close", nullptr));
        Header->setText(QCoreApplication::translate("MessageWindow", "Info", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MessageWindow", "Open", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MessageWindow", "Minimize", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MessageWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageWindow: public Ui_MessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWINDOW_H
