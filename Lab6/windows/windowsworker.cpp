#include "windowsworker.h"

MainWindow* WindowsWorker::window_main = nullptr;
PresettingWindow* WindowsWorker::window_presetting = nullptr;
GameWindow* WindowsWorker::window_game = nullptr;
WindowRank* WindowsWorker::window_rank = nullptr;
WindowSuit* WindowsWorker::window_suit = nullptr;
WindowRules* WindowsWorker::window_rules = nullptr;

WindowsWorker::WindowsWorker()
{
}


void WindowsWorker::open_MainWindow()
{
    window_main = new MainWindow();
    window_main->setWindowTitle("Останній гравець");
    window_main->show();
}

void WindowsWorker::close_MainWindow()
{
    window_main->close();
    delete window_main;
    window_main = nullptr;
}


void WindowsWorker::open_PresettingWindow()
{
    window_presetting = new PresettingWindow();
    window_presetting->setWindowTitle("Останній гравець");
    window_presetting->show();
}
void WindowsWorker::close_PresettingWindow()
{
    window_presetting->close();
    delete window_presetting;
    window_presetting = nullptr;
}


void WindowsWorker::open_GameWindow()
{
    window_game = new GameWindow();
    window_game->setWindowTitle("Останній гравець");
    window_game->show();
}

void WindowsWorker::open_GameWindow(int score, bool play_with_pc)
{
    window_game = new GameWindow(score, play_with_pc);
    window_game->setWindowTitle("Останній гравець");
    window_game->show();
}

void WindowsWorker::close_GameWindow()
{
    window_game->close();
    delete window_game;
    window_game = nullptr;
}


void WindowsWorker::open_WindowRank(int* rank)
{
    window_rank = new WindowRank(rank);
    window_rank->setWindowTitle("Останній гравець");
    window_rank->exec();
}
void WindowsWorker::close_WindowRank()
{
    window_rank->close();
    delete window_rank;
    window_rank = nullptr;
}


void WindowsWorker::open_WindowSuit(int* suit)
{
    window_suit = new WindowSuit(suit);
    window_suit->setWindowTitle("Останній гравець");
    window_suit->exec();
}
void WindowsWorker::close_WindowSuit()
{
    window_suit->close();
    delete window_suit;
    window_suit = nullptr;
}


void WindowsWorker::open_WindowRules()
{
    window_rules = new WindowRules();
    window_rules->setWindowTitle("Останній гравець");
    window_rules->show();
}
void WindowsWorker::close_WindowRules()
{
    window_rules->close();
    delete window_rules;
    window_rules = nullptr;
}
