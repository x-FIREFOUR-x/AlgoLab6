#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include "windows/windowsworker.h"

#include <iostream>
#include <string>
#include "logic/fileworker.h"
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
    for (int i = 0; i < buttons.size(); i++ ) {
        delete buttons[i];
        buttons[i] = nullptr;
    }
}

void DownloadWindow::closeEvent(QCloseEvent *event)
{
    WindowsWorker::close_DownloadWindow();
    if (WindowsWorker::get_GameWindow() == nullptr)
        WindowsWorker::open_MainWindow();
}

void DownloadWindow::list_file()
{
    QDir directory(FileWorker::get_path());
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);

    int index = 0;
    foreach(QString filename, files)
    {
        string f_name = filename.toStdString();
        f_name = f_name.substr(0, f_name.find("."));
        create_button(QString::fromUtf8(f_name), index);
        index++;
    }
}

void DownloadWindow::create_button(QString filename, int index)
{
    float top = this->height() / 10;
    float left = this->width()/8;

    float button_height = this->height() / 10;
    float button_width = this->width() - 2 *left;

    float backdown = this->height() / 20;

    float x = left;
    float y = (index * button_height) + top + (backdown * index);

    QPushButton *button = new QPushButton(filename, this);
    button->setGeometry(x, y, button_width, button_height);
    button->setStyleSheet("background-color:red;");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(clicked()));
    buttons.append(button);
}

void DownloadWindow::clicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    cout << endl << btn->text().toStdString() << endl;
    FileWorker::set_filename(btn->text());
    WindowsWorker::open_GameWindow();
    WindowsWorker::close_DownloadWindow();

}
