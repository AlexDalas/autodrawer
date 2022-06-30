#include "previewwindow.h"
#include "autodrawer.h"
#include "ui_previewwindow.h"
#include "messagewindow.h"
#include <iostream>
#include <fstream>
#include <QShortcut>
#include <QtConcurrent>
#include <thread>
#include <chrono>
#include <future>
#include <QMouseEvent>
#include <QStandardPaths>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStandardPaths>
#include <QTest>
#ifdef _WIN32
    #include <Windows.h>
#elif  __linux__
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    Display *display = XOpenDisplay (NULL);
    void click (Display *display, int button)
    {
      // Create and setting up the event
      XEvent event;
      memset (&event, 0, sizeof (event));
      event.xbutton.button = button;
      event.xbutton.same_screen = True;
      event.xbutton.subwindow = DefaultRootWindow (display);
      while (event.xbutton.subwindow)
        {
          event.xbutton.window = event.xbutton.subwindow;
          XQueryPointer (display, event.xbutton.window,
                 &event.xbutton.root, &event.xbutton.subwindow,
                 &event.xbutton.x_root, &event.xbutton.y_root,
                 &event.xbutton.x, &event.xbutton.y,
                 &event.xbutton.state);
        }
      // Press
      event.type = ButtonPress;
      if (XSendEvent (display, PointerWindow, True, ButtonPressMask, &event) == 0)
        fprintf (stderr, "Error to send the event!\n");
      XFlush (display);
      std::this_thread::sleep_for(std::chrono::microseconds(1));
      // Release
      event.type = ButtonRelease;
      if (XSendEvent (display, PointerWindow, True, ButtonReleaseMask, &event) == 0)
        fprintf (stderr, "Error to send the event!\n");
      XFlush (display);
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    void hold (Display *display, int button){
        XEvent event;
        memset (&event, 0, sizeof (event));
        event.xbutton.button = button;
        event.xbutton.same_screen = True;
        event.xbutton.subwindow = DefaultRootWindow (display);
        while (event.xbutton.subwindow)
          {
            event.xbutton.window = event.xbutton.subwindow;
            XQueryPointer (display, event.xbutton.window,
                   &event.xbutton.root, &event.xbutton.subwindow,
                   &event.xbutton.x_root, &event.xbutton.y_root,
                   &event.xbutton.x, &event.xbutton.y,
                   &event.xbutton.state);
          }
        // Press
        event.type = ButtonPress;
        if (XSendEvent (display, PointerWindow, True, ButtonPressMask, &event) == 0)
          fprintf (stderr, "Error to send the event!\n");
        XFlush (display);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    void release (Display *display, int button){
        XEvent event;
        memset (&event, 0, sizeof (event));
        event.xbutton.button = button;
        event.xbutton.same_screen = True;
        event.xbutton.subwindow = DefaultRootWindow (display);
        while (event.xbutton.subwindow)
          {
            event.xbutton.window = event.xbutton.subwindow;
            XQueryPointer (display, event.xbutton.window,
                   &event.xbutton.root, &event.xbutton.subwindow,
                   &event.xbutton.x_root, &event.xbutton.y_root,
                   &event.xbutton.x, &event.xbutton.y,
                   &event.xbutton.state);
          }
        // Release
        event.type = ButtonRelease;
        if (XSendEvent (display, PointerWindow, True, ButtonReleaseMask, &event) == 0)
          fprintf (stderr, "Error to send the event!\n");
        XFlush (display);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

#elif __APPLE__

#endif

bool cursorHeld = false;
bool loopRunning = true;
bool stopAutodraw;
int moveInterval;
int clickDelay;
QImage image;
using namespace Qt;
QWidget* MainWin;

auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDrawer";

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
    MainWin = parent;
    reloadThemes();
    cursorHeld = false;
    //parent->show();
    QFuture<void> future = QtConcurrent::run([=]() {
        while (loopRunning){
            move(QCursor::pos().x() - ui->ShownImage->width()/2, QCursor::pos().y() - ui->ShownImage->height()/2);
        }
    });
    QFuture<void> start = QtConcurrent::run([=]() {
        if(pyCode("start") && !stopAutodraw) Draw();
    });
    QFuture<void> stop = QtConcurrent::run([=]() {
        if(pyCode("stop")) on_pushButton_2_released();
    });
    QFuture<void> lockpos = QtConcurrent::run([=]() {
        if(pyCode("lock")) lockPos();
    });
}

static void sendMessage(QString a, int b, QWidget *t){
    //1 for info, 2 for error, 3 for alert
    MessageWindow *w = new MessageWindow(a, b, t);
    w->show();
}

void PreviewWindow::reloadThemes(){

    QFile inFile(path+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto theme = rootObj2.value("theme").toString();
    inFile.close();

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
    } else if (QFile::exists(path+"/themes/"+theme+".drawtheme") ){
        QFile inFile2(path+"/themes/"+theme+".drawtheme");
        inFile2.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray themeData = inFile2.readAll();
        QJsonParseError errorPtr;
        QJsonDocument docT = QJsonDocument::fromJson(themeData, &errorPtr);
        rootObj = docT.object();
        preview = rootObj["settings"].toObject();
        inFile2.close();
    }
    ui->Header->setStyleSheet("color: "+preview["text"].toString());
    ui->Background->setStyleSheet("border-radius: 25px; background: "+preview["background"].toString());
}

bool PreviewWindow::pyCode(std::string str){
    QStringList arguments;
    arguments << path+"/hotkey.py" << str.c_str();
    QProcess *myProcess = new QProcess(this);
    myProcess->start("python3", arguments);
    myProcess->waitForFinished(-1);
    if(myProcess->exitCode() == 0) return true; else return false;
}

void PreviewWindow::setCursor(int x, int y){
    //This code is cross-platform
    QCursor::setPos(QPoint(x,y));
}

void PreviewWindow::clickCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32

    #elif  __linux__
        click (display, Button1);
    #elif __APPLE__

    #endif
}

void PreviewWindow::holdCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32
11!11!
    #elif  __linux__
        hold (display, Button1);
    #elif __APPLE__

    #endif
}

void PreviewWindow::releaseCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32

    #elif  __linux__
        release (display, Button1);
    #elif __APPLE__

    #endif
}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}
void PreviewWindow::closeDraw(int a){
    //0 is stopped, 1 is success
    if (a == 1){
        sendMessage("Drawing finished", 4, MainWin);
        this->close();
    } else{
        sendMessage("Drawing stopped", 5, MainWin);
        this->close();
    }
}

void PreviewWindow::lockPos(){
    //To be done when the save config code is done
}

void PreviewWindow::on_pushButton_2_released()
{
    if (!loopRunning) stopAutodraw = true; else {
        MainWin->show();
        this->close();
    }
}

void PreviewWindow::Draw()
{
    QFile inFile(path+"/user.cfg");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto printer = rootObj2.value("printer").toBool();
    inFile.close();

    loopRunning = false;
    this->hide();
    int x = QCursor::pos().x() - (image.width()/2);
    int y = QCursor::pos().y() - (image.height()/2);
    if (printer){
        //printer mode
        for (int yImg = 0; yImg < image.height(); ++yImg) {
            if (stopAutodraw) break;
            QRgb *scanLine = (QRgb*)image.scanLine(yImg);
            if (yImg % 2 == 0){
                for (int xImg = 0; xImg < image.width(); ++xImg) {
                    if (stopAutodraw) break;
                    QRgb pixel = *scanLine;
                    uint ci = uint(qGray(pixel));
                    if (ci <= 254){
                        setCursor(x+xImg, y+(yImg));
                        if (!cursorHeld) {holdCursor(); cursorHeld = true;}
                        std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));
                    }
                    else{
                        if (cursorHeld) {releaseCursor(); cursorHeld = false;}
                    }
                    ++scanLine;
                }
            }
            else{
                --scanLine;
                for (int xImg = image.width(); xImg --> 0;) {
                    if (stopAutodraw) break;
                    QRgb pixel = *scanLine;
                    uint ci = uint(qGray(pixel));
                    if (ci <= 254){
                        setCursor(x+xImg, y+(yImg));
                        if (!cursorHeld) {holdCursor(); cursorHeld = true;}
                        std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));
                    }
                    else{
                        if (cursorHeld) {releaseCursor(); cursorHeld = false;}
                    }
                    --scanLine;
                }
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

