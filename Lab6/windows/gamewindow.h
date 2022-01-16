#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include "logic/gameboard.h"
#include "logic/fileworker.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::GameWindow *ui;  //Покажчик на інтерфейс вікна

    GameBoard* game_board;  //покажчик на ігрове поле

public:
        // конструктор створення вікна гри для 2 гравців
    explicit GameWindow(int max_score, bool g_with_pc, QWidget *parent = nullptr);
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
        // слот в menu_bar "Зікінчити гру" закриває вікно GameWindow і повертається MainWindow
    void on_CloseEnd_triggered();
    void on_Save_triggered();
    void on_SaveAs_triggered();

    void on_Rules_triggered();

private:
    void save_game();
    void download_game();
};

#endif // GAMEWINDOW_H
