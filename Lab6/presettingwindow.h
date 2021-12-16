#ifndef PRESETTINGWINDOW_H
#define PRESETTINGWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class PresettingWindow;
}

class PresettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PresettingWindow(QWidget *parent = nullptr);
    ~PresettingWindow();

private slots:
        // перейти до гри (з вибраними параметрами)
    void on_ButtonGoGame_clicked();

        // повернутися назад вголовне меню (MainWindow)
    void on_ButtonBack_clicked();

        // встановлення кнопки гра з пк активною (для відображення вибору параметрів)
    void on_radioButtonPlayPC_clicked();

        // встановлення кнопки гра 2 гравців активною (для приховання вибору параметрів гри з пк)
    void on_radioButtonTwoPlayers_clicked();

private:
    Ui::PresettingWindow *ui;
};

#endif // PRESETTINGWINDOW_H
