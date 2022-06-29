#include "custompattern.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "ui_custompattern.h"
#include "messagewindow.h"
#include <QStandardPaths>
#include <QJsonObject>
#include <QFile>
#include <QPainter>

QString pathATD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";
custompattern::custompattern(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::custompattern)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    reloadThemes();
}

custompattern::~custompattern()
{
    delete ui;
}

void custompattern::on_Close_released()
{
    this->close();
}

void custompattern::reloadThemes(){
    QFile inFile(pathATD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

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
        pattern = rootObj["pattern"].toObject();
    } else if (theme == "light"){
        extern QString lightJson;
        QByteArray br = lightJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        pattern = rootObj["pattern"].toObject();
    } else if (QFile::exists(pathATD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(pathATD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        pattern = rootObj["pattern"].toObject();
        inFile2.close();
    }
    if (rootObj["light-icons"].toString() == "true") ui->Image->setPixmap(QPixmap(":/images/images/pattern.png")); else ui->Image->setPixmap(QPixmap(":/images/images/pattern_black.png"));
    ui->Close->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["close"].toString()+";border-radius: 10px;");
    ui->TextInt->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["textbox"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-left-radius: 10px;border-bottom-right-radius: 0px;");
    ui->Submit->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["button"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-left-radius: 0px;border-bottom-right-radius: 10px;");
    ui->Background->setStyleSheet("background: "+pattern["background"].toString()+";border-radius:25px;");
    ui->ImageBackground->setStyleSheet("border-radius: 25px; background: "+pattern["image-background"].toString());
    ui->Header->setStyleSheet("color: "+pattern["text"].toString());
    ui->Footer->setStyleSheet("color: "+pattern["text"].toString());
    ui->Footer2->setStyleSheet("color: "+pattern["text"].toString());
}

void custompattern::on_Submit_released()
{
    if (ui->TextInt->text().toStdString().length() != 8) {
        MessageWindow *w = new MessageWindow("Not a valid number!", 1, this);
        w->show();
    };
    if (ui->TextInt->text().toStdString().length() != 8) return;
    int a = 0;
    std::string s = ui->TextInt->text().toStdString();
    for (int i = 1; i <= 8; ++i) {
        if (s.find(std::to_string(i)) != std::string::npos) a=a+1;
    }
    if (a == 8){
        int s = ui->TextInt->text().toInt();
        QFile inFile(pathATD+"/user.cfg");
        inFile.open(QIODevice::ReadWrite|QIODevice::Text);
        QByteArray data = inFile.readAll();
        QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
        QJsonObject doc_obj = doc.object();
        doc_obj.insert("pattern", s);
        QJsonDocument new_doc(doc_obj);
        inFile.resize(0);
        inFile.write(new_doc.toJson());
        inFile.close();
        MessageWindow *w = new MessageWindow("Success!", 1, this);
        w->show();
        return;
    }
    else{
        MessageWindow *w = new MessageWindow("Not a valid number!", 1, this);
        w->show();
        return;
    }
}

