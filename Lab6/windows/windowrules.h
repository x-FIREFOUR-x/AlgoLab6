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
    void on_CloseRuleButton_clicked();              //закрити вікно правил

    void on_PreviousPageButton_clicked();           //відкрити попередню сторінку правил (зображення)

    void on_NextPageButton_clicked();              //відкрити попередню сторінку правил (зображення)

private:
    Ui::WindowRules *ui;

    QString path = ":/image/PNG-cards/";        //шлях до зображеннь
    QString name_file = "RulesPage";            //головна частина імені зображення + номер зображення
    int current_page;                           //номер поточного зображення
    QString type_file = ".png";                 //розширення зображення

    int amount_page = 6;                        //кількість зображень сторінок правил

private:
    void set_NumberPage();                      //установити номер поточного зображення
    void paint_page_rules();                    //відобразити номер поточного зображення на label

    void style();                //стилізує вікно
};

#endif // WINDOWRULES_H
