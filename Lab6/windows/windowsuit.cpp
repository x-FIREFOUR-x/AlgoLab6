#include "windowsuit.h"
#include "ui_windowsuit.h"
#include "windows/windowsworker.h"

WindowSuit::WindowSuit(int* suit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSuit)
{
    ui->setupUi(this);
    suit_card = suit;
}

WindowSuit::~WindowSuit()
{
    delete ui;
}

void WindowSuit::on_ButtonHeart_clicked()
{
    *suit_card = 2;
    WindowsWorker::close_WindowSuit();
}


void WindowSuit::on_ButtonSpades_clicked()
{
    *suit_card = 3;
    WindowsWorker::close_WindowSuit();
}


void WindowSuit::on_ButtonClubs_clicked()
{
    *suit_card = 0;
    WindowsWorker::close_WindowSuit();
}


void WindowSuit::on_ButtonDiamonds_clicked()
{
    *suit_card = 1;
    WindowsWorker::close_WindowSuit();
}

