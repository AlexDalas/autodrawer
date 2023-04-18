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

    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void on_pushButton_2_released();

    void closeDraw(int a);

    void Draw();

    void on_Draw_released();

    void lockPos();

    void reloadThemes();

private:
    Ui::PreviewWindow *ui;
    QImage image;
    int interval;
    int clickdelay;
};

#endif // PREVIEWWINDOW_H
