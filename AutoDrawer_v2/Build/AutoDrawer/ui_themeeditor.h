/********************************************************************************
** Form generated from reading UI file 'themeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEEDITOR_H
#define UI_THEMEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeEditor
{
public:
    QWidget *centralwidget;
    QFrame *Background_2;
    QPushButton *Exit;
    QLabel *label;

    void setupUi(QMainWindow *ThemeEditor)
    {
        if (ThemeEditor->objectName().isEmpty())
            ThemeEditor->setObjectName(QString::fromUtf8("ThemeEditor"));
        ThemeEditor->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ThemeEditor->setWindowIcon(icon);
        centralwidget = new QWidget(ThemeEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background_2 = new QFrame(centralwidget);
        Background_2->setObjectName(QString::fromUtf8("Background_2"));
        Background_2->setGeometry(QRect(0, 0, 801, 601));
        Background_2->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background_2->setFrameShape(QFrame::StyledPanel);
        Background_2->setFrameShadow(QFrame::Raised);
        Exit = new QPushButton(Background_2);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(120, 540, 131, 41));
        QFont font;
        font.setPointSize(14);
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
        label->setGeometry(QRect(300, 150, 271, 101));
        ThemeEditor->setCentralWidget(centralwidget);

        retranslateUi(ThemeEditor);

        QMetaObject::connectSlotsByName(ThemeEditor);
    } // setupUi

    void retranslateUi(QMainWindow *ThemeEditor)
    {
        ThemeEditor->setWindowTitle(QCoreApplication::translate("ThemeEditor", "MainWindow", nullptr));
        Exit->setText(QCoreApplication::translate("ThemeEditor", "Exit", nullptr));
        label->setText(QCoreApplication::translate("ThemeEditor", "<html><head/><body><p><span style=\" font-size:18pt;\">coming soon</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThemeEditor: public Ui_ThemeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEEDITOR_H
