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
    static QString type_file ;
    static QString path;
public:
    FileWorker();

    static QString get_filename();              //отримати ім'я файлу
    static QString get_path();                  //отримати шлях до файлів збереження
    static void set_filename(QString fname);    //встановити ім'я файлу
    static void set_path(QString fpath);        //встановити шлях до файлів збереження

    static QStringList list_files();            //отримати список всіх файлів збереження
    static bool is_already_file(QString fname);     //перевірка чи файл вже існує


                //зберегти необіхідні парметри в файл
    static void save_game_state(bool game_with_pc, bool finished, int who_move_first, int current_player, vector<int> scores);
    static void save_game_effects(vector<bool> flags, pair<int,int> converted);
    static void save_game_cards(typeVec hands1, typeVec hands2, typeVec deck, pair<int,int> top_card, typeVec discard);

                //зчитати необіхідні параметри з файлу
    static void download_game_state(bool& game_with_pc, bool& finished, int& who_move_first, int& current_player, vector<int>& scores);
    static void download_game_effects(vector<bool>& flags, pair<int,int>& converted);
    static void download_game_cards(typeVec& hands1, typeVec& hands2, typeVec& deck, pair<int,int>& top_card, typeVec& discard);

private:
    static void input_cards(ifstream& fin, typeVec& cards);     //зчитування набору карт з файлу
    static string all_name_file();                              //весь шлях до файлу
};

#endif // FILEWORKER_H
