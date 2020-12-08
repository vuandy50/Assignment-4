#ifndef ORDER_H
#define ORDER_H

#include <QVector>
#include <QTime>
#include <QDebug>
#include "item.h"
#include "iostream"

struct individualItem
{
    int quanity;
    item name;
    item side;
    item drink;
    double price;
};

class order
{
public:
    order();
    const double tax_rate = 0.06;
    QVector<individualItem> getItems(){return individual;}
    int size(){return individual.size();}
    double getSubTotal(){return subtotal;}
    double getTotal(){return total;}
    double getTax() {return (subtotal * tax_rate);}
    QTime getTime() {return *time;}

    void addItem(item temp);
    void addSide(item temp);
    void addDrink(item temp);
    void checkRepeatCombo();

    void addFreeItem(individualItem temp);
    void addToMain();
    double getRewardsPts();

    void addTime();
    void calculatePrice();
    void makeReceipt();
    QString printItem(int i);

    QString quanityLine(int i);
    QString itemLine(int i);
    QString priceLine(int i);

    bool ifCombo(int i);
    QString sideLine(int i);
    QString drinkLine(int i);

    void removal(int i);
    void print();
    void clear();

private:
    QVector<individualItem> individual;
    double subtotal;
    double total;
    QTime *time;
    QVector<individualItem> free;

};

#endif // ORDER_H
