#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:

    void on_GH_released();

    void on_LR_released();

    void on_Discord_released();

    void on_CloseBox_released();

    void on_OpenThemes_released();

    void reloadThemes(QString theme);

    void on_Reload_released();

    void on_ThemeCombo_currentIndexChanged();

    void on_OffsetBox_released();

    void on_LogBox_released();

    void reloadList();
    void on_OpenLogs_released();

    void on_PrinterBox_released();

    void on_Console_released();

    void on_ThemeEditor_released();

    void on_intervalTextBox_textChanged(const QString &arg1);

    void on_intervalTextBox_2_textChanged(const QString &arg1);

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
