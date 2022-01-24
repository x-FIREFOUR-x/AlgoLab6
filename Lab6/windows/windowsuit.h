#ifndef WINDOWSUIT_H
#define WINDOWSUIT_H

#include <QDialog>

namespace Ui {
class WindowSuit;
}

class WindowSuit : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSuit( int* suit, QWidget *parent = nullptr);
    ~WindowSuit();

private:
    void style();

private slots:
    void on_ButtonHeart_clicked();      //вибір масті черви для перетворення карти

    void on_ButtonSpades_clicked();     //вибір масті піки для перетворення карти

    void on_ButtonClubs_clicked();      //вибір масті хрести для перетворення карти

    void on_ButtonDiamonds_clicked();   //вибір масті буби для перетворення карти

private:
    Ui::WindowSuit *ui;

    int* suit_card;         //вибрана масть
};

#endif // WINDOWSUIT_H
