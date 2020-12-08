#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H

#include <order.h>
#include <date.h>

class orderHistory
{
public:
    orderHistory();
    orderHistory(QVector<individualItem> p, QString d);
    QVector<individualItem> getItems() {return items;}
    QString getDateTime() {return dateTime;}

    QString printItem(int i);
    QString quanityLine(int i);
    QString itemLine(int i);
    QString priceLine(int i);
    bool ifCombo(int i);
    QString sideLine(int i);
    QString drinkLine(int i);

    double calSub();
    double calTax();
    double calTotal();

    void clear();
    void print();

private:
    QVector<individualItem> items;
    QString dateTime;
};

#endif // ORDERHISTORY_H
