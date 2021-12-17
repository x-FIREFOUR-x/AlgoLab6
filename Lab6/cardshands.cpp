#include "cardshands.h"


CardsHands::CardsHands()
{

}

void CardsHands::give_card(pair<int,int> card)
{
    cards_of_hands.push_back(card);
}

void CardsHands::set_y(int y)
{
    y_hands = y;
}

void CardsHands::picture_cards_hands(PrinterCards& printer, QGraphicsScene*& scene)
{
    for(int i =0; i < ptr_img_cards.size(); i++)
    {
        delete ptr_img_cards[i];
        ptr_img_cards[i] = nullptr;
    }
    ptr_img_cards.clear();

    int x = 25;
    QGraphicsItem* ptr;
    for(int i =0; i < cards_of_hands.size(); i++)
    {
       ptr = printer.print_card(cards_of_hands[i],scene,x,y_hands);
       ptr_img_cards.push_back(ptr);
        x+=25;
    }
}
int CardsHands::get_count_cards()
{
    return cards_of_hands.size();
}
