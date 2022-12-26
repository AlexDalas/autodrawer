/********************************************************************************
** Form generated from reading UI file 'custompattern.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPATTERN_H
#define UI_CUSTOMPATTERN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_custompattern
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QLabel *Header;
    QPushButton *Close;
    QLabel *Footer;
    QLabel *Footer2;
    QLineEdit *TextInt;
    QPushButton *Submit;
    QFrame *ImageBackground;
    QLabel *Image;

    void setupUi(QMainWindow *custompattern)
    {
        if (custompattern->objectName().isEmpty())
            custompattern->setObjectName(QString::fromUtf8("custompattern"));
        custompattern->resize(470, 471);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        custompattern->setWindowIcon(icon);
        centralwidget = new QWidget(custompattern);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 471, 471));
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        Header = new QLabel(Background);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(0, 10, 471, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Header->setFont(font);
        Header->setTextFormat(Qt::RichText);
        Header->setAlignment(Qt::AlignCenter);
        Close = new QPushButton(Background);
        Close->setObjectName(QString::fromUtf8("Close"));
        Close->setGeometry(QRect(130, 400, 201, 48));
        QFont font1;
        font1.setPointSize(14);
        Close->setFont(font1);
        Close->setCursor(QCursor(Qt::PointingHandCursor));
        Close->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 10px;"));
        Footer = new QLabel(Background);
        Footer->setObjectName(QString::fromUtf8("Footer"));
        Footer->setGeometry(QRect(0, 60, 471, 21));
        Footer->setFont(font);
        Footer->setStyleSheet(QString::fromUtf8("background:transparent"));
        Footer->setTextFormat(Qt::RichText);
        Footer->setAlignment(Qt::AlignCenter);
        Footer2 = new QLabel(Background);
        Footer2->setObjectName(QString::fromUtf8("Footer2"));
        Footer2->setGeometry(QRect(0, 360, 471, 41));
        Footer2->setFont(font);
        Footer2->setStyleSheet(QString::fromUtf8("background:transparent"));
        Footer2->setTextFormat(Qt::RichText);
        Footer2->setAlignment(Qt::AlignCenter);
        TextInt = new QLineEdit(Background);
        TextInt->setObjectName(QString::fromUtf8("TextInt"));
        TextInt->setGeometry(QRect(70, 330, 218, 31));
        QFont font2;
        font2.setPointSize(12);
        TextInt->setFont(font2);
        TextInt->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        TextInt->setAlignment(Qt::AlignCenter);
        Submit = new QPushButton(Background);
        Submit->setObjectName(QString::fromUtf8("Submit"));
        Submit->setGeometry(QRect(290, 330, 111, 31));
        Submit->setFont(font1);
        Submit->setCursor(QCursor(Qt::PointingHandCursor));
        Submit->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        ImageBackground = new QFrame(Background);
        ImageBackground->setObjectName(QString::fromUtf8("ImageBackground"));
        ImageBackground->setGeometry(QRect(125, 90, 221, 231));
        ImageBackground->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 25px;"));
        ImageBackground->setFrameShape(QFrame::StyledPanel);
        ImageBackground->setFrameShadow(QFrame::Raised);
        Image = new QLabel(ImageBackground);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(10, 5, 201, 221));
        Image->setPixmap(QPixmap(QString::fromUtf8(":/images/images/pattern.png")));
        Image->setScaledContents(true);
        custompattern->setCentralWidget(centralwidget);

        retranslateUi(custompattern);

        QMetaObject::connectSlotsByName(custompattern);
    } // setupUi

    void retranslateUi(QMainWindow *custompattern)
    {
        custompattern->setWindowTitle(QCoreApplication::translate("custompattern", "MainWindow", nullptr));
        Header->setText(QCoreApplication::translate("custompattern", "<html><head/><body><p><span style=\" font-size:20pt;\">Enter a Custom Path Sequence</span></p></body></html>", nullptr));
        Close->setText(QCoreApplication::translate("custompattern", "Close", nullptr));
        Footer->setText(QCoreApplication::translate("custompattern", "<html><head/><body><p><span style=\" font-size:10pt;\">It has to be an 8 digit integer, with all 1-8 numbers.</span></p></body></html>", nullptr));
        Footer2->setText(QCoreApplication::translate("custompattern", "<html><head/><body><p><span style=\" font-size:10pt;\">If you don't know what you are doing, just close this</span></p></body></html>", nullptr));
        TextInt->setText(QCoreApplication::translate("custompattern", "12345678", nullptr));
        Submit->setText(QCoreApplication::translate("custompattern", "Submit", nullptr));
        Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class custompattern: public Ui_custompattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPATTERN_H
