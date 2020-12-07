#include "item.h"

item::item()
{
    itemName = "";
    type = "";
    description = "";
    price = NULL;
    pic = NULL;
}
item::item(QString i, QString t, QString d, double p, QByteArray image)
{
    itemName = i;
    type = t;
    description = d;
    price = p;
    pic = image;
}
item item::operator = (item const &obj)
{
    itemName = obj.itemName;
    type = obj.type;
    description = obj.description;
    price = obj.price;
    pic = obj.pic;
    return *this;
}
