#include "autodrawer.h"
#include "./ui_autodrawer.h"
#include "infowindow.h"
#include "messagewindow.h"
#include "previewwindow.h"
#include <qapplication.h>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QDragEnterEvent>
#include <QMimeData>

using namespace std;

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
}

static void sendMessage(QString a, int b, QWidget *t){
    //1 for info, 2 for error, 3 for alert
    MessageWindow *w = new MessageWindow(a, b, t);
    w->show();
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
    QApplication::quit();
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

void AutoDrawer::on_pushButton_3_released()
{
    QString filename = QFileDialog::getOpenFileName(
                nullptr,
                QObject::tr("Open Config"),
                QDir::currentPath(),
                QObject::tr("AutoDraw Config(*.drawcfg);;All files (*.*)"));


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


void AutoDrawer::on_pushButton_6_released()
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


void AutoDrawer::on_pushButton_7_released()
{
    ui->ImageDrawn->clear();
    ui->ImageSource->clear();
    ui->ShownImage->clear();
    ui->heightBox->setText("");
    ui->widthBox->setText("");
    ui->ScaleSlider->setSliderPosition(100);
}


void AutoDrawer::on_pushButton_5_released()
{
    infoDialog = new InfoWindow(this);
    infoDialog->show();
}


void AutoDrawer::on_pushButton_released()
{
    settingsWindow = new SettingsWindow(this);
    settingsWindow->show();
}

void AutoDrawer::on_pushButton_12_released()
{
    settingsWindow = new SettingsWindow(this);
    settingsWindow->show();
}


void AutoDrawer::on_pushButton_9_released()
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

void AutoDrawer::on_pushButton_8_released()
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
    ui->pushButton_8->setText("Processing...");
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
    ui->pushButton_8->setText("Process Image");
}


void AutoDrawer::on_pushButton_4_released()
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

