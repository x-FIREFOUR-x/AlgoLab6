#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>
#include <QMessageBox>
#include "windows/windowsworker.h"

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

    download_game();
    game_board->start_download_game(ui->graphicsView->height(), ui->graphicsView->width());

    setFixedSize(this->width(), this->height());
}

GameWindow::~GameWindow()
{
    delete ui;
    delete game_board;
}

void GameWindow::on_CloseEnd_triggered()
{
    FileWorker::set_filename("");
    WindowsWorker::open_MainWindow();
    WindowsWorker::close_GameWindow();
}

void GameWindow::on_Save_triggered()
{
    if(FileWorker::get_filename() == "")
        on_SaveAs_triggered();
    else
    {
        save_game();
        QMessageBox::about(this, "Збережено", "Файл успішно збережено");
    }

}


void GameWindow::on_SaveAs_triggered()
{
    WindowsWorker::open_SaveWindow();
    WindowsWorker::hide_WindowGame();
    //save_game();
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

void GameWindow::download_game()
{
    bool game_with_pc;
    bool finished;
    int who_first_move;
    int cur_move;
    vector<int> scores;
    FileWorker::download_game_state(game_with_pc,finished,who_first_move,cur_move, scores);

    vector<bool> flags;
    pair<int,int> conv;
    FileWorker::download_game_effects(flags, conv);

    vector<pair<int,int>> hands1;
    vector<pair<int,int>> hands2;
    vector<pair<int,int>> deck;
    pair<int,int> top_card;
    vector<pair<int,int>> discard;
    FileWorker::download_game_cards(hands1, hands2, deck, top_card, discard);

    game_board->set_game_with_pc(game_with_pc);
    game_board->set_finished(finished);
    game_board->set_who_move_first(who_first_move);
    game_board->set_current_player(cur_move);
    game_board->set_scores(scores);
    game_board->set_flags(flags);
    game_board->set_card_converted(conv);
    game_board->set_cards_hands1(hands1);
    game_board->set_cards_hands2(hands2);
    game_board->set_cards_deck(deck);
    game_board->set_top_card(top_card);
    game_board->set_discardcards_deck(discard);

}

void GameWindow::on_Rules_triggered()
{
    WindowsWorker::open_WindowRules();
    WindowsWorker::hide_WindowGame();
}

