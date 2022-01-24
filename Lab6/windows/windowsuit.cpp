#include "windowsuit.h"
#include "ui_windowsuit.h"
#include "windows/windowsworker.h"

WindowSuit::WindowSuit(int* suit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSuit)
{
    ui->setupUi(this);
    suit_card = suit;
    //this->setWindowFlags( (Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint) & ~Qt::WindowCloseButtonHint );
    setFixedSize(this->width(),this->height());
    style();
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

void WindowSuit::style()
{
    //this->setWindowTitle("Останній гравець");
    this->setStyleSheet("background-color:#2c8616;");
    ui->label->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; font-weight: 550;");

}
