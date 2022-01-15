#include "fileworker.h"
#include <iostream>

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
    fout << who_move_first << "\n";
    fout << current_player << "\n";
    fout <<  game_with_pc << "\n";
    fout <<  finished << "\n";

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
        fout << hands1[i].first << ":" << hands1[i].second << " " ;
    }
    fout << "\n";

    fout << hands2.size() << "\n";
    for(int i =0; i <hands2.size(); i++)
    {
        fout << hands2[i].first << ":" << hands2[i].second << " " ;
    }
    fout << "\n";

    fout << deck.size() << "\n";
    for(int i =0; i <deck.size(); i++)
    {
        fout << deck[i].first << ":" << deck[i].second << " " ;
    }
    fout << "\n";

    fout << top_card.first << ":" << top_card.second << "\n";

    fout << discard.size() << "\n";
    for(int i =0; i < discard.size(); i++)
    {
        fout << discard[i].first << ":" << discard[i].second << " " ;
    }
    fout << "\n";

    fout.close();
}

void FileWorker::download_game_state(bool& game_with_pc, bool& finished, int& who_move_first, int& current_player, vector<int>& scores)
{
    ifstream fin;
    fin.open(filename.toStdString());

    string read_str;
    fin >> read_str;
    if (read_str == "LastPlayer")
    {
        fin >> read_str;
        who_move_first = stoi(read_str);

        fin >> read_str;
        current_player = stoi(read_str);

        int buf_bool;

        fin >> read_str;
        buf_bool = stoi(read_str);
        game_with_pc = buf_bool;

        fin >> read_str;
        buf_bool = stoi(read_str);
        finished = buf_bool;


        for(int i = 0; i < 3; i++)              //зчитування очок з файлів з одної строки
        {
            fin >> read_str;
            scores.push_back(stoi(read_str));
        }

    }
    fin.close();
}
void FileWorker::download_game_effects(vector<bool>& flags, pair<int,int>& converted)
{
    ifstream fin;
    fin.open(filename.toStdString());

    string read_str;
    fin >> read_str;
    if (read_str == "LastPlayer")
    {
        for(int i =0; i < 7; i++)       //пропускаємо рядки які не оброблюються цією функцією в файлі
            fin >> read_str;


        for (int i =0; i < 4; i++)      //зчитування флажків з одної строки
        {
            fin >> read_str;
            flags.push_back(stoi(read_str));
        }



        fin >> read_str;
        int rank = stoi(read_str);
        fin >> read_str;
        int suit = stoi(read_str);
        converted = pair<int,int>(rank,suit);

    }
    fin.close();
}
void FileWorker::download_game_cards(typeVec& hands1, typeVec& hands2, typeVec& deck, pair<int,int>& top_card, typeVec& discard)
{
    ifstream fin;
    fin.open(filename.toStdString());

    string read_str;
    fin >> read_str;
    if (read_str == "LastPlayer")
    {
        for(int i =0; i < 13; i++)       //пропускаємо рядки які не оброблюються цією функцією в файлі
            fin >> read_str;

        input_cards(fin, hands1);

        input_cards(fin, hands2);

        input_cards(fin, deck);


        int pos;
        int rank;
        int suit;
        string buf;
        string read_str;
        fin >> read_str;
        pos = read_str.find(":");

        buf = read_str;
        buf = buf.substr(0, pos);
        rank = stoi(buf);

        buf = read_str;
        buf = buf.substr(pos+1, buf.size() - pos - 1);
        suit = stoi(buf);

        top_card = pair<int,int>(rank,suit);


        input_cards(fin, discard);


    }
    fin.close();
}

void FileWorker::input_cards(ifstream& fin, typeVec& cards)
{
    int pos;
    int rank;
    int suit;
    string buf;
    string read_str;

    fin >> read_str;
    int amount_hands1 = stoi(read_str);
    for(int i =0; i< amount_hands1; i++)
    {
        fin >> read_str;
        pos = read_str.find(":");

        buf = read_str;
        buf = buf.substr(0, pos);
        rank = stoi(buf);

        buf = read_str;
        buf = buf.substr(pos+1, buf.size() - pos - 1);
        suit = stoi(buf);

        cards.push_back(pair<int,int>(rank,suit));
    }
}
