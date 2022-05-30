#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QDesktopServices>
#include <QUrl>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_pushButton_7_released()
{
    this->close();
}


void SettingsWindow::on_pushButton_8_released()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Siydge/autodraw-roblox"));
}


void SettingsWindow::on_pushButton_9_released()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Siydge/autodraw-roblox/releases/latest"));
}


void SettingsWindow::on_pushButton_10_released()
{
    QDesktopServices::openUrl(QUrl("https://discord.gg/rwvUFraDnb"));
}

