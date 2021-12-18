#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include "gameboard.h"

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
