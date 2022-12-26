/********************************************************************************
** Form generated from reading UI file 'autodrawer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTODRAWER_H
#define UI_AUTODRAWER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QLineEdit *scaleNumber;
    QLabel *ScaleText;
    QLabel *HeightText;
    QLabel *WidthText;
    QLineEdit *widthBox;
    QLineEdit *heightBox;
    QPushButton *exitButton;
    QPushButton *Minimize;
    QLabel *ADText;
    QPushButton *DP;
    QPushButton *loadConfig;
    QPushButton *saveConfig;
    QPushButton *infoButton;
    QLabel *DPText;
    QPushButton *uploadImage;
    QPushButton *clearImage;
    QPushButton *processImage;
    QPushButton *startButton;
    QLineEdit *intervalTextBox;
    QLineEdit *clickDelayTextBox;
    QLabel *intText;
    QLabel *cdText;
    QLabel *ttText;
    QLabel *btText;
    QPushButton *dirButton;
    QPushButton *reloadButton;
    QLineEdit *transThresh;
    QLineEdit *blackThresh;
    QLabel *ImageDrawn;
    QPushButton *settingButton;
    QLabel *ImageSource;
    QLabel *ImageBackground;
    QLabel *ShownImage;
    QLabel *LightLogo;
    QLabel *DarkLogo;
    QListWidget *listView;
    QListWidget *drawingList;

    void setupUi(QMainWindow *AutoDrawer)
    {
        if (AutoDrawer->objectName().isEmpty())
            AutoDrawer->setObjectName(QString::fromUtf8("AutoDrawer"));
        AutoDrawer->resize(891, 631);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AutoDrawer->setWindowIcon(icon);
        AutoDrawer->setStyleSheet(QString::fromUtf8("background:transparent"));
        centralwidget = new QWidget(AutoDrawer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 891, 631));
        Background->setStyleSheet(QString::fromUtf8("background: #FF2C302E;\n"
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
        ScaleFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-radius: 5px;"));
        ScaleFrame->setFrameShape(QFrame::StyledPanel);
        ScaleFrame->setFrameShadow(QFrame::Raised);
        ScaleSlider = new QSlider(ScaleFrame);
        ScaleSlider->setObjectName(QString::fromUtf8("ScaleSlider"));
        ScaleSlider->setGeometry(QRect(70, 10, 335, 20));
        ScaleSlider->setCursor(QCursor(Qt::SizeHorCursor));
        ScaleSlider->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        ScaleSlider->setMaximum(200);
        ScaleSlider->setPageStep(0);
        ScaleSlider->setValue(100);
        ScaleSlider->setOrientation(Qt::Horizontal);
        scaleNumber = new QLineEdit(ScaleFrame);
        scaleNumber->setObjectName(QString::fromUtf8("scaleNumber"));
        scaleNumber->setGeometry(QRect(420, 8, 51, 25));
        scaleNumber->setStyleSheet(QString::fromUtf8("background: rgb(49, 49, 49);\n"
"border-radius: 5px;"));
        scaleNumber->setAlignment(Qt::AlignCenter);
        ScaleText = new QLabel(ScaleFrame);
        ScaleText->setObjectName(QString::fromUtf8("ScaleText"));
        ScaleText->setGeometry(QRect(10, 10, 51, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScaleText->sizePolicy().hasHeightForWidth());
        ScaleText->setSizePolicy(sizePolicy);
        ScaleText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"background: transparent;\n"
"border-radius: 5px;"));
        ScaleText->setAlignment(Qt::AlignCenter);
        HeightText = new QLabel(ImageOpt);
        HeightText->setObjectName(QString::fromUtf8("HeightText"));
        HeightText->setGeometry(QRect(246, 45, 235, 31));
        HeightText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";"));
        HeightText->setAlignment(Qt::AlignCenter);
        WidthText = new QLabel(ImageOpt);
        WidthText->setObjectName(QString::fromUtf8("WidthText"));
        WidthText->setGeometry(QRect(10, 45, 231, 31));
        WidthText->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";"));
        WidthText->setAlignment(Qt::AlignCenter);
        widthBox = new QLineEdit(ImageOpt);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setGeometry(QRect(10, 80, 234, 21));
        widthBox->setStyleSheet(QString::fromUtf8("background: rgb(44, 48, 46);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        widthBox->setAlignment(Qt::AlignCenter);
        heightBox = new QLineEdit(ImageOpt);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setGeometry(QRect(247, 80, 231, 21));
        heightBox->setStyleSheet(QString::fromUtf8("background: rgb(44, 48, 46);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        heightBox->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(Background);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(840, 20, 31, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro Black"));
        font.setPointSize(16);
        exitButton->setFont(font);
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        Minimize = new QPushButton(Background);
        Minimize->setObjectName(QString::fromUtf8("Minimize"));
        Minimize->setGeometry(QRect(800, 20, 31, 31));
        Minimize->setFont(font);
        Minimize->setCursor(QCursor(Qt::PointingHandCursor));
        Minimize->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            color: grey;\n"
"        }\n"
""));
        ADText = new QLabel(Background);
        ADText->setObjectName(QString::fromUtf8("ADText"));
        ADText->setGeometry(QRect(555, 20, 251, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        ADText->setFont(font1);
        DP = new QPushButton(Background);
        DP->setObjectName(QString::fromUtf8("DP"));
        DP->setGeometry(QRect(515, 250, 171, 41));
        QFont font2;
        font2.setPointSize(14);
        DP->setFont(font2);
        DP->setCursor(QCursor(Qt::PointingHandCursor));
        DP->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        loadConfig = new QPushButton(Background);
        loadConfig->setObjectName(QString::fromUtf8("loadConfig"));
        loadConfig->setGeometry(QRect(515, 109, 171, 43));
        loadConfig->setFont(font2);
        loadConfig->setCursor(QCursor(Qt::PointingHandCursor));
        loadConfig->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        saveConfig = new QPushButton(Background);
        saveConfig->setObjectName(QString::fromUtf8("saveConfig"));
        saveConfig->setGeometry(QRect(515, 155, 171, 42));
        saveConfig->setFont(font2);
        saveConfig->setCursor(QCursor(Qt::PointingHandCursor));
        saveConfig->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        infoButton = new QPushButton(Background);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(640, 60, 46, 46));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif"));
        font3.setPointSize(14);
        infoButton->setFont(font3);
        infoButton->setCursor(QCursor(Qt::PointingHandCursor));
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        infoButton->setIconSize(QSize(35, 35));
        DPText = new QLabel(Background);
        DPText->setObjectName(QString::fromUtf8("DPText"));
        DPText->setGeometry(QRect(515, 210, 171, 41));
        DPText->setFont(font1);
        DPText->setTextFormat(Qt::RichText);
        DPText->setAlignment(Qt::AlignCenter);
        uploadImage = new QPushButton(Background);
        uploadImage->setObjectName(QString::fromUtf8("uploadImage"));
        uploadImage->setGeometry(QRect(515, 460, 179, 48));
        uploadImage->setFont(font2);
        uploadImage->setCursor(QCursor(Qt::PointingHandCursor));
        uploadImage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        clearImage = new QPushButton(Background);
        clearImage->setObjectName(QString::fromUtf8("clearImage"));
        clearImage->setGeometry(QRect(697, 460, 179, 48));
        clearImage->setFont(font2);
        clearImage->setCursor(QCursor(Qt::PointingHandCursor));
        clearImage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        processImage = new QPushButton(Background);
        processImage->setObjectName(QString::fromUtf8("processImage"));
        processImage->setGeometry(QRect(515, 512, 361, 44));
        QFont font4;
        font4.setPointSize(18);
        processImage->setFont(font4);
        processImage->setCursor(QCursor(Qt::PointingHandCursor));
        processImage->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
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
        startButton = new QPushButton(Background);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setEnabled(true);
        startButton->setGeometry(QRect(515, 560, 361, 61));
        QFont font5;
        font5.setPointSize(26);
        startButton->setFont(font5);
        startButton->setCursor(QCursor(Qt::PointingHandCursor));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        startButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        intervalTextBox = new QLineEdit(Background);
        intervalTextBox->setObjectName(QString::fromUtf8("intervalTextBox"));
        intervalTextBox->setGeometry(QRect(515, 340, 179, 31));
        QFont font6;
        font6.setPointSize(12);
        intervalTextBox->setFont(font6);
        intervalTextBox->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        intervalTextBox->setAlignment(Qt::AlignCenter);
        clickDelayTextBox = new QLineEdit(Background);
        clickDelayTextBox->setObjectName(QString::fromUtf8("clickDelayTextBox"));
        clickDelayTextBox->setGeometry(QRect(697, 340, 179, 31));
        clickDelayTextBox->setFont(font6);
        clickDelayTextBox->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        clickDelayTextBox->setAlignment(Qt::AlignCenter);
        intText = new QLabel(Background);
        intText->setObjectName(QString::fromUtf8("intText"));
        intText->setGeometry(QRect(515, 310, 181, 21));
        intText->setFont(font1);
        intText->setTextFormat(Qt::RichText);
        intText->setAlignment(Qt::AlignCenter);
        cdText = new QLabel(Background);
        cdText->setObjectName(QString::fromUtf8("cdText"));
        cdText->setGeometry(QRect(695, 310, 181, 21));
        cdText->setFont(font1);
        cdText->setTextFormat(Qt::RichText);
        cdText->setAlignment(Qt::AlignCenter);
        ttText = new QLabel(Background);
        ttText->setObjectName(QString::fromUtf8("ttText"));
        ttText->setGeometry(QRect(695, 380, 181, 21));
        ttText->setFont(font1);
        ttText->setTextFormat(Qt::RichText);
        ttText->setAlignment(Qt::AlignCenter);
        btText = new QLabel(Background);
        btText->setObjectName(QString::fromUtf8("btText"));
        btText->setGeometry(QRect(515, 380, 181, 21));
        btText->setFont(font1);
        btText->setTextFormat(Qt::RichText);
        btText->setAlignment(Qt::AlignCenter);
        dirButton = new QPushButton(Background);
        dirButton->setObjectName(QString::fromUtf8("dirButton"));
        dirButton->setGeometry(QRect(705, 171, 143, 26));
        QFont font7;
        font7.setPointSize(10);
        dirButton->setFont(font7);
        dirButton->setCursor(QCursor(Qt::PointingHandCursor));
        dirButton->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        reloadButton = new QPushButton(Background);
        reloadButton->setObjectName(QString::fromUtf8("reloadButton"));
        reloadButton->setGeometry(QRect(850, 171, 26, 26));
        reloadButton->setFont(font7);
        reloadButton->setCursor(QCursor(Qt::PointingHandCursor));
        reloadButton->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        reloadButton->setIconSize(QSize(18, 18));
        transThresh = new QLineEdit(Background);
        transThresh->setObjectName(QString::fromUtf8("transThresh"));
        transThresh->setGeometry(QRect(697, 410, 179, 31));
        transThresh->setFont(font6);
        transThresh->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 0px;"));
        transThresh->setAlignment(Qt::AlignCenter);
        blackThresh = new QLineEdit(Background);
        blackThresh->setObjectName(QString::fromUtf8("blackThresh"));
        blackThresh->setGeometry(QRect(515, 410, 179, 31));
        blackThresh->setFont(font6);
        blackThresh->setStyleSheet(QString::fromUtf8("background: rgb(56, 56, 56);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 10px;"));
        blackThresh->setAlignment(Qt::AlignCenter);
        ImageDrawn = new QLabel(Background);
        ImageDrawn->setObjectName(QString::fromUtf8("ImageDrawn"));
        ImageDrawn->setGeometry(QRect(10, 10, 0, 0));
        ImageDrawn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background:transparent"));
        ImageDrawn->setScaledContents(false);
        ImageDrawn->setAlignment(Qt::AlignCenter);
        settingButton = new QPushButton(Background);
        settingButton->setObjectName(QString::fromUtf8("settingButton"));
        settingButton->setGeometry(QRect(515, 60, 122, 46));
        settingButton->setFont(font2);
        settingButton->setCursor(QCursor(Qt::PointingHandCursor));
        settingButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        ImageSource = new QLabel(Background);
        ImageSource->setObjectName(QString::fromUtf8("ImageSource"));
        ImageSource->setGeometry(QRect(0, 0, 0, 0));
        ImageSource->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 61, 59);\n"
"border-radius: 5px;\n"
"background-size: cover;"));
        ImageSource->setScaledContents(false);
        ImageSource->setAlignment(Qt::AlignCenter);
        ImageBackground = new QLabel(Background);
        ImageBackground->setObjectName(QString::fromUtf8("ImageBackground"));
        ImageBackground->setGeometry(QRect(10, 10, 491, 491));
        ImageBackground->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 61, 59);\n"
"border-radius: 5px;\n"
"background-size: cover;"));
        ImageBackground->setScaledContents(false);
        ImageBackground->setAlignment(Qt::AlignCenter);
        ShownImage = new QLabel(Background);
        ShownImage->setObjectName(QString::fromUtf8("ShownImage"));
        ShownImage->setGeometry(QRect(10, 10, 491, 491));
        ShownImage->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background:transparent"));
        ShownImage->setScaledContents(false);
        ShownImage->setAlignment(Qt::AlignCenter);
        LightLogo = new QLabel(Background);
        LightLogo->setObjectName(QString::fromUtf8("LightLogo"));
        LightLogo->setGeometry(QRect(520, 20, 31, 31));
        LightLogo->setStyleSheet(QString::fromUtf8("background: transparent;"));
        LightLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Icon_Light.ico")));
        LightLogo->setScaledContents(true);
        DarkLogo = new QLabel(Background);
        DarkLogo->setObjectName(QString::fromUtf8("DarkLogo"));
        DarkLogo->setGeometry(QRect(520, 20, 31, 31));
        DarkLogo->setStyleSheet(QString::fromUtf8("background: transparent;"));
        DarkLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Icon.ico")));
        DarkLogo->setScaledContents(true);
        listView = new QListWidget(Background);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(705, 60, 171, 109));
        listView->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        drawingList = new QListWidget(Background);
        new QListWidgetItem(drawingList);
        new QListWidgetItem(drawingList);
        new QListWidgetItem(drawingList);
        new QListWidgetItem(drawingList);
        drawingList->setObjectName(QString::fromUtf8("drawingList"));
        drawingList->setGeometry(QRect(705, 220, 171, 71));
        drawingList->setStyleSheet(QString::fromUtf8("background: rgb(58,61,59);\n"
"border-radius: 10px;"));
        DarkLogo->raise();
        ImageOpt->raise();
        exitButton->raise();
        Minimize->raise();
        ADText->raise();
        DP->raise();
        loadConfig->raise();
        saveConfig->raise();
        infoButton->raise();
        DPText->raise();
        uploadImage->raise();
        clearImage->raise();
        processImage->raise();
        startButton->raise();
        intervalTextBox->raise();
        clickDelayTextBox->raise();
        intText->raise();
        cdText->raise();
        ttText->raise();
        btText->raise();
        dirButton->raise();
        reloadButton->raise();
        transThresh->raise();
        blackThresh->raise();
        settingButton->raise();
        ImageSource->raise();
        ImageBackground->raise();
        ImageDrawn->raise();
        ShownImage->raise();
        LightLogo->raise();
        listView->raise();
        drawingList->raise();
        AutoDrawer->setCentralWidget(centralwidget);

        retranslateUi(AutoDrawer);

        QMetaObject::connectSlotsByName(AutoDrawer);
    } // setupUi

    void retranslateUi(QMainWindow *AutoDrawer)
    {
        AutoDrawer->setWindowTitle(QCoreApplication::translate("AutoDrawer", "AutoDrawer", nullptr));
        scaleNumber->setText(QCoreApplication::translate("AutoDrawer", "100", nullptr));
        ScaleText->setText(QCoreApplication::translate("AutoDrawer", "Scale", nullptr));
        HeightText->setText(QCoreApplication::translate("AutoDrawer", "Height", nullptr));
        WidthText->setText(QCoreApplication::translate("AutoDrawer", "Width", nullptr));
        exitButton->setText(QCoreApplication::translate("AutoDrawer", "X", nullptr));
        Minimize->setText(QCoreApplication::translate("AutoDrawer", "-", nullptr));
        ADText->setText(QCoreApplication::translate("AutoDrawer", "AutoDrawer v2.0", nullptr));
        DP->setText(QCoreApplication::translate("AutoDrawer", "Custom Pattern", nullptr));
        loadConfig->setText(QCoreApplication::translate("AutoDrawer", "Load Config", nullptr));
        saveConfig->setText(QCoreApplication::translate("AutoDrawer", "Save Config", nullptr));
        infoButton->setText(QString());
        DPText->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p>Drawing Pattern</p></body></html>", nullptr));
        uploadImage->setText(QCoreApplication::translate("AutoDrawer", "Upload Image", nullptr));
        clearImage->setText(QCoreApplication::translate("AutoDrawer", "Clear Image", nullptr));
        processImage->setText(QCoreApplication::translate("AutoDrawer", "Process Image", nullptr));
        startButton->setText(QCoreApplication::translate("AutoDrawer", "Start", nullptr));
        intervalTextBox->setText(QCoreApplication::translate("AutoDrawer", "10000", nullptr));
        clickDelayTextBox->setText(QCoreApplication::translate("AutoDrawer", "1000", nullptr));
        intText->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Interval</span></p><p><br/></p></body></html>", nullptr));
        cdText->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Click Delay</span></p></body></html>", nullptr));
        ttText->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Transparency Threshold</span></p></body></html>", nullptr));
        btText->setText(QCoreApplication::translate("AutoDrawer", "<html><head/><body><p><span style=\" font-weight:400;\">Black Threshold</span></p></body></html>", nullptr));
        dirButton->setText(QCoreApplication::translate("AutoDrawer", "Set Directory", nullptr));
        reloadButton->setText(QString());
        transThresh->setText(QCoreApplication::translate("AutoDrawer", "127", nullptr));
        blackThresh->setText(QCoreApplication::translate("AutoDrawer", "127", nullptr));
        ImageDrawn->setText(QString());
        settingButton->setText(QCoreApplication::translate("AutoDrawer", "Settings", nullptr));
        ImageSource->setText(QString());
        ImageBackground->setText(QString());
        ShownImage->setText(QString());
        LightLogo->setText(QString());
        DarkLogo->setText(QString());

        const bool __sortingEnabled = drawingList->isSortingEnabled();
        drawingList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = drawingList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("AutoDrawer", "Horizontal - 12345678", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = drawingList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("AutoDrawer", "Vertical - 14627358", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = drawingList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("AutoDrawer", "Diagonal - 26573481", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = drawingList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("AutoDrawer", "Spiral - 12358764", nullptr));
        drawingList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class AutoDrawer: public Ui_AutoDrawer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTODRAWER_H
