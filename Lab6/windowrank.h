#ifndef WINDOWRANK_H
#define WINDOWRANK_H

#include <QDialog>

namespace Ui {
class WindowRank;
}

class WindowRank : public QDialog
{
    Q_OBJECT

public:
    explicit WindowRank(int& rank, QWidget *parent = nullptr);
    ~WindowRank();

private slots:

    void on_radioButtonTwo_clicked();         //вибір рангу карти 2 для перетвореної

    void on_radioButtonThree_clicked();       //вибір рангу карти 3 для перетвореної

    void on_radioButtonFour_clicked();        //вибір рангу карти 4 для перетвореної

    void on_radioButtonFive_clicked();        //вибір рангу карти 5 для перетвореної

    void on_radioButtonSix_clicked();         //вибір рангу карти 6 для перетвореної

    void on_radioButtonSeven_clicked();       //вибір рангу карти 7 для перетвореної

    void on_radioButtonEight_clicked();       //вибір рангу карти 8 для перетвореної

    void on_radioButtonNine_clicked();        //вибір рангу карти 9 для перетвореної

    void on_radioButtonTen_clicked();         //вибір рангу карти 10 для перетвореної

    void on_radioButtonJack_clicked();        //вибір рангу карти валєт для перетвореної

    void on_radioButtonQueen_clicked();       //вибір рангу карти дама для перетвореної

    void on_radioButtonKing_clicked();        //вибір рангу карти король для перетвореної

    void on_radioButtonAce_clicked();         //вибір рангу карти туз для перетвореної

private:
    Ui::WindowRank *ui;

    int* rank_card;         //вибраний ранг карти
};

#endif // WINDOWRANK_H
