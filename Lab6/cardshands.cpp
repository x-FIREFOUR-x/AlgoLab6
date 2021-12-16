#include "cardshands.h"


CardsHands::CardsHands()
{

}

void CardsHands::give_card(pair<int,int> card)
{
    cards_of_hands.push_back(card);
}
