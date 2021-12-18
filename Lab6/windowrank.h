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

    void on_radioButtonTwo_clicked();

    void on_radioButtonKing_clicked();

    void on_radioButtonThree_clicked();

    void on_radioButtonFour_clicked();

    void on_radioButtonFive_clicked();

    void on_radioButtonSix_clicked();

    void on_radioButtonSeven_clicked();

    void on_radioButtonEight_clicked();

    void on_radioButtonNine_clicked();

    void on_radioButtonTen_clicked();

    void on_radioButtonJack_clicked();

    void on_radioButtonQueen_clicked();

    void on_radioButtonAce_clicked();

private:
    Ui::WindowRank *ui;

    int* rank_card;
};

#endif // WINDOWRANK_H
