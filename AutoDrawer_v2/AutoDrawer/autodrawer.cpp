#include "autodrawer.h"
#include "./ui_autodrawer.h"
#include "custompattern.h"
#include "infowindow.h"
#include "messagewindow.h"
#include "previewwindow.h"
#include "qdiriterator.h"
#include "qjsonarray.h"
#include "qjsondocument.h"
#include "consolewindow.h"
#include "qjsonobject.h"
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
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
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
    on_reloadButton_released();
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
            re.loadFromData(QByteArray::fromBase64("iVBORw0KGgoAAAANSUhEUgAAAAwAAAAMCAMAAABhq6zVAAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAABOFBMVEX8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vsAAAD8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv8/vv/////JpyKAAAAZnRSTlMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABuD3f393YMbLMHzvIuKu/PALCEbwOJXCQlW4c/Lg/FXcv7XuQstxvv5QyomS0dFR0s5BPn631QBhQHS0uBWCSQtwfO8iou88xuD3f1UQIzsAAAAAWJLR0RnW9PpswAAAAd0SU1FB+YGGwowA09JlZ4AAACdSURBVAjXBcEFAoIADADAoSjMxO7CLrC7sbu7g/8/wTsAwu5wutwer08iBZL1B4KhcCQaiycgyfGptEyeyebyBSiWyhSNqFBWqiLU6g0VolrTbLU7IHS1DKJO3+sPhjAcjSdTAyKj7Qowmy+WKyOiqlGvgSiuNyZEmiqXirDd7Q9HsyWd4rkknM6X6+3+eL78LAlW2/vz/bmcDjsBf9v2GcBrLAxCAAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDIyLTA2LTI3VDEwOjQ4OjAzLTA0OjAwwAdwBAAAACV0RVh0ZGF0ZTptb2RpZnkAMjAyMi0wNi0yN1QxMDo0ODowMy0wNDowMLFayLgAAAAASUVORK5CYII="));
            in.loadFromData(QByteArray::fromBase64("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"));
        }else{
            ui->DarkLogo->setVisible(true);
            ui->LightLogo->setVisible(false);
            re.loadFromData(QByteArray::fromBase64("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"));
            in.loadFromData(QByteArray::fromBase64("iVBORw0KGgoAAAANSUhEUgAAAgAAAAIACAYAAAD0eNT6AAAAAXNSR0IArs4c6QAAIABJREFUeF7tnQm8d9X0/9//5jklZSjSRIqUSkllaFAolUSkQSWEMiaUSpS5zE1EhIRQmlEUMkVSRFE/QqV5jv/r07Ov7jPc536/Z9rTZ71e93UfOnuvtd9r33PWOXvvtf4fFhMwARMwARMwgeoI/L/qRuwBm4AJmIAJmIAJ4ADAk8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwARMwARMwAQqJOAAoEKne8gmYAImYAIm4ADAc8AETMAETMAEKiTgAKBCp3vIJmACJmACJuAAwHPABEzABEzABCok4ACgQqd7yCZgAiZgAibgAMBzwATyIvAI4FHAcsBSwNJz+L04sCQwz1x+TzXqW4D/ALcC94bfdwF3h3/fDtwYfm4A/jXp3/r//xna50XV1ppAhQQcAFTodA85WQILAo8H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Eb5Vm4AJmIAJmEAsAg4AYpG3XhMwARMwAROISMABQET4Vm0CJmACJmACsQg4AIhF3npNwARMwARMICIBBwAR4Vu1CZiACZiACcQi4AAgFnnrNQETMAETMIGIBBwARIRv1SZgAiZgAiYQi4ADgFjkrdcETMAETMAEIhJwABARvlWbgAmYgAmYQCwCDgBikbdeEzABEzABE4hIwAFARPhWbQImYAImYAKxCDgAiEXeek3ABEzABEwgIgEHABHhW7UJmIAJmIAJxCLgACAWees1ARMwARMwgYgEHABEhG/VJmACJmACJhCLgAOAWOSt1wRMwARMwAQiEnAAEBG+VZuACZiACZhALAIOAGKRt14TMAETMAETiEjAAUBE+FZtAiZgAiZgArEIOACIRd56TcAETMAETCAiAQcAEeFbtQmYgAmYgAnEIuAAIBZ56zUBEzABEzCBiAQcAESEb9UmYAImYAImEIuAA4BY5K3XBEzABEzABCIScAAQEb5Vm4AJmIAJmEAsAg4AYpG3XhMwARMwAROISMABQET4Vm0CJmACJmACsQg4AIhF3npNwARMwARMICIBBwAR4Vu1CZiACZiACcQi4AAgFnnrNQETMAETMIGIBBwARIRv1SZgAiZgAiYQi4ADgFjkrdcETMAETMAEIhJwABARvlWbgAmYgAmYQCwCDgBikbdeEzABEzABE4hIwAFARPhWbQImYAImYAKxCDgAiEXeek3ABEzABEwgIgEHABHhW7UJmIAJmIAJxCLw/wGG62mXaXiylAAAAABJRU5ErkJggg=="));
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
    string url = urls[0].toString().toStdString();
    cout << url;
    if (url.find(".drawcfg") != string::npos || url.find(".autodrawconfig") != string::npos
            || url.find(".autodrawconfi") != string::npos || url.find(".autodrawconf") != string::npos){

        ifstream is(url);
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
    else{
        try{
            QString url2 = urls[0].toString();
            QPixmap img(url2);
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

void AutoDrawer::on_ScaleSlider_sliderReleased()
{
    QPixmap pm = ui->ImageSource->pixmap(Qt::ReturnByValue);
    if (pm.isQBitmap()){
        float value = ui->ScaleSlider->value() / 100;
        ui->heightBox->setText(QString::number(ui->heightBox->text().toInt()*value));
        ui->widthBox->setText(QString::number(ui->widthBox->text().toInt()*value));
        on_heightBox_textEdited();
        on_widthBox_textEdited();
    }
}


void AutoDrawer::on_scaleNumber_textEdited()
{
    ui->ScaleSlider->setSliderPosition(ui->scaleNumber->text().toInt());
}


void AutoDrawer::on_exitButton_released()
{
    QCoreApplication::quit();
}

void AutoDrawer::on_ScaleSlider_valueChanged(int value)
{
    ui->scaleNumber->setText(QString::number(value));
    qApp->processEvents();
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

