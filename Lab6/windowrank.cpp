#include "windowrank.h"
#include "ui_windowrank.h"

WindowRank::WindowRank(int& rank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowRank)
{
    ui->setupUi(this);
    rank_card = &rank;
}

WindowRank::~WindowRank()
{
    delete ui;
}


void WindowRank::on_radioButtonTwo_clicked()
{
    *rank_card = 2;
    this->close();
}

void WindowRank::on_radioButtonThree_clicked()
{
    *rank_card = 3;
    this->close();
}


void WindowRank::on_radioButtonFour_clicked()
{
    *rank_card = 4;
    this->close();
}


void WindowRank::on_radioButtonFive_clicked()
{
    *rank_card = 5;
    this->close();
}


void WindowRank::on_radioButtonSix_clicked()
{
    *rank_card = 6;
    this->close();
}


void WindowRank::on_radioButtonSeven_clicked()
{
    *rank_card = 7;
    this->close();
}


void WindowRank::on_radioButtonEight_clicked()
{
    *rank_card = 8;
    this->close();
}


void WindowRank::on_radioButtonNine_clicked()
{
    *rank_card = 9;
    this->close();
}


void WindowRank::on_radioButtonTen_clicked()
{
    *rank_card = 10;
    this->close();
}


void WindowRank::on_radioButtonJack_clicked()
{
    *rank_card = 11;
    this->close();
}


void WindowRank::on_radioButtonQueen_clicked()
{
    *rank_card = 12;
    this->close();
}


void WindowRank::on_radioButtonKing_clicked()
{
    *rank_card = 13;
    this->close();
}


void WindowRank::on_radioButtonAce_clicked()
{
    *rank_card = 14;
    this->close();
}

