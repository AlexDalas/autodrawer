#include "settingswindow.h"
#include "consolewindow.h"
#include "qfilesystemwatcher.h"
#include "qjsondocument.h"
#include "themeeditor.h"
#include "ui_settingswindow.h"
#include "messagewindow.h"
#include "autodrawer.h"
#include "downloadthemes.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDirIterator>
#include <QApplication>
#include <QProcess>
auto PathAD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";
bool indexReady = false;

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    indexReady = false;
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    QString theme = rootObj.value("theme").toString();
    reloadThemes(theme);
    reloadList();
    ui->ThemeCombo->setCurrentIndex(ui->ThemeCombo->findText(theme));
    ui->PrinterBox->setChecked(rootObj["printer"].toBool());
    ui->LogBox->setChecked(rootObj["logs"].toBool());
    ui->OffsetBox->setChecked(rootObj["offset_enabled"].toBool());
    ui->intervalTextBox->setEnabled(rootObj["offset_enabled"].toBool());
    ui->intervalTextBox->setText(QString::number(rootObj["offset_x"].toInt()));
    ui->intervalTextBox_2->setEnabled(rootObj["offset_enabled"].toBool());
    ui->intervalTextBox_2->setText(QString::number(rootObj["offset_y"].toInt()));
    inFile.close();
    indexReady = true;
    QFileSystemWatcher* watcher = new QFileSystemWatcher(this);
    watcher->addPath(PathAD+"/user.cfg");
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &SettingsWindow::onFileChanged);
}
void SettingsWindow::onFileChanged(const QString& path)
{
    if (path == PathAD+"/user.cfg") {
        QFile inFile(PathAD+"/user.cfg");
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = inFile.readAll();
        QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
        QJsonObject rootObj = doc.object();
        reloadThemes(rootObj.value("theme").toString());
    }
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
    QPixmap in;
    auto lightmode = rootObj.value("light-icons").toString();
    if(lightmode=="true"){
        in = QPixmap (":/images/images/RefreshIcon_Light.png");
    }else{
        in = QPixmap (":/images/images/RefreshIcon.png");
    }
    QIcon InfoIcon(in);
    ui->Reload->setIcon(InfoIcon);
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
    ui->intervalTextBox->setStyleSheet("color: "+preview["text"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+preview["buttons"].toString());
    ui->intervalTextBox_2->setStyleSheet("color: "+preview["text"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+preview["buttons"].toString());
    ui->Background_2->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());
    ui->offsetPos->setStyleSheet("color: "+preview["text"].toString());
    ui->X->setStyleSheet("color: "+preview["text"].toString());
    ui->Y->setStyleSheet("color: "+preview["text"].toString());
    ui->opt->setStyleSheet("color: "+preview["text"].toString());
    ui->themes->setStyleSheet("color: "+preview["text"].toString());
    ui->ThemeCombo->setStyleSheet("background: "+preview["buttons"].toString()+"; color: "+preview["text"].toString());
}

void SettingsWindow::reloadList(){
    ui->ThemeCombo->clear();
    QList list(QStringList()<<"dark"<<"light");
    QDirIterator it(PathAD+"/themes/", QStringList() << "*.drawtheme", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        it.next();
        QString fileName = it.fileName().replace(".drawtheme", "");
        if (fileName != "light" && fileName != "dark"){
            list << fileName;
        }
    }
    list << "Get more!";
    ui->ThemeCombo->addItems(list);
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    ui->ThemeCombo->setCurrentIndex(ui->ThemeCombo->findText(doc_obj["theme"].toString()));
    inFile.close();
}

void SettingsWindow::on_GH_released()
{
    new ConsoleWindow("Opening Github page");
    QDesktopServices::openUrl(QUrl("https://github.com/AlexCYP/autodraw-roblox"));
}


void SettingsWindow::on_LR_released()
{
    new ConsoleWindow("Opening Latest Release");
    QDesktopServices::openUrl(QUrl("https://github.com/AlexCYP/autodraw-roblox/releases/latest"));
}


void SettingsWindow::on_Discord_released()
{
    new ConsoleWindow("Opening Discord invite");
    QDesktopServices::openUrl(QUrl("https://discord.gg/rwvUFraDnb"));
}


void SettingsWindow::on_CloseBox_released()
{
    new ConsoleWindow("Closing Settings");
    this->close();
}

void SettingsWindow::on_OpenThemes_released()
{
    new ConsoleWindow("Opening theme path");
    QDesktopServices::openUrl(PathAD+"/themes/");
}


void SettingsWindow::on_Reload_released()
{
    new ConsoleWindow("Reloading theme listing");
    indexReady = false;
    reloadList();
    indexReady = true;
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj = doc.object();
    QString theme = rootObj.value("theme").toString();
    reloadThemes(theme);
    inFile.close();
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
    if (Item == "Get more!"){
        indexReady = false;
        ui->ThemeCombo->setCurrentIndex(ui->ThemeCombo->findText(doc_obj["theme"].toString()));
        downloadthemes *w = new downloadthemes();
        w->show();
        inFile.close();
        indexReady = true;
    }
    else{
        new ConsoleWindow("Changing theme to "+Item);
        doc_obj.insert("theme", Item);
        QJsonDocument new_doc(doc_obj);
        inFile.resize(0);
        inFile.write(new_doc.toJson());
        inFile.close();
        on_Reload_released();
 //       QApplication::closeAllWindows();
   //     QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}

void SettingsWindow::on_OffsetBox_released()
{
    if (!indexReady) return;
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    if (!ui->OffsetBox->checkState()) {doc_obj.insert("offset_enabled", false); new ConsoleWindow("Offset Enabled");} else {new ConsoleWindow("Offset Disabled");doc_obj.insert("offset_enabled", true);}
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
}

void SettingsWindow::on_LogBox_released()
{
    if (!indexReady) return;
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    if (!ui->LogBox->checkState()) {doc_obj.insert("logs", false); new ConsoleWindow("Logs Enabled");} else {new ConsoleWindow("Logs Disabled");doc_obj.insert("logs", true);}
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
}


void SettingsWindow::on_OpenLogs_released()
{
    new ConsoleWindow("Opening log path");
    QDesktopServices::openUrl(PathAD+"/logs/");
}


void SettingsWindow::on_PrinterBox_released()
{
    if (!indexReady) return;
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    if (!ui->PrinterBox->checkState()) {
        doc_obj.insert("printer", false);
        new ConsoleWindow("Setting printer mode to True");}
    else {
        doc_obj.insert("printer", true);
        new ConsoleWindow("Setting printer mode to False");}
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
}


void SettingsWindow::on_Console_released()
{
    ConsoleWindow *cw = new ConsoleWindow("openWindow");
    cw->show();
}


void SettingsWindow::on_ThemeEditor_released()
{
    ThemeEditor *te = new ThemeEditor();
    te->show();
}


void SettingsWindow::on_intervalTextBox_textChanged(const QString &arg1)
{
    if (!indexReady) return;
    new ConsoleWindow("Changed offset to "+ui->intervalTextBox->text());
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("offset_x", ui->intervalTextBox->text().toInt());
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    ui->intervalTextBox->setEnabled(ui->OffsetBox->checkState());
    ui->intervalTextBox_2->setEnabled(ui->OffsetBox->checkState());
}


void SettingsWindow::on_intervalTextBox_2_textChanged(const QString &arg1)
{
    if (!indexReady) return;
    new ConsoleWindow("Changed offset to "+ui->intervalTextBox_2->text());
    QFile inFile(PathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("offset_y", ui->intervalTextBox_2->text().toInt());
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    ui->intervalTextBox->setEnabled(ui->OffsetBox->checkState());
    ui->intervalTextBox_2->setEnabled(ui->OffsetBox->checkState());
}

