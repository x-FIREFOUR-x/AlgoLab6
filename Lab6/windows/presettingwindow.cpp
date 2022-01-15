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

    int score = 0;
    QString str_score = ui->Score->text();
    if (str_score != "")
    {
        score = str_score.toInt();
        if (score > 0 && score < 1000)
        {
            this->close();
            GameWindow * game_window = new GameWindow(score, play_with_pc);
            game_window->setWindowTitle("Останній гравець");
            game_window->show();
        }
    }

}


void PresettingWindow::on_ButtonBack_clicked()
{
    this->close();
    MainWindow * menu = new MainWindow;
    menu->setWindowTitle("Останній гравець");
    menu->show();
}




