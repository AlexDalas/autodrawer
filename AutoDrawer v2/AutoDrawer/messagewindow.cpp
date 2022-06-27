#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "autodrawer.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
auto PathAT = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";
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

    QFile inFile(PathAT+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    auto theme = rootObj.value("theme").toString();

    if (theme == "dark") {} else if (QFile::exists(PathAT+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathAT+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        QJsonObject rootObj = docT.object();
        QJsonObject info = rootObj["info"].toObject();
        ui->Text->setStyleSheet("color: "+info["text"].toString());
        ui->Header->setStyleSheet("color: "+info["text"].toString());
        ui->Background->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());
        ui->pushButton_6->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
        ui->pushButton_7->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
        ui->pushButton_8->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
        ui->pushButton_9->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    }

    if (type == 1){
        ui->Header->setText("Info");
        buttonType(0);
    } else if (type == 2){
        ui->Header->setText("Error");
        buttonType(0);
    }else if (type == 3){
        ui->Header->setText("Alert");
        buttonType(0);
    }else if (type == 4){
        //Only to be used in context of drawing finished
        ui->Header->setText("Success");
        buttonType(1);
    }else if (type == 5){
        //Only to be used in context of drawing stopped
        ui->Header->setText("Stopped");
        buttonType(1);
    }
    ui->Text->setText(text);
}

void MessageWindow::buttonType(int a){
    if (a==1) {
        ui->pushButton_6->hide();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
    }else{
        ui->pushButton_6->show();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
    }
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::on_pushButton_6_released()
{
    this->close();
}

void MessageWindow::on_pushButton_8_released()
{
    this->close();
    MainWinMW->showMinimized();
}

void MessageWindow::on_pushButton_7_released()
{
    this->close();
    MainWinMW->show();
    MainWinMW->raise();
}


void MessageWindow::on_pushButton_9_released()
{
    QApplication::quit();
}

