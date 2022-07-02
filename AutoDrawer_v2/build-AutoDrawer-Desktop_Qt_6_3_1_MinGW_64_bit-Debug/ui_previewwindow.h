/********************************************************************************
** Form generated from reading UI file 'previewwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWWINDOW_H
#define UI_PREVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QLabel *ShownImage;
    QFrame *frame;
    QPushButton *Stop;
    QPushButton *LastPOS;
    QLabel *Header;
    QPushButton *Draw;

    void setupUi(QMainWindow *PreviewWindow)
    {
        if (PreviewWindow->objectName().isEmpty())
            PreviewWindow->setObjectName(QString::fromUtf8("PreviewWindow"));
        PreviewWindow->resize(471, 211);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PreviewWindow->setWindowIcon(icon);
        centralwidget = new QWidget(PreviewWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 471, 211));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(255);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Background->sizePolicy().hasHeightForWidth());
        Background->setSizePolicy(sizePolicy);
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37, 200);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        ShownImage = new QLabel(Background);
        ShownImage->setObjectName(QString::fromUtf8("ShownImage"));
        ShownImage->setGeometry(QRect(0, 21, 471, 191));
        ShownImage->setStyleSheet(QString::fromUtf8(""));
        ShownImage->setScaledContents(false);
        ShownImage->setAlignment(Qt::AlignCenter);
        frame = new QFrame(Background);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 471, 21));
        frame->setStyleSheet(QString::fromUtf8("background:transparent"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Stop = new QPushButton(frame);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Stop->setGeometry(QRect(80, 0, 0, 20));
        Stop->setCursor(QCursor(Qt::PointingHandCursor));
        LastPOS = new QPushButton(frame);
        LastPOS->setObjectName(QString::fromUtf8("LastPOS"));
        LastPOS->setGeometry(QRect(120, 0, 0, 20));
        LastPOS->setCursor(QCursor(Qt::PointingHandCursor));
        Header = new QLabel(Background);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(0, 0, 471, 20));
        QFont font;
        font.setPointSize(10);
        Header->setFont(font);
        Header->setAlignment(Qt::AlignCenter);
        Draw = new QPushButton(Background);
        Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->setGeometry(QRect(0, 30, 0, 51));
        Draw->setCursor(QCursor(Qt::PointingHandCursor));
        PreviewWindow->setCentralWidget(centralwidget);

        retranslateUi(PreviewWindow);

        QMetaObject::connectSlotsByName(PreviewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PreviewWindow)
    {
        PreviewWindow->setWindowTitle(QCoreApplication::translate("PreviewWindow", "MainWindow", nullptr));
        ShownImage->setText(QString());
        Stop->setText(QCoreApplication::translate("PreviewWindow", "Stop", nullptr));
        LastPOS->setText(QCoreApplication::translate("PreviewWindow", "Last Pos", nullptr));
        Header->setText(QCoreApplication::translate("PreviewWindow", "Shift to Draw, Alt to stop, CTRL to lock last position", nullptr));
        Draw->setText(QCoreApplication::translate("PreviewWindow", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewWindow: public Ui_PreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWWINDOW_H
