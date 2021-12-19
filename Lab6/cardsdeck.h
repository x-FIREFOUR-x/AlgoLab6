#ifndef CARDSDECK_H
#define CARDSDECK_H

#include <vector>
#include <algorithm>
#include <cardshands.h>
#include <printercards.h>

using namespace std;
class CardsDeck
{
private:
    vector<pair<int,int>> deck_cards;               //колода
    pair<int,int> top_card;                         //остання покладена карта
    vector<pair<int,int>> discarded_cards;          //аокладены карти

public:
    CardsDeck();

        // роздача карт
    void distribution (int number_card, CardsHands& hands1, CardsHands& hands2);
        //перероздача карт
    void collect_cards(PrinterCards& printer);

        //взяти карту з колоди
    pair<int,int> take_card();

        //покласти карту
    void put_card(pair<int,int> card, QGraphicsScene*& scene, PrinterCards& printer);

        // отримати значення останньої покладеної карти
    pair<int,int> get_top_card();


    int get_amount_card_in_deck();       //отримати кількість карт в колоді
    int get_amount_descarded_card();     //отримати кількість скинутих карт(крім верхньої)
    bool is_card_no_in_players();         // повертає true якщо є скинуті карти(крім верхньої) чи в колоді

};

#endif // CARDSDECK_H
