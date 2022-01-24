#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "windows/windowsworker.h"

PresettingWindow::PresettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PresettingWindow)
{
    ui->setupUi(this);
    style();
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
            WindowsWorker::open_GameWindow(score, play_with_pc);
            WindowsWorker::close_PresettingWindow();

        }
    }

}


void PresettingWindow::on_ButtonBack_clicked()
{
    WindowsWorker::open_MainWindow();
    WindowsWorker::close_PresettingWindow();
}

void PresettingWindow::style()
{
    this->setWindowTitle("Останній гравець");
    this->setStyleSheet("background-color:#2c8616;");

    ui->ButtonBack->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");
    ui->ButtonGoGame->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");

    ui->Score->setStyleSheet("background-color:white; border: 1px solid black; font: italic 10pt Calibri;");

    ui->label->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; font-weight: 550;");
    ui->label_2->setStyleSheet("color:yellow; font: italic 16pt Monotype Corsiva; font-weight: 550;");
    ui->label_3->setStyleSheet("font: italic 14pt Monotype Corsiva;");

    ui->radioButtonPlayPC->setStyleSheet("font: italic 11pt Calibri; ");
    ui->radioButtonTwoPlayers->setStyleSheet("font: italic 11pt Calibri;");
}


