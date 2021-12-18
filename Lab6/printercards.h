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

    int width;         //ширина карти
    int height;        //висота карти

    int size_mark;                // розмір мітки
    int x_mark_move_players;      //координата x малювання мітки біля гравця чий хід
    int y_mark_move_player1;      //координата y малювання мітки біля гравця1
    int y_mark_move_player2;      //координата y малювання мітки біля гравця2

    int x_cards_deck;       //координата x малювання карти колоди на gameboard
    int y_cards_deck;       //координата y розміщення карти колоди на gameboard

    int x_top_card;         //координата x малювання останньої покладеної карти колоди на gameboard
    int y_top_card;         //координата y малювання останньої покладеної карти колоди на gameboard

    QGraphicsItem* ptr_card_deck = nullptr;                 //вказівник на малюнок колоди
    QGraphicsItem* ptr_card_converted_card = nullptr;     // вказівник на малюнок карти яку вибрали (8-ою або джокером)

    QGraphicsItem* ptr_mark_move= nullptr;          //

public:
    PrinterCards();

            // встановлення значень координат малювання колоди і верхньої карти
    void set_coordinate(int x_deck, int y_deck, int x_top_c, int y_top_c);


    void set_side(int width, int height);

    int get_width();
    int get_height();

    int get_x_cards_deck();
    int get_y_cards_deck();

    int get_x_top_card();
    int get_y_top_card();

            // малювання рубашки карти на коордах x y розміру width height
    QGraphicsItem* print_back(QGraphicsScene*& scene, int x, int y);

            // малювання карти card на коордах x y розміру width height
    QGraphicsItem* print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y);

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

    void print_marc_move(QGraphicsScene*& scene, int current_player, int x_mark_players, int y_mark_player1, int y_mark_player2, int size);
    void print_change_move(QGraphicsScene*& scene, int current_player);

private:
    void push_namefile_bigcards(std::string name);
};

#endif // PRINTERCARDS_H
