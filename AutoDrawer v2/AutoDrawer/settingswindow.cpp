#include "settingswindow.h"
#include "qjsondocument.h"
#include "ui_settingswindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>

auto PathAD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    auto theme = rootObj.value("theme").toString();

    if (theme == "dark") {} else if (QFile::exists(PathAD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathAD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        QJsonObject rootObj = docT.object();
        QJsonObject preview = rootObj["settings"].toObject();
        ui->Header->setStyleSheet("color: "+preview["text"].toString());
        ui->CloseBox->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 10px; background: "+preview["buttons"].toString());
        ui->Console->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 20px; border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
        ui->ThemeEditor->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 0px; background: "+preview["buttons"].toString());
        ui->OpenLogs->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 20px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
        ui->CloseBox->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 10px; background: "+preview["close"].toString());
        ui->Discord->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 20px; background: "+preview["buttons"].toString());
        ui->LR->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 0px; background: "+preview["buttons"].toString());
        ui->GH->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 20px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
        ui->frame->setStyleSheet("border-radius: 25px; background: "+preview["checkbox-box"].toString());
        ui->OffsetBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
        ui->LogBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
        ui->PrinterBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
        ui->OpenThemes->setStyleSheet("border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+preview["buttons"].toString());
        ui->Reload->setStyleSheet("border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+preview["buttons"].toString());
        ui->intervalTextBox->setStyleSheet("border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+preview["buttons"].toString());
        ui->intervalTextBox_2->setStyleSheet("border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+preview["buttons"].toString());
        ui->Background_2->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());
    }

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_GH_released()
{
    QDesktopServices::openUrl(QUrl("https://github.com/AlexCYP/autodraw-roblox"));
}


void SettingsWindow::on_LR_released()
{
    QDesktopServices::openUrl(QUrl("https://github.com/AlexCYP/autodraw-roblox/releases/latest"));
}


void SettingsWindow::on_Discord_released()
{
    QDesktopServices::openUrl(QUrl("https://discord.gg/rwvUFraDnb"));
}


void SettingsWindow::on_CloseBox_released()
{
    this->close();
}

