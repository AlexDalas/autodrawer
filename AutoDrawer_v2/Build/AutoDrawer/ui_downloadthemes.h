/********************************************************************************
** Form generated from reading UI file 'downloadthemes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADTHEMES_H
#define UI_DOWNLOADTHEMES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_downloadthemes
{
public:
    QWidget *centralwidget;
    QFrame *Background_2;
    QPushButton *Black;
    QPushButton *Violet;
    QPushButton *OrangeYellow;
    QPushButton *Green;
    QPushButton *Red;
    QPushButton *Blue;
    QPushButton *Exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *Text;

    void setupUi(QMainWindow *downloadthemes)
    {
        if (downloadthemes->objectName().isEmpty())
            downloadthemes->setObjectName(QString::fromUtf8("downloadthemes"));
        downloadthemes->resize(731, 511);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        downloadthemes->setWindowIcon(icon);
        centralwidget = new QWidget(downloadthemes);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background_2 = new QFrame(centralwidget);
        Background_2->setObjectName(QString::fromUtf8("Background_2"));
        Background_2->setGeometry(QRect(0, 0, 731, 511));
        Background_2->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background_2->setFrameShape(QFrame::StyledPanel);
        Background_2->setFrameShadow(QFrame::Raised);
        Black = new QPushButton(Background_2);
        Black->setObjectName(QString::fromUtf8("Black"));
        Black->setGeometry(QRect(30, 190, 211, 41));
        QFont font;
        font.setPointSize(14);
        Black->setFont(font);
        Black->setCursor(QCursor(Qt::PointingHandCursor));
        Black->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Violet = new QPushButton(Background_2);
        Violet->setObjectName(QString::fromUtf8("Violet"));
        Violet->setGeometry(QRect(260, 190, 211, 41));
        Violet->setFont(font);
        Violet->setCursor(QCursor(Qt::PointingHandCursor));
        Violet->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        OrangeYellow = new QPushButton(Background_2);
        OrangeYellow->setObjectName(QString::fromUtf8("OrangeYellow"));
        OrangeYellow->setGeometry(QRect(490, 190, 211, 41));
        OrangeYellow->setFont(font);
        OrangeYellow->setCursor(QCursor(Qt::PointingHandCursor));
        OrangeYellow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Green = new QPushButton(Background_2);
        Green->setObjectName(QString::fromUtf8("Green"));
        Green->setGeometry(QRect(490, 410, 211, 41));
        Green->setFont(font);
        Green->setCursor(QCursor(Qt::PointingHandCursor));
        Green->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Red = new QPushButton(Background_2);
        Red->setObjectName(QString::fromUtf8("Red"));
        Red->setGeometry(QRect(30, 410, 211, 41));
        Red->setFont(font);
        Red->setCursor(QCursor(Qt::PointingHandCursor));
        Red->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Blue = new QPushButton(Background_2);
        Blue->setObjectName(QString::fromUtf8("Blue"));
        Blue->setGeometry(QRect(260, 410, 211, 41));
        Blue->setFont(font);
        Blue->setCursor(QCursor(Qt::PointingHandCursor));
        Blue->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Exit = new QPushButton(Background_2);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(300, 460, 131, 41));
        Exit->setFont(font);
        Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        label = new QLabel(Background_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(25, 240, 222, 157));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/red.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(Background_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(255, 240, 222, 157));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/blue.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(Background_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(485, 240, 222, 157));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/images/green.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(Background_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(255, 20, 222, 157));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/violet")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(Background_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(485, 20, 222, 157));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/images/yellow.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(Background_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(25, 20, 222, 157));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/images/black.png")));
        label_6->setScaledContents(true);
        Text = new QLabel(Background_2);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(450, 465, 281, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        Text->setFont(font1);
        Text->setStyleSheet(QString::fromUtf8("background: transparent;"));
        downloadthemes->setCentralWidget(centralwidget);

        retranslateUi(downloadthemes);

        QMetaObject::connectSlotsByName(downloadthemes);
    } // setupUi

    void retranslateUi(QMainWindow *downloadthemes)
    {
        downloadthemes->setWindowTitle(QCoreApplication::translate("downloadthemes", "MainWindow", nullptr));
        Black->setText(QCoreApplication::translate("downloadthemes", "Download Black", nullptr));
        Violet->setText(QCoreApplication::translate("downloadthemes", "Download Violet", nullptr));
        OrangeYellow->setText(QCoreApplication::translate("downloadthemes", "Download Banana", nullptr));
        Green->setText(QCoreApplication::translate("downloadthemes", "Download Green", nullptr));
        Red->setText(QCoreApplication::translate("downloadthemes", "Download Red", nullptr));
        Blue->setText(QCoreApplication::translate("downloadthemes", "Download Blue", nullptr));
        Exit->setText(QCoreApplication::translate("downloadthemes", "Exit", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        Text->setText(QCoreApplication::translate("downloadthemes", "Select your theme in settings!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadthemes: public Ui_downloadthemes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADTHEMES_H
