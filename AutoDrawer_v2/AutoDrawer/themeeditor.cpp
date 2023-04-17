#include "themeeditor.h"
#include "qevent.h"
#include "qjsonobject.h"
#include "ui_themeeditor.h"
#include "consolewindow.h"
#include <QFileDialog>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QFile>

auto PathAUTD = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";

QString themesrc = "{" \
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

QJsonDocument theme = QJsonDocument::fromJson(themesrc.toUtf8());

ThemeEditor::ThemeEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowFullscreenButtonHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    new ConsoleWindow("Opened theme editor.");
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    on_Exit_3_released();
    updateText(themesrc.toUtf8());
    updateTheme();
}

int m_nMouseClick_X_Coordinate8;
int m_nMouseClick_Y_Coordinate8;

void ThemeEditor::mousePressEvent(QMouseEvent* event){
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  m_nMouseClick_X_Coordinate8 = event->x();
  m_nMouseClick_Y_Coordinate8 = event->y();
#else
    m_nMouseClick_X_Coordinate8 = event->position().x();
    m_nMouseClick_Y_Coordinate8 = event->position().y();
#endif
  //qDebug() << m_nMouseClick_X_Coordinate;
  //qDebug() << m_nMouseClick_Y_Coordinate;
}

void ThemeEditor::mouseMoveEvent(QMouseEvent* event){
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
        #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        move(event->globalX()-m_nMouseClick_X_Coordinate8,event->globalY()-m_nMouseClick_Y_Coordinate8);
        #else
        move(event->globalPosition().x()-m_nMouseClick_X_Coordinate8,event->globalPosition().y()-m_nMouseClick_Y_Coordinate8);
        #endif
    }
}

void ThemeEditor::updateTheme(){
    QJsonObject otheme = theme.object();
    auto main = otheme.value("main");
    auto settings = otheme.value("settings");
    auto info = otheme.value("info");
    auto preview = otheme.value("preview");
    auto pattern = otheme.value("pattern");
    auto console = otheme["console"].toObject();

    QPixmap re;
    QPixmap in;
    auto lightmode = otheme.value("light-icons").toString();
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
    ui->Main->setStyleSheet("border-radius: 10px; background: "+main["background"].toString());
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

    ui->Reload->setIcon(ReloadIcon);
    ui->Header->setStyleSheet("color: "+settings["text"].toString());
    ui->CloseBox->setStyleSheet("color: "+settings["text"].toString()+"; border-radius: 10px; background: "+settings["buttons"].toString());
    ui->Console->setStyleSheet("color: "+settings["text"].toString()+"; border-top-left-radius: 20px; border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+settings["buttons"].toString());
    ui->ThemeEditorBTN->setStyleSheet("color: "+settings["text"].toString()+"; border-radius: 0px; background: "+settings["buttons"].toString());
    ui->OpenLogs->setStyleSheet("color: "+settings["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 20px;border-bottom-right-radius: 0px;border-bottom-left-radius: 0px; background: "+settings["buttons"].toString());
    ui->CloseBox->setStyleSheet("color: "+settings["text"].toString()+"; border-radius: 10px; background: "+settings["close"].toString());
    ui->Discord->setStyleSheet("color: "+settings["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 20px; background: "+settings["buttons"].toString());
    ui->LR->setStyleSheet("color: "+settings["text"].toString()+"; border-radius: 0px; background: "+settings["buttons"].toString());
    ui->GH->setStyleSheet("color: "+settings["text"].toString()+"; border-top-left-radius: 0px;border-top-right-radius: 0px;border-bottom-right-radius: 20px;border-bottom-left-radius: 0px; background: "+settings["buttons"].toString());
    ui->frame->setStyleSheet("border-radius: 25px; background: "+settings["textbox"].toString());
    ui->OffsetBox->setStyleSheet("background:transparent;color: "+settings["text"].toString());
    ui->LogBox->setStyleSheet("background:transparent;color: "+settings["text"].toString());
    ui->PrinterBox->setStyleSheet("background:transparent;color: "+settings["text"].toString());
    ui->OpenThemes->setStyleSheet("color: "+settings["text"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+settings["buttons"].toString());
    ui->Reload->setStyleSheet("color: "+settings["text"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+settings["buttons"].toString());
    ui->intervalTextBox_27->setStyleSheet("color: "+settings["text"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-right-radius: 0px;border-bottom-left-radius: 10px;background: "+settings["buttons"].toString());
    ui->intervalTextBox_89->setStyleSheet("color: "+settings["text"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-right-radius: 10px;border-bottom-left-radius: 0px;background: "+settings["buttons"].toString());
    ui->SettingsMenu->setStyleSheet("border-radius: 25px; background: "+settings["background"].toString());
    ui->offsetPos->setStyleSheet("color: "+settings["text"].toString());
    ui->X->setStyleSheet("color: "+settings["text"].toString());
    ui->Y->setStyleSheet("color: "+settings["text"].toString());
    ui->opt->setStyleSheet("color: "+settings["text"].toString());
    ui->themes->setStyleSheet("color: "+settings["text"].toString());
    ui->ThemeCombo->setStyleSheet("background: "+settings["buttons"].toString()+"; color: "+settings["text"].toString());

    ui->TextINF->setStyleSheet("color: "+info["text"].toString());
    ui->HeaderINF->setStyleSheet("color: "+info["text"].toString());
    ui->ButtonINF->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->BackgroundINF->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());
    ui->TextINFO->setStyleSheet("color: "+info["text"].toString());
    ui->HeaderINFO->setStyleSheet("color: "+info["text"].toString());
    ui->ButtonINFO->setStyleSheet("background: "+info["close"].toString()+"; border-radius: 10px; color: "+info["text"].toString());
    ui->BackgroundINFO->setStyleSheet("border-radius: 25px; background: "+info["background"].toString());

    ui->Header_3->setStyleSheet("color: "+preview["text"].toString());
    ui->Background_3->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());

    if (lightmode == "true"){ui->Image->setPixmap(QPixmap(":/images/images/pattern.png"));} else {ui->Image->setPixmap(QPixmap(":/images/images/pattern_black.png"));}
    ui->ClosePTN->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["close"].toString()+";border-radius: 10px;");
    ui->TextInt->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["textbox"].toString()+";border-top-left-radius: 10px;border-top-right-radius: 0px;border-bottom-left-radius: 10px;border-bottom-right-radius: 0px;");
    ui->Submit->setStyleSheet("color: "+pattern["text"].toString()+";background: "+pattern["button"].toString()+";border-top-left-radius: 0px;border-top-right-radius: 10px;border-bottom-left-radius: 0px;border-bottom-right-radius: 10px;");
    ui->Background_4->setStyleSheet("background: "+pattern["background"].toString()+";border-radius:25px;");
    ui->ImageBackgroundPTN->setStyleSheet("border-radius: 25px; background: "+pattern["image-background"].toString());
    ui->Header_4->setStyleSheet("color: "+pattern["text"].toString());
    ui->Footer->setStyleSheet("color: "+pattern["text"].toString());
    ui->Footer2->setStyleSheet("color: "+pattern["text"].toString());

    ui->Exit_6->setStyleSheet("color: "+console["text"].toString()+";background: "+console["close"].toString()+";border-radius: 10px;");
    ui->Exit_7->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Exit_8->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Exit_9->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->Exit_10->setStyleSheet("color: "+console["text"].toString()+";background: "+console["button"].toString()+";border-radius: 10px;");
    ui->ConsoleWND->setStyleSheet("background: "+console["background"].toString()+";border-radius:25px;");
    ui->listWidget->setStyleSheet("background: "+console["console-background"].toString()+";border-radius:10px;");
}

void ThemeEditor::on_Upload_released()
{
    QString filename = QFileDialog::getOpenFileName(
                nullptr,
                QObject::tr("Open Theme"),
                PathAUTD+"/themes",
                QObject::tr("AutoDraw Theme (*.drawtheme);;All files (*.*)"));

    if (filename.isNull()) return;
    QFile inFile(filename);
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    updateText(inFile.readAll());
    inFile.close();
    updateTheme();
}

void ThemeEditor::updateText(QByteArray data){
    QJsonParseError errorPtr;
    auto mpTheme = QJsonDocument::fromJson(data, &errorPtr);
    auto impTheme = mpTheme.object();
    auto main = impTheme.value("main");
    auto settings = impTheme.value("settings");
    auto info = impTheme.value("info");
    auto preview = impTheme.value("preview");
    auto pattern = impTheme.value("pattern");
    auto console = impTheme.value("console");

    //if the icons are one colour, set the text of the button to the opposite, then trigger a button click, which would swap the colours to the theme's colour.
    if (impTheme["light-icons"].toString() == "true") { ui->buttonColour->setText("Black");} else{ui->buttonColour->setText("White");}
    on_buttonColour_released();
    //it's designed in a way that it edits the text instead of overwriting the themes file, as a measure of verifying all the textboxes work.
    //it also fills in the textboxes, which is very necessary.
    ui->intervalTextBox_2->setText(main["text"].toString());
    ui->intervalTextBox_4->setText(main["background"].toString());
    ui->intervalTextBox_6->setText(main["background-1"].toString());
    ui->intervalTextBox_5->setText(main["background-2"].toString());
    ui->intervalTextBox_8->setText(main["image-background"].toString());
    ui->intervalTextBox_20->setText(main["textbox-backgrounds"].toString());
    ui->intervalTextBox_29->setText(main["scalebar-background"].toString());
    ui->intervalTextBox_7->setText(main["config-listbox"].toString());
    ui->intervalTextBox_32->setText(main["pattern-listbox"].toString());
    ui->intervalTextBox_26->setText(main["scale-textbox"].toString());
    ui->intervalTextBox_34->setText(main["width-textbox"].toString());
    ui->intervalTextBox_35->setText(main["height-textbox"].toString());
    ui->intervalTextBox_10->setText(main["loadconfig-button"].toString());
    ui->intervalTextBox_13->setText(main["loadconfig-button-hover"].toString());
    ui->intervalTextBox_12->setText(main["saveconfig-button"].toString());
    ui->intervalTextBox_11->setText(main["saveconfig-button-hover"].toString());
    ui->intervalTextBox_14->setText(main["settings-info-buttons"].toString());
    ui->intervalTextBox_15->setText(main["settings-info-buttons-hover"].toString());
    ui->intervalTextBox_16->setText(main["pattern-button"].toString());
    ui->intervalTextBox_17->setText(main["pattern-button-hover"].toString());
    ui->intervalTextBox_19->setText(main["directory-buttons"].toString());
    ui->intervalTextBox_18->setText(main["directory-buttons-hover"].toString());
    ui->intervalTextBox_21->setText(main["upload-buttons"].toString());
    ui->intervalTextBox_22->setText(main["upload-buttons-hover"].toString());
    ui->intervalTextBox_24->setText(main["clear-buttons"].toString());
    ui->intervalTextBox_23->setText(main["clear-buttons-hover"].toString());
    ui->intervalTextBox_30->setText(main["process-button"].toString());
    ui->intervalTextBox_25->setText(main["process-button-hover"].toString());
    ui->intervalTextBox_31->setText(main["start-button"].toString());
    ui->intervalTextBox_33->setText(main["start-button-hover"].toString());
    ui->intervalTextBox_68->setText(settings["text"].toString());
    ui->intervalTextBox_69->setText(settings["background"].toString());
    ui->intervalTextBox_70->setText(settings["buttons"].toString());
    ui->intervalTextBox_28->setText(settings["textbox"].toString());
    ui->intervalTextBox_72->setText(settings["checkbox-box"].toString());
    ui->intervalTextBox_71->setText(settings["close"].toString());
    ui->intervalTextBox_74->setText(preview["text"].toString());
    ui->intervalTextBox_75->setText(preview["background"].toString());
    ui->intervalTextBox_76->setText(info["text"].toString());
    ui->intervalTextBox_77->setText(info["background"].toString());
    ui->intervalTextBox_78->setText(info["close"].toString());
    ui->intervalTextBox_81->setText(pattern["text"].toString());
    ui->intervalTextBox_90->setText(pattern["background"].toString());
    ui->intervalTextBox_87->setText(pattern["image-background"].toString());
    ui->intervalTextBox_80->setText(pattern["button"].toString());
    ui->intervalTextBox_83->setText(pattern["textbox"].toString());
    ui->intervalTextBox_79->setText(pattern["close"].toString());
    ui->intervalTextBox_84->setText(console["text"].toString());
    ui->intervalTextBox_86->setText(pattern["background"].toString());
    ui->intervalTextBox_82->setText(console["console-background"].toString());
    ui->intervalTextBox_85->setText(console["button"].toString());
    ui->intervalTextBox_88->setText(console["close"].toString());
}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

void ThemeEditor::on_Exit_2_released()
{
    this->close();
}

void ThemeEditor::on_ScaleSlider_valueChanged(int value)
{
    ui->scaleNumber->setText(QString::number(value));
}

void ThemeEditor::on_Exit_released()
{
    QString filters("AutoDraw Theme (*.drawtheme);;All files (*.*)");
    QString defaultFilter("AutoDraw Theme (*.drawtheme)");
    QString filename = QFileDialog::getSaveFileName(0, "Save config", PathAUTD+"/themes",
            filters, &defaultFilter);

    if (filename.isNull()) return;
    QFile ourJson(QString::fromStdString(filename.toStdString()));
    ourJson.open(QFile::WriteOnly);
    ourJson.write(theme.toJson());
    ourJson.close();
}

void ThemeEditor::on_ButtonINF_released()
{
    QStringList avaliableEntries; avaliableEntries << "Info" << "Error" << "Alert" << "Success" << "Stopped";
    if (avaliableEntries.indexOf(ui->HeaderINF->text())+1 == 5){
        ui->HeaderINF->setText(avaliableEntries[avaliableEntries.indexOf("Info")]); }
    else{ ui->HeaderINF->setText(avaliableEntries[avaliableEntries.indexOf(ui->HeaderINF->text())+1]);}
}

void ThemeEditor::hideAll(){
    ui->Main->setVisible(false);
    ui->Settings->setVisible(false);
    ui->IPP->setVisible(false);
    ui->Exit_3->setEnabled(true);
    ui->Exit_4->setEnabled(true);
    ui->Exit_5->setEnabled(true);
}

void ThemeEditor::on_Exit_3_released()
{
    hideAll();
    ui->Main->setVisible(true);
    ui->Exit_3->setEnabled(false);
}


void ThemeEditor::on_Exit_4_released()
{
    hideAll();
    ui->Settings->setVisible(true);
    ui->Exit_4->setEnabled(false);
}


void ThemeEditor::on_Exit_5_released()
{
    hideAll();
    ui->IPP->setVisible(true);
    ui->Exit_5->setEnabled(false);
}

void ThemeEditor::changeValue(QString objED, QString branED, QLineEdit* Obj){
    QJsonObject root = theme.object();
    auto edit = root[branED].toObject();
    edit[objED] = Obj->text();
    root[branED] = edit;
    theme.setObject(root);
    updateTheme();
}

void ThemeEditor::on_intervalTextBox_3_textChanged()
{
    QJsonObject root = theme.object();
    root["ver"] = ui->intervalTextBox_3->text().toFloat();
    theme.setObject(root);
    updateTheme();
}

void ThemeEditor::on_buttonColour_released()
{
    if (ui->buttonColour->text() == "White") {
        QJsonObject root = theme.object();
        root["light-icons"] = "false";
        theme.setObject(root);
        updateTheme();
        ui->buttonColour->setText("Black");
    } else{
        QJsonObject root = theme.object();
        root["light-icons"] = "true";
        theme.setObject(root);
        updateTheme();
        ui->buttonColour->setText("White");
    }
}

void ThemeEditor::on_intervalTextBox_2_textChanged(){changeValue("text", "main", ui->intervalTextBox_2);}
void ThemeEditor::on_intervalTextBox_4_textChanged(){changeValue("background", "main", ui->intervalTextBox_4);}
void ThemeEditor::on_intervalTextBox_6_textChanged(){changeValue("background-1", "main", ui->intervalTextBox_6);}
void ThemeEditor::on_intervalTextBox_5_textChanged(){changeValue("background-2", "main", ui->intervalTextBox_5);}
void ThemeEditor::on_intervalTextBox_8_textChanged(){changeValue("image-background", "main", ui->intervalTextBox_8);}
void ThemeEditor::on_intervalTextBox_20_textChanged(){changeValue("textbox-backgrounds", "main", ui->intervalTextBox_20);}
void ThemeEditor::on_intervalTextBox_29_textChanged(){changeValue("scalebar-background", "main", ui->intervalTextBox_29);}
void ThemeEditor::on_intervalTextBox_7_textChanged(){changeValue("config-listbox", "main", ui->intervalTextBox_7);}
void ThemeEditor::on_intervalTextBox_32_textChanged(){changeValue("pattern-listbox", "main", ui->intervalTextBox_32);}
void ThemeEditor::on_intervalTextBox_26_textChanged(){changeValue("scale-textbox", "main", ui->intervalTextBox_26);}
void ThemeEditor::on_intervalTextBox_34_textChanged(){changeValue("width-textbox", "main", ui->intervalTextBox_34);}
void ThemeEditor::on_intervalTextBox_35_textChanged(){changeValue("height-textbox", "main", ui->intervalTextBox_35);}
void ThemeEditor::on_intervalTextBox_10_textChanged(){changeValue("loadconfig-button", "main", ui->intervalTextBox_10);}
void ThemeEditor::on_intervalTextBox_13_textChanged(){changeValue("loadconfig-button-hover", "main", ui->intervalTextBox_13);}
void ThemeEditor::on_intervalTextBox_12_textChanged(){changeValue("saveconfig-button", "main", ui->intervalTextBox_12);}
void ThemeEditor::on_intervalTextBox_11_textChanged(){changeValue("saveconfig-button-hover", "main", ui->intervalTextBox_11);}
void ThemeEditor::on_intervalTextBox_14_textChanged(){changeValue("settings-info-buttons", "main", ui->intervalTextBox_14);}
void ThemeEditor::on_intervalTextBox_15_textChanged(){changeValue("settings-info-buttons-hover", "main", ui->intervalTextBox_15);}
void ThemeEditor::on_intervalTextBox_16_textChanged(){changeValue("pattern-button", "main", ui->intervalTextBox_16);}
void ThemeEditor::on_intervalTextBox_17_textChanged(){changeValue("pattern-button-hover", "main", ui->intervalTextBox_17);}
void ThemeEditor::on_intervalTextBox_19_textChanged(){changeValue("directory-buttons", "main", ui->intervalTextBox_19);}
void ThemeEditor::on_intervalTextBox_18_textChanged(){changeValue("directory-buttons-hover", "main", ui->intervalTextBox_18);}
void ThemeEditor::on_intervalTextBox_21_textChanged(){changeValue("upload-buttons", "main", ui->intervalTextBox_21);}
void ThemeEditor::on_intervalTextBox_22_textChanged(){changeValue("upload-buttons-hover", "main", ui->intervalTextBox_22);}
void ThemeEditor::on_intervalTextBox_24_textChanged(){changeValue("clear-buttons", "main", ui->intervalTextBox_24);}
void ThemeEditor::on_intervalTextBox_23_textChanged(){changeValue("clear-buttons-hover", "main", ui->intervalTextBox_23);}
void ThemeEditor::on_intervalTextBox_30_textChanged(){changeValue("process-button", "main", ui->intervalTextBox_30);}
void ThemeEditor::on_intervalTextBox_25_textChanged(){changeValue("process-button-hover", "main", ui->intervalTextBox_25);}
void ThemeEditor::on_intervalTextBox_31_textChanged(){changeValue("start-button", "main", ui->intervalTextBox_31);}
void ThemeEditor::on_intervalTextBox_33_textChanged(){changeValue("start-button-hover", "main", ui->intervalTextBox_33);}
void ThemeEditor::on_intervalTextBox_68_textChanged(){changeValue("text", "settings", ui->intervalTextBox_68);}
void ThemeEditor::on_intervalTextBox_69_textChanged(){changeValue("background", "settings", ui->intervalTextBox_69);}
void ThemeEditor::on_intervalTextBox_70_textChanged(){changeValue("buttons", "settings", ui->intervalTextBox_70);}
void ThemeEditor::on_intervalTextBox_28_textChanged(){changeValue("textbox", "settings", ui->intervalTextBox_28);}
void ThemeEditor::on_intervalTextBox_72_textChanged(){changeValue("checkbox-box", "settings", ui->intervalTextBox_72);}
void ThemeEditor::on_intervalTextBox_71_textChanged(){changeValue("close", "settings", ui->intervalTextBox_71);}
void ThemeEditor::on_intervalTextBox_74_textChanged(){changeValue("text", "preview", ui->intervalTextBox_74);}
void ThemeEditor::on_intervalTextBox_75_textChanged(){changeValue("background", "preview", ui->intervalTextBox_75);}
void ThemeEditor::on_intervalTextBox_76_textChanged(){changeValue("text", "info", ui->intervalTextBox_76);}
void ThemeEditor::on_intervalTextBox_77_textChanged(){changeValue("background", "info", ui->intervalTextBox_77);}
void ThemeEditor::on_intervalTextBox_78_textChanged(){changeValue("close", "info", ui->intervalTextBox_78);}
void ThemeEditor::on_intervalTextBox_81_textChanged(){changeValue("text", "pattern", ui->intervalTextBox_81);}
void ThemeEditor::on_intervalTextBox_90_textChanged(){changeValue("background", "pattern", ui->intervalTextBox_90);}
void ThemeEditor::on_intervalTextBox_87_textChanged(){changeValue("image-background", "pattern", ui->intervalTextBox_87);}
void ThemeEditor::on_intervalTextBox_80_textChanged(){changeValue("button", "pattern", ui->intervalTextBox_80);}
void ThemeEditor::on_intervalTextBox_83_textChanged(){changeValue("textbox", "pattern", ui->intervalTextBox_83);}
void ThemeEditor::on_intervalTextBox_79_textChanged(){changeValue("close", "pattern", ui->intervalTextBox_79);}
void ThemeEditor::on_intervalTextBox_84_textChanged(){changeValue("text", "console", ui->intervalTextBox_84);}
void ThemeEditor::on_intervalTextBox_86_textChanged(){changeValue("background", "console", ui->intervalTextBox_86);}
void ThemeEditor::on_intervalTextBox_82_textChanged(){changeValue("console-background", "console", ui->intervalTextBox_82);}
void ThemeEditor::on_intervalTextBox_85_textChanged(){changeValue("button", "console", ui->intervalTextBox_85);}
void ThemeEditor::on_intervalTextBox_88_textChanged(){changeValue("close", "console", ui->intervalTextBox_88);}
void ThemeEditor::on_Exit_11_released(){this->showMinimized();}


