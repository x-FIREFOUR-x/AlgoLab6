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
        // конструктор створення вікна нової гри
    explicit GameWindow(int max_score, bool g_with_pc, QWidget *parent = nullptr);
        // конструктор створення вікна завантаженої гри
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_CloseEnd_triggered();           // слот в menu_bar "Зікінчити гру" закриває вікно GameWindow і повертається MainWindow
    void on_Save_triggered();               // слот в menu_bar "Зберегти" зберігає гру в активние збереження або викликає слот  в menu_bar "Зберегти як"
    void on_SaveAs_triggered();             // слот в menu_bar "Зберегти як" відкриває вікно для збереження гри
    void on_Rules_triggered();              // слот в menu_bar "Правила" відкриває вікно з правилами гри

public:
    void save_game();               //функція передачі в FileWorker необхідних параметрів збереження гри
    void download_game();           //функція отримання від FileWorker необхідних параметрів збереження гри
};

#endif // GAMEWINDOW_H
