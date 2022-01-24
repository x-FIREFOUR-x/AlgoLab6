#include "windowrank.h"
#include "ui_windowrank.h"
#include "windows/windowsworker.h"

WindowRank::WindowRank(int* rank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowRank)
{
    ui->setupUi(this);
    rank_card = rank;
    setFixedSize(this->width(),this->height());
    style();
}

WindowRank::~WindowRank()
{
    delete ui;
}


void WindowRank::on_radioButtonTwo_clicked()
{
    *rank_card = 2;
    WindowsWorker::close_WindowRank();
}

void WindowRank::on_radioButtonThree_clicked()
{
    *rank_card = 3;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonFour_clicked()
{
    *rank_card = 4;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonFive_clicked()
{
    *rank_card = 5;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonSix_clicked()
{
    *rank_card = 6;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonSeven_clicked()
{
    *rank_card = 7;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonEight_clicked()
{
    *rank_card = 8;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonNine_clicked()
{
    *rank_card = 9;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonTen_clicked()
{
    *rank_card = 10;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonJack_clicked()
{
    *rank_card = 11;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonQueen_clicked()
{
    *rank_card = 12;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonKing_clicked()
{
    *rank_card = 13;
    WindowsWorker::close_WindowRank();
}


void WindowRank::on_radioButtonAce_clicked()
{
    *rank_card = 14;
    WindowsWorker::close_WindowRank();
}

void WindowRank::style()
{
    //this->setWindowTitle("Останній гравець");
    this->setStyleSheet("background-color:#2c8616;");

    ui->label->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; font-weight: 550;");

    ui->radioButtonTwo->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonThree->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonFour->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonFive->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonSix->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonSeven->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonEight->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonNine->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonTen->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonJack->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonQueen->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonKing->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
    ui->radioButtonAce->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; ");
}
