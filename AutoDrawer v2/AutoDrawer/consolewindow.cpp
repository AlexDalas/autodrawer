#include "consolewindow.h"
#include "ui_consolewindow.h"
#include <QDesktopServices>
#include <QStandardPaths>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <fstream>
#include <QDate>
QString pathAPD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";
ConsoleWindow::ConsoleWindow(QString text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsoleWindow)
{
    if (text != "openWindow"){
        std::string logPath = pathAPD.toStdString()+"/logs/";
        std::string year = std::to_string(QDate::currentDate().year());
        std::string month = std::to_string(QDate::currentDate().month());
        if (std::stoi(month)<=9) month="0"+month;
        std::string day = std::to_string(QDate::currentDate().day());
        std::string logName = "autodraw_"+year+month+day;
        if (!QFile::exists(QString::fromStdString(logPath+logName+".log"))){
            std::ofstream MyFile(logPath+logName+".log");;
            MyFile << text.toStdString() << "\n";
            MyFile.close();
        }
        else{
            QFile MyFile(QString::fromStdString(logPath+logName+".log"));
            MyFile.open(QIODevice::Append |QIODevice::Text);
            MyFile.write(text.toUtf8()+"\n");
            MyFile.close();
        }

    }
    else{
        ui->setupUi(this);
        setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
        setParent(0);
        setAttribute(Qt::WA_NoSystemBackground, true);
        setAttribute(Qt::WA_TranslucentBackground, true);
    }
}

ConsoleWindow::~ConsoleWindow()
{
    delete ui;
}

void ConsoleWindow::on_Exit_3_released()
{
    QDesktopServices::openUrl(pathAPD+"/logs/");
}


void ConsoleWindow::on_Exit_2_released()
{
    QString filters("Log File (*.log);;All files (*.*)");
    QString defaultFilter("Log File (*.log)");
    QString filename = QFileDialog::getSaveFileName(0, "Save Log", QDir::currentPath(),
            filters, &defaultFilter);

    if (filename.isNull()) return;
    std::ofstream MyFile(filename.toStdString());
    for(int i = ui->listWidget->count(); i --> 0;)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        MyFile << item->text().toStdString() << "\n";
    }
    MyFile.close();
}


void ConsoleWindow::on_Exit_released()
{
    this->close();
}


void ConsoleWindow::on_Exit_4_released()
{
    ui->listWidget->clear();
}

