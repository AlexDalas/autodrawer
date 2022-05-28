#include "messagewindow.h"
#include "ui_messagewindow.h"

MessageWindow::MessageWindow(QString text, int type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    if (type == 1){
        ui->Header->setText("Info");
    } else if (type == 2){
        ui->Header->setText("Error");
    }else if (type == 3){
        ui->Header->setText("Alert");
    }
    ui->Text->setText(text);
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::on_pushButton_6_released()
{
    this->close();
}

