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
    explicit ConsoleWindow(QString text, QWidget *parent = nullptr);
    ~ConsoleWindow();

private slots:
    void on_Exit_3_released();

    void on_Exit_2_released();

    void on_Exit_released();

    void on_Exit_4_released();

    void reloadConsole(std::string ln);

    void on_Exit_5_released();

    void reloadThemes();

    void onFileChanged(const QString& path);

    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

private:
    Ui::ConsoleWindow *ui;
};

#endif // CONSOLEWINDOW_H
