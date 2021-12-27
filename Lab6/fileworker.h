#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QFileDialog>
#include <QString>
#include <vector>
#include <fstream>

using namespace std;
using typeVec = vector<pair<int,int>>;
class FileWorker
{
private:
    static QString filename;
    static QString path;
public:
    FileWorker();

    static QString get_filename();
    static QString get_path();
    static void set_filename(QString fname);
    static void set_path(QString fpath);

    static void save_game_state(bool game_with_pc, bool finished, int who_move_first, int current_player, vector<int> scores);
    static void save_game_effects(vector<bool> flags, pair<int,int> converted);
    static void save_game_cards(typeVec hands1, typeVec hands2, typeVec deck, pair<int,int> top_card, typeVec discard);
};

#endif // FILEWORKER_H
