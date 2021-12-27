#include "fileworker.h"

QString FileWorker::filename = "";
QString FileWorker::path = "\Saves";

FileWorker::FileWorker()
{

}
QString FileWorker::get_filename()
{
    return filename;
}
QString FileWorker::get_path()
{
    return path;
}
void FileWorker::set_filename(QString fname)
{
    filename = fname;
}
void FileWorker::set_path(QString fpath)
{
    path = fpath;
}

void FileWorker::save_game_state(bool game_with_pc, bool finished, int who_move_first, int current_player, vector<int> scores)
{
    ofstream fout;
    fout.open(filename.toStdString());

    fout << "LastPlayer" << "\n";
    fout << who_move_first << " " << current_player << "\n";
    fout <<  game_with_pc << "\n";       //game_with_pc
    fout <<  finished << "\n";       //finished

    fout << scores[0] << " " << scores[1] << " " << scores[2] << "\n" ;

    fout.close();
}
void FileWorker::save_game_effects(vector<bool> flags, pair<int,int> converted)
{
    ofstream fout;
    fout.open(filename.toStdString(),ios::out | ios::app);
        // flags effect 3 4 8 joker
    fout << flags[0] << " " << flags[1] << " " << flags[2] << " " << flags[3] << "\n";
    fout << converted.first << " " << converted.second << "\n";

    fout.close();
}
void FileWorker::save_game_cards(typeVec hands1, typeVec hands2, typeVec deck, pair<int,int> top_card, typeVec discard)
{
    ofstream fout;
    fout.open(filename.toStdString(),ios::out | ios::app);

    fout << hands1.size() << "\n";
    for(int i =0; i <hands1.size(); i++)
    {
        fout << hands1[i].first << " " << hands1[i].second << ";" ;
    }
    fout << "\n";

    fout << hands2.size() << "\n";
    for(int i =0; i <hands2.size(); i++)
    {
        fout << hands2[i].first << " " << hands2[i].second << ";" ;
    }
    fout << "\n";

    fout << deck.size() << "\n";
    for(int i =0; i <deck.size(); i++)
    {
        fout << deck[i].first << " " << deck[i].second << ";" ;
    }
    fout << "\n";

    fout << top_card.first << " " << top_card.second << "\n";

    fout << discard.size() << "\n";
    for(int i =0; i < discard.size(); i++)
    {
        fout << discard[i].first << " " << discard[i].second << ";" ;
    }
    fout << "\n";

    fout.close();
}
