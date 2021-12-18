#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include "gameboard.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::GameWindow *ui;  //Покажчик на інтерфейс вікна

    GameBoard* game_board;

public:
        // конструктор створення вікна гри для 2 гравців
    explicit GameWindow(bool g_with_pc, QWidget *parent = nullptr);
    ~GameWindow();

private slots:
        // слот в menu_bar "Зікінчити гру" закриває вікно GameWindow і повертається MainWindow
    void on_CloseEnd_triggered();
};

#endif // GAMEWINDOW_H
