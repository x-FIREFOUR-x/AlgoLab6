#include "cardshands.h"

#include<iostream>
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

bool CardsHands::pull_card_with_hands(QGraphicsItem* ptr_chosen_card)
{
    bool succses_card_chosen = false;

    for(int i =0; i < ptr_img_cards.size(); i++)
    {
        if(ptr_img_cards[i] == ptr_chosen_card)
        {
            succses_card_chosen = true;

            delete ptr_img_cards[i];
            ptr_img_cards[i] = nullptr;
            ptr_img_cards.erase(ptr_img_cards.begin() + i);

            cards_of_hands.erase(cards_of_hands.begin()+i);
        }
    }
    ptr_chosen_card = nullptr;
    return succses_card_chosen;
}

bool CardsHands::get_chosen_card(QGraphicsItem* ptr_chosen_card, pair<int,int>& chosen_card)
{
    bool succses_card_chosen = false;

    for(int i =0; i < ptr_img_cards.size(); i++)
    {
        if(ptr_img_cards[i] == ptr_chosen_card)
        {
            chosen_card = cards_of_hands[i];
            succses_card_chosen = true;
        }
    }

    return succses_card_chosen;
}

void CardsHands::discard_cards()
{
    for(int i =0; i<cards_of_hands.size(); i++)
    {
        delete ptr_img_cards[i];
        ptr_img_cards[i] = nullptr;
    }
    cards_of_hands.erase(cards_of_hands.begin(), cards_of_hands.end());
    ptr_img_cards.erase(ptr_img_cards.begin(), ptr_img_cards.end());

}
