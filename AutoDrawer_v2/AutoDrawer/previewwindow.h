#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QMainWindow>

namespace Ui {
class PreviewWindow;
}

class PreviewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PreviewWindow(QImage image, int interval, int clickdelay, QWidget *parent = nullptr);
    ~PreviewWindow();

private slots:
    void on_pushButton_2_released();

    void closeDraw(int a);

    void Draw();

    void on_Draw_released();

    void lockPos();

    void reloadThemes();

    void ResetPixels();

    void NOP(int ourint);

    void setPA(int x, int y, int value);

    int getPA(int x, int y);

    bool DrawArea(std::vector<QPoint> stack, int xImg, int yImg, int x, int y);

    std::vector<QPoint> Push(std::vector<QPoint> stack, int xImg, int yImg);

    std::tuple<bool, int, int> Pop(std::vector<QPoint> stack, int xImg, int yImg);

private:
    Ui::PreviewWindow *ui;
    QImage image;
    int interval;
    int clickdelay;
};

#endif // PREVIEWWINDOW_H
