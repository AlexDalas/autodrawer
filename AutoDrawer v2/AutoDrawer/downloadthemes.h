#ifndef DOWNLOADTHEMES_H
#define DOWNLOADTHEMES_H

#include <QMainWindow>

namespace Ui {
class downloadthemes;
}

class downloadthemes : public QMainWindow
{
    Q_OBJECT

public:
    explicit downloadthemes(QWidget *parent = nullptr);
    ~downloadthemes();

private slots:
    void on_Violet_released();

    void downloadSet(QString url, QString saveAS);

    void on_Blue_2_released();

    void on_Blue_released();

    void on_Black_released();

    void on_OrangeYellow_released();

    void on_Red_released();

    void on_Green_released();

private:
    Ui::downloadthemes *ui;
};

#endif // DOWNLOADTHEMES_H
