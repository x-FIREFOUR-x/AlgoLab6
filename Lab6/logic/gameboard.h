#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>
#include "printercards.h"
#include "cardshands.h"
#include "cardsdeck.h"
#include <QLabel>
#include "enemycomputer.h"

class GameBoard: public QGraphicsView
{
    float height_side_px;        // розмір сторони в пікселях
    float width_side_px;        // розмір сторони в пікселях

    int level_recur;        // глибина рекурсії рівна складності
    int time_deley = 10;    // час затримки перд ходом компютера

    int who_move_first;       // номер гравця який починає гру (з початку гри вибирається випадково далі в раундах змінюється)
    int current_player;      //номер гравця чий хід

    bool game_with_pc;      //тип гри з комп'ютером чи два гравці
    bool finished = false;          //гра закінчена

    QGraphicsScene *scene;  // покажчик на графічну сцену
    PrinterCards printer;   // рисувальщик карт

    int number_card_of_distrib = 6;   // кількість карт при роздачі
    CardsDeck cards_deck;             //колода карт
    CardsHands cards_hands1;          // руки першого гравця
    CardsHands cards_hands2;          // руки другого гравця

    bool put_three = false;           // флажок спрацьовує при кладенні 3
    bool put_four = false;            // флажок спрацьовує при кладенні 4
    bool put_eight = false;           // флажок спрацьовує при кладенні 8
    bool put_jocker = false;          // флажок спрацьовує при кладенні джокера
    pair<int,int> card_converted;     //карта на яку перетворений джокер чи вісім(тільки масть)

    QLabel* Deck_counter;           //вказівник на поле виводу кількості карт на екрані
    QLabel* Score_player1;          //вказівник на поле вивовуду штрафних балів 1 гравця
    QLabel* Score_player2;          //вказівник на поле вивовуду штрафних балів 2 гравця
    QLabel* Score_max;              //вказівник на поле виводу межі штрафних балів

    int max_score = 0;      //межа штрафних балів
    int score1 = 0;         //штрафні бали 1 гравця
    int score2 = 0;         //штрафні бали 1 гравця

    EnemyComputer enemy_computer;       //компютерний опоненет

    int time_move_pc = 1500;                   //час ходу компютера (в мс не враховуючи час обрахунку алго мінімакс)

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

        //Метод, що використовується для встановлення параметрів (для нової гри)
    void set_parameters(int max_score ,float height, float width, bool g_with_pc);

        // метод для встановлення вказіників на лейбли на ігровому полі
    void set_label(QLabel* counter, QLabel* score_player1, QLabel* score_player2, QLabel* score_max);

        //встановити значеннь обєктів колода, руки на ігровому полі (використ для загрузки збереженої гри)
    void set_cards_download(CardsDeck& deck, CardsHands& hands1, CardsHands& hands2);
        //встановити значення ігрових ефектів флажків і перет карти (використ під час загрузки гри)
    void set_flags_download( vector<bool> flags, pair<int,int> conv_card);
        //встановити параметри стану гри (для загрузки збереженої гри)
    void set_stategame_download(int who_move, int cur_move, bool game_pc, bool finished,vector<int> scores);

        //почати завантажену гру
    void start_download_game(float height, float width);

protected:
        // встановлення спільних параметрів координатів графічних обєктів ...
    void set_graphic_parameters(float height, float width);


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
    void move_computer();

    void comp_put_card_in_top(pair<int,int> card);

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

    void reset_flags();         //скинути флажки ефектів карт



            //гетери і сетери атрибутів класа
public:
    vector<bool> get_flags();               // отримати вектор значень флажків ефектів
    void set_flags(vector<bool> flags);     // встановити значення флажкам ефектам

    pair<int,int> get_card_converted();
    void set_card_converted(pair<int,int> card);

    bool get_game_with_pc();
    void set_game_with_pc(bool g_with_pc);

    bool get_finished();
    void set_finished(bool finish);

    int get_current_player();
    void set_current_player(int cur_player);

    int get_who_move_first();
    void set_who_move_first(int who_move);

    vector<int> get_scores();
    void set_scores(vector<int> scores);

    vector<pair<int,int>> get_cards_hands1();
    void set_cards_hands1(vector<pair<int,int>> cards);

    vector<pair<int,int>> get_cards_hands2();
    void set_cards_hands2(vector<pair<int,int>> cards);

    vector<pair<int,int>> get_cards_deck();
    void set_cards_deck( vector<pair<int,int>> cards);

    vector<pair<int,int>> get_diacardcards_deck();
    void set_discardcards_deck( vector<pair<int,int>> cards);

    pair<int,int> get_top_card();
    void set_top_card(pair<int,int> card);


};

#endif // GAMEBOARD_H

