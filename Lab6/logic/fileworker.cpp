#include "fileworker.h"
#include <iostream>

QString FileWorker::filename = "";
QString FileWorker::path = "\Saves\\";
QString FileWorker::type_file = ".txt";

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

string FileWorker::all_name_file()
{
    string all_filename;

    string str_path = path.toStdString();
    string str_filename = filename.toStdString();
    string str_type = type_file.toStdString();
    all_filename = str_path + str_filename + str_type;

    return all_filename;
}

QStringList FileWorker::list_files()
{
    QDir directory(FileWorker::get_path());
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);

    return files;
}

bool FileWorker::is_already_file(QString fname)
{
    bool file_exist = false;
    QStringList files = FileWorker::list_files();
    foreach(QString filename, files)
    {
        if (filename == fname + type_file)
        {
            file_exist = true;
            break;
        }
    }
    return file_exist;
}
void FileWorker::remove_file(QString fname)
{
    QString all_fname = path + fname + type_file;
    QDir dir;
    dir.remove(all_fname);
}

void FileWorker::save_game_state(bool game_with_pc, bool finished, int who_move_first, int current_player, vector<int> scores)
{
    ofstream fout;
    fout.open(all_name_file());

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
    fout.open(all_name_file(),ios::out | ios::app);
        // flags effect 3 4 8 joker
    fout << flags[0] << " " << flags[1] << " " << flags[2] << " " << flags[3] << "\n";
    fout << converted.first << " " << converted.second << "\n";

    fout.close();
}
void FileWorker::save_game_cards(typeVec hands1, typeVec hands2, typeVec deck, pair<int,int> top_card, typeVec discard)
{
    ofstream fout;
    fout.open(all_name_file(),ios::out | ios::app);

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
    fin.open(all_name_file());

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


        for(int i = 0; i < 3; i++)              //???????????????????? ???????? ?? ???????????? ?? ?????????? ????????????
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
    fin.open(all_name_file());

    string read_str;
    fin >> read_str;
    if (read_str == "LastPlayer")
    {
        for(int i =0; i < 7; i++)       //?????????????????????? ?????????? ?????? ???? ???????????????????????? ???????? ???????????????? ?? ??????????
            fin >> read_str;


        for (int i =0; i < 4; i++)      //???????????????????? ?????????????? ?? ?????????? ????????????
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
    fin.open(all_name_file());

    string read_str;
    fin >> read_str;
    if (read_str == "LastPlayer")
    {
        for(int i =0; i < 13; i++)       //?????????????????????? ?????????? ?????? ???? ???????????????????????? ???????? ???????????????? ?? ??????????
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
