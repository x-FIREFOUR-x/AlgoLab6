#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "mainwindow.h"

PresettingWindow::PresettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresettingWindow)
{
    ui->setupUi(this);
}

PresettingWindow::~PresettingWindow()
{
    delete ui;
}

void PresettingWindow::on_ButtonGoGame_clicked()
{
    bool play_with_pc = ui->radioButtonPlayPC->isChecked();
    this->close();
    if (!play_with_pc)
    {
        GameWindow * game_window = new GameWindow(play_with_pc, this);
        game_window->setWindowTitle("Domineering 8x8");
        game_window->show();
    }
    else
    {
        bool pc_first = ui->radioButtonPCFirst->isChecked();
        int level_dif;
        if(ui->radioButtonEazy->isChecked())
            level_dif = 1;
        else
            if(ui->radioButtonMiddle->isChecked())
                level_dif = 2;
            else
                level_dif = 3;
        GameWindow* game_window= new GameWindow(play_with_pc,pc_first,level_dif,this);
        game_window->setWindowTitle("Domineering 8x8");
        game_window->show();
    }

}


void PresettingWindow::on_ButtonBack_clicked()
{
    this->close();
    MainWindow * menu = new MainWindow;
    menu->setWindowTitle("Останній гравець");
    menu->show();
}


void PresettingWindow::on_radioButtonPlayPC_clicked()
{
    ui->frameWhoFirst->setVisible(true);
    ui->frameWhoFirst->setEnabled(true);
    ui->frameDifficulty->setVisible(true);
    ui->frameDifficulty->setEnabled(true);
}


void PresettingWindow::on_radioButtonTwoPlayers_clicked()
{
    ui->frameWhoFirst->setVisible(false);
    ui->frameWhoFirst->setEnabled(false);
    ui->frameDifficulty->setVisible(false);
    ui->frameDifficulty->setEnabled(false);
}

