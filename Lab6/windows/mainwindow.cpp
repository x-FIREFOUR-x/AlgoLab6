#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "windows/windowsworker.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(width(), height());
    style();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::style()
{
    this->setWindowTitle("Останній гравець");
    this->setStyleSheet("background-color:#2c8616;");

    ui->ButtonStart->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");
    ui->ButtonDownload->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");
    ui->ButtonEnd->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");
    ui->ButtonRules->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 16pt Monotype Corsiva; font-weight: 570;");
}

void MainWindow::on_ButtonStart_clicked()
{
    WindowsWorker::open_PresettingWindow();
    WindowsWorker::close_MainWindow();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
   // WindowsWorker::close_MainWindow();

}

void MainWindow::on_ButtonDownload_clicked()
{
    WindowsWorker::open_DownloadWindow();
    WindowsWorker::close_MainWindow();

}


void MainWindow::on_ButtonRules_clicked()
{
    WindowsWorker::open_WindowRules();
    WindowsWorker::close_MainWindow();
}

 void MainWindow::closeEvent(QCloseEvent *event)
 {
     WindowsWorker::close_MainWindow();
 }
