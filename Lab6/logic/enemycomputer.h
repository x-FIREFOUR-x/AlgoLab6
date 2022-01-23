#ifndef ENEMYCOMPUTER_H
#define ENEMYCOMPUTER_H

#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int const terminal_win = 0;                 //термінальне значення цінності виграш
int const terminal_lose = 1000;             //термінальне значення цінності програш
using t_list =  vector<pair<int,int>>;

struct StepNode
{
     vector<shared_ptr<StepNode>> ptr_nodes;        //вказівники на наступні вузли
     vector<pair<int,int>> card_deck;               //колода на поточному вузлі
     vector<pair<int,int>> discard_cards;           //скинуті карти на поточному вузлі
     vector<pair<int,int>> hands_computer;          //карти на руках в пк на поточному вузлі
     vector<pair<int,int>> hands_player;            // карти на руках гравця на поточному вузлі

     bool put_three;        //діє ефект 3
     bool put_four;         // діє ефект 4
     bool put_eight;        // діє ефект 8
     bool put_jocker;       // діє ефект джокера
     pair<int,int> card_converted;  //перетворена карта

     float value;       //цінність вузла


     StepNode(t_list card_deck, t_list discard_cards ,t_list hands_computer, t_list hands_player);
     void calculate_value();             //підрахунок цінності (0 термінальний стан виграша 1000 програш)
};


class EnemyComputer
{
    shared_ptr<StepNode> row;   // вказівник на поточний стан ігри(корінний вузол)
    int max_depth;              //максимальна глибина рекурсії
public:

    EnemyComputer();
    void set_date(t_list card_deck, t_list discard_cards ,t_list hands_computer, t_list hands_player, int depth = 2);       //встановити дані(стан гри розт карти глибина)
    void set_flags(bool put_three, bool put_four, bool put_eigh, bool put_jocker, pair<int,int> card_converted);        //встановити флажки гри

    pair<int,int> mini_max();           //мінімакс

    float min(shared_ptr<StepNode> cur_node, int current_depth);        //виклик мінімізатора
    float chanse_min(shared_ptr<StepNode> cur_node, int current_depth); //виклик мінімазатора з шансовими вузлами (можливі руки гравця)
    float max(shared_ptr<StepNode> cur_node, int current_depth);        //виклик максимізатора

private:
    bool can_put(t_list discard_cards, pair<int,int> card, shared_ptr<StepNode>& ptr_node );    //перевірка можливості хода

};

#endif // ENEMYCOMPUTER_H
