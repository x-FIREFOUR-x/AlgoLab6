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
    void on_CloseButton_clicked();

    void on_SaveButton_clicked();

private:
    bool is_correct_filename();
    void save_game();
private:
    Ui::SaveWindow *ui;
};

#endif // SAVEWINDOW_H
