#include "messagewindow.h"
#include "consolewindow.h"
#include "ui_messagewindow.h"
#include "autodrawer.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
auto PathAT = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";
int result;
QWidget* MainWinMW;
MessageWindow::MessageWindow(QString text, int type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    this->window()->raise();
    MainWinMW = parent;
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->Text->setText(text);
    QFont myFont("Sans Serrif", 16);;
    QFontMetrics fm(myFont);
    int width=fm.horizontalAdvance(text)+50;

    if (width > 450){
        resize(width, this->height());
        ui->Background->resize(width, ui->Background->height());
        ui->Header->resize(width, ui->Header->height());
        ui->Text->resize(width, ui->Text->height());
    }

    reloadThemes();
    //new ConsoleWindow("Sent message \""+text+"\" (with code "+QString::number(type)+")");
    QStringList textTypes; textTypes << "Info" << "Error" << "Alert" << "Success" << "Stopped";
    ui->Header->setText(textTypes[type-1]);
    if (type<=3) {buttonType(0);} else {buttonType(1);}
}

void MessageWindow::reloadThemes(){
    QFile inFile(PathAT+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr2;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr2);
    QJsonObject rootObj2 = doc.object();
    auto theme = rootObj2.value("theme").toString();
    inFile.close();

    QJsonObject preview;
    QJsonObject rootObj;
    if (theme == "dark") {
        extern QString darkJson;
        QByteArray br = darkJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        preview = rootObj["settings"].toObject();
    } else if (theme == "light"){
        extern QString lightJson;
        QByteArray br = lightJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        preview = rootObj["settings"].toObject();
    } else if (QFile::exists(PathAT+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathAT+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        inFile2.close();
    }
    QJsonObject info = rootObj["info"].toObject();
    ui->Text->setStyleSheet("color: "+info["text"].toString());
    ui->Header->setStyleSheet("color: "+info["text"].toString());
    ui->Background->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());
    ui->pushButton_6->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->pushButton_7->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->pushButton_8->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->pushButton_9->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
}

void MessageWindow::buttonType(int a){
    if (a==1) {
        ui->pushButton_6->hide();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
        ui->pushButton_9->move(ui->Background->width()-ui->pushButton_9->width(), 0);
        ui->frame->move((ui->Background->width()/2-ui->pushButton_7->width())-5, 150);
    }else{
        ui->pushButton_6->show();
        ui->frame->hide();
        ui->pushButton_9->hide();
        ui->pushButton_6->move((ui->Background->width()/2-ui->pushButton_6->width()/2), 150);
    }
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::on_pushButton_6_released()
{
    new ConsoleWindow("Closed message.");
    this->close();
}

void MessageWindow::on_pushButton_8_released()
{
    new ConsoleWindow("Closed message (and minimized Autodrawer).");
    new ConsoleWindow("Closed Autodrawer (at notification).");
    this->close();
    MainWinMW->showMinimized();
}

void MessageWindow::on_pushButton_7_released()
{
    new ConsoleWindow("Closed message (and showed Autodrawer).");
    this->close();
    MainWinMW->show();
    MainWinMW->raise();
}


void MessageWindow::on_pushButton_9_released()
{
    new ConsoleWindow("Closed Autodrawer at notification.");
    QApplication::quit();
}

