#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>
#include "printercards.h"
#include "cardshands.h"
#include "cardsdeck.h"
#include "windowsuit.h"
#include "windowrank.h"
#include <QLabel>

class GameBoard: public QGraphicsView
{
    int height_side_px;        // розмір сторони в пікселях
    int width_side_px;        // розмір сторони в пікселях

    bool game_with_pc;      //тип гри з комп'ютером чи два гравці
    bool computer_first;    // чи перший ходить компютер

    int level_recur;        // глибина рекурсії рівна складності
    int time_deley = 10;    // час затримки перд ходом компютера

    int who_move_first;       // номер гравця який починає гру (з початку гри вибирається випадково далі в раундах змінюється)
    int current_player;      //номер гравця чий хід

    bool finished = false;          //гра закінчена
    bool player_win;        //гравець виграв

    QGraphicsScene *scene;  // покажчик на графічну сцену
    PrinterCards printer;   // рисувальщик карт

    int number_card_of_distrib = 6;   // кількість карт при роздачі
    CardsDeck cards_deck;             //колода карт
    CardsHands cards_hands1;          // руки першого гравця
    CardsHands cards_hands2;          // руки другого гравця

    bool put_three = false;           // флажок спрацьовує при кладенні трійки
    bool put_four = false;            // флажок спрацьовує при кладенні чітвірки
    bool put_eight = false;
    bool put_jocker = false;
    pair<int,int> card_converted;     //карта на яку перетворений джокер чи вісім(тільки масть)

    QLabel* Deck_counter;
    QLabel* Score_player1;
    QLabel* Score_player2;
    QLabel* Score_max;

    int max_score = 0;
    int score1 = 0;
    int score2 = 0;

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення розміру, ігрового поля і параметра g_with_pc max_score
    void set_parameters(int max_score ,int height, int width, bool g_with_pc);
        // метод для встановлення вказіників на лейбли на ігровому полі
    void set_label(QLabel* counter, QLabel* score_player1, QLabel* score_player2, QLabel* score_max);

protected:
         // встановлення спільних параметрів
    void parameters(int height, int width, bool g_with_pc);
         // метод що реагує на клік миші по цьому класу віджету GameBoard на вікні GameWindow для ходу гравця
    virtual void mousePressEvent(QMouseEvent *event);

        //Метод, який при зміні розміру області перегляду масштабує сцену
    void resizeEvent(QResizeEvent *event);

private:
        //початок раунда роздача карт
    void start_round();
        //кінець раунда збір колоди скидка карт гравців
    void end_round();
        //підрахунок штрафних балів в кінці раунда
    void calculate_score();
        //відобразити очки на лейблах
    void display_score();
        //змінює за ким перший хід в раунді по закінчення раундів
    void change_who_first_move();


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

        //зміна ходу (зміна current_player)
    void change_move();
        // відобразити кількість карт в колоді
    void display_count_deck();

        // визначення ефекту покладеної карти
    void assign_effect_card(pair<int,int> card);

    void effect_two();          // активація ефекту коли кладуть 2
    void effect_three();        // активація ефекту коли кладуть 3
    void effect_four();         // активація ефекту коли кладуть 4
    void effect_eight();        // активація ефекту коли кладуть 8
    void effect_jack();         // активація ефекту коли кладуть валєт
    void effect_joker();        // активація ефекту коли кладуть джокер
};

#endif // GAMEBOARD_H

