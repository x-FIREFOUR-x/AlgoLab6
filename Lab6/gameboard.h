#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>
#include "printercards.h"
#include "cardshands.h"
#include "cardsdeck.h"

class GameBoard: public QGraphicsView
{
    int height_side_px;        // розмір сторони в пікселях
    int width_side_px;        // розмір сторони в пікселях

    bool game_with_pc;      //тип гри з комп'ютером чи два гравці
    bool computer_first;    // чи перший ходить компютер
    int difficulty;         // рівень складності (1 легкий, 2 середній, 3 тяжкий)

    int level_recur;        // глибина рекурсії рівна складності
    int time_deley = 10;    // час затримки перд ходом компютера

    int current_player;      //номер гравця чий хід

    bool finished;          //гра закінчена
    bool player_win;        //гравець виграв

    QGraphicsScene *scene;  // покажчик на графічну сцену
    PrinterCards printer;   // рисувальщик карт

    int number_card_of_distrib = 6;   // кількість карт при роздачі
    CardsDeck cards_deck;             //колода карт
    CardsHands cards_hands1;          // руки першого гравця
    CardsHands cards_hands2;          // руки другого гравця

    bool put_three = false;


public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення розміру, ігрового поля і параметра g_with_pc(false) виклик при грі 2 гравців
    void set_parameters(int height, int width, bool g_with_pc);
        //Метод, що використовується для встановлення розміру, ігрового поля і параметра g_with_pc(true) виклик при грі з пк і встановлення порядку ходу, рівня тяжкості
    void set_parameters(int height, int width, bool g_with_pc, bool pc_first, int level_dif);


protected:
         // встановлення спільних параметрів
    void parameters(int height, int width, bool g_with_pc);
         // метод що реагує на клік миші по цьому класу віджету GameBoard на вікні GameWindow для ходу гравця
    virtual void mousePressEvent(QMouseEvent *event);

        //Метод, який при зміні розміру області перегляду масштабує сцену
    void resizeEvent(QResizeEvent *event);

private:
        // гра йде гравець проти гравця
    void player_vs_player(int mouse_x, int mouse_y);


        // гра йде гравець проти комп'ютера
    void player_vs_computer(int mouse_x, int mouse_y);

        // функція ходу гравця коли він ходить другим граючи з компютером і асинхронний виклик першого ходу компютера pc_move_first
    void player_move_second(int mouse_x, int mouse_y);
    void pc_move_first();

        // функція ходу гравця коли він ходить першим граючи з компютером і асинхронний виклик другого ходу компютера pc_move_second
    void player_move_first(int mouse_x, int mouse_y);
    void pc_move_second();


        //перевірка чи клік здійснено по колоді
    bool is_click_on_deck(int mouse_x, int mouse_y);

        //хід взяти карту з колоди
    void take_card_with_deck();
        //хід покласти карту
    void put_card_in_top(int mouse_x, int mouse_y);

        //перевіряє чи вибрану карту можна покласти на верх минуло скинутої карти
    bool can_put_chosen_card(pair<int,int>);

        // визначення ефекту покладеної карти
    void assign_effect_card(pair<int,int> card);

    void effect_two();
    void effect_three();
    void effect_four();
    void effect_eight();
    void effect_jack();
    void effect_joker();
};

#endif // GAMEBOARD_H

