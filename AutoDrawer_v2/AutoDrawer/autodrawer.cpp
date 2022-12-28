#include "autodrawer.h"
#include "./ui_autodrawer.h"
#include "custompattern.h"
#include "infowindow.h"
#include "messagewindow.h"
#include "previewwindow.h"
#include "qcryptographichash.h"
#include "qdiriterator.h"
#include "qfilesystemwatcher.h"
#include "qjsonarray.h"
#include "qjsondocument.h"
#include "consolewindow.h"
#include "qjsonobject.h"
#include "qtimer.h"
#include <qapplication.h>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QStandardPaths>
#include <QProcess>

using namespace std;

//Theme colours
QString pathAD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";
QString darkJson = "{" \
              "\"ver\": 2.0, " \
              "\"light-icons\": \"true\",  " \
              "\"main\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#FF2C302E\", " \
              "    \"background-1\": \"#FF333735\", " \
              "    \"background-2\": \"#FF2C302E\", " \
              "    \"image-background\": \"#FF3A3D3B\", " \
              "    \"pattern-listbox\": \"#FF3A3D3B\", " \
              "    \"config-listbox\": \"#FF3A3D3B\", " \
              "    \"loadconfig-button\": \"#FF3A3D3B\", " \
              "    \"loadconfig-button-hover\": \"#FF373737\", " \
              "    \"saveconfig-button\": \"#FF3A3D3B\", " \
              "    \"saveconfig-button-hover\": \"#FF373737\", " \
              "    \"settings-info-buttons\": \"#FF3A3D3B\", " \
              "    \"settings-info-buttons-hover\": \"#FF373737\", " \
              "    \"pattern-button\": \"#FF3A3D3B\", " \
              "    \"pattern-button-hover\": \"#FF373737\", " \
              "    \"directory-buttons\": \"#FF3A3D3B\", " \
              "    \"directory-buttons-hover\": \"#FF373737\", " \
              "    \"textbox-backgrounds\": \"#383838\", " \
              "    \"upload-buttons\": \"#FF3A3D3B\", " \
              "    \"upload-buttons-hover\": \"#FF373737\", " \
              "    \"clear-buttons\": \"#FF3A3D3B\", " \
              "    \"clear-buttons-hover\": \"#FF373737\", " \
              "    \"process-button\": \"#FF3A3D3B\", " \
              "    \"process-button-hover\": \"#FF373737\", " \
              "    \"start-button\": \"#FF3A3D3B\", " \
              "    \"start-button-hover\": \"#FF373737\", " \
              "    \"scalebar-background\": \"#00000000\", " \
              "    \"scale-textbox\": \"#FF474A48\", " \
              "    \"width-textbox\": \"#FF2C302E\", " \
              "    \"height-textbox\": \"#FF2C302E\" " \
              "}, " \
              "\"settings\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#232625\", " \
              "    \"buttons\": \"#FF2C302E\", " \
              "    \"textbox\": \"#FF2C302E\", " \
              "    \"checkbox-box\": \"#FFFFFFFF\", " \
              "    \"close\": \"#FF2C302E\" " \
              "}, " \
              "\"info\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#232625\", " \
              "    \"close\": \"#FF2C302E\" " \
              "}, " \
              "\"pattern\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#232625\", " \
              "    \"image-background\": \"#FF3C3C3C\", " \
              "    \"button\": \"#FF2C302E\", " \
              "    \"textbox\": \"#FF2C302E\", " \
              "    \"close\": \"#FF2C302E\" " \
              "}, " \
              "\"console\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#232625\", " \
              "    \"console-background\": \"#FF333735\", " \
              "    \"button\": \"#FF2C302E\", " \
              "    \"close\": \"#FF2C302E\" " \
              "}, " \
              "\"preview\": { " \
              "    \"text\": \"#FFFFFFFF\", " \
              "    \"background\": \"#232625\" " \
              "}"\
          "}";

QString lightJson = "{" \
            "    \"ver\": 1.4," \
            "    \"light-icons\": \"false\"," \
            "    \"main\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#DEE2E6\"," \
            "        \"background-1\": \"#D6DBE0\"," \
            "        \"background-2\": \"#D6DBE0\"," \
            "        \"image-background\": \"#C6CDD3\"," \
            "        \"pattern-listbox\": \"#C6CDD3\"," \
            "        \"config-listbox\": \"#C6CDD3\"," \
            "        \"loadconfig-button\": \"#C6CDD3\"," \
            "        \"loadconfig-button-hover\": \"#BEC5CC\"," \
            "        \"saveconfig-button\": \"#C6CDD3\"," \
            "        \"saveconfig-button-hover\": \"#BEC5CC\"," \
            "        \"settings-info-buttons\": \"#C6CDD3\"," \
            "        \"settings-info-buttons-hover\": \"#BEC5CC\"," \
            "        \"pattern-button\": \"#C6CDD3\"," \
            "        \"pattern-button-hover\": \"#BEC5CC\"," \
            "        \"directory-buttons\": \"#C6CDD3\"," \
            "        \"directory-buttons-hover\": \"#BEC5CC\"," \
            "        \"textbox-backgrounds\": \"#C6CDD3\"," \
            "        \"upload-buttons\": \"#C6CDD3\"," \
            "        \"upload-buttons-hover\": \"#BEC5CC\"," \
            "        \"clear-buttons\": \"#C6CDD3\"," \
            "        \"clear-buttons-hover\": \"#BEC5CC\"," \
            "        \"process-button\": \"#C6CDD3\"," \
            "        \"process-button-hover\": \"#BEC5CC\"," \
            "        \"start-button\": \"#C6CDD3\"," \
            "        \"start-button-hover\": \"#BEC5CC\"," \
            "        \"scalebar-background\": \"#BEC5CC\"," \
            "        \"scale-textbox\": \"#BEC5CC\"," \
            "        \"width-textbox\": \"#BEC5CC\"," \
            "        \"height-textbox\": \"#BEC5CC\"" \
            "    }," \
            "    \"settings\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#D6DBE0\"," \
            "        \"buttons\": \"#C6CDD3\"," \
            "        \"textbox\": \"#C6CDD3\"," \
            "        \"checkbox-box\": \"#C6CDD3\"," \
            "        \"close\": \"#C6CDD3\"" \
            "    }," \
            "    \"info\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#D6DBE0\"," \
            "        \"close\": \"#C6CDD3\"" \
            "    }," \
            "    \"pattern\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#D6DBE0\"," \
            "        \"image-background\": \"#D6DBE0\"," \
            "        \"button\": \"#C6CDD3\"," \
            "        \"textbox\": \"#C6CDD3\"," \
            "        \"close\": \"#C6CDD3\"" \
            "    }," \
            "    \"console\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#D6DBE0\"," \
            "        \"console-background\": \"#D6DBE0\"," \
            "        \"button\": \"#C6CDD3\"," \
            "        \"close\": \"#C6CDD3\"" \
            "    }," \
            "    \"preview\": {" \
            "        \"text\": \"#0C0E0F\"," \
            "        \"background\": \"#D6DBE0\"" \
            "    }" \
            "}";

static void sendMessage(QString a, int b, QWidget *t){
    //1 for info, 2 for error, 3 for alert
    MessageWindow *w = new MessageWindow(a, b, t);
    w->show();
}

AutoDrawer::AutoDrawer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoDrawer)

{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAcceptDrops(true);
    ui->setupUi(this);
    qApp->installEventFilter(this);
    this->setFixedSize(this->width(),this->height());
    if (!QDir(pathAD).exists()) QDir().mkdir(pathAD);
    if (!QDir(pathAD+"/themes/").exists()) QDir().mkdir(pathAD+"/themes/");
    if (!QDir(pathAD+"/logs/").exists()) QDir().mkdir(pathAD+"/logs/");
    if (!QDir(pathAD).exists()) QDir().mkdir(pathAD);
    if (!QFile(pathAD+"/user.cfg").exists()){
        QJsonObject UserCFG;

        //recordObject.insert("as", QJsonValue::fromVariant(43));

        QFile Old_theme(pathAD+"/themes/theme.txt");
        if (Old_theme.exists()) {
            Old_theme.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream Old_themeStream(&Old_theme);
            UserCFG.insert("theme", QJsonValue::fromVariant(Old_themeStream.readLine()));
        }
        else{
            UserCFG.insert("theme", QJsonValue::fromVariant("dark"));
        }
        QFile Old_dir(pathAD+"/dir.txt");
        if (Old_dir.exists()) {
            Old_dir.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream Old_dirStream(&Old_dir);
            UserCFG.insert("dir", QJsonValue::fromVariant(Old_dirStream.readLine()));
        }
        else{
            UserCFG.insert("dir", QJsonValue::fromVariant(""));
        }
        UserCFG.insert("offset_enabled", true);
        UserCFG.insert("offset_x", 0);
        UserCFG.insert("offset_y", 0);
        UserCFG.insert("pattern", 12345678);
        UserCFG.insert("logs", QJsonValue::fromVariant(false));
        UserCFG.insert("printer", QJsonValue::fromVariant(false));
        ofstream MyFile((pathAD+"/user.cfg").toStdString());
        QJsonDocument doc(UserCFG);
        MyFile << (doc.toJson(QJsonDocument::Indented)).toStdString();
        MyFile.close();
    }
    reloadThemes();
    QFileSystemWatcher* watcher = new QFileSystemWatcher(this);
    watcher->addPath(pathAD+"/user.cfg");
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &AutoDrawer::onFileChanged);
    on_reloadButton_released();
}

int m_nMouseClick_X_Coordinate;
int m_nMouseClick_Y_Coordinate;
int absPosX;
int absPosY;
bool disableMove = false;

void AutoDrawer::mousePressEvent(QMouseEvent* event){
    QPoint mousePos = event->globalPos();
    QWidget *widgetUnderMouse = QApplication::widgetAt(mousePos);

    if (widgetUnderMouse && qobject_cast<QPushButton*>(widgetUnderMouse)) {
      // Mouse is over a button, do nothing
        disableMove = true;
    } else {
      // Mouse is not over a button, move the widget
        disableMove = false;
        m_nMouseClick_X_Coordinate = event->x();
        m_nMouseClick_Y_Coordinate = event->y();
    }
}

void AutoDrawer::mouseMoveEvent(QMouseEvent* event){
    if (disableMove){
        move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
    }
}

void AutoDrawer::onFileChanged(const QString& path)
{
  if (path == pathAD+"/user.cfg") {
   reloadThemes();
  }
}

void AutoDrawer::reloadThemes(){
    QFile inFile(pathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto theme = rootObj2.value("theme").toString();
    inFile.close();

    QJsonObject main;
    QJsonObject rootObj;
    if (theme == "dark") {
        QByteArray br = darkJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        main = rootObj["main"].toObject();
    } else if (theme == "light"){
        QByteArray br = lightJson.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(br);
        rootObj = doc.object();
        main = rootObj["main"].toObject();
    } else if (QFile::exists(pathAD+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(pathAD+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        main = rootObj["main"].toObject();
        inFile2.close();
    }else{
        QFile inFile(pathAD+"/user.cfg");
        inFile.open(QIODevice::ReadWrite|QIODevice::Text);
        QByteArray data = inFile.readAll();
        QJsonParseError errorPtr;
        QJsonDocument doc2 = QJsonDocument::fromJson(data, &errorPtr);
        QJsonObject doc_obj = doc2.object();
        doc_obj.insert("theme", "dark");
        QJsonDocument new_doc(doc_obj);
        inFile.resize(0);
        inFile.write(new_doc.toJson());
        inFile.close();
        //
        QByteArray br = darkJson.toUtf8();
        QJsonDocument doc3 = QJsonDocument::fromJson(br);
        rootObj = doc3.object();
        main = rootObj["main"].toObject();
    }
        QPixmap re;
        QPixmap in;
        auto lightmode = rootObj.value("light-icons").toString();
        if(lightmode=="true"){
            ui->DarkLogo->setVisible(false);
            ui->LightLogo->setVisible(true);
            re = QPixmap (":/images/images/RefreshIcon_Light.png");
            in = QPixmap (":/images/images/InfoIcon_Light.png");
        }else{
            ui->DarkLogo->setVisible(true);
            ui->LightLogo->setVisible(false);
            re = QPixmap (":/images/images/RefreshIcon.png");
            in = QPixmap (":/images/images/InfoIcon.png");
            }
        QIcon ReloadIcon(re);
        QIcon InfoIcon(in);
        ui->infoButton->setIcon(InfoIcon);
        ui->reloadButton->setIcon(ReloadIcon);
        ui->ADText->setStyleSheet("color: "+main["text"].toString());
        ui->Background->setStyleSheet("border-radius: 10px; background: "+main["background"].toString());
        ui->ImageOpt->setStyleSheet("border-radius: 10px; background-color: "+main["background-1"].toString());
        ui->ImageBackground->setStyleSheet("background-size: cover; border-radius: 10px; background-color: "+main["image-background"].toString());
        ui->ADText->setStyleSheet("color: "+main["text"].toString());
        ui->ScaleText->setStyleSheet("background: transparent; font: 11pt \"Sans Serif\"; color: "+main["text"].toString());
        ui->scaleNumber->setStyleSheet("background: "+main["background-2"].toString()+"; border-radius: 5px; font: 11pt \"Sans Serif\"; color: "+main["text"].toString());
        ui->WidthText->setStyleSheet("font: 11pt \"Sans Serif\"; color: "+main["text"].toString());
        ui->HeightText->setStyleSheet("font: 11pt \"Sans Serif\"; color: "+main["text"].toString());
        ui->ScaleText->setStyleSheet("background:transparent; border-radius: 5px; color: "+main["text"].toString());
        ui->widthBox->setStyleSheet("border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px; color: "+main["text"].toString()+"; background: "+main["width-textbox"].toString());
        ui->heightBox->setStyleSheet("border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px; color: "+main["text"].toString()+"; background: "+main["height-textbox"].toString());
        ui->exitButton->setStyleSheet("color: "+main["text"].toString());
        ui->Minimize->setStyleSheet("color: "+main["text"].toString());
        ui->btText->setStyleSheet("color: "+main["text"].toString());
        ui->intText->setStyleSheet("color: "+main["text"].toString());
        ui->ttText->setStyleSheet("color: "+main["text"].toString());
        ui->cdText->setStyleSheet("color: "+main["text"].toString());
        ui->settingButton->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["settings-info-buttons"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}QPushButton:hover {background: "+main["settings-info-buttons-hover"].toString()+";}");
        ui->infoButton->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["settings-info-buttons"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}QPushButton:hover {background: "+main["settings-info-buttons-hover"].toString()+";}");
        ui->loadConfig->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["loadconfig-button"].toString()+"; border-radius:0px;}QPushButton:hover {background: "+main["loadconfig-button-hover"].toString()+";}");
        ui->saveConfig->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["saveconfig-button"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 10px;border-bottom-left-radius: 10px;}QPushButton:hover {background: "+main["saveconfig-button-hover"].toString()+";}");
        ui->listView->setStyleSheet("color: "+main["text"].toString()+";background: "+main["config-listbox"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 10px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;");
        ui->dirButton->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["directory-buttons"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;}QPushButton:hover {background: "+main["directory-buttons-hover"].toString()+";}");
        ui->reloadButton->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["directory-buttons"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;}QPushButton:hover {background: "+main["directory-buttons-hover"].toString()+";}");
        ui->DPText->setStyleSheet("color: "+main["text"].toString());
        ui->DP->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["pattern-button"].toString()+";border-radius: 10px;}QPushButton:hover {background: "+main["pattern-button-hover"].toString()+";}");
        ui->drawingList->setStyleSheet("color: "+main["text"].toString()+";background: "+main["pattern-listbox"].toString()+";border-radius: 10px;");
        ui->intervalTextBox->setStyleSheet("color: "+main["text"].toString()+";background: "+main["textbox-backgrounds"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;");
        ui->clickDelayTextBox->setStyleSheet("color: "+main["text"].toString()+";background: "+main["textbox-backgrounds"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;");
        ui->blackThresh->setStyleSheet("color: "+main["text"].toString()+";background: "+main["textbox-backgrounds"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;");
        ui->transThresh->setStyleSheet("color: "+main["text"].toString()+";background: "+main["textbox-backgrounds"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;");
        ui->uploadImage->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["upload-buttons"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}QPushButton:hover {background: "+main["upload-buttons-hover"].toString()+";}");
        ui->clearImage->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["clear-buttons"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}QPushButton:hover {background: "+main["clear-buttons-hover"].toString()+";}");
        ui->processImage->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["process-button"].toString()+";border-radius: 0px;}QPushButton:hover {background: "+main["process-button-hover"].toString()+";}");
        ui->startButton->setStyleSheet("QPushButton{color: "+main["text"].toString()+";background: "+main["start-button"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 10px;border-bottom-left-radius: 10px;}QPushButton:hover {background: "+main["start-button-hover"].toString()+";}");
}

void AutoDrawer::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void AutoDrawer::dropEvent(QDropEvent* event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString url = QString::fromStdString(urls[0].toLocalFile().toStdString());
    //sendMessage(url +" "+ pathAD+"/themes/"+urls[0].fileName(), 1, this);
    //return;
    if (url.toStdString().find(".drawcfg") != string::npos || url.toStdString().find(".autodrawconfig") != string::npos
            || url.toStdString().find(".autodrawconfi") != string::npos || url.toStdString().find(".autodrawconf") != string::npos){loadConfig(url);}
    else if (url.toStdString().find(".drawtheme") != string::npos ){
        new ConsoleWindow("Changing theme to "+url);
        if (!QFile::copy(url, pathAD+"/themes/"+urls[0].fileName())){
            sendMessage("Permission denied to access this file or theme is already installed!", 1, this);
            return;
        }
        QString Item = urls[0].fileName().split(".").at(0);
        QFile inFile(pathAD+"/user.cfg");
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
        QApplication::closeAllWindows();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    else{
        try{
            QPixmap img(url);
            ui->heightBox->setText(QString::number(img.height()));
            ui->widthBox->setText(QString::number(img.width()));
            changeImage(img);
            ui->ImageSource->setPixmap(img);
            ui->ScaleSlider->setSliderPosition(100);
        }
        catch (const std::exception& e){
            sendMessage("Dropped file is incompatible", 2, this);
        }
    }
}

AutoDrawer::~AutoDrawer()
{
    delete ui;
}

void AutoDrawer::changeImage(QPixmap img){
    ui->ImageDrawn->setPixmap(img);
    ui->ShownImage->setPixmap(img.scaled(491, 491, Qt::KeepAspectRatio));
}

void AutoDrawer::on_ScaleSlider_sliderMoved(int position)
{
    ui->scaleNumber->setText(QString::number(position));
}


void AutoDrawer::on_exitButton_released()
{
    QCoreApplication::quit();
}

void AutoDrawer::on_Minimize_released()
{
    QWidget::showMinimized();
}

void AutoDrawer::on_pushButton_12_released()
{
    settingsWindow = new SettingsWindow(this);
    settingsWindow->show();
}


void AutoDrawer::on_startButton_released()
{
    QPixmap pm = ui->ImageDrawn->pixmap(Qt::ReturnByValue);
    if (pm.isNull()){
        return sendMessage("You have not uploaded an image to draw!", 2, this);
    } else if (ui->intervalTextBox->text().toInt() == 0 && ui->intervalTextBox->text() == ""){
        return sendMessage("Interval text is empty!", 2, this);
    } else if (ui->clickDelayTextBox->text().toInt() == 0 && ui->clickDelayTextBox->text() == ""){
        return sendMessage("Click Delay text is empty!", 2, this);
    }
    this->close();
    PreviewWindow *w = new PreviewWindow(
                pm.toImage(),
                ui->intervalTextBox->text().toInt(),
                ui->clickDelayTextBox->text().toInt(),
                this);
    w->show();
}

void AutoDrawer::on_widthBox_textEdited()
{
    QPixmap id = ui->ImageSource->pixmap(Qt::ReturnByValue);
    if (!id.isNull())
        changeImage(id.scaled(ui->widthBox->text().toInt(), ui->heightBox->text().toInt()));
}


void AutoDrawer::on_heightBox_textEdited()
{
    QPixmap id = ui->ImageSource->pixmap(Qt::ReturnByValue);
    if (!id.isNull())
        changeImage(id.scaled(ui->widthBox->text().toInt(), ui->heightBox->text().toInt()));
}

void AutoDrawer::on_pushButton_2_released()
{

}


void AutoDrawer::on_infoButton_released()
{
    infoDialog = new InfoWindow(this);
    infoDialog->show();
}


void AutoDrawer::on_settingButton_released()
{
    settingsWindow = new SettingsWindow(this);
    settingsWindow->show();
}


void AutoDrawer::on_saveConfig_released()
{
    QString filters("AutoDraw Config (*.drawcfg);;All files (*.*)");
    QString defaultFilter("AutoDraw Config (*.drawcfg)");
    QString filename = QFileDialog::getSaveFileName(0, "Save config", QDir::currentPath(),
            filters, &defaultFilter);

    if (filename.isNull()) return;
    ofstream MyFile(filename.toStdString());
    MyFile << ui->intervalTextBox->text().toStdString() + "\n" + ui->clickDelayTextBox->text().toStdString() + "\n"
              + ui->blackThresh->text().toStdString() + "\n"+ ui->transThresh->text().toStdString();
    MyFile.close();
}


void AutoDrawer::on_loadConfig_released()
{
    QString filename = QFileDialog::getOpenFileName(
                nullptr,
                QObject::tr("Open Config"),
                QDir::currentPath(),
                QObject::tr("AutoDraw Config(*.drawcfg);;All files (*.*)"));


    loadConfig(filename);
}

void AutoDrawer::loadConfig(QString filename){
    if (filename.isNull()) return;
    ifstream is(filename.toStdString());
    string line;

    vector<string> x = {};
    while (getline(is, line)) {
        x.push_back(line);
    }
    ui->intervalTextBox->setText(QString::fromStdString(x[0]));
    ui->clickDelayTextBox->setText(QString::fromStdString(x[1]));
    ui->blackThresh->setText(QString::fromStdString(x[2]));
    ui->transThresh->setText(QString::fromStdString(x[3]));
}


void AutoDrawer::on_clearImage_released()
{
    ui->ImageDrawn->clear();
    ui->ImageSource->clear();
    ui->ShownImage->clear();
    ui->heightBox->setText("");
    ui->widthBox->setText("");
    ui->ScaleSlider->setSliderPosition(100);
}


void AutoDrawer::on_processImage_released()
{
    QPixmap pm = ui->ImageSource->pixmap(Qt::ReturnByValue);
    if (pm.isNull()){
        return sendMessage("You have not uploaded an image to draw!", 2, this);
    } else if (ui->blackThresh->text().toInt() == 0 && ui->intervalTextBox->text() == ""){
        return sendMessage("Black Threshold text is empty!", 2, this);
    } else if (ui->transThresh->text().toInt() == 0 && ui->clickDelayTextBox->text() == ""){
        return sendMessage("Transparency Threshold text is empty!", 2, this);
    }else if (ui->blackThresh->text().toInt() >= 257){
        return sendMessage("Black Threshold text is too high!", 2, this);
    } else if (ui->transThresh->text().toInt() == 257){
        return sendMessage("Transparency Threshold text is too high!", 2, this);
    }
    ui->processImage->setText("Processing...");
    QImage im = pm.scaled(ui->widthBox->text().toInt(), ui->heightBox->text().toInt()).toImage().convertToFormat(QImage::Format_ARGB32);
    for (int y = 0; y < im.height(); ++y) {
        QRgb *scanLine = (QRgb*)im.scanLine(y);
        for (int x = 0; x < im.width(); ++x) {
            QRgb pixel = *scanLine;
            uint ci = uint(qGray(pixel));
            if (ci >= (unsigned int) ui->blackThresh->text().toInt() && qAlpha(pixel) >= ui->transThresh->text().toInt()){
                *scanLine = qRgba(255, 255, 255, qAlpha(pixel)/3);
            }
            else{
                *scanLine = qRgba(0, 0, 0, qAlpha(pixel)/3);
            }
            ++scanLine;
        }
    }
    changeImage(QPixmap::fromImage(im.convertToFormat(QImage::Format_Grayscale8)));
    ui->processImage->setText("Process Image");
}


void AutoDrawer::on_uploadImage_released()
{
    QString filename = QFileDialog::getOpenFileName(
                nullptr,
                QObject::tr("Open Image"),
                QDir::currentPath(),
                QObject::tr("All files (*.*)"));

    if (filename.isNull()) return;
    QString url = filename;
    QPixmap img(url);
    ui->heightBox->setText(QString::number(img.height()));
    ui->widthBox->setText(QString::number(img.width()));
    changeImage(img);
    ui->ImageSource->setPixmap(img);
    ui->ScaleSlider->setSliderPosition(100);
}

void AutoDrawer::on_reloadButton_released()
{
    ui->listView->clear();
    QFile inFile(pathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto dir = rootObj2.value("dir").toString();
    inFile.close();

    QStringList list;
    QDirIterator it(dir, QStringList() << "*.drawcfg");
    while (it.hasNext()){
        it.next();
        list << it.fileName().replace(".drawcfg", "");
    }
    ui->listView->addItems(list);
}

void AutoDrawer::on_dirButton_released()
{
    QString filename = QFileDialog::getExistingDirectory(0, "Choose a directory", QDir::currentPath());
    if (filename.isNull()) return;
    QFile inFile(pathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("dir", filename);
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    on_reloadButton_released();
}

void AutoDrawer::on_listView_itemClicked(QListWidgetItem *item)
{
    QString Item = item->text();
    //ui->listView->clear();
    QFile inFile(pathAD+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto dir = rootObj2.value("dir").toString();
    if (!QFile::exists(dir+"/"+Item+".drawcfg")) return;
    loadConfig(dir+"/"+Item+".drawcfg");
    //on_reloadButton_released();
}


void AutoDrawer::on_drawingList_itemClicked(QListWidgetItem *item)
{
    int Item = item->text().split("-")[1].toInt();
    QFile inFile(pathAD+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject doc_obj = doc.object();
    doc_obj.insert("pattern", Item);
    QJsonDocument new_doc(doc_obj);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    on_reloadButton_released();
}

void AutoDrawer::on_DP_released()
{
    custompattern *c = new custompattern();
    c->show();
}

void AutoDrawer::on_ScaleSlider_sliderReleased()
{
    if (ui->ScaleSlider->value() > 200){ui->ScaleSlider->setMaximum(ui->scaleNumber->text().toInt());} else {ui->ScaleSlider->setMaximum(200);}
    QPixmap pm = ui->ImageSource->pixmap(Qt::ReturnByValue);
    float value = ui->ScaleSlider->value();
    ui->heightBox->setText(QString::number(((pm.height()/100)*value)));
    ui->widthBox->setText(QString::number((pm.width()/100)*value));
    on_heightBox_textEdited();
    on_widthBox_textEdited();
}

void AutoDrawer::on_scaleNumber_textEdited()
{
    if (ui->scaleNumber->text().toInt() > 200){ui->ScaleSlider->setMaximum(ui->scaleNumber->text().toInt());} else {ui->ScaleSlider->setMaximum(200);}
    ui->ScaleSlider->setSliderPosition(ui->scaleNumber->text().toInt());
    on_ScaleSlider_sliderReleased();
}
