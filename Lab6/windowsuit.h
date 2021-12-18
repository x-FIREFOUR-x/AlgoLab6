#ifndef WINDOWSUIT_H
#define WINDOWSUIT_H

#include <QMainWindow>
#include <QDialog>

namespace Ui {
class WindowSuit;
}

class WindowSuit : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSuit( int& suit, QWidget *parent = nullptr);
    ~WindowSuit();

private slots:
    void on_ButtonHeart_clicked();

    void on_ButtonSpades_clicked();

    void on_ButtonClubs_clicked();

    void on_ButtonDiamonds_clicked();

private:
    Ui::WindowSuit *ui;

    int* suit_card;
};

#endif // WINDOWSUIT_H
