#include "consolewindow.h"
#include "messagewindow.h"
#include "qfilesystemwatcher.h"
#include "ui_consolewindow.h"
#include <QDesktopServices>
#include <QStandardPaths>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <fstream>
#include <QDate>
#include <QTextStream>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>

QString pathAPD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";
ConsoleWindow::ConsoleWindow(QString text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsoleWindow)
{
    if (text != "openWindow"){
        std::cout << text.toStdString() << "\n";
        QFile inFile(pathAPD+"/user.cfg");
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = inFile.readAll();
        QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
        QJsonObject rootObj2 = doc.object();
        if (!rootObj2.value("logs").toBool()) return;
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("hh:mm:ss");
        text = text+" (at "+formattedTime+")";
        std::string logPath = pathAPD.toStdString()+"/logs/";
        std::string year = std::to_string(QDate::currentDate().year());
        std::string month = std::to_string(QDate::currentDate().month());
        if (std::stoi(month)<=9) month="0"+month;
        std::string day = std::to_string(QDate::currentDate().day());
        std::string logName = "autodraw_"+year+month+day;
        if (!QFile::exists(QString::fromStdString(logPath+logName+".log"))){
            std::ofstream MyFile(logPath+logName+".log");;
            MyFile << "\n" + text.toStdString();
            MyFile.close();
        }
        else{
            QFile MyFile(QString::fromStdString(logPath+logName+".log"));
            MyFile.open(QIODevice::Append |QIODevice::Text);
            MyFile.write("\n" + text.toUtf8());
            MyFile.close();
        }
        this->close();
    }
    else{
        new ConsoleWindow("Console opened.");
        ui->setupUi(this);
        setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
        setParent(0);
        setAttribute(Qt::WA_NoSystemBackground, true);
        setAttribute(Qt::WA_TranslucentBackground, true);
        ui->listWidget->clear();
        std::string year = std::to_string(QDate::currentDate().year());
        std::string month = std::to_string(QDate::currentDate().month());
        if (std::stoi(month)<=9) month="0"+month;
        std::string day = std::to_string(QDate::currentDate().day());
        std::string logName = "autodraw_"+year+month+day;
        if (QFile::exists(pathAPD+"/logs/"+QString::fromStdString(logName)+".log")) {
            reloadConsole(logName);
            reloadThemes();
        }else{
            MessageWindow *w = new MessageWindow("Logs are not enabled!", 1, this);
            w->show();
            this->close();
        }
        QFileSystemWatcher* watcher = new QFileSystemWatcher(this);
        watcher->addPath(pathAPD+"/user.cfg");
        watcher->addPath(pathAPD+"/logs/"+QString::fromStdString(logName)+".log");
        connect(watcher, &QFileSystemWatcher::fileChanged, this, &ConsoleWindow::onFileChanged);
    }
}

void ConsoleWindow::onFileChanged(const QString& path)
{
    if (path == pathAPD+"/user.cfg") {
       reloadThemes();
      }else{
        std::string year = std::to_string(QDate::currentDate().year());
        std::string month = std::to_string(QDate::currentDate().month());
        if (std::stoi(month)<=9) month="0"+month;
        std::string day = std::to_string(QDate::currentDate().day());
        std::string logName = "autodraw_"+year+month+day;
        reloadConsole(logName);
    }
}

void ConsoleWindow::reloadThemes(){
    QFile inFile(pathAPD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    new ConsoleWindow("Opened Custom Pattern window.");
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto theme = rootObj2.value("theme").toString();
    inFile.close();

    QJsonObject pattern;
    QJsonObject rootObj;
    if (theme == "dark") {
        extern QString darkJson;
        QByteArray br = darkJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
    } else if (theme == "light"){
        extern QString lightJson;
        QByteArray br = lightJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
    } else if (QFile::exists(pathAPD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(pathAPD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        inFile2.close();
    }
    auto console = rootObj["console"].toObject();
    ui->Exit->setStyleSheet("color: "+console["text"].toString()+";background: "+console["close"].toString()+";border-radius: 10px;");
    ui->Exit_2->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Exit_3->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Exit_4->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Background->setStyleSheet("background: "+console["background"].toString()+";border-radius:25px;");
    ui->listWidget->setStyleSheet("background: "+console["console-background"].toString()+";border-radius:10px;");
}

ConsoleWindow::~ConsoleWindow()
{
    delete ui;
}

void ConsoleWindow::reloadConsole(std::string logName){
    ui->listWidget->clear();
    QFile MyFile(pathAPD+"/logs/"+QString::fromStdString(logName)+".log");
    MyFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream QTS(&MyFile);
    QStringList Q = QTS.readAll().split("\n");
    for(int i = Q.size(); i --> 0;)
    {
        ui->listWidget->addItem(Q[i]);
    }
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
    new ConsoleWindow("Closed Console window.");
    this->close();
}


void ConsoleWindow::on_Exit_4_released()
{
    std::string year = std::to_string(QDate::currentDate().year());
    std::string month = std::to_string(QDate::currentDate().month());
    if (std::stoi(month)<=9) month="0"+month;
    std::string day = std::to_string(QDate::currentDate().day());
    std::string logName = "autodraw_"+year+month+day;
    QFile file(pathAPD+"/logs/"+QString::fromStdString(logName)+".log");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
      file.resize(0);
      file.close();
    }
}


void ConsoleWindow::on_Exit_5_released()
{
    std::string year = std::to_string(QDate::currentDate().year());
    std::string month = std::to_string(QDate::currentDate().month());
    if (std::stoi(month)<=9) month="0"+month;
    std::string day = std::to_string(QDate::currentDate().day());
    std::string logName = "autodraw_"+year+month+day;
    reloadConsole(logName);
}

