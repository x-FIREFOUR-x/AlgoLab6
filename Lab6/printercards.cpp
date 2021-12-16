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
}
void PrinterCards::push_namefile_bigcards(std::string name)
{
    namefile_cards.push_back(name + "_of_clubs.png");
    namefile_cards.push_back(name + "_of_diamonds.png");
    namefile_cards.push_back(name + "_of_hearts.png");
    namefile_cards.push_back(name + "_of_spades.png");
}
QGraphicsItem* PrinterCards::print_back(QGraphicsScene*& scene ,int x, int y, int width, int height)
{
    QPixmap image_deck(":/image/PNG-cards/back.png");
    image_deck = image_deck.scaled(width, height);
    QGraphicsItem* ptr_gi_card = scene->addPixmap(image_deck);
    ptr_gi_card->setPos(x, y);

    return ptr_gi_card;
}
 QGraphicsItem* PrinterCards::print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y, int width, int height)
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
