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
    void on_Exit_released();

private:
    Ui::ThemeEditor *ui;
};

#endif // THEMEEDITOR_H
