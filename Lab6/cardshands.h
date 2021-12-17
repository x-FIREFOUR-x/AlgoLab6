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
    void set_y(int y);                          // встановити координату y малювання карт на столі
    void picture_cards_hands(PrinterCards& printer, QGraphicsScene*& scene);    //намалювати карти на руках в гравця на столі
    int get_count_cards();      //вернути кількість карт в гравця
};

#endif // CARDSHANDS_H
