#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include "windows/windowsworker.h"

#include <iostream>
#include <string>
//#include <filesystem>


DownloadWindow::DownloadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadWindow)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
    list_file();
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
}

void DownloadWindow::closeEvent(QCloseEvent *event)
{
    WindowsWorker::close_DownloadWindow();
    WindowsWorker::open_MainWindow();
}

void DownloadWindow::list_file()
{
    QDir directory(FileWorker::get_path());
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);
    foreach(QString filename, files)
    {
        cout << filename.toStdString()  << endl;
    }
}
