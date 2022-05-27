/********************************************************************************
** Form generated from reading UI file 'autodrawer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTODRAWER_H
#define UI_AUTODRAWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoDrawer
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QFrame *ImageOpt;
    QFrame *ScaleFrame;
    QSlider *ScaleSlider;
    QLabel *ScaleText;
    QLineEdit *scaleNumber;
    QLabel *HeightText;
    QLabel *WidthText;
    QLineEdit *heightBox;
    QLineEdit *widthBox;
    QPushButton *exitButton;
    QPushButton *Minimize;
    QLabel *Logo;
    QLabel *Logo_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *Logo_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLineEdit *intervalTextBox;
    QLineEdit *clickDelayTextBox;
    QLabel *Logo_4;
    QLabel *Logo_5;
    QLabel *Logo_6;
    QLabel *Logo_7;
    QListView *listView;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QListView *drawingList;
    QLineEdit *transThresh;
    QLineEdit *blackThresh;
    QLabel *ImageFrame;
    QPushButton *pushButton_12;

    void setupUi(QMainWindow *AutoDrawer)
    {
        if (AutoDrawer->objectName().isEmpty())
            AutoDrawer->setObjectName(QString::fromUtf8("AutoDrawer"));
        AutoDrawer->resize(909, 648);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../AutoDrawer v1/Assets/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AutoDrawer->setWindowIcon(icon);
        AutoDrawer->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(AutoDrawer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(10, 10, 891, 631));
        Background->setStyleSheet(QString::fromUtf8("background: rgb(44, 48, 46);\n"
"border-radius: 10px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        ImageOpt = new QFrame(Background);
        ImageOpt->setObjectName(QString::fromUtf8("ImageOpt"));
        ImageOpt->setGeometry(QRect(10, 510, 490, 111));
        ImageOpt->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 55, 53);\n"
"border-radius: 5px;"));
        ImageOpt->setFrameShape(QFrame::StyledPanel);
        ImageOpt->setFrameShadow(QFrame::Raised);
        ScaleFrame = new QFrame(ImageOpt);
        ScaleFrame->setObjectName(QString::fromUtf8("ScaleFrame"));
        ScaleFrame->setGeometry(QRect(9, 10, 471, 41));
        ScaleFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 55, 53);\n"
"border-radius: 5px;"));
        ScaleFrame->setFrameShape(QFrame::StyledPanel);
        ScaleFrame->setFrameShadow(QFrame::Raised);
        ScaleSlider = new QSlider(ScaleFrame);
        ScaleSlider->setObjectName(QString::fromUtf8("ScaleSlider"));
        ScaleSlider->setGeometry(QRect(70, 10, 335, 20));
        ScaleSlider->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        ScaleSlider->setMaximum(200);
        ScaleSlider->setValue(100);
        ScaleSlider->setOrientation(Qt::Horizontal);
        ScaleText = new QLabel(ScaleFrame);
        ScaleText->setObjectName(QString::fromUtf8("ScaleText"));
        ScaleText->setGeometry(QRect(10, -1, 40, 40));
        ScaleText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";"));
        scaleNumber = new QLineEdit(ScaleFrame);
        scaleNumber->setObjectName(QString::fromUtf8("scaleNumber"));
        scaleNumber->setGeometry(QRect(420, 8, 51, 25));
        scaleNumber->setStyleSheet(QString::fromUtf8("background: rgb(49, 49, 49);\n"
"border-radius: 5px;"));
        scaleNumber->setAlignment(Qt::AlignCenter);
        HeightText = new QLabel(ImageOpt);
        HeightText->setObjectName(QString::fromUtf8("HeightText"));
        HeightText->setGeometry(QRect(10, 45, 235, 31));
        HeightText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"background:transparent;"));
        HeightText->setAlignment(Qt::AlignCenter);
        WidthText = new QLabel(ImageOpt);
        WidthText->setObjectName(QString::fromUtf8("WidthText"));
        WidthText->setGeometry(QRect(246, 45, 231, 31));
        WidthText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"background:transparent;"));
        WidthText->setAlignment(Qt::AlignCenter);
        heightBox = new QLineEdit(ImageOpt);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setGeometry(QRect(10, 80, 234, 21));
        heightBox->setStyleSheet(QString::fromUtf8("background: rgb(44, 48, 46);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        heightBox->setAlignment(Qt::AlignCenter);
        widthBox = new QLineEdit(ImageOpt);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setGeometry(QRect(247, 80, 231, 21));
        widthBox->setStyleSheet(QString::fromUtf8("background: rgb(44, 48, 46);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        widthBox->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(Background);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(850, 20, 31, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro Black"));
        font.setPointSize(16);
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        Minimize = new QPushButton(Background);
        Minimize->setObjectName(QString::fromUtf8("Minimize"));
        Minimize->setGeometry(QRect(810, 20, 31, 31));
        Minimize->setFont(font);
        Minimize->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        Logo = new QLabel(Background);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(520, 20, 31, 31));
        Logo_2 = new QLabel(Background);
        Logo_2->setObjectName(QString::fromUtf8("Logo_2"));
        Logo_2->setGeometry(QRect(550, 20, 251, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        Logo_2->setFont(font1);
        pushButton_2 = new QPushButton(Background);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(515, 250, 171, 41));
        QFont font2;
        font2.setPointSize(14);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_3 = new QPushButton(Background);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(515, 110, 171, 41));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_4 = new QPushButton(Background);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(515, 156, 171, 41));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_5 = new QPushButton(Background);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(641, 60, 45, 45));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Logo_3 = new QLabel(Background);
        Logo_3->setObjectName(QString::fromUtf8("Logo_3"));
        Logo_3->setGeometry(QRect(515, 210, 171, 41));
        Logo_3->setFont(font1);
        Logo_3->setTextFormat(Qt::RichText);
        Logo_3->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(Background);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(515, 460, 179, 48));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_7 = new QPushButton(Background);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(697, 460, 179, 48));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        pushButton_8 = new QPushButton(Background);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(515, 512, 361, 44));
        QFont font3;
        font3.setPointSize(18);
        pushButton_8->setFont(font3);
        pushButton_8->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"        }\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }\n"
""));
        pushButton_9 = new QPushButton(Background);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(515, 560, 361, 61));
        QFont font4;
        font4.setPointSize(26);
        pushButton_9->setFont(font4);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        intervalTextBox = new QLineEdit(Background);
        intervalTextBox->setObjectName(QString::fromUtf8("intervalTextBox"));
        intervalTextBox->setGeometry(QRect(515, 340, 179, 31));
        QFont font5;
        font5.setPointSize(12);
        intervalTextBox->setFont(font5);
        intervalTextBox->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        intervalTextBox->setAlignment(Qt::AlignCenter);
        clickDelayTextBox = new QLineEdit(Background);
        clickDelayTextBox->setObjectName(QString::fromUtf8("clickDelayTextBox"));
        clickDelayTextBox->setGeometry(QRect(697, 340, 179, 31));
        clickDelayTextBox->setFont(font5);
        clickDelayTextBox->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        clickDelayTextBox->setAlignment(Qt::AlignCenter);
        Logo_4 = new QLabel(Background);
        Logo_4->setObjectName(QString::fromUtf8("Logo_4"));
        Logo_4->setGeometry(QRect(515, 310, 171, 21));
        Logo_4->setFont(font1);
        Logo_4->setTextFormat(Qt::RichText);
        Logo_4->setAlignment(Qt::AlignCenter);
        Logo_5 = new QLabel(Background);
        Logo_5->setObjectName(QString::fromUtf8("Logo_5"));
        Logo_5->setGeometry(QRect(705, 310, 171, 21));
        Logo_5->setFont(font1);
        Logo_5->setTextFormat(Qt::RichText);
        Logo_5->setAlignment(Qt::AlignCenter);
        Logo_6 = new QLabel(Background);
        Logo_6->setObjectName(QString::fromUtf8("Logo_6"));
        Logo_6->setGeometry(QRect(695, 380, 181, 21));
        Logo_6->setFont(font1);
        Logo_6->setTextFormat(Qt::RichText);
        Logo_6->setAlignment(Qt::AlignCenter);
        Logo_7 = new QLabel(Background);
        Logo_7->setObjectName(QString::fromUtf8("Logo_7"));
        Logo_7->setGeometry(QRect(515, 380, 171, 21));
        Logo_7->setFont(font1);
        Logo_7->setTextFormat(Qt::RichText);
        Logo_7->setAlignment(Qt::AlignCenter);
        listView = new QListView(Background);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(705, 60, 171, 118));
        listView->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        listView->setMovement(QListView::Snap);
        pushButton_10 = new QPushButton(Background);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(705, 180, 148, 21));
        QFont font6;
        font6.setPointSize(10);
        pushButton_10->setFont(font6);
        pushButton_10->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        pushButton_11 = new QPushButton(Background);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(855, 180, 21, 21));
        pushButton_11->setFont(font6);
        pushButton_11->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        drawingList = new QListView(Background);
        drawingList->setObjectName(QString::fromUtf8("drawingList"));
        drawingList->setGeometry(QRect(705, 220, 171, 71));
        drawingList->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 10px;"));
        drawingList->setMovement(QListView::Snap);
        transThresh = new QLineEdit(Background);
        transThresh->setObjectName(QString::fromUtf8("transThresh"));
        transThresh->setGeometry(QRect(697, 410, 179, 31));
        transThresh->setFont(font5);
        transThresh->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        transThresh->setAlignment(Qt::AlignCenter);
        blackThresh = new QLineEdit(Background);
        blackThresh->setObjectName(QString::fromUtf8("blackThresh"));
        blackThresh->setGeometry(QRect(515, 410, 179, 31));
        blackThresh->setFont(font5);
        blackThresh->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        blackThresh->setAlignment(Qt::AlignCenter);
        ImageFrame = new QLabel(Background);
        ImageFrame->setObjectName(QString::fromUtf8("ImageFrame"));
        ImageFrame->setGeometry(QRect(10, 10, 491, 491));
        ImageFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 61, 59);\n"
"border-radius: 5px;\n"
"background-size: cover;"));
        ImageFrame->setScaledContents(false);
        ImageFrame->setAlignment(Qt::AlignCenter);
        pushButton_12 = new QPushButton(Background);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(515, 60, 121, 45));
        pushButton_12->setFont(font2);
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        AutoDrawer->setCentralWidget(centralwidget);

        retranslateUi(AutoDrawer);

        QMetaObject::connectSlotsByName(AutoDrawer);
    } // setupUi

    void retranslateUi(QMainWindow *AutoDrawer)
    {
        AutoDrawer->setWindowTitle(QCoreApplication::translate("AutoDrawer", "AutoDrawer", nullptr));
        ScaleText->setText(QCoreApplication::translate("AutoDrawer", "Scale", nullptr));
        scaleNumber->setText(QCoreApplication::translate("AutoDrawer", "100", nullptr));
        HeightText->setText(QCoreApplication::translate("AutoDrawer", "Height", nullptr));
        WidthText->setText(QCoreApplication::translate("AutoDrawer", "Width", nullptr));
        exitButton->setText(QCoreApplication::translate("AutoDrawer", "X", nullptr));
        Minimize->setText(QCoreApplication::translate("AutoDrawer", "-", nullptr));
        Logo->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p>no</p></body></html>", nullptr));
        Logo_2->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p>Autodrawer v2.0-alpha</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AutoDrawer", "Custom Pattern", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AutoDrawer", "Load Config", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AutoDrawer", "Save Config", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AutoDrawer", "I", nullptr));
        Logo_3->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p>Drawing Pattern</p></body></html>", nullptr));
        pushButton_6->setText(QCoreApplication::translate("AutoDrawer", "Upload Image", nullptr));
        pushButton_7->setText(QCoreApplication::translate("AutoDrawer", "Clear Image", nullptr));
        pushButton_8->setText(QCoreApplication::translate("AutoDrawer", "Process Image", nullptr));
        pushButton_9->setText(QCoreApplication::translate("AutoDrawer", "Start", nullptr));
        Logo_4->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Interval</span></p><p><br/></p></body></html>", nullptr));
        Logo_5->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Click Delay</span></p></body></html>", nullptr));
        Logo_6->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Transparency Threshold</span></p></body></html>", nullptr));
        Logo_7->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Black Threshold</span></p></body></html>", nullptr));
        pushButton_10->setText(QCoreApplication::translate("AutoDrawer", "Set Directory", nullptr));
        pushButton_11->setText(QCoreApplication::translate("AutoDrawer", "R", nullptr));
        ImageFrame->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("AutoDrawer", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoDrawer: public Ui_AutoDrawer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTODRAWER_H
