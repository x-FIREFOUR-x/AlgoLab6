#ifndef CARDSDECK_H
#define CARDSDECK_H

#include <vector>
#include <algorithm>
#include <cardshands.h>

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

        //взяти карту з колоди
    pair<int,int> take_card();

        //покласти карту
    void put_card(pair<int,int> card);

        // отримати значення останньої покладеної карти
    pair<int,int> get_top_card();
};

#endif // CARDSDECK_H
