#ifndef ENEMYCOMPUTER_H
#define ENEMYCOMPUTER_H

#include <vector>
#include <memory>
using namespace std;

int const terminal_win = 0;
int const terminal_lose = 1000;
using t_list =  vector<pair<int,int>>;

struct StepNode
{
     vector<shared_ptr<StepNode>> ptr_nodes;
     vector<pair<int,int>> card_deck;
     vector<pair<int,int>> discard_cards;
     vector<pair<int,int>> hands_computer;
     vector<pair<int,int>> hands_player;

     bool put_three;
     bool put_four;
     bool put_eight;
     bool put_jocker;
     pair<int,int> card_converted;

     float value;
     StepNode(t_list card_deck, t_list discard_cards ,t_list hands_computer, t_list hands_player);
     void calculate_value();             //підрахунок цінності (0 термінальний стан виграша 1000 програш)
};


class EnemyComputer
{
    shared_ptr<StepNode> row;
    int max_depth;
public:

    EnemyComputer();
    void set_date(t_list card_deck, t_list discard_cards ,t_list hands_computer, t_list hands_player);
    void set_flags(bool put_three, bool put_four, bool put_eigh, bool put_jocker, pair<int,int> card_converted);
    pair<int,int> mini_max();
    float min(shared_ptr<StepNode> row, int current_depth);

private:
    bool can_put(t_list discard_cards, pair<int,int> card, shared_ptr<StepNode>& ptr_node );

};

#endif // ENEMYCOMPUTER_H
