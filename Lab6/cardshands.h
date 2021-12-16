#ifndef CARDSHANDS_H
#define CARDSHANDS_H

#include<vector>
#include<QGraphicsItem>
#include<printercards.h>

using namespace std;
class CardsHands
{
private:
    int y_hands;                                      //рівень малювання карт на руках в гравця
    vector<pair<int,int>> cards_of_hands;       //карти на руках
    vector<QGraphicsItem*> ptr_img_cards;
public:
    CardsHands();
    void give_card(pair<int,int> card);         //дати карту в руки гравцю
    void set_y(int y);
    void picture_cards_hands(PrinterCards& printer, QGraphicsScene*& scene);
};

#endif // CARDSHANDS_H
