#include "previewwindow.h"
#include "autodrawer.h"
#include "ui_previewwindow.h"
#include "messagewindow.h"
#include <iostream>
#include <QShortcut>
#include <QtConcurrent>
#include <thread>
#include <chrono>
#include <future>
#include <QMouseEvent>

bool loopRunning = true;
bool stopAutodraw;
int moveInterval;
int clickDelay;
QImage image;
using namespace Qt;

PreviewWindow::PreviewWindow(QImage dimage, int interval, int delay, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    setParent(0);
    setMouseTracking(true);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ui->ShownImage->setPixmap(QPixmap::fromImage(dimage));
    resize(dimage.width(), dimage.height()+21);
    ui->ShownImage->setFixedWidth(dimage.width());
    ui->ShownImage->setFixedHeight(dimage.height());
    ui->Header->setFixedWidth(dimage.width());
    ui->Background->setFixedWidth(dimage.width());
    ui->Background->setFixedHeight(dimage.height()+21);
    ui->LastPOS->setShortcut(Qt::CTRL);
    ui->Stop->setShortcut(Qt::ALT);
    ui->Draw->setShortcut(QKeySequence(Qt::SHIFT));
    moveInterval = interval;
    clickDelay = delay;
    image = dimage;


    //parent->show();
    QFuture<void> future = QtConcurrent::run([=]() {
        while (loopRunning){
            move(QCursor::pos().x() - ui->ShownImage->width()/2, QCursor::pos().y() - ui->ShownImage->height()/2);
        }
    });
}

void PreviewWindow::setCursor(int x, int y){
    QCursor::setPos(QPoint(x,y));

    //QFuture<void> future = QtConcurrent::run([=]() {
    //    std::system(("xdotool mousemove " + std::to_string(x) + " " + std::to_string(y)+" --delay 0").c_str());
    //});
}

void PreviewWindow::clickCursor(){

}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}
void PreviewWindow::closeDraw(int a){
    //0 is stopped, 1 is success
    if (a == 1){
        this->close();
        MessageWindow *w = new MessageWindow("Drawing finished", 4, this);
        w->show();
    } else{
        this->close();
        MessageWindow *w = new MessageWindow("Drawing stopped", 5, this);
        w->show();
    }
}

void PreviewWindow::on_pushButton_2_released()
{
    stopAutodraw = true;
}

void PreviewWindow::Draw()
{
    loopRunning = false;
    this->hide();
    int x = QCursor::pos().x() - (image.width()/2);
    int y = QCursor::pos().y() - (image.height()/2);
    if (true){
        //printer mode
        for (int yImg = 0; yImg < image.height(); ++yImg) {
            if (stopAutodraw) break;
            QRgb *scanLine = (QRgb*)image.scanLine(yImg);
            for (int xImg = 0; xImg < image.width(); ++xImg) {
                if (stopAutodraw) break;
                QRgb pixel = *scanLine;
                uint ci = uint(qGray(pixel));
                if (ci <= 254){
                    setCursor(x+xImg, y+(yImg));
                    clickCursor();
                    std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));
                }
                else{}
                ++scanLine;
            }
        }
    }
    else{
        //normal draw mode
        for (int i = 0; i < 3840; i++) {
            if (stopAutodraw) break;
            setCursor(i, y);
            std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));
            //auto f = std::async( std::launch::async, setCursor );
            //std::future<void> fut = std::async(std::launch::async, setCursor, this, i, y);
        }
    }
    if (stopAutodraw) closeDraw(0); else closeDraw(1);
}

void PreviewWindow::on_Draw_released()
{
    Draw();
}

