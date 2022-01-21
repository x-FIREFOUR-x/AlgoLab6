#include "savewindow.h"
#include "ui_savewindow.h"
#include "windows/windowsworker.h"

#include <QMessageBox>
#include <string>

#include "logic/fileworker.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
}

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::closeEvent(QCloseEvent *event)
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
        if (!FileWorker::is_already_file(file_name))
        {
            FileWorker::set_filename(file_name);
            WindowsWorker::get_GameWindow()->save_game();
            QMessageBox::about(this, "Збережено", "Гра успішно збережено");
            WindowsWorker::close_SaveWindow();
            WindowsWorker::show_WindowGame();
        }
        else
        {

        }

    }
    else
    {
        ui->labelFilename->setText("");
        QMessageBox::about(this, "Некоректне ім'я", "Ви повинні ввести назву для збереження гри. Назва може містити цифри, букви англійського алфавіту, символ '_'.");
    }

}

bool SaveWindow::is_correct_filename()
{
    bool correct_name = true;
    QString name_file = ui->labelFilename->text();

    if(name_file == "")
        correct_name = false;

    string file = name_file.toStdString();
    if(file.find(".") != file.npos)
        correct_name = false;

    for(int i = 0; i< file.length(); i++)
    {
        if(!((file[i] >= '0' && file[i] <= '9') || (file[i] >= 'A' && file[i] <= 'Z')|| (file[i] >= 'a' && file[i] <= 'z') || file[i] == '_'))
        {
            correct_name = false;
            break;
        }
    }

    return correct_name;
}

