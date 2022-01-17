#ifndef WINDOWSWORKER_H
#define WINDOWSWORKER_H

#include "gamewindow.h"
#include "mainwindow.h"
#include "presettingwindow.h"
#include "windowrank.h"
#include "windowrules.h"
#include "windowsuit.h"

class WindowsWorker
{
private:
    static MainWindow* window_main;
    static PresettingWindow* window_presetting;
    static GameWindow* window_game;
    static WindowRank* window_rank;
    static WindowSuit* window_suit;
    static WindowRules* window_rules;

public:
    WindowsWorker();


    static void open_MainWindow();
    static void close_MainWindow();

    static void open_PresettingWindow();
    static void close_PresettingWindow();

    static void open_GameWindow();
    static void close_GameWindow();

    static void open_WindowRank(int& rank);
    static void close_WindowRank();

    static void open_WindowSuit(int& suit);
    static void close_WindowSuit();

    static void open_WindowRules();
    static void close_WindowRules();
};

#endif // WINDOWSWORKER_H
