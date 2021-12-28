#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include "gameboard.h"
#include <iostream>

GameWindow::GameWindow(int max_score, bool g_with_pc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_board= ui->graphicsView;
    game_board->set_label(ui->CountCardDeck, ui->labelScore1, ui->labelScore2, ui->MaxScore);
    game_board->set_parameters(max_score, ui->graphicsView->height(), ui->graphicsView->width(), g_with_pc);
    setFixedSize(this->width(), this->height());

}

GameWindow::GameWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_board= ui->graphicsView;
    game_board->set_label(ui->CountCardDeck, ui->labelScore1, ui->labelScore2, ui->MaxScore);


    bool game_with_pc;
    bool finished;
    int who_first_move;
    int cur_move;
    vector<int> scores;
    FileWorker::download_game_state(game_with_pc,finished,who_first_move,cur_move, scores);

    //std::cout << game_with_pc << std::endl<< finished<< std::endl<<who_first_move<< std::endl<<cur_move<< std::endl;
    //std::cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;

    vector<bool> flags;
    pair<int,int> conv;
    FileWorker::download_game_effects(flags, conv);

    //std::cout << flags[0] << " " << flags[1] << " " << flags[2] << " " << flags[3] << endl;
    //std::cout << conv.first << " " << conv.second << endl;


    vector<pair<int,int>> hands1;
    vector<pair<int,int>> hands2;
    vector<pair<int,int>> deck;
    pair<int,int> top_card;
    vector<pair<int,int>> discard;
    FileWorker::download_game_cards(hands1, hands2, deck, top_card, discard);

    /*std::cout << hands1.size() << endl;
    for (int i =0; i < hands1.size() ; i++ ) {
        cout << hands1[i].first << ":" << hands1[i].second << " ";
    }

    std::cout << endl << hands2.size() << endl;
    for (int i =0; i < hands2.size() ; i++ ) {
        cout << hands2[i].first << ":" << hands2[i].second << " ";
    }


    std::cout << endl << deck.size() << endl;
    for (int i =0; i <  deck.size() ; i++ ) {
        cout <<  deck[i].first << ":" <<  deck[i].second << " ";
    }

    cout << endl << top_card.first << ":" << top_card.second << endl;

    std::cout << endl << discard.size() << endl;
    for (int i =0; i <  discard.size() ; i++ ) {
        cout <<  discard[i].first << ":" <<  discard[i].second << " ";
    }
    cout << endl;*/

    //game_board->set_parameters(max_score, ui->graphicsView->height(), ui->graphicsView->width(), g_with_pc);
    setFixedSize(this->width(), this->height());
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_CloseEnd_triggered()
{
    this->close();
    MainWindow * menu = new MainWindow;
    menu->setWindowTitle("Останній гравець");
    menu->show();
}

void GameWindow::on_Save_triggered()
{
    if(FileWorker::get_filename() == "")
        on_SaveAs_triggered();
    else
        save_game();
}


void GameWindow::on_SaveAs_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("Збереження файла"), FileWorker::get_path(), tr("Текстовий файл(*.txt)"));
    FileWorker::set_filename(file_name);
    save_game();
}

void GameWindow::save_game()
{
    bool game_with_pc = game_board->get_game_with_pc();
    bool finished = game_board->get_finished();
    int who_move_first =  game_board->get_who_move_first();
    int current_player = game_board->get_current_player();
    vector<int> scores = game_board->get_scores();

    FileWorker::save_game_state(game_with_pc,finished, who_move_first, current_player, scores);


    vector<bool> flags = game_board->get_flags();
    pair<int,int> converted_card = game_board->get_card_converted();

    FileWorker::save_game_effects(flags, converted_card);


    vector<pair<int,int>> hands1 = game_board->get_cards_hands1();
    vector<pair<int,int>> hands2 = game_board->get_cards_hands2();
    vector<pair<int,int>> deck = game_board->get_cards_deck();
    pair<int,int> top_card = game_board->get_top_card();
    vector<pair<int,int>> discard = game_board->get_diacardcards_deck();

    FileWorker::save_game_cards(hands1, hands2, deck, top_card, discard);
}
