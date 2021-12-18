#include "windowsuit.h"
#include "ui_windowsuit.h"

WindowSuit::WindowSuit(int& suit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSuit)
{
    ui->setupUi(this);
    suit_card = &suit;
}

WindowSuit::~WindowSuit()
{
    delete ui;
}

void WindowSuit::on_ButtonHeart_clicked()
{
    *suit_card = 2;
    this->close();
}


void WindowSuit::on_ButtonSpades_clicked()
{
    *suit_card = 3;
    this->close();
}


void WindowSuit::on_ButtonClubs_clicked()
{
    *suit_card = 0;
    this->close();
}


void WindowSuit::on_ButtonDiamonds_clicked()
{
    *suit_card = 1;
    this->close();
}
