#ifndef CARDSHANDS_H
#define CARDSHANDS_H

#include<vector>

using namespace std;
class CardsHands
{
private:
    vector<pair<int,int>> cards_of_hands;       //карти на руках
public:
    CardsHands();
    void give_card(pair<int,int> card);         //дати карту в руки гравцю
};

#endif // CARDSHANDS_H
