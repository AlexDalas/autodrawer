#include "themeeditor.h"
#include "ui_themeeditor.h"
#include "consolewindow.h"

ThemeEditor::ThemeEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    new ConsoleWindow("Opened theme editor.");
}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

void ThemeEditor::on_Exit_released()
{
    this->close();
}

