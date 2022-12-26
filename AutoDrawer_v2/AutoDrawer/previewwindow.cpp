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
#include <uglobalhotkeys.h>

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGHT = 4920;

#ifdef _WIN32
    #define WINVER 0x0500
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
#elif  __linux__
    #include <errno.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <linux/uinput.h>
// https://www.froglogic.com/blog/tip-of-the-week/using-linux-uinput-from-a-test-script/


void emitLX(int fd, int type, int code, int val)
{
   struct input_event ie;

   ie.type = type;
   ie.code = code;
   ie.value = val;
   /* timestamp values below are ignored */
   ie.time.tv_sec = 0;
   ie.time.tv_usec = 0;

   write(fd, &ie, sizeof(ie));
}




void deleteDevice(int fd) {
    if (fd > 0) {
        ioctl(fd, UI_DEV_DESTROY);
        close(fd);
    }
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

std::vector<std::vector<int>> pixelArray;

bool cont;
bool CloseRequested = false;
bool Paused = false;

auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/AutoDraw";

auto offsetX = 0;
auto offsetY = 0;

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
    image = dimage;
    pixelArray.clear();
    //pixelArray.resize(image.width(), std::vector<int>(image.height(), 0));
    MainWin = parent;
    reloadThemes();
    loopRunning = true;
    cursorHeld = false;
    //parent->show();
    // Code that puts window under mouse until done
    QFuture<void> future = QtConcurrent::run([=]() {
        while (loopRunning){
            move(QCursor::pos().x() - ui->ShownImage->width()/2, QCursor::pos().y() - ui->ShownImage->height()/2);
        }
    });
    //To-do: Make code run on Windows
    UGlobalHotkeys *hotkeyManager = new UGlobalHotkeys();
    hotkeyManager->registerHotkey("Ctrl+Alt+Q");
    connect(hotkeyManager, &::UGlobalHotkeys::activated, [=](size_t id)
    {
        QApplication::quit();
        Draw();
    });
    UGlobalHotkeys *hotkeyManager1 = new UGlobalHotkeys();
    hotkeyManager1->registerHotkey("Ctrl+Alt+W");
    connect(hotkeyManager1, &::UGlobalHotkeys::activated, [=](size_t id)
    {
        QApplication::quit();
        Draw();
    });
    UGlobalHotkeys *hotkeyManager2 = new UGlobalHotkeys();
    hotkeyManager2->registerHotkey("Ctrl+Alt+E");
    connect(hotkeyManager2, &::UGlobalHotkeys::activated, [=](size_t id)
    {
        QApplication::quit();
        Draw();
    });
    UGlobalHotkeys *hotkeyManager3 = new UGlobalHotkeys();
    hotkeyManager3->registerHotkey("Ctrl+Alt+R");
    connect(hotkeyManager3, &::UGlobalHotkeys::activated, [=](size_t id)
    {
        closeDraw(0);
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

int i = 10;
struct uinput_setup usetup;
int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
#ifdef __linux__
void setupLXMouse(){

    ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);

    ioctl(fd, UI_SET_EVBIT, EV_REL);
    ioctl(fd, UI_SET_RELBIT, REL_X);
    ioctl(fd, UI_SET_RELBIT, REL_Y);
    memset(&usetup, 0, sizeof(usetup));
    usetup.id.bustype = BUS_USB;
    usetup.id.vendor = 0x1234; /* sample vendor */
    usetup.id.product = 0x5678; /* sample product */
    strcpy(usetup.name, "AutoDrawer");

    ioctl(fd, UI_DEV_SETUP, &usetup);
    ioctl(fd, UI_DEV_CREATE);
    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
}
#endif
//fix tmr: cursor doesn't click down
void setCursor(int x, int y){
    x += offsetX;
    y += offsetY;
    //This code is cross-platform, but does not work with games.
    //QCursor::setPos(QPoint(x,y));
    #ifdef _WIN32

    #elif  __linux__
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_REL, REL_X, (x - QCursor::pos().x()/2));
        emitLX(fd, EV_REL, REL_Y, (y - QCursor::pos().y()/2));
        qDebug() << QCursor::pos().x()-x << "\n1";
        //emitLX(fd, EV_REL, REL_X, (x-QCursor::pos().x()));
        //emitLX(fd, EV_REL, REL_Y, (y-QCursor::pos().y()));
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    #elif  __APPLE__

    #endif
}

void setCursorREL(int x, int y){
    x += offsetX;
    y += offsetY;
    //This code is cross-platform, but does not work with games.
    //QCursor::setPos(QPoint(x,y));
    #ifdef _WIN32

    #elif  __linux__
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_REL, REL_X, (x));
        emitLX(fd, EV_REL, REL_Y, (y));
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    #elif  __APPLE__

    #endif
}

void clickCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32

    #elif  __linux__
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_KEY, BTN_LEFT, 1);
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_KEY, BTN_LEFT, 0);
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    #elif __APPLE__

    #endif
}

void holdCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32

    #elif  __linux__
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_KEY, BTN_LEFT, 1);
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    #elif __APPLE__

    #endif
}

void releaseCursor(){
    //This code is not cross platform, so you have to run different code on different OS'.
    #ifdef _WIN32

    #elif  __linux__
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        emitLX(fd, EV_KEY, BTN_LEFT, 0);
        emitLX(fd, EV_SYN, SYN_REPORT, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    #elif __APPLE__

    #endif
}

int PreviewWindow::getPA(int x, int y){
    //return pixelArray[x][y];
    return pixelArray.at(x).at(y);
}

void PreviewWindow::setPA(int x, int y, int value){
    pixelArray[x][y] = value;
}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}
void PreviewWindow::closeDraw(int a){
    //0 is stopped, 1 is success
    #ifdef __linux__

    #endif
    if (a == 1){
        new ConsoleWindow("Drawing finished.");
        sendMessage("Drawing finished", 4, MainWin);
        this->close();
    } else{
        new ConsoleWindow("Drawing stopped.");
        sendMessage("Drawing stopped", 5, MainWin);
        this->close();
    }
}

void PreviewWindow::lockPos(){

    QFile inFile(path+"/user.cfg");
    QByteArray data = inFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject rootObj2 = doc.object();
    inFile.close();

    ::setCursor(rootObj2.value("lockpos_x").toInt() + offsetX, rootObj2.value("lockpos_y").toInt() + offsetY);
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
    int x = QCursor::pos().x() - (image.width()/2);
    int y = QCursor::pos().y() - (image.height()/2);

    new ConsoleWindow("Started drawing {\n   Interval: "+QString::number(interval)+"\n   Click Delay: "+QString::number(clickDelay)+"\n}");

    loopRunning = false;
    this->hide();
    #ifdef __linux
        setupLXMouse();
    #endif
    if (printer){
        //printer mode
        for (int yImg = 0; yImg < image.height(); ++yImg) {
            if (stopAutodraw) break;
            QRgb *scanLine = (QRgb*)image.scanLine(yImg);
            for (int xImg = 0; xImg < image.width(); ++xImg) {
                if (stopAutodraw) break;
                QRgb pixel = *scanLine;
                uint ci = uint(qGray(pixel));
                std::cout << ci << "\n" << xImg << "\n";
                if (ci <= 254){
                    ::setCursor(x+xImg, y+yImg);
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
        cont = true;
        pixelArray.resize(image.width(), std::vector<int>(image.height(), 0));
        //dodgy code somewhat
        for(int i = 0; i< QString::number(path8).length(); i++)
        {
            if (QString::number(path8).at(i) != " ")
                pathStr.push_back(QString::number(path8).at(i).toLatin1());
        }
        //end dodgy code

        //Scan
        for (int y = 0; y < image.height(); ++y) {
            QRgb *scanLine = (QRgb*)image.scanLine(y);
            for (int x = 0; x < image.width(); ++x) {
                QRgb pixel = *scanLine;
                uint ci = uint(qGray(pixel));
                if (ci >= (unsigned int) 200){
                    setPA(x, y, 1);
                }
                else{
                    setPA(x, y, 0);
                }
                ++scanLine;
            }
        }
        //USE THE BELOW CODE TO TEST OUT WHAT THE ARRAY LOOKS LIKE IN IMAGE FORM
/*
        QImage image2(image.width(), image.height(), QImage::Format_RGB32);
        for (int i=0;i<image2.width();++i) {
            for (int j=0;j<image2.height();++j) {
                QRgb value = getPA(i, j);
                if (value % 5 == 0) value = qRgb(0, 0, 0); else value = qRgb(255, 255, 255);
                //new ConsoleWindow(QString::number(getPA(i, j)));
                image.setPixel(i, j, value);
            }
        }
        ui->ShownImage->setPixmap(QPixmap::fromImage(image));
        this->show();
        //new ConsoleWindow("Image test mode on, showing user scanned image.");
        return;
*/
        //END OF TEST CODE
        //Draw
        for (int yImg = 0; yImg < image.height(); ++yImg) {
            if (stopAutodraw) break;
            QRgb *scanLine = (QRgb*)image.scanLine(yImg);
            for (int xImg = 0; xImg < image.width(); ++xImg) {
                if (stopAutodraw) break;
                //remove if unneeded
                QRgb pixel = *scanLine;
                uint ci = uint(qGray(pixel));
                //new ConsoleWindow(QString::number(getPA(xImg, yImg)));
                //end
                if (getPA(xImg, yImg) == 1){
                    int xpos = x+xImg;
                    int ypos = y+yImg;
                    NOP(clickdelay*5000);
                    if (stopAutodraw) break;
                    ::setCursor(xpos, ypos+1);
                    NOP(clickdelay*5000);
                    if (stopAutodraw) break;
                    holdCursor();
                    cont = DrawArea(stack, xImg, yImg, x, y);//drawarea
                    releaseCursor();
                }
                if (!cont){
                    ResetPixels();
                }
            }
        }
        ResetPixels();
    }
}
bool PreviewWindow::DrawArea(std::vector<QPoint> stack, int xImg, int yImg, int x, int y){
    //new ConsoleWindow("DrawArea  ");
    while (true){
        if (Paused){

        }
        if (stopAutodraw){
            break;
        }
        NOP(moveInterval);
        ::setCursor(x+xImg, y+yImg);
        //Code below errors
        //new ConsoleWindow("C");
        setPA(xImg, yImg, 2);
        //new ConsoleWindow("A");
        /*
        +---+---+---+
        | 1 | 2 | 3 |
        +---+---+---+
        | 4 |   | 5 |
        +---+---+---+
        | 6 | 7 | 8 |
        +---+---+---+
        */
        //User chosen path is defined by "path8" integer and (mostly used) "pathStr" array.
        cont = false;
        for (int i = 1; i <= 8; ++i) {
           switch (pathStr[i]){
               case 1:
                if ((xImg > 0) && (yImg > 0)){
                    if (getPA((xImg+1 - 1), (yImg+1 - 1)) == 1){
                        stack = Push(stack, xImg, yImg);
                        xImg -= 1;
                        yImg -= 1;
                        cont = true;
                    }
                }
                break;
               case 2:
                if (yImg > 0){
                    if (getPA(xImg, (yImg - 1)) == 1){
                        stack = Push(stack, xImg, yImg);
                        yImg -= 1;
                        cont = true;
                    }
                }
                break;
           case 3:
               if ((xImg > 0) && (yImg > 0)){
                   if (getPA((xImg + 1), (yImg - 1)) == 1){
                       stack = Push(stack, xImg, yImg);
                       xImg += 1;
                       yImg += 1;
                       cont = true;
                   }
               }
            break;
           case 4:
               if (xImg > 0){
                   if (getPA((xImg - 1), yImg) == 1){
                       stack = Push(stack, xImg, yImg);
                       yImg -= 1;
                       cont = true;
                   }
               }
               break;
           case 5:
               if (xImg > (image.width() - 1)){
                   if (getPA((xImg + 1), yImg) == 1){
                       stack = Push(stack, xImg, yImg);
                       xImg += 1;
                       cont = true;
                   }
               }
               break;
           case 6:
               if ((xImg < 0) & (yImg > 0)){
                   if (getPA((xImg - 1), (yImg + 1)) == 1){
                       stack = Push(stack, xImg, yImg);
                       xImg -= 1;
                       yImg -= 1;
                       cont = true;
                   }
               }
               break;
           case 7:
               if (xImg > (image.height() - 1)){
                   if (getPA(xImg, (yImg + 1)) == 1){
                       stack = Push(stack, xImg, yImg);
                       yImg += 1;
                       cont = true;
                   }
               }
               break;
           case 8:
               if ((xImg < (image.width() - 1)) && (y < (image.height()) - 1)){
                   if (getPA(xImg, (yImg + 1)) == 1){
                       stack = Push(stack, xImg, yImg);
                       xImg += 1;
                       yImg += 1;
                       cont = true;
                   }
               }
               break;


           }
        }
        if (cont) continue;
        std::tuple<bool, int, int> t = Pop(stack, xImg, yImg);
        std::get<1>(t) = xImg;
        std::get<2>(t) = yImg;
        if (!std::get<0>(t)) break;
    }
    return true;
}

std::vector<QPoint> PreviewWindow::Push(std::vector<QPoint> stack, int xImg, int yImg){
    stack.push_back(QPoint(xImg, yImg));
    return stack;
}

std::tuple<bool, int, int> PreviewWindow::Pop(std::vector<QPoint> stack, int xImg, int yImg){
    //new ConsoleWindow("stackCount: ");
    int stackCount = stack.size();
    //new ConsoleWindow(QString::number(stackCount));
    if (stackCount < 1){
            return std::make_tuple(false, xImg, yImg);
    }
    //imporvides code
    QPoint pos = (QPoint)stack[stackCount - 1];
    xImg = pos.x();
    yImg = pos.y();

    stack.erase(std::remove(stack.begin(), stack.end(), pos), stack.end());

    return std::make_tuple(true, xImg, yImg);
}

void PreviewWindow::ResetPixels(){
    //new ConsoleWindow("Resetting pixels  ");
    for (int yImg = 0; yImg < image.height(); ++yImg) {
        if (stopAutodraw) break;
        for (int xImg = 0; xImg < image.width(); ++xImg) {
            if (stopAutodraw) break;
            if (getPA(xImg, yImg) == 2){
                setPA(xImg, yImg, 1);
            }
        }
    }
    //new ConsoleWindow("Reset Success  ");
}

void PreviewWindow::NOP(int ourint){
    std::this_thread::sleep_for(std::chrono::microseconds(ourint*250));
}

void PreviewWindow::on_Draw_released()
{
    Draw();
}

