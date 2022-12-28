#include "downloadthemes.h"
#include "consolewindow.h"
#include "qevent.h"
#include "qfilesystemwatcher.h"
#include "ui_downloadthemes.h"
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QStandardPaths>
#include <fstream>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>

auto pathAUD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";

downloadthemes::downloadthemes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::downloadthemes)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    new ConsoleWindow("Opened Theme Downloader window.");
    if (QFile(pathAUD+"/themes/banana.drawtheme").exists()) ui->OrangeYellow->setText("Installed Banana");
    if (QFile(pathAUD+"/themes/black.drawtheme").exists()) ui->Black->setText("Installed Black");
    if (QFile(pathAUD+"/themes/blue.drawtheme").exists()) ui->Blue->setText("Installed Blue");
    if (QFile(pathAUD+"/themes/green.drawtheme").exists()) ui->Green->setText("Installed Green");
    if (QFile(pathAUD+"/themes/red.drawtheme").exists()) ui->Red->setText("Installed Red");
    if (QFile(pathAUD+"/themes/violet.drawtheme").exists()) ui->Violet->setText("Installed Violet");
    reloadThemes();
    QFileSystemWatcher* watcher = new QFileSystemWatcher(this);
    watcher->addPath(pathAUD+"/user.cfg");
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &downloadthemes::onFileChanged);
}
void downloadthemes::onFileChanged(const QString& path)
{
    if (path == pathAUD+"/user.cfg") {
   reloadThemes();
  }
}

int m_nMouseClick_X_Coordinate4;
int m_nMouseClick_Y_Coordinate4;

void downloadthemes::mousePressEvent(QMouseEvent* event){
  m_nMouseClick_X_Coordinate4 = event->x();
  m_nMouseClick_Y_Coordinate4 = event->y();
  //qDebug() << m_nMouseClick_X_Coordinate;
  //qDebug() << m_nMouseClick_Y_Coordinate;
}

void downloadthemes::mouseMoveEvent(QMouseEvent* event){
    // Check if the mouse is currently over a QPushButton
    bool mouseOverButton = false;
    // Iterate over all the QPushButtons in the window
    foreach (QPushButton* button, findChildren<QPushButton*>()) {
        if (button->underMouse()) {
            mouseOverButton = true;
            break;
        }
    }

    // If the mouse is not over a QPushButton, move the window
    if (!mouseOverButton) {
        move(event->globalX()-m_nMouseClick_X_Coordinate4,event->globalY()-m_nMouseClick_Y_Coordinate4);
    }
}

downloadthemes::~downloadthemes()
{
    delete ui;
}

void downloadthemes::reloadThemes(){
    QFile inFile(pathAUD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
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
    } else if (QFile::exists(pathAUD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(pathAUD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        preview = rootObj["settings"].toObject();
        inFile2.close();
    }
    ui->Black->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Violet->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->OrangeYellow->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Red->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Blue->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Green->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Exit->setStyleSheet("color: "+preview["text"].toString()+";background: "+preview["close"].toString()+";border-radius: 10px;");
    ui->Background_2->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());
    ui->Text->setStyleSheet("background: transparent; color: "+preview["text"].toString());
}

bool downloadthemes::downloadSet(QString url, QString saveAS){
    new ConsoleWindow("Requested to download \""+saveAS+"\" at \""+url+"\"");
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    std::string content = response->readAll().toStdString();
    QVariant statusCode = response->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if ( !statusCode.isValid() ) return false;
    int status = statusCode.toInt();
    if (status == 200){
        std::ofstream Download((pathAUD+"/themes/"+saveAS+".drawtheme").toStdString());
        Download << content;
        Download.close();
        return true;
    } else return false;
}

void downloadthemes::on_Exit_released()
{
    new ConsoleWindow("Closed Theme Downloader window.");
    this->close();
}

void downloadthemes::on_Violet_released()
{
    if (ui->Violet->text() == "Installed") return;
    ui->Violet->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/violet.drawtheme", "violet")) return ui->Violet->setText("Download failed");
    ui->Violet->setText("Installed Violet");
}

void downloadthemes::on_Blue_released()
{
    if (ui->Blue->text() == "Installed") return;
    ui->Blue->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/blue.drawtheme", "blue")) return ui->Blue->setText("Download failed");
    ui->Blue->setText("Installed Blue");
}


void downloadthemes::on_Black_released()
{
    if (ui->Black->text() == "Installed") return;
    ui->Black->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/black.drawtheme", "black")) return ui->Black->setText("Download failed");
    ui->Black->setText("Installed Black");
}


void downloadthemes::on_OrangeYellow_released()
{
    if (ui->OrangeYellow->text() == "Installed") return;
    ui->OrangeYellow->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/banana.drawtheme", "banana")) return ui->OrangeYellow->setText("Download failed");
    ui->OrangeYellow->setText("Installed Banana");
}


void downloadthemes::on_Red_released()
{
    if (ui->Red->text() == "Installed") return;
    ui->Red->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/red.drawtheme", "red")) return ui->Red->setText("Download failed");
    ui->Red->setText("Installed Banana");
}


void downloadthemes::on_Green_released()
{
    if (ui->Green->text() == "Installed") return;
    ui->Green->setText("Downloading...");
    if (!downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer_v2/themes/green.drawtheme", "green")) return ui->Green->setText("Download failed");
    ui->Green->setText("Installed Green");
}

