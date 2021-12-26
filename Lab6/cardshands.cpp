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

void CardsHands::picture_cards_hands(PrinterCards& printer, QGraphicsScene*& scene, float width_board)
{
    for(int i =0; i < ptr_img_cards.size(); i++)
    {
        delete ptr_img_cards[i];
        ptr_img_cards[i] = nullptr;
    }
    ptr_img_cards.clear();

    float x = width_board / 36;

    float backdown = width_board - (2 * x) - printer.get_width();
    backdown = backdown / (cards_of_hands.size() - 1);

    QGraphicsItem* ptr;
    for(int i =0; i < cards_of_hands.size(); i++)
    {
       ptr = printer.print_card(cards_of_hands[i],scene,x,y_hands);
       ptr_img_cards.push_back(ptr);
        x+=backdown;
    }
}

void CardsHands::picture_backcards_hands(PrinterCards& printer, QGraphicsScene*& scene, float width_board)
{
    for(int i =0; i < ptr_img_cards.size(); i++)
    {
        delete ptr_img_cards[i];
        ptr_img_cards[i] = nullptr;
    }
    ptr_img_cards.clear();

    float x = width_board / 36;

    float backdown = width_board - (2 * x) - printer.get_width();
    backdown = backdown / (cards_of_hands.size() - 1);

    QGraphicsItem* ptr;
    for(int i =0; i < cards_of_hands.size(); i++)
    {
       ptr = printer.print_backcard(cards_of_hands[i],scene,x, y_hands);
       ptr_img_cards.push_back(ptr);
        x+=backdown;
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

int CardsHands::calculate_scorecards()
{
    int score = 0;
    for(int i = 0; i < cards_of_hands.size(); i++)
    {
        switch (cards_of_hands[i].first)
        {
            case 8: score+=25; break;
            case 10: score+=10; break;
            case 11: score+=10; break;
            case 12: score+=10; break;
            case 13: score+=10; break;
            case 14: score+=15; break;
            case 15: score+=40; break;
            default: break;
        }
    }

    return score;
}

vector<pair<int,int>> CardsHands::get_cards()
{
    return cards_of_hands;
}
QGraphicsItem* CardsHands::get_ptr_image_card(pair<int,int> card)
{
    for(int i =0; i <cards_of_hands.size(); i++)
    {
        if (cards_of_hands[i] == card)
        {
            return ptr_img_cards[i];
        }
    }
}

int CardsHands::suit_which_most()
{
    int max_count = 0;
    int suit = 0;
    for(int i =0; i < 4; i++)
    {
        int count =0;
        for(int j =0; j < cards_of_hands.size(); j++)
        {
            if(cards_of_hands[j].second == i && cards_of_hands[j].first !=8)
            {
                count++;
            }
        }
        if(max_count < count)
        {
            max_count = count;
            suit = i;
        }
    }

    return suit;
}
