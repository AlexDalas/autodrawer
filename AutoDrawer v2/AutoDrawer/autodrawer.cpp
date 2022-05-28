#include "autodrawer.h"
#include "./ui_autodrawer.h"
#include "infowindow.h"
#include "messagewindow.h"
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
}

void AutoDrawer::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void AutoDrawer::dropEvent(QDropEvent* event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty()) return;
    std::ifstream is(urls.first().path().toUtf8());
    std::string line;
    std::vector<std::string> x = {};
    while (getline(is, line)) x.push_back(line);
    ui->intervalTextBox->setText(QString::fromStdString(x[0])); ui->clickDelayTextBox->setText(QString::fromStdString(x[1]));
    ui->blackThresh->setText(QString::fromStdString(x[2])); ui->transThresh->setText(QString::fromStdString(x[3]));
}

AutoDrawer::~AutoDrawer()
{
    delete ui;
}

void AutoDrawer::on_ScaleSlider_sliderMoved(int position)
{
    ui->scaleNumber->setText(QString::number(position));
}

void AutoDrawer::on_ScaleSlider_sliderReleased()
{
    auto value = ui->ScaleSlider->value();
    QImage img = ui->ImageFrame->pixmap()->toImage();
    QImage img2 = img.scaled(img.width() * value, img.height() * value, Qt::KeepAspectRatio);
    ui->ImageFrame->setPixmap(QPixmap::fromImage(img2));
    return;
}


void AutoDrawer::on_scaleNumber_textEdited(const QString &arg1)
{
    ui->ScaleSlider->setSliderPosition(ui->scaleNumber->text().toInt());
}


void AutoDrawer::on_exitButton_released()
{
    QApplication::quit();
}

// do not know how to delete. pls delete without error
void AutoDrawer::on_exitButton_2_released()
{
    QWidget::showMinimized();
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
    std::ifstream is(filename.toStdString());
    std::string line;

    std::vector<std::string> x = {};
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
    QLabel *label = new QLabel(this);
    ui->heightBox->setText(QString::number(img.height()));
    ui->widthBox->setText(QString::number(img.width()));
    ui->ImageFrame->setPixmap(img);
}


void AutoDrawer::on_pushButton_7_released()
{
    ui->ImageFrame->clear();
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

}


void AutoDrawer::on_pushButton_8_released()
{
    //QImage img = ui->ImageFrame->pixmap()->toImage();
    //If image exists
    if (false){

    }
    else{
        MessageWindow *w = new MessageWindow("You have not uploaded an image to process!", 1, this);
        w->show();
    }
}


void AutoDrawer::on_widthBox_textChanged(const QString &arg1)
{
    auto value = ui->ScaleSlider->value();
    QImage img = ui->ImageFrame->pixmap()->toImage();
    img.size() = QSize(ui->ImageFrame->width(), arg1.toInt());
    ui->ImageFrame->setPixmap(QPixmap::fromImage(img));
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

