#ifndef AUTODRAWER_H
#define AUTODRAWER_H

#include <QMainWindow>
#include "infowindow.h"
#include "settingswindow.h"
#include "autodrawer.h"
#include "./ui_autodrawer.h"
#include "infowindow.h"
#include "messagewindow.h"
#include "previewwindow.h"
#include "qjsonarray.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <qapplication.h>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QStandardPaths>

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

    void reloadThemes();


private slots:
    void on_ScaleSlider_sliderReleased();

    void on_ScaleSlider_sliderMoved(int position);

    void on_scaleNumber_textEdited();

    void on_exitButton_released();

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

    void on_dirButton_released();

    void on_reloadButton_released();

    void on_listView_itemClicked(QListWidgetItem *item);

    void loadConfig(QString a);

    void on_drawingList_itemClicked(QListWidgetItem *item);

    void on_DP_released();

private:
    Ui::AutoDrawer *ui;
    InfoWindow *infoDialog;
    SettingsWindow *settingsWindow;
};
#endif // AUTODRAWER_H
