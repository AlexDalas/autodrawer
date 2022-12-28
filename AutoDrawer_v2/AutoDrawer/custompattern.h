#ifndef CUSTOMPATTERN_H
#define CUSTOMPATTERN_H

#include <QMainWindow>

namespace Ui {
class custompattern;
}

class custompattern : public QMainWindow
{
    Q_OBJECT

public:
    explicit custompattern(QWidget *parent = nullptr);
    ~custompattern();

private slots:
    void on_Submit_released();

    void reloadThemes();

    void on_Close_released();

    void onFileChanged(const QString& path);

    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

private:
    Ui::custompattern *ui;
};

#endif // CUSTOMPATTERN_H
