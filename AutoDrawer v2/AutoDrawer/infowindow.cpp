#include "infowindow.h"
#include "ui_infowindow.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
auto PathATD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QFile inFile(PathATD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    auto theme = rootObj.value("theme").toString();

    if (theme == "dark") {} else if (QFile::exists(PathATD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathATD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        QJsonObject rootObj = docT.object();
        QJsonObject info = rootObj["info"].toObject();
        ui->Text->setStyleSheet("color: "+info["text"].toString());
        ui->Header->setStyleSheet("color: "+info["text"].toString());
        ui->Button->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
        ui->Background->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());
    }
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::on_Button_released()
{
    this->close();
}

