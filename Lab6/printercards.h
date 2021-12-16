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

    int x_cards_deck;       //координата x малювання карти колоди на gameboard
    int y_cards_deck;       //координата y розміщення карти колоди на gameboard

    int x_top_card;         //координата x малювання останньої покладеної карти колоди на gameboard
    int y_top_card;         //координата y малювання останньої покладеної карти колоди на gameboard
public:
    PrinterCards();

            // встановлення значень координат малювання колоди і верхньої карти
    void set_coordinate(int x_deck, int y_deck, int x_top_c, int y_top_c);


    void set_side(int width, int height);

            // малювання рубашки карти на коордах x y розміру width height
    QGraphicsItem* print_back(QGraphicsScene*& scene, int x, int y);

            // малювання карти card на коордах x y розміру width height
    QGraphicsItem* print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y);

            // малювання колоди (рубашки карти розміру width height)
    QGraphicsItem* print_cards_deck(QGraphicsScene*& scene);

            // малювання верхньої карти (останньої покладеної карти розміру width height)
    QGraphicsItem* print_top_card(std::pair<int,int> card ,QGraphicsScene*& scene);

private:
    void push_namefile_bigcards(std::string name);
};

#endif // PRINTERCARDS_H
