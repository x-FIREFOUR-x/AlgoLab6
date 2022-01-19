#include "savewindow.h"
#include "ui_savewindow.h"
#include "windows/windowsworker.h"

#include <QMessageBox>

#include "logic/fileworker.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
}

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::on_CloseButton_clicked()
{
    WindowsWorker::close_SaveWindow();
    WindowsWorker::show_WindowGame();
}


void SaveWindow::on_SaveButton_clicked()
{
    QString file_name = ui->labelFilename->text();
    bool correct_name = is_correct_filename();

    if (correct_name)
    {
        FileWorker::set_filename(file_name);
        WindowsWorker::get_GameWindow()->save_game();
        QMessageBox::about(this, "Збережено", "Файл успішно збережено");
        WindowsWorker::close_SaveWindow();
        WindowsWorker::show_WindowGame();
    }
    else
    {
        ui->labelFilename->setText("");
        QMessageBox::about(this, "Некоректне ім'я", "Ви повинні ввести назву для збереження гри. Назва збереження гри не повинно містити символів '.' ");
    }

}

bool SaveWindow::is_correct_filename()
{
    bool correct_name = true;
    QString name_file = ui->labelFilename->text();

    if(name_file == "")
        correct_name = false;

    string file = name_file.toStdString();
    //if(file.find(".") == file.npos)
       // correct_name = false;

    return correct_name;
}
