/********************************************************************************
** Form generated from reading UI file 'consolewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEWINDOW_H
#define UI_CONSOLEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsoleWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QPushButton *Exit;
    QPushButton *Exit_2;
    QPushButton *Exit_3;
    QPushButton *Exit_4;
    QListWidget *listWidget;
    QPushButton *Exit_5;

    void setupUi(QMainWindow *ConsoleWindow)
    {
        if (ConsoleWindow->objectName().isEmpty())
            ConsoleWindow->setObjectName(QString::fromUtf8("ConsoleWindow"));
        ConsoleWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ConsoleWindow->setWindowIcon(icon);
        centralwidget = new QWidget(ConsoleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 801, 601));
        Background->setStyleSheet(QString::fromUtf8("background:rgb(35, 38, 37);\n"
"border-radius: 25px;"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        Exit = new QPushButton(Background);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(55, 540, 131, 41));
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
        Exit_2 = new QPushButton(Background);
        Exit_2->setObjectName(QString::fromUtf8("Exit_2"));
        Exit_2->setGeometry(QRect(195, 540, 131, 41));
        Exit_2->setFont(font);
        Exit_2->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Exit_3 = new QPushButton(Background);
        Exit_3->setObjectName(QString::fromUtf8("Exit_3"));
        Exit_3->setGeometry(QRect(335, 540, 131, 41));
        Exit_3->setFont(font);
        Exit_3->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        Exit_4 = new QPushButton(Background);
        Exit_4->setObjectName(QString::fromUtf8("Exit_4"));
        Exit_4->setGeometry(QRect(475, 540, 131, 41));
        Exit_4->setFont(font);
        Exit_4->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        listWidget = new QListWidget(Background);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 40, 711, 481));
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        Exit_5 = new QPushButton(Background);
        Exit_5->setObjectName(QString::fromUtf8("Exit_5"));
        Exit_5->setGeometry(QRect(615, 540, 131, 41));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        Exit_5->setFont(font1);
        Exit_5->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: rgb(58,61,59);\n"
"border-radius: 10px;\n"
"font: 16px;\n"
"}\n"
"        QPushButton:hover {\n"
"background: rgb(55,55,55);\n"
"        }"));
        ConsoleWindow->setCentralWidget(centralwidget);

        retranslateUi(ConsoleWindow);

        QMetaObject::connectSlotsByName(ConsoleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConsoleWindow)
    {
        ConsoleWindow->setWindowTitle(QCoreApplication::translate("ConsoleWindow", "MainWindow", nullptr));
        Exit->setText(QCoreApplication::translate("ConsoleWindow", "Exit", nullptr));
        Exit_2->setText(QCoreApplication::translate("ConsoleWindow", "Save Logs", nullptr));
        Exit_3->setText(QCoreApplication::translate("ConsoleWindow", "Open Logs", nullptr));
        Exit_4->setText(QCoreApplication::translate("ConsoleWindow", "Clear Logs", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ConsoleWindow", "a", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("ConsoleWindow", "b", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("ConsoleWindow", "c", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("ConsoleWindow", "d", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget->item(19);
        ___qlistwidgetitem19->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget->item(20);
        ___qlistwidgetitem20->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget->item(21);
        ___qlistwidgetitem21->setText(QCoreApplication::translate("ConsoleWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget->item(22);
        ___qlistwidgetitem22->setText(QCoreApplication::translate("ConsoleWindow", "e", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        Exit_5->setText(QCoreApplication::translate("ConsoleWindow", "Update Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConsoleWindow: public Ui_ConsoleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEWINDOW_H
