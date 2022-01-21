#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>


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

    QGridLayout *pLayout;

private:
    void list_file();                                   //створити список збережень(кнопок)
    void create_button(QString filename, int index);    //створити кнопку


    void closeEvent(QCloseEvent *event);        //подія тригер спрацьовує на нажимання хрестика закриває дане вікно

private slots:
    void clicked();             //слот привязаний до кнопок збережень завантажує потрібне збереження

};

#endif // DOWNLOADWINDOW_H
