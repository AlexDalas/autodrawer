/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background_2;
    QLabel *Header;
    QLabel *themes;
    QPushButton *CloseBox;
    QPushButton *GH;
    QPushButton *LR;
    QPushButton *Discord;
    QPushButton *OpenLogs;
    QPushButton *Console;
    QPushButton *ThemeEditor;
    QPushButton *OpenThemes;
    QPushButton *Reload;
    QLineEdit *intervalTextBox;
    QLineEdit *intervalTextBox_2;
    QLabel *X;
    QLabel *Y;
    QLabel *offsetPos;
    QLabel *opt;
    QFrame *frame;
    QCheckBox *LogBox;
    QCheckBox *OffsetBox;
    QCheckBox *PrinterBox;
    QComboBox *ThemeCombo;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(621, 391);
        SettingsWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsWindow->setWindowIcon(icon);
        SettingsWindow->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background_2 = new QFrame(centralwidget);
        Background_2->setObjectName(QString::fromUtf8("Background_2"));
        Background_2->setGeometry(QRect(0, 0, 621, 391));
        Background_2->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background_2->setFrameShape(QFrame::StyledPanel);
        Background_2->setFrameShadow(QFrame::Raised);
        Header = new QLabel(Background_2);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(0, 20, 621, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Header->setFont(font);
        Header->setTextFormat(Qt::RichText);
        Header->setAlignment(Qt::AlignCenter);
        themes = new QLabel(Background_2);
        themes->setObjectName(QString::fromUtf8("themes"));
        themes->setGeometry(QRect(410, 85, 181, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        themes->setFont(font1);
        themes->setTextFormat(Qt::RichText);
        themes->setAlignment(Qt::AlignCenter);
        CloseBox = new QPushButton(Background_2);
        CloseBox->setObjectName(QString::fromUtf8("CloseBox"));
        CloseBox->setGeometry(QRect(210, 320, 201, 48));
        QFont font2;
        font2.setPointSize(18);
        CloseBox->setFont(font2);
        CloseBox->setCursor(QCursor(Qt::PointingHandCursor));
        CloseBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        GH = new QPushButton(Background_2);
        GH->setObjectName(QString::fromUtf8("GH"));
        GH->setGeometry(QRect(406, 258, 181, 41));
        QFont font3;
        font3.setPointSize(14);
        GH->setFont(font3);
        GH->setCursor(QCursor(Qt::PointingHandCursor));
        GH->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 20px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        LR = new QPushButton(Background_2);
        LR->setObjectName(QString::fromUtf8("LR"));
        LR->setGeometry(QRect(220, 258, 181, 41));
        LR->setFont(font3);
        LR->setCursor(QCursor(Qt::PointingHandCursor));
        LR->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Discord = new QPushButton(Background_2);
        Discord->setObjectName(QString::fromUtf8("Discord"));
        Discord->setGeometry(QRect(34, 258, 181, 41));
        Discord->setFont(font3);
        Discord->setCursor(QCursor(Qt::PointingHandCursor));
        Discord->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 20px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        OpenLogs = new QPushButton(Background_2);
        OpenLogs->setObjectName(QString::fromUtf8("OpenLogs"));
        OpenLogs->setGeometry(QRect(406, 212, 181, 41));
        OpenLogs->setFont(font3);
        OpenLogs->setCursor(QCursor(Qt::PointingHandCursor));
        OpenLogs->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 20px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Console = new QPushButton(Background_2);
        Console->setObjectName(QString::fromUtf8("Console"));
        Console->setGeometry(QRect(34, 212, 181, 41));
        Console->setFont(font3);
        Console->setCursor(QCursor(Qt::PointingHandCursor));
        Console->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 20px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        ThemeEditor = new QPushButton(Background_2);
        ThemeEditor->setObjectName(QString::fromUtf8("ThemeEditor"));
        ThemeEditor->setGeometry(QRect(220, 212, 181, 41));
        ThemeEditor->setFont(font3);
        ThemeEditor->setCursor(QCursor(Qt::PointingHandCursor));
        ThemeEditor->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        OpenThemes = new QPushButton(Background_2);
        OpenThemes->setObjectName(QString::fromUtf8("OpenThemes"));
        OpenThemes->setGeometry(QRect(406, 160, 141, 31));
        QFont font4;
        font4.setPointSize(12);
        OpenThemes->setFont(font4);
        OpenThemes->setCursor(QCursor(Qt::PointingHandCursor));
        OpenThemes->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Reload = new QPushButton(Background_2);
        Reload->setObjectName(QString::fromUtf8("Reload"));
        Reload->setGeometry(QRect(550, 160, 31, 31));
        Reload->setFont(font4);
        Reload->setCursor(QCursor(Qt::PointingHandCursor));
        Reload->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Reload->setIconSize(QSize(20, 20));
        intervalTextBox = new QLineEdit(Background_2);
        intervalTextBox->setObjectName(QString::fromUtf8("intervalTextBox"));
        intervalTextBox->setEnabled(false);
        intervalTextBox->setGeometry(QRect(38, 142, 89, 41));
        intervalTextBox->setFont(font4);
        intervalTextBox->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        intervalTextBox->setAlignment(Qt::AlignCenter);
        intervalTextBox_2 = new QLineEdit(Background_2);
        intervalTextBox_2->setObjectName(QString::fromUtf8("intervalTextBox_2"));
        intervalTextBox_2->setEnabled(false);
        intervalTextBox_2->setGeometry(QRect(130, 142, 89, 41));
        intervalTextBox_2->setFont(font4);
        intervalTextBox_2->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        intervalTextBox_2->setAlignment(Qt::AlignCenter);
        X = new QLabel(Background_2);
        X->setObjectName(QString::fromUtf8("X"));
        X->setGeometry(QRect(51, 120, 61, 21));
        X->setFont(font);
        X->setTextFormat(Qt::RichText);
        X->setAlignment(Qt::AlignCenter);
        Y = new QLabel(Background_2);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setGeometry(QRect(128, 120, 91, 21));
        Y->setFont(font);
        Y->setTextFormat(Qt::RichText);
        Y->setAlignment(Qt::AlignCenter);
        offsetPos = new QLabel(Background_2);
        offsetPos->setObjectName(QString::fromUtf8("offsetPos"));
        offsetPos->setGeometry(QRect(40, 85, 181, 21));
        offsetPos->setFont(font1);
        offsetPos->setTextFormat(Qt::RichText);
        offsetPos->setAlignment(Qt::AlignCenter);
        opt = new QLabel(Background_2);
        opt->setObjectName(QString::fromUtf8("opt"));
        opt->setGeometry(QRect(220, 85, 181, 21));
        opt->setFont(font1);
        opt->setTextFormat(Qt::RichText);
        opt->setAlignment(Qt::AlignCenter);
        frame = new QFrame(Background_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(239, 114, 151, 75));
        frame->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 25px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        LogBox = new QCheckBox(frame);
        LogBox->setObjectName(QString::fromUtf8("LogBox"));
        LogBox->setGeometry(QRect(15, 27, 181, 23));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogBox->sizePolicy().hasHeightForWidth());
        LogBox->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setBold(true);
        LogBox->setFont(font5);
        LogBox->setCursor(QCursor(Qt::PointingHandCursor));
        LogBox->setLayoutDirection(Qt::LeftToRight);
        LogBox->setAutoFillBackground(false);
        LogBox->setStyleSheet(QString::fromUtf8("background:transparent"));
        OffsetBox = new QCheckBox(frame);
        OffsetBox->setObjectName(QString::fromUtf8("OffsetBox"));
        OffsetBox->setGeometry(QRect(15, 5, 181, 23));
        OffsetBox->setFont(font5);
        OffsetBox->setCursor(QCursor(Qt::PointingHandCursor));
        OffsetBox->setLayoutDirection(Qt::LeftToRight);
        OffsetBox->setAutoFillBackground(false);
        OffsetBox->setStyleSheet(QString::fromUtf8("background:transparent"));
        PrinterBox = new QCheckBox(frame);
        PrinterBox->setObjectName(QString::fromUtf8("PrinterBox"));
        PrinterBox->setGeometry(QRect(15, 49, 181, 23));
        sizePolicy.setHeightForWidth(PrinterBox->sizePolicy().hasHeightForWidth());
        PrinterBox->setSizePolicy(sizePolicy);
        PrinterBox->setFont(font5);
        PrinterBox->setCursor(QCursor(Qt::PointingHandCursor));
        PrinterBox->setLayoutDirection(Qt::LeftToRight);
        PrinterBox->setAutoFillBackground(false);
        PrinterBox->setStyleSheet(QString::fromUtf8("background:transparent"));
        ThemeCombo = new QComboBox(Background_2);
        ThemeCombo->setObjectName(QString::fromUtf8("ThemeCombo"));
        ThemeCombo->setGeometry(QRect(410, 120, 171, 25));
        SettingsWindow->setCentralWidget(centralwidget);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "MainWindow", nullptr));
        Header->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Settings</span></p></body></html>", nullptr));
        themes->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Themes</span></p></body></html>", nullptr));
        CloseBox->setText(QCoreApplication::translate("SettingsWindow", "Close", nullptr));
        GH->setText(QCoreApplication::translate("SettingsWindow", "GitHub", nullptr));
        LR->setText(QCoreApplication::translate("SettingsWindow", "Latest Release", nullptr));
        Discord->setText(QCoreApplication::translate("SettingsWindow", "Discord", nullptr));
        OpenLogs->setText(QCoreApplication::translate("SettingsWindow", "Open Logs", nullptr));
        Console->setText(QCoreApplication::translate("SettingsWindow", "Open Console", nullptr));
        ThemeEditor->setText(QCoreApplication::translate("SettingsWindow", "Theme Editor", nullptr));
        OpenThemes->setText(QCoreApplication::translate("SettingsWindow", "Open Themes", nullptr));
        Reload->setText(QString());
        intervalTextBox->setText(QCoreApplication::translate("SettingsWindow", "0", nullptr));
        intervalTextBox_2->setText(QCoreApplication::translate("SettingsWindow", "0", nullptr));
        X->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">X</span></p></body></html>", nullptr));
        Y->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">Y</span></p></body></html>", nullptr));
        offsetPos->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Offset Position</span></p></body></html>", nullptr));
        opt->setText(QCoreApplication::translate("SettingsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Options</span></p></body></html>", nullptr));
        LogBox->setText(QCoreApplication::translate("SettingsWindow", "Turn on logs", nullptr));
        OffsetBox->setText(QCoreApplication::translate("SettingsWindow", "Enable Offset", nullptr));
        PrinterBox->setText(QCoreApplication::translate("SettingsWindow", "Printer mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
