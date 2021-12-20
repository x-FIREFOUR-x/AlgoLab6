#include "enemycomputer.h"
StepNode::StepNode(t_list deck, t_list discard ,t_list computer, t_list player)
{
    card_deck = deck;
    discard_cards = discard;
    hands_computer = computer;
    hands_player = player;

    value = -1;
}
void StepNode::calculate_value()
{
    if (hands_player.size() == 0)
    {
        value = terminal_lose;
    }
    else
    {
        if(hands_computer.size() == 0)
        {
            value = terminal_win;
        }
        else
        {
            value = 0;
            for(int i =0; i<hands_computer.size(); i++)
            {
                switch (hands_computer[i].first)
                {
                    case 14: value += 10; break;
                    case 13: value += 9; break;
                    case 12: value += 9; break;
                    case 10: value += 9; break;
                    case 11: value += 7; break;
                    case  5: value += 6; break;
                    case  8: value += 5; break;
                    case 15: value += 4; break;
                    case  4: value += 3; break;
                    case  2: value += 2; break;
                    case  3: value += 1; break;
                    default: value += 7; break;
                }
            }
        }
    }

}

void EnemyComputer::set_flags(bool put_three, bool put_four, bool put_eigh, bool put_jocker, pair<int,int> card_converted)
{
    row->put_three = put_three;
    row->put_four = put_four;
    row->put_eight = put_eigh;
    row->put_jocker = put_jocker;
    row->card_converted = card_converted;
}

EnemyComputer::EnemyComputer()
{

}

void EnemyComputer::set_date(t_list card_deck, t_list discard_cards ,t_list hands_computer, t_list hands_player)
{
    row = make_shared<StepNode>(card_deck, discard_cards, hands_computer, hands_player);
    max_depth = 1;
}

pair<int,int> EnemyComputer::mini_max()
{
    int index = -1 ;
    int current_depth = 0;
    int val;
    for(int i =0; i < row->hands_computer.size(); i++)          //перебір можливих варіантів положити карту
    {

        if (can_put(row->discard_cards, row->hands_computer[i], row))
        {
            vector<pair<int,int>> new_hands_comp;
            new_hands_comp = row->hands_computer;
            new_hands_comp.erase(new_hands_comp.begin()+i);

            vector<pair<int,int>> new_dis_card;
            new_dis_card = row->discard_cards;
            new_dis_card.push_back(row->hands_computer[i]);

            row->ptr_nodes.push_back(make_shared<StepNode>(row->card_deck, new_dis_card, new_hands_comp, row->hands_player));
            val = min(row->ptr_nodes.back(), current_depth+1);

            if(row->value == -1 || row->value > val )
            {
                row->value = val;
                index =i;
            }
        }
    }

    if(index != -1)
        return row->hands_computer[index];
    else
        return pair<int,int>(-1,-1);
}

float EnemyComputer::min(shared_ptr<StepNode> cur_node, int current_depth)
{
    int index = -1 ;
    if (current_depth < max_depth)
    {
        int val;
        for(int i =0; i < cur_node->hands_computer.size(); i++)          //перебір можливих варіантів положити карту
        {

            if (can_put(cur_node->discard_cards, cur_node->hands_computer[i], cur_node))
            {
                vector<pair<int,int>> new_hands_comp;
                new_hands_comp = cur_node->hands_computer;
                new_hands_comp.erase(new_hands_comp.begin()+i);

                vector<pair<int,int>> new_dis_card;
                new_dis_card = cur_node->discard_cards;
                new_dis_card.push_back(cur_node->hands_computer[i]);

                cur_node->ptr_nodes.push_back(make_shared<StepNode>(cur_node->card_deck, new_dis_card, new_hands_comp, cur_node->hands_player));
                //val = max(cur_node->ptr_nodes.back(), current_depth+1);
            }

            if(cur_node->value == -1 || cur_node->value < val )
            {
                cur_node->value = val ;
                index = i;
            }
        }
    }
    else
    {
        cur_node->calculate_value();
    }


    return cur_node->value;
}

bool EnemyComputer::can_put(t_list discard_cards, pair<int,int> card, shared_ptr<StepNode>& ptr_node)
{

    bool correct_move = false;
    pair<int,int> top_card;
    if(ptr_node->put_jocker)
    {
        top_card = ptr_node->card_converted;
    }
    else
    {
        top_card = discard_cards.back();
    }


           //перевірка чи вибрана карта одного значення чи масті з верхньою
    if ((card.first == top_card.first) || (card.second == top_card.second))
    {
            correct_move = true;
    }

    if (top_card.first == 15 && ptr_node->put_jocker == false)         //якщо лежить джокер
    {
        correct_move = false;
        if(top_card.second == 0 && (card.second == 0 || card.second == 3 ))
            correct_move = true;

        if(top_card.second == 1 && (card.second == 1 || card.second == 2 ))
            correct_move = true;
    }

    if(top_card.first == 8 && ptr_node->put_eight)   //якщо лежить 8
    {
         correct_move = false;
         if (card.second == ptr_node->card_converted.second)
         {
             correct_move = true;
             //put_eight = false;
         }

    }

    if (card.first == 8 || card.first == 15)       // перевірка чи вибрана карта 8 чи джокер
    {
        correct_move = true;
    }

    if (ptr_node->put_four)              // якщо працює ефект четвьорки
    {
        correct_move = false;
        if (((card.first == (top_card.first + 1)) && (card.second == top_card.second)) || card.first == 15)
        {
            correct_move = true;
            if(card.first != 15)
            {
               //put_four = false;
            }
        }

    }

    if(ptr_node->put_three)
    {
        correct_move = true;
        //put_three = false;
    }

    if(ptr_node->put_jocker && correct_move == true && card.first != 15)
    {
       // put_jocker = false;
    }


   return correct_move;
}
