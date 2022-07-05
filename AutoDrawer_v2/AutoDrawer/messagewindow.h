#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class MessageWindow;
}

class MessageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MessageWindow(QString text, int type, QWidget *parent = nullptr);
    ~MessageWindow();

private slots:
    void on_pushButton_6_released();
    void buttonType(int a);

    void on_pushButton_8_released();

    void on_pushButton_7_released();

    void on_pushButton_9_released();

    void reloadThemes();
private:
    Ui::MessageWindow *ui;
    QString sharedText;
    int type;
};

#endif // MESSAGEWINDOW_H
