#include "settingswindow.h"
#include "qjsondocument.h"
#include "ui_settingswindow.h"
#include "messagewindow.h"
#include "autodrawer.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
#include <QDirIterator>

auto PathAD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";
bool indexReady = false;

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    indexReady = false;
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    QList list(QStringList()<<"dark"<<"light");
    QDirIterator it(PathAD+"/themes/", QStringList() << "*.drawtheme", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        it.next();
        QString fileName = it.fileName().replace(".drawtheme", "");
        if (fileName != "light" && fileName != "dark"){
            list << fileName;
        }
    }
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    QString theme = rootObj.value("theme").toString();
    reloadThemes(theme);
    ui->ThemeCombo->addItems(list);
    ui->ThemeCombo->setCurrentIndex(ui->ThemeCombo->findText(theme));
    inFile.close();
    indexReady = true;
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::reloadThemes(QString theme){

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
    } else if (QFile::exists(PathAD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(PathAD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        preview = rootObj["settings"].toObject();
        inFile2.close();
    }
    ui->Header->setStyleSheet("color: "+preview["text"].toString());
    ui->CloseBox->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 10px; background: "+preview["buttons"].toString());
    ui->Console->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 20px; border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
    ui->ThemeEditor->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 0px; background: "+preview["buttons"].toString());
    ui->OpenLogs->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 20px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
    ui->CloseBox->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 10px; background: "+preview["close"].toString());
    ui->Discord->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 20px; background: "+preview["buttons"].toString());
    ui->LR->setStyleSheet("color: "+preview["text"].toString()+"; border-radius: 0px; background: "+preview["buttons"].toString());
    ui->GH->setStyleSheet("color: "+preview["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 20px;border-bottom-left-radius: 0px; background: "+preview["buttons"].toString());
    ui->frame->setStyleSheet("border-radius: 25px; background: "+preview["textbox"].toString());
    ui->OffsetBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
    ui->LogBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
    ui->PrinterBox->setStyleSheet("background:transparent;color: "+preview["text"].toString());
    ui->OpenThemes->setStyleSheet("color: "+preview["text"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+preview["buttons"].toString());
    ui->Reload->setStyleSheet("color: "+preview["text"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+preview["buttons"].toString());
    ui->intervalTextBox->setStyleSheet("border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+preview["buttons"].toString());
    ui->intervalTextBox_2->setStyleSheet("border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+preview["buttons"].toString());
    ui->Background_2->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());
    ui->offsetPos->setStyleSheet("color: "+preview["text"].toString());
    ui->X->setStyleSheet("color: "+preview["text"].toString());
    ui->Y->setStyleSheet("color: "+preview["text"].toString());
    ui->opt->setStyleSheet("color: "+preview["text"].toString());
    ui->themes->setStyleSheet("color: "+preview["background"].toString());
    ui->ThemeCombo->setStyleSheet("color: "+preview["text"].toString());
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

void SettingsWindow::on_OpenThemes_released()
{
    QDesktopServices::openUrl(PathAD+"/themes/");
}


void SettingsWindow::on_Reload_released()
{
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    QString theme = rootObj.value("theme").toString();
    reloadThemes(theme);
}

void SettingsWindow::on_ThemeCombo_currentIndexChanged()
{
    if (!indexReady) return;
    QString Item = ui->ThemeCombo->currentText();
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("theme", Item);
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    on_Reload_released();
    MessageWindow *w = new MessageWindow("Theme sucessfully set to "+Item+"!", 1, this);
    w->show();
}


void SettingsWindow::on_OffsetBox_released()
{
    if (!indexReady) return;
    QString Item = ui->ThemeCombo->currentText();
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("theme", Item);
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
}


void SettingsWindow::on_LogBox_released()
{
    if (!indexReady) return;
    QString Item = ui->ThemeCombo->currentText();
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    if (ui->LogBox->checkState() == 0) doc_obj.insert("logs", false); else doc_obj.insert("logs", true);
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
}

