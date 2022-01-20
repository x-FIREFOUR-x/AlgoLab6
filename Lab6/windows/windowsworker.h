#ifndef WINDOWSWORKER_H
#define WINDOWSWORKER_H

class MainWindow;
class PresettingWindow;
class GameWindow;
class WindowRank;
class WindowSuit;
class WindowRules;
class SaveWindow;
class DownloadWindow;

#include "gamewindow.h"
#include "mainwindow.h"
#include "presettingwindow.h"
#include "windowrank.h"
#include "windowrules.h"
#include "windowsuit.h"
#include "savewindow.h"
#include "downloadwindow.h"

class WindowsWorker
{
private:
    static MainWindow* window_main;
    static PresettingWindow* window_presetting;
    static GameWindow* window_game;
    static WindowRank* window_rank;
    static WindowSuit* window_suit;
    static WindowRules* window_rules;
    static SaveWindow* window_save;
    static DownloadWindow* window_download;

public:
    WindowsWorker();

    static MainWindow* get_MainWindow();
    static PresettingWindow* get_PresettingWindow();
    static GameWindow* get_GameWindow();
    static WindowRank* get_WindowRank();
    static WindowSuit* get_WindowSuit();
    static WindowRules* get_WindowRules();

    static void open_MainWindow();
    static void close_MainWindow();

    static void open_PresettingWindow();
    static void close_PresettingWindow();

    static void open_GameWindow();
    static void open_GameWindow(int score, bool play_with_pc);
    static void close_GameWindow();

    static void open_WindowRank(int* rank);
    static void close_WindowRank();

    static void open_WindowSuit(int* suit);
    static void close_WindowSuit();

    static void open_WindowRules();
    static void close_WindowRules();

    static void open_SaveWindow();
    static void close_SaveWindow();

    static void open_DownloadWindow();
    static void close_DownloadWindow();


    static void hide_WindowGame();
    static void show_WindowGame();
};

#endif // WINDOWSWORKER_H
