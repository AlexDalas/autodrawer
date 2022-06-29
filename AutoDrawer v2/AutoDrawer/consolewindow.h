#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ConsoleWindow;
}

class ConsoleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsoleWindow(QWidget *parent = nullptr);
    ~ConsoleWindow();

private slots:
    void on_Exit_3_released();

    void on_Exit_2_released();

    void on_Exit_released();

    void on_Exit_4_released();

private:
    Ui::ConsoleWindow *ui;
};

#endif // CONSOLEWINDOW_H
