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

void PrinterCards::set_coordinate(float x_deck, float y_deck, float x_top_c, float y_top_c)
{
    x_cards_deck = x_deck;
    y_cards_deck = y_deck;
    x_top_card = x_top_c;
    y_top_card = y_top_c;
}

void PrinterCards::set_side(float width1, float height1)
{
    width = width1;
    height = height1;
}

float PrinterCards::get_width()
{
    return width;
}

float PrinterCards::get_height()
{
    return height;
}

float PrinterCards::get_x_cards_deck()
{
    return x_cards_deck;
}

float PrinterCards::get_y_cards_deck()
{
    return y_cards_deck;
}

float PrinterCards::get_x_top_card()
{
    return x_top_card;
}

float PrinterCards::get_y_top_card()
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
    QPixmap image_deck(":/image/PNG-cards/cards/back.png");
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
     namefile_card = ":/image/PNG-cards/cards/" + namefile_card;
     QString path;
     path = QString::fromStdString(namefile_card);

     QPixmap image_deck(path);
     image_deck = image_deck.scaled(width, height);
     QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
     ptr_gi_card->setPos(x, y);
     return ptr_gi_card;
 }

 QGraphicsItem* PrinterCards::print_backcard(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y)
 {

     QPixmap image_deck(":/image/PNG-cards/cards/back.png");
     image_deck = image_deck.scaled(width, height);
     QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
     ptr_gi_card->setPos(x, y);
     return ptr_gi_card;
 }

 QGraphicsItem* PrinterCards::print_cards_deck(QGraphicsScene*& scene)
 {
     delete ptr_card_deck;
     ptr_card_deck = nullptr;

     QPixmap image_deck(":/image/PNG-cards/cards/back.png");
     image_deck = image_deck.scaled(width, height);
     ptr_card_deck = scene->addPixmap(image_deck);
     ptr_card_deck->setPos(x_cards_deck, y_cards_deck);

     return ptr_card_deck;
 }

 QGraphicsItem* PrinterCards::print_top_card(std::pair<int,int> card ,QGraphicsScene*& scene)
 {
     int index_card = 4 * (card.first - 2) + card.second;

     std::string namefile_card = namefile_cards[index_card];
     namefile_card = ":/image/PNG-cards/cards/" + namefile_card;
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

 void PrinterCards::print_converted_card(std::pair<int,int> card ,QGraphicsScene*& scene)
 {
    erase_converted_card();
    ptr_card_converted_card = print_card(card,scene, x_top_card + 1.5* width, y_top_card);
 }

 void PrinterCards::erase_converted_card()
 {
     delete ptr_card_converted_card;
     ptr_card_converted_card = nullptr;
 }

 void PrinterCards::print_marc_move(QGraphicsScene*& scene, int current_player, float x_mark_players, float y_mark_player1, float y_mark_player2, float size)
 {
     x_mark_move_players = x_mark_players;
     y_mark_move_player1 = y_mark_player1;
     y_mark_move_player2 = y_mark_player2;

     QPixmap image_mark(":/image/PNG-cards/other/mark.png");
     image_mark = image_mark.scaled(size, size);
     ptr_mark_move = scene->addPixmap(image_mark);

     if(current_player == 1)
        ptr_mark_move->setPos(x_mark_move_players, y_mark_move_player1);
     else
        ptr_mark_move->setPos(x_mark_move_players, y_mark_move_player2);

     scene->update();

 }
 void PrinterCards::print_change_move(QGraphicsScene*& scene, int current_player)
 {
     if(current_player == 1)
        ptr_mark_move->setPos(x_mark_move_players, y_mark_move_player1);
     else
        ptr_mark_move->setPos(x_mark_move_players, y_mark_move_player2);

      scene->update();
 }
void PrinterCards::erase_marc_move(QGraphicsScene*& scene)
{
    delete ptr_mark_move;
    ptr_mark_move = nullptr;
}
