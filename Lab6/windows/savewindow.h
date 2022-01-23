#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *parent = nullptr);
    ~SaveWindow();

private slots:    
    void on_SaveButton_clicked();           //зберегти гру під введеною назвою

private:
    void closeEvent(QCloseEvent *event);    //подія яка спрацьовує на нажимання хрестика закриває дане вікно і показує вікно гри

    bool is_correct_filename();             //перевіряє коректність введеної назви для збереження

private:
    Ui::SaveWindow *ui;
};

#endif // SAVEWINDOW_H
