#include "presettingwindow.h"
#include "ui_presettingwindow.h"
#include "windows/windowsworker.h"

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




