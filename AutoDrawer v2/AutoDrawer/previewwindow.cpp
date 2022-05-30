#include "previewwindow.h"
#include "ui_previewwindow.h"

PreviewWindow::PreviewWindow(QImage image, int interval, int clickdelay, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ui->ShownImage->setPixmap(QPixmap::fromImage(image));
    if (image.width() < 300){
        ui->Header->setText("");
    }
    resize(image.width(), image.height()+21);
    ui->ShownImage->setFixedWidth(image.width());
    ui->ShownImage->setFixedHeight(image.height());
    ui->Header->setFixedWidth(image.width());
    ui->Background->setFixedWidth(image.width());
    ui->Background->setFixedHeight(image.height()+21);

}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}
