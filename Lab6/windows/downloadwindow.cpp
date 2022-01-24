#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include "windows/windowsworker.h"

#include <iostream>
#include <string>
#include "logic/fileworker.h"


DownloadWindow::DownloadWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadWindow)
{
    ui->setupUi(this);

    setFixedSize(width(), height());

    pLayout = new QGridLayout();
    list_file();
    style();
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
    for (int i = 0; i < buttons.size(); i++ ) {
        delete buttons[i];
        buttons[i] = nullptr;
    }
    for (int i = 0; i < buttons_delete.size(); i++ ) {
        delete buttons_delete[i];
        buttons_delete[i] = nullptr;
    }
    delete pLayout;
}

void DownloadWindow::closeEvent(QCloseEvent *event)
{
    WindowsWorker::close_DownloadWindow();
    if (WindowsWorker::get_GameWindow() == nullptr)
        WindowsWorker::open_MainWindow();
}

void DownloadWindow::list_file()
{

    QStringList files = FileWorker::list_files();
    int index = 0;

    pLayout->horizontalSpacing();
    foreach(QString filename, files)
    {
        string f_name = filename.toStdString();
        f_name = f_name.substr(0, f_name.find("."));

        create_button(QString::fromUtf8(f_name), index);
        create_button_delete(index);
        index++;
    }

    //pLayout->setHorizontalSpacing();
    pLayout->setVerticalSpacing(this->height() / 30);

    ui->scrollArea->widget()->setLayout(pLayout);
}

void DownloadWindow::create_button(QString filename, int index)
{
    float top = this->height() / 10;
    float left = this->width()/8;

    float button_height = this->height() / 10;
    float button_width = this->width() - 2 *left - button_height;


    QPushButton *button = new QPushButton(filename, this);

    button->setMinimumSize(QSize(button_width, button_height));

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(clicked()));
    buttons.append(button);

    pLayout->addWidget(button,index, 0);

}

void DownloadWindow::create_button_delete(int index)
{
    float button_height = this->height() / 10;
    float button_width = button_height;


    QPushButton *button = new QPushButton("X", this);

    button->setMinimumSize(QSize(button_width, button_height));
    button->setMaximumSize(QSize(button_width, button_height));

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(clicked_delete()));

    buttons_delete.append(button);
    pLayout->addWidget(button,index, 1);
}


void DownloadWindow::clicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    FileWorker::set_filename(btn->text());
    WindowsWorker::open_GameWindow();
    WindowsWorker::close_DownloadWindow();

}

void DownloadWindow::clicked_delete()
{
    int index;
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    for (int i = 0; i < buttons_delete.size(); i++ )
    {
        if (buttons_delete[i] == btn)
            index = i;
    }
    QString message = "Ви впевненні, що хочете видалити збереження: '" + buttons[index]->text() + "' ?";

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Видалити збереження", message ,QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {

        FileWorker::remove_file(buttons[index]->text());

        delete buttons_delete[index];
        delete buttons[index];

        buttons.erase(buttons.begin()+index);
        buttons_delete.erase(buttons_delete.begin()+index);
    }
}

void DownloadWindow::style()
{
    this->setWindowTitle("Останній гравець");

    //ui->centralwidget->setStyleSheet("background-color:#2c8616;");
    //ui->scrollArea->setStyleSheet("background-color:white;");
    ui->scrollAreaWidgetContents->setStyleSheet("background-color:#2c8616;");

    ui->label->setStyleSheet("color:black; font: italic 16pt Monotype Corsiva; font-weight: 550;") ;

    for (int i = 0; i < buttons.size(); i++ )
    {
        buttons[i]->setStyleSheet("background-color:yellow; border: 1px solid black; font: italic 12pt Calibri;") ;
        buttons_delete[i]->setStyleSheet("background-color:red; border: 1px solid black; font: 16pt;") ;
    }

}
