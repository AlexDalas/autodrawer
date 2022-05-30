#ifndef AUTODRAWER_H
#define AUTODRAWER_H

#include <QMainWindow>
#include "infowindow.h"
#include "settingswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AutoDrawer; }
QT_END_NAMESPACE

class AutoDrawer : public QMainWindow
{
    Q_OBJECT

public:
    AutoDrawer(QWidget *parent = nullptr);
    ~AutoDrawer();

private slots:
    void on_ScaleSlider_sliderReleased();

    void on_ScaleSlider_sliderMoved(int position);

    void on_scaleNumber_textEdited(const QString &arg1);

    void on_exitButton_released();

    void on_exitButton_2_released();

    void on_ScaleSlider_valueChanged(int value);

    void on_Minimize_released();

    void on_pushButton_3_released();

    void dropEvent(QDropEvent *e) override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void on_pushButton_6_released();

    void on_pushButton_7_released();

    void on_pushButton_5_released();

    void on_pushButton_released();

    void on_pushButton_12_released();

    void on_pushButton_9_released();

    void on_pushButton_8_released();

    void on_pushButton_4_released();

    void on_widthBox_textEdited(const QString &arg1);

    void on_heightBox_textEdited(const QString &arg1);

    void changeImage(QPixmap img);

private:
    Ui::AutoDrawer *ui;
    InfoWindow *infoDialog;
    SettingsWindow *settingsWindow;
};
#endif // AUTODRAWER_H
