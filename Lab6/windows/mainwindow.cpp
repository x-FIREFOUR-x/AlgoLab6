#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "windows/windowsworker.h"

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
    WindowsWorker::open_PresettingWindow();
    WindowsWorker::close_MainWindow();

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
        WindowsWorker::open_GameWindow();
        WindowsWorker::close_MainWindow();
    }

}

