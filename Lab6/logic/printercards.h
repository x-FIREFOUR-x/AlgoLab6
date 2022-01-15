#ifndef PRINTERCARDS_H
#define PRINTERCARDS_H

#include<string>
#include<vector>
#include <QGraphicsItem>
#include <QBrush>

class PrinterCards
{
private:
    std::vector<std::string> namefile_cards;        //масив імен файлів картинок карт

    float width;         //ширина карти
    float height;        //висота карти

    float size_mark;                // розмір мітки
    float x_mark_move_players;      //координата x малювання мітки біля гравця чий хід
    float y_mark_move_player1;      //координата y малювання мітки біля гравця1
    float y_mark_move_player2;      //координата y малювання мітки біля гравця2

    float x_cards_deck;       //координата x малювання карти колоди на gameboard
    float y_cards_deck;       //координата y розміщення карти колоди на gameboard

    float x_top_card;         //координата x малювання останньої покладеної карти колоди на gameboard
    float y_top_card;         //координата y малювання останньої покладеної карти колоди на gameboard

    QGraphicsItem* ptr_card_deck = nullptr;               //вказівник на малюнок колоди
    QGraphicsItem* ptr_card_converted_card = nullptr;     //вказівник на малюнок карти яку вибрали (8-ою або джокером)
    QGraphicsItem* ptr_mark_move= nullptr;                //вказівник на мітку відображення ходу

public:
    PrinterCards();

            // встановлення значень координат малювання колоди і верхньої карти
    void set_coordinate(float x_deck, float y_deck, float x_top_c, float y_top_c);
            //встановлення розмірів карти   (в пікселях)
    void set_side(float width, float height);

    float get_width();    //отримання ширини карти(в пікселях)
    float get_height();   //отримання висоти карти (в пікселях)

    float get_x_cards_deck();     //отримання координати x малювання колоди (в пікселях)
    float get_y_cards_deck();     //отримання координати y малювання колоди (в пікселях)

    float get_x_top_card();       //отримання координати x малювання верхньої карти (в пікселях)
    float get_y_top_card();       //отримання координати y малювання верхньої карти (в пікселях)

            // малювання рубашки карти на коордах x y розміру width height
    QGraphicsItem* print_back(QGraphicsScene*& scene, int x, int y);

            // малювання карти card на коордах x y розміру width height
    QGraphicsItem* print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y);
        // малювання карти card закритою на коордах x y розміру width height
    QGraphicsItem* print_backcard(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y);

            // малювання колоди (рубашки карти розміру width height)
    QGraphicsItem* print_cards_deck(QGraphicsScene*& scene);
            // стерти малюнок колоди
    void erase_cards_deck();

            // малювання верхньої карти (останньої покладеної карти розміру width height)
    QGraphicsItem* print_top_card(std::pair<int,int> card ,QGraphicsScene*& scene);



            //намалювати карту в яку перетворено 8-ку або джокера
    void print_converted_card(std::pair<int,int> card ,QGraphicsScene*& scene);
            //стерти карту в яку перетворено 8-ку або джокера
    void erase_converted_card();

            //малювання мітки відображення ходу (чий хід)
    void print_marc_move(QGraphicsScene*& scene, int current_player, float x_mark_players, float y_mark_player1, float y_mark_player2, float size);
            //зміна положення мітки відображення ходу (чий хід) (зміна ходу)
    void print_change_move(QGraphicsScene*& scene, int current_player);
            //видалення мітки відображення ходу (чий хід)
    void erase_marc_move(QGraphicsScene*& scene);

private:
        //присвоєння значень списку namefile_cards шляхв до картинок великих карт J, Q, K, A
    void push_namefile_bigcards(std::string name);

};

#endif // PRINTERCARDS_H
