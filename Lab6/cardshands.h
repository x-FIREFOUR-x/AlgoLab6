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
    int get_count_cards();              //вернути кількість карт в гравця

    void picture_cards_hands(PrinterCards& printer, QGraphicsScene*& scene);    //намалювати карти на руках в гравця на столі

        //дати chosen_card карту вибрану гравецем (повертає булеву змінну true вибрана коректно false не коректно)
    bool get_chosen_card(QGraphicsItem* ptr_chosen_card, pair<int,int>& chosen_card);
        //витянути карту з рук і покласти на стіл вибрану гравцем
    bool pull_card_with_hands(QGraphicsItem* ptr_chosen_card);
};

#endif // CARDSHANDS_H
