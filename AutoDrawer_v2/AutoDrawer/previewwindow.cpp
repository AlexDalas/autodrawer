#include "previewwindow.h"
#include "consolewindow.h"
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
#include <algorithm>
#include <QApplication>
#include <QTextStream>
#include <QKeyEvent>
//#include <uglobalhotkeys.h>

#ifdef _WIN32
#include <Windows.h>
#elif  __linux__
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <linux/uinput.h>
#include <X11/Xlib.h>
int fd;
Display *dpy;
void initMouse()
{

}
#elif __APPLE__

#endif

bool cursorHeld = false;
bool loopRunning = true;
bool stopAutodraw;
int moveInterval;
int clickDelay;
QImage image;
int path8 = 12345678;
using namespace Qt;
QWidget* MainWin;

bool cont;
bool CloseRequested = false;
bool Paused = false;

auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";

auto offsetX = 0;
auto offsetY = 0;

void getMousePos(int &x, int &y)
{
#ifdef _WIN32
    // for our use case, we don't really need this on windows, but it's here anyway (untested)
    POINT cursorPos;
    if (GetCursorPos(&cursorPos))
    {
        x = cursorPos.x;
        y = cursorPos.y;
    }
#elif __linux__
    //to do
#endif
}

void setCursorABS(int x, int y){
#ifdef _WIN32
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
    input.mi.dx = x * (65535 / GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy = y * (65535 / GetSystemMetrics(SM_CYSCREEN));
    SendInput(1, &input, sizeof(INPUT));
#elif  __linux__


#endif
}

void setCursorREL(int dx, int dy){
#ifdef _WIN32
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    input.mi.dx = dx;
    input.mi.dy = dy;
    SendInput(1, &input, sizeof(INPUT));
#elif  __linux__
    int xx, yy;
    getMousePos(xx, yy);
    setCursorABS(xx + dx, yy + dy);
#endif
}

void holdCursor(){
#ifdef _WIN32
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
#elif  __linux__

#endif
}

void releaseCursor(){
#ifdef _WIN32
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
#elif  __linux__

#endif
}

void clickCursor(){
    holdCursor();
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
    releaseCursor();
}
PreviewWindow::PreviewWindow(QImage dimage, int interval, int delay, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint | Qt::WindowTransparentForInput | Qt::WindowStaysOnTopHint);
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
    moveInterval = interval;
    clickDelay = delay;
    #if  __linux__
    //initialise mouse and display (linux only)
    ::initMouse();
    dpy = XOpenDisplay(NULL);
    #endif
    image = dimage;
    //pixelArray.resize(image.width(), std::vector<int>(image.height(), 0));
    MainWin = parent;
    reloadThemes();
    loopRunning = true;
    cursorHeld = false;
#if _WIN32
#define HOTKEY_ID_CTRL 1
#define HOTKEY_ID_SHIFT 2
#define HOTKEY_ID_ALT 3
    // Register Ctrl hotkey
    if (RegisterHotKey(NULL, HOTKEY_ID_CTRL, MOD_CONTROL, 'C'))
    {
        std::cout << "Ctrl global hotkey registered!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to register Ctrl global hotkey!" << std::endl;
        return 1;
    }

    // Register Shift hotkey
    if (RegisterHotKey(NULL, HOTKEY_ID_SHIFT, MOD_SHIFT, 'S'))
    {
        std::cout << "Shift global hotkey registered!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to register Shift global hotkey!" << std::endl;
        return 1;
    }

    // Register Alt hotkey
    if (RegisterHotKey(NULL, HOTKEY_ID_ALT, MOD_ALT, 'A'))
    {
        std::cout << "Alt global hotkey registered!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to register Alt global hotkey!" << std::endl;
        return 1;
    }
    QFuture<void> future = QtConcurrent::run([=]() {
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0))
        {
            if (msg.message == WM_HOTKEY)
            {
                wprintf(L"WM_HOTKEY received\n");
            }
        }

        // Unregister the hotkeys
        UnregisterHotKey(NULL, HOTKEY_ID_CTRL);
        UnregisterHotKey(NULL, HOTKEY_ID_SHIFT);
        UnregisterHotKey(NULL, HOTKEY_ID_ALT);
    });
#endif
    //parent->show();
    // Code that puts window under mouse until done
    /*
    QFuture<void> future = QtConcurrent::run([=]() {
        while (loopRunning){
            move(QCursor::pos().x() - ui->ShownImage->width()/2, QCursor::pos().y() - ui->ShownImage->height()/2);
        }
    });*/

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
    path8 = rootObj2.value("pattern").toInt();
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

PreviewWindow::~PreviewWindow()
{
    delete ui;
}
void PreviewWindow::closeDraw(int a){
    //0 is stopped, 1 is success
    if (a == 1){
        new ConsoleWindow("Drawing finished.");
        sendMessage("Drawing finished", 4, MainWin);
    } else{
        new ConsoleWindow("Drawing stopped.");
        sendMessage("Drawing stopped", 5, MainWin);
    }
}

void PreviewWindow::lockPos(){

    QFile inFile(path+"/user.cfg");
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    inFile.close();

    ::setCursorABS(rootObj2.value("lockpos_x").toInt(), rootObj2.value("lockpos_y").toInt());
}

void PreviewWindow::on_pushButton_2_released()
{
    stopAutodraw = true;
    releaseCursor();
    MainWin->show();
}
std::vector<QPoint> stack;
std::vector<int> pathStr;
void PreviewWindow::Draw()
{
    QFile inFile(path+"/user.cfg");
    inFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    auto printer = rootObj2.value("printer").toBool();
    path8 = rootObj2.value("pattern").toInt();
    offsetX = rootObj2.value("lockpos_x").toInt();
    offsetY = rootObj2.value("lockpos_x").toInt();
    rootObj2.insert("lockpos_x", QCursor::pos().x());
    rootObj2.insert("lockpos_y", QCursor::pos().y());
    QJsonDocument new_doc(rootObj2);
    inFile.resize(0);
    inFile.write(new_doc.toJson());
    inFile.close();
    int x = QCursor::pos().x() - (image.width()/2) + offsetX;
    int y = QCursor::pos().y() - (image.height()/2) + offsetY;

    new ConsoleWindow("Started drawing {\n   Interval: "+QString::number(moveInterval)+"\n   Click Delay: "+QString::number(clickDelay)+"\n}");

    loopRunning = false;
    this->hide();
    if (printer){
        //printer mode
        // NOTE - Doesn't work
        for (int yImg = 0; yImg < image.height(); ++yImg) {
            if (stopAutodraw) break;
            QRgb *scanLine = (QRgb*)image.scanLine(yImg);
            for (int xImg = 0; xImg < image.width(); ++xImg) {
                if (stopAutodraw) break;
                QRgb pixel = *scanLine;
                uint ci = uint(qGray(pixel));
                std::cout << ci << "\n" << xImg << "\n";
                if (ci <= 254){
                    ::setCursorABS(x+xImg, y+yImg);
                    if (!cursorHeld) {::holdCursor(); cursorHeld = true;}
                    std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));
                }
                else{
                    if (cursorHeld) {::releaseCursor(); cursorHeld = false; std::this_thread::sleep_for(std::chrono::microseconds(clickdelay*2));}
                }
                ++scanLine;
            }
            if (cursorHeld) {::releaseCursor(); cursorHeld = false; std::this_thread::sleep_for(std::chrono::microseconds(clickdelay*2));}
        }
    }
    else{
        // AUTODRAW CODE
        // Variables:
        // image (QImage)
        // cursorHeld, stopAutodraw (bool)
        // moveInterval, clickDelay, x, y (int)
        // Sleep for microseconds: std::this_thread::sleep_for(std::chrono::microseconds(moveInterval));



    }
    closeDraw(1);
}

void PreviewWindow::on_Draw_released()
{
    Draw();
}

