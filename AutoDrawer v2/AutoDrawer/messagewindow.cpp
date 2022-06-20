#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "autodrawer.h"
int result;
MessageWindow::MessageWindow(QString text, int type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    this->window()->raise();
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    if (type == 1){
        ui->Header->setText("Info");
        buttonType(0);
    } else if (type == 2){
        ui->Header->setText("Error");
        buttonType(0);
    }else if (type == 3){
        ui->Header->setText("Alert");
        buttonType(0);
    }else if (type == 4){
        //Only to be used in context of drawing finished
        ui->Header->setText("Success");
        buttonType(1);
    }else if (type == 5){
        //Only to be used in context of drawing stopped
        ui->Header->setText("Stopped");
        buttonType(1);
    }
    ui->Text->setText(text);
}

void MessageWindow::buttonType(int a){
    if (a==1) {
        ui->pushButton_6->hide();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
    }else{
        ui->pushButton_6->show();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
    }
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::on_pushButton_6_released()
{
    this->close();
}

void MessageWindow::on_pushButton_8_released()
{
    this->close();
    AutoDrawer *w = new AutoDrawer();
    w->showMinimized();
}

void MessageWindow::on_pushButton_7_released()
{
    this->close();
    AutoDrawer *w = new AutoDrawer();
    w->show();
}


void MessageWindow::on_pushButton_9_released()
{
    QApplication::quit();
}

