#ifndef WINDOWRULES_H
#define WINDOWRULES_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class WindowRules;
}

class WindowRules : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowRules(QWidget *parent = nullptr);
    ~WindowRules();

private slots:
    void on_CloseRuleButton_clicked();

    void on_PreviousPageButton_clicked();

    void on_NextPageButton_2_clicked();

private:
    Ui::WindowRules *ui;

    QString path = ":/image/PNG-cards/";
    QString name_file = "RulesPage";
    int current_page;
    QString type_file = ".png";

    int amount_page = 6;

private:
    void set_NumberPage();
    void paint_page_rules();
};

#endif // WINDOWRULES_H
