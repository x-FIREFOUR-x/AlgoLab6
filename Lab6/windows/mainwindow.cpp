#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Останній гравець");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonStart_clicked()
{
    this->close();
    PresettingWindow * preset_window = new PresettingWindow();
    preset_window->setWindowTitle("Останній гравець");
    preset_window->show();

}

void MainWindow::on_ButtonEnd_clicked()
{
   QApplication::quit();
}




void MainWindow::on_ButtonDownload_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Відкрити файл"), FileWorker::get_path(), tr("Текстовий файл(*.txt)"));
    if (file_name != "")
    {
        FileWorker::set_filename(file_name);
        this->close();
        GameWindow * game_window = new GameWindow();

        game_window->setWindowTitle("Останній гравець");
        game_window->show();
    }

}

