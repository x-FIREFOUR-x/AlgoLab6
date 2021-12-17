#include "cardsdeck.h"

CardsDeck::CardsDeck()
{
    for(int i = 2; i < 15; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            deck_cards.push_back(pair<int,int>(i,j));
        }
    }
    deck_cards.push_back(pair<int,int>(15,0));
    deck_cards.push_back(pair<int,int>(15,1));
}
void CardsDeck::distribution (int number_card, CardsHands& hands_player1, CardsHands& hands_player2)
{
    random_shuffle(deck_cards.begin(), deck_cards.end());

    pair<int,int>card;

    for(int i =0; i < number_card; i++)
    {
        card = deck_cards.back();
        deck_cards.pop_back();
        hands_player1.give_card(card);
    }

    for(int i =0; i < number_card; i++)
    {
        card = deck_cards.back();
        deck_cards.pop_back();
        hands_player2.give_card(card);
    }

    card = deck_cards.back();
    deck_cards.pop_back();
    top_card = card;
}

pair<int,int> CardsDeck::take_card()
{
    pair<int,int>card;
    if(deck_cards.size() == 0 )
    {
        deck_cards = discarded_cards;
        discarded_cards.clear();
        random_shuffle(deck_cards.begin(), deck_cards.end());
    }

    card = deck_cards.back();
    deck_cards.pop_back();
    return card;
}

void CardsDeck::put_card(pair<int,int> card, QGraphicsScene*& scene, PrinterCards& printer)
{
    discarded_cards.push_back(top_card);
    top_card = card;
    printer.print_cards_deck(scene);
}

pair<int,int> CardsDeck::get_top_card()
{
    return top_card;
}

int CardsDeck::get_amount_card_in_deck()
{
    return deck_cards.size();
}
int CardsDeck::get_amount_descarded_card()
{
    return discarded_cards.size();
}

bool CardsDeck::is_card_no_in_players()
{
    if (get_amount_card_in_deck() + get_amount_descarded_card() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
