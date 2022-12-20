#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include "qlineedit.h"
#include <QMainWindow>

namespace Ui {
class ThemeEditor;
}

class ThemeEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThemeEditor(QWidget *parent = nullptr);
    ~ThemeEditor();

private slots:
    void on_Exit_2_released();

    void on_buttonColour_released();

    void on_ScaleSlider_valueChanged(int value);

    void on_Upload_released();

    void on_Exit_3_released();

    void on_Exit_4_released();

    void hideAll();

    void on_Exit_5_released();

    void updateTheme();

    void on_intervalTextBox_3_textChanged();

    void updateText(QByteArray data);

    void on_intervalTextBox_2_textChanged();

    void on_intervalTextBox_4_textChanged();

    void on_intervalTextBox_6_textChanged();

    void on_intervalTextBox_5_textChanged();

    void on_intervalTextBox_8_textChanged();

    void changeValue(QString objED, QString branED, QLineEdit* Obj);

    void on_intervalTextBox_20_textChanged();

    void on_intervalTextBox_29_textChanged();

    void on_intervalTextBox_7_textChanged();

    void on_intervalTextBox_32_textChanged();

    void on_intervalTextBox_26_textChanged();

    void on_intervalTextBox_34_textChanged();

    void on_intervalTextBox_35_textChanged();

    void on_intervalTextBox_10_textChanged();

    void on_intervalTextBox_13_textChanged();

    void on_intervalTextBox_12_textChanged();

    void on_intervalTextBox_11_textChanged();

    void on_intervalTextBox_14_textChanged();

    void on_intervalTextBox_15_textChanged();

    void on_intervalTextBox_16_textChanged();

    void on_intervalTextBox_17_textChanged();

    void on_intervalTextBox_19_textChanged();

    void on_intervalTextBox_18_textChanged();

    void on_intervalTextBox_21_textChanged();

    void on_intervalTextBox_22_textChanged();

    void on_intervalTextBox_24_textChanged();

    void on_intervalTextBox_23_textChanged();

    void on_intervalTextBox_30_textChanged();

    void on_intervalTextBox_25_textChanged();

    void on_intervalTextBox_31_textChanged();

    void on_intervalTextBox_33_textChanged();

    void on_intervalTextBox_68_textChanged();

    void on_intervalTextBox_69_textChanged();

    void on_intervalTextBox_70_textChanged();

    void on_intervalTextBox_28_textChanged();

    void on_intervalTextBox_72_textChanged();

    void on_intervalTextBox_71_textChanged();

    void on_intervalTextBox_74_textChanged();

    void on_intervalTextBox_75_textChanged();

    void on_intervalTextBox_76_textChanged();

    void on_intervalTextBox_77_textChanged();

    void on_intervalTextBox_78_textChanged();

    void on_intervalTextBox_81_textChanged();

    void on_intervalTextBox_90_textChanged();

    void on_intervalTextBox_87_textChanged();

    void on_intervalTextBox_80_textChanged();

    void on_intervalTextBox_83_textChanged();

    void on_intervalTextBox_79_textChanged();

    void on_intervalTextBox_84_textChanged();

    void on_intervalTextBox_86_textChanged();

    void on_intervalTextBox_82_textChanged();

    void on_intervalTextBox_85_textChanged();

    void on_intervalTextBox_88_textChanged();

    void on_Exit_11_released();

    void on_Exit_released();

    void on_ButtonINF_released();

private:
    Ui::ThemeEditor *ui;
};

#endif // THEMEEDITOR_H
