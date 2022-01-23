#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>


namespace Ui {
class DownloadWindow;
}

class DownloadWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DownloadWindow(QWidget *parent = nullptr);
    ~DownloadWindow();

private:
    Ui::DownloadWindow *ui;

    QList<QPushButton*> buttons;            //масив кнопок відповідаючих збереженям гри
    QList<QPushButton*> buttons_delete;     //масив кнопок відповідаючих за видалення збережень

    QGridLayout *pLayout;                   //сітка гріда для розміщення обєктів в потрібних місцях

private:
    void list_file();                                   //створити список збережень(кнопок)
    void create_button(QString filename, int index);    //створити кнопку
    void create_button_delete(int index);               //створити кнопки видалення сейвів

    void closeEvent(QCloseEvent *event);        //подія тригер спрацьовує на нажимання хрестика закриває дане вікно

private slots:
    void clicked();             //слот привязаний до кнопок збережень завантажує потрібне збереження
    void clicked_delete();      //слот привязаний до кнопок видалення збережень

};

#endif // DOWNLOADWINDOW_H
