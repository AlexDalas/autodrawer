#include "downloadthemes.h"
#include "ui_downloadthemes.h"
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QStandardPaths>
#include <fstream>
#include <QFile>

auto pathAUD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";

downloadthemes::downloadthemes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::downloadthemes)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    if (QFile(pathAUD+"/themes/banana.drawtheme").exists()) ui->OrangeYellow->setText("Installed");
    if (QFile(pathAUD+"/themes/black.drawtheme").exists()) ui->Black->setText("Installed");
    if (QFile(pathAUD+"/themes/blue.drawtheme").exists()) ui->Blue->setText("Installed");
    if (QFile(pathAUD+"/themes/green.drawtheme").exists()) ui->Green->setText("Installed");
    if (QFile(pathAUD+"/themes/red.drawtheme").exists()) ui->Red->setText("Installed");
    if (QFile(pathAUD+"/themes/violet.drawtheme").exists()) ui->Violet->setText("Installed");
}

downloadthemes::~downloadthemes()
{
    delete ui;
}


void downloadthemes::downloadSet(QString url, QString saveAS){
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    std::string content = response->readAll().toStdString();

    std::ofstream Download((pathAUD+"/themes/"+saveAS+".drawtheme").toStdString());
    Download << content;
    Download.close();
}

void downloadthemes::on_Blue_2_released()
{
    this->close();
}

void downloadthemes::on_Violet_released()
{
    if (ui->Violet->text() == "Installed") return;
    ui->Violet->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/violet.drawtheme", "violet");
    ui->Violet->setText("Installed");
}

void downloadthemes::on_Blue_released()
{
    if (ui->Blue->text() == "Installed") return;
    ui->Blue->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/blue.drawtheme", "blue");
    ui->Blue->setText("Installed");
}


void downloadthemes::on_Black_released()
{
    if (ui->Black->text() == "Installed") return;
    ui->Black->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/black.drawtheme", "black");
    ui->Black->setText("Installed");
}


void downloadthemes::on_OrangeYellow_released()
{
    if (ui->OrangeYellow->text() == "Installed") return;
    ui->OrangeYellow->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/banana.drawtheme", "banana");
    ui->OrangeYellow->setText("Installed");
}


void downloadthemes::on_Red_released()
{
    if (ui->Red->text() == "Installed") return;
    ui->Red->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/red.drawtheme", "red");
    ui->Red->setText("Installed");
}


void downloadthemes::on_Green_released()
{
    if (ui->Green->text() == "Installed") return;
    ui->Green->setText("Downloading...");
    downloadSet("https://raw.githubusercontent.com/AlexCYP/autodraw-roblox/main/AutoDrawer%20v2/themes/green.drawtheme", "green");
    ui->Green->setText("Installed");
}

