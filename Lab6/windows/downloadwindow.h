#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>


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
    QList<QPushButton*> buttons;

private:
    void list_file();
    void create_button(QString filename, int index);


    void closeEvent(QCloseEvent *event);

private slots:
    void clicked();

};

#endif // DOWNLOADWINDOW_H
