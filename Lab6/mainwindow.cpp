#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonStart_clicked()
{
    this->close();
    PresettingWindow * preset_window = new PresettingWindow(this);
    preset_window->setWindowTitle("Останній гравець");
    preset_window->show();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
}



