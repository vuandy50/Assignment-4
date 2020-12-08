#include "orderhistory.h"

orderHistory::orderHistory()
{

}
orderHistory::orderHistory(QVector<individualItem> p, QString d)
{
    items = p;
    dateTime = d;
}
QString orderHistory::sideLine(int i)
{
    QString temp = "(" + items[i].side.getItem()+"/";
    return temp;
}
QString orderHistory::drinkLine(int i)
{
    QString temp = items[i].drink.getItem() + ")";
    return temp;
}
QString orderHistory::printItem(int i)
{
    QString temp = "";
    temp = temp + quanityLine(i);
    temp = temp + itemLine(i);
    return temp;
}
QString orderHistory::priceLine(int i)
{
    QString temp = QString::number(items[i].price,'f',2);
    QString returnLine = "$";
    int spaces = 8 - temp.size();
    for(int j = 0; j < spaces; j++ )
    {
        returnLine += " ";
    }
    returnLine = returnLine + temp;
    return returnLine;
}
bool orderHistory::ifCombo(int i)
{
    return(items[i].name.getItem() == "COMBO A" ||
           items[i].name.getItem() == "COMBO B" ||
           items[i].name.getItem() == "COMBO C");
}
QString orderHistory::quanityLine(int i)
{
    QString temp = QString::number(items[i].quanity) + "x";
    int spaces = 9 - temp.size();
    for(int j = 0; j < spaces; j++ )
    {
        temp = temp + " ";
    }
    return temp;
}
QString orderHistory::itemLine(int i)
{
    QString temp;
    if(ifCombo(i))
    {
        temp = items[i].name.getItem() + " " + sideLine(i) + drinkLine(i);
    }
    else
    {
        temp = items[i].name.getItem();
    }
    return temp;
}
double orderHistory::calSub()
{
    double subtotal = 0;
    for(int i = 0; i < items.size(); i++)
    {
        subtotal += items[i].price;
    }
    return subtotal;
}
double orderHistory::calTax()
{
    return calSub() * 0.06;
}
double orderHistory::calTotal()
{
    return calSub() + calTax();
}
void orderHistory::clear()
{
    items.clear();
    dateTime = "";
}
void orderHistory::print()
{
    for(int i = 0; i < items.size(); i++)
    {
        qDebug() << printItem(i);
        qDebug() << priceLine(i);
    }
}
