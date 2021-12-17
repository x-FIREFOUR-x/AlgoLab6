#include "printercards.h"
#include <QGraphicsView>
#include <QString>
#include <iostream>
#include <QDebug>

PrinterCards::PrinterCards()
{
    for(int i = 2; i <= 10; i++)
    {
        std::string n = std::to_string(i);
        namefile_cards.push_back(n + "_of_clubs.png");
        namefile_cards.push_back(n + "_of_diamonds.png");
        namefile_cards.push_back(n + "_of_hearts.png");
        namefile_cards.push_back(n + "_of_spades.png");
    }
    push_namefile_bigcards("jack");
    push_namefile_bigcards("queen");
    push_namefile_bigcards("king");
    push_namefile_bigcards("ace");
    namefile_cards.push_back("black_joker.png");
    namefile_cards.push_back("red_joker.png");

    ptr_card_deck = nullptr;
}

void PrinterCards::set_coordinate(int x_deck, int y_deck, int x_top_c, int y_top_c)
{
    x_cards_deck = x_deck;
    y_cards_deck = y_deck;
    x_top_card = x_top_c;
    y_top_card = y_top_c;
}

void PrinterCards::set_side(int width1, int height1)
{
    width = width1;
    height = height1;
}

int PrinterCards::get_width()
{
    return width;
}

int PrinterCards::get_height()
{
    return height;
}

int PrinterCards::get_x_cards_deck()
{
    return x_cards_deck;
}

int PrinterCards::get_y_cards_deck()
{
    return y_cards_deck;
}

int PrinterCards::get_x_top_card()
{
    return x_top_card;
}

int PrinterCards::get_y_top_card()
{
    return y_top_card;
}

void PrinterCards::push_namefile_bigcards(std::string name)
{
    namefile_cards.push_back(name + "_of_clubs.png");
    namefile_cards.push_back(name + "_of_diamonds.png");
    namefile_cards.push_back(name + "_of_hearts.png");
    namefile_cards.push_back(name + "_of_spades.png");
}

QGraphicsItem* PrinterCards::print_back(QGraphicsScene*& scene ,int x, int y)
{
    QPixmap image_deck(":/image/PNG-cards/back.png");
    image_deck = image_deck.scaled(width, height);
    QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
    ptr_gi_card->setPos(x, y);

    return ptr_gi_card;
}

 QGraphicsItem* PrinterCards::print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y)
 {
            // 4 - карти одної масті, card.first номінал карти, 2 - карти починаються(індекси з 0), card.second номер масті (хреста, бубаб черва, піка)
     int index_card = 4 * (card.first - 2) + card.second;

     std::string namefile_card = namefile_cards[index_card];
     namefile_card = ":/image/PNG-cards/" + namefile_card;
     QString path;
     path = QString::fromStdString(namefile_card);

     QPixmap image_deck(path);
     image_deck = image_deck.scaled(width, height);
     QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
     ptr_gi_card->setPos(x, y);
     return ptr_gi_card;
 }

 QGraphicsItem* PrinterCards::print_cards_deck(QGraphicsScene*& scene)
 {
     delete ptr_card_deck;
     ptr_card_deck = nullptr;

     QPixmap image_deck(":/image/PNG-cards/back.png");
     image_deck = image_deck.scaled(width, height);
     ptr_card_deck = scene->addPixmap(image_deck);
     ptr_card_deck->setPos(x_cards_deck, y_cards_deck);

     return ptr_card_deck;
 }

 QGraphicsItem* PrinterCards::print_top_card(std::pair<int,int> card ,QGraphicsScene*& scene)
 {
     int index_card = 4 * (card.first - 2) + card.second;

     std::string namefile_card = namefile_cards[index_card];
     namefile_card = ":/image/PNG-cards/" + namefile_card;
     QString path;
     path = QString::fromStdString(namefile_card);

     QPixmap image_deck(path);
     image_deck = image_deck.scaled(width, height);
     QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
     ptr_gi_card->setPos(x_top_card, y_top_card);
     return ptr_gi_card;
 }

 void PrinterCards::erase_cards_deck()
 {
     delete ptr_card_deck;
     ptr_card_deck = nullptr;
 }
