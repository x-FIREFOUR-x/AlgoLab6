#ifndef PRINTERCARDS_H
#define PRINTERCARDS_H

#include<string>
#include<vector>
#include <QGraphicsItem>
#include <QBrush>

class PrinterCards
{
private:
    std::vector<std::string> namefile_cards;
public:
    PrinterCards();
    QGraphicsItem* print_back(QGraphicsScene*& scene, int x, int y, int width, int height);
    QGraphicsItem* print_card(std::pair<int,int> card ,QGraphicsScene*& scene, int x, int y, int width, int height);
private:
    void push_namefile_bigcards(std::string name);
};

#endif // PRINTERCARDS_H
