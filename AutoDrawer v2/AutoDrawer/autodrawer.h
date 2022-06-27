#ifndef AUTODRAWER_H
#define AUTODRAWER_H

#include <QMainWindow>
#include "infowindow.h"
#include "settingswindow.h"

extern QString darkJson;
extern QString lightJson;

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

    void on_scaleNumber_textEdited();

    void on_exitButton_released();

    void on_ScaleSlider_valueChanged(int value);

    void on_Minimize_released();

    void dropEvent(QDropEvent *e) override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void on_pushButton_12_released();

    void on_startButton_released();

    void on_uploadImage_released();

    void on_widthBox_textEdited();

    void on_heightBox_textEdited();

    void changeImage(QPixmap img);

    void on_pushButton_2_released();

    void on_infoButton_released();

    void on_settingButton_released();

    void on_loadConfig_released();

    void on_saveConfig_released();

    void on_clearImage_released();

    void on_processImage_released();

    void reloadThemes();

private:
    Ui::AutoDrawer *ui;
    InfoWindow *infoDialog;
    SettingsWindow *settingsWindow;
};
#endif // AUTODRAWER_H
