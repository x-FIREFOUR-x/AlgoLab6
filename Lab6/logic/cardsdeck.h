#ifndef CARDSDECK_H
#define CARDSDECK_H

#include <vector>
#include <algorithm>
#include <logic/cardshands.h>
#include <logic/printercards.h>

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


    pair<int,int> get_top_card();               // отримати значення останньої покладеної карти
    void set_top_card(pair<int,int> top_c);     // встановити значення останньої покладеної карти

    int get_amount_card_in_deck();       //отримати кількість карт в колоді
    int get_amount_descarded_card();     //отримати кількість скинутих карт(крім верхньої)
    bool is_card_no_in_players();         // повертає true якщо є скинуті карти(крім верхньої) чи в колоді

    vector<pair<int,int>> get_deck_cards();         //повертає список карт в колоді
    void set_deck_cards(vector<pair<int,int>> deck);           //встановити список карт в колоді

    vector<pair<int,int>> get_discarded_cards();    //повертає список скинутих карт (включно з верхньою)

    vector<pair<int,int>> get_discard_cards();              //повертає список скинутих карт
    void set_discard_cards(vector<pair<int,int>> discard);  //встановити список скинутих карт
};

#endif // CARDSDECK_H
