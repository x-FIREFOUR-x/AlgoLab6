#ifndef PRESETTINGWINDOW_H
#define PRESETTINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class PresettingWindow;
}

class PresettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PresettingWindow(QWidget *parent = nullptr);
    ~PresettingWindow();

private:
    void style();           //стилізує вікно

private slots:
        // перейти до гри (з вибраними параметрами)
    void on_ButtonGoGame_clicked();

        // повернутися назад вголовне меню (MainWindow)
    void on_ButtonBack_clicked();


private:
    Ui::PresettingWindow *ui;
};

#endif // PRESETTINGWINDOW_H
