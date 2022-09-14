#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

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

private:
    Ui::ThemeEditor *ui;
};

#endif // THEMEEDITOR_H
