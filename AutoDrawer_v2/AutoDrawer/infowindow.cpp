#include "infowindow.h"
#include "consolewindow.h"
#include "qfilesystemwatcher.h"
#include "ui_infowindow.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
auto PathATD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    new ConsoleWindow("Opened Info window.");
    reloadThemes();
    QFileSystemWatcher* watcher = new QFileSystemWatcher(this);
    watcher->addPath(PathATD+"/user.cfg");
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &InfoWindow::onFileChanged);
}
void InfoWindow::onFileChanged(const QString& path)
{
    if (path == PathATD+"/user.cfg") {
   reloadThemes();
  }
}
InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::reloadThemes(){
    QFile inFile(PathATD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto theme = rootObj2.value("theme").toString();
    inFile.close();

    QJsonObject info;
    QJsonObject rootObj;
    if (theme == "dark") {
        extern QString darkJson;
        QByteArray br = darkJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        info = rootObj["settings"].toObject();
    } else if (theme == "light") {
        extern QString lightJson;
        QByteArray br = lightJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        info = rootObj["settings"].toObject();
    } else if (QFile::exists(PathATD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathATD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        info = rootObj["info"].toObject();
        inFile2.close();
    }
    ui->Text->setStyleSheet("color: "+info["text"].toString());
    ui->Header->setStyleSheet("color: "+info["text"].toString());
    ui->Button->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->Background->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());
}

void InfoWindow::on_Button_released()
{
    new ConsoleWindow("Closed Info window.");
    this->close();
}

