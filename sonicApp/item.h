#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QVector>
#include <QByteArray>
class item
{
public:
    item();
    item(QString i, QString t, QString d, double p, QByteArray image);
    item operator = (item const &obj);

    QString getItem(){return itemName;}
    QString getType(){return type;}
    QString getDescription(){return description;}
    double getPrice(){return price;}
    QByteArray getPic(){return pic;}

private:
    QString itemName;
    QString type;
    QString description;
    double price;
    QByteArray pic;

};

#endif // ITEM_H
