#include "order.h"

order::order()
{
    total = 0;
    subtotal = 0;
    time = new QTime(0,0,0);
}
void order::addItem(item temp)
{
    individualItem *setter = new individualItem;
    item *nullItem = new item();
    bool newItem = true;

    if(individual.isEmpty())
    {
        setter->quanity = 1;
        setter->name = temp;
        setter->price = temp.getPrice() * setter->quanity;
        setter->side = *nullItem;
        setter->drink = *nullItem;
        individual.push_back(*setter);
    }
    else
    {
        int i = 0;
        while(newItem && i < size())
        {
            if(individual[i].name.getItem() == temp.getItem())
            {
                if(temp.getType() == "combo")
                {
                    newItem= true;
                }
                else
                {
                    individual[i].quanity++;
                    individual[i].price = individual[i].price + temp.getPrice();
                    newItem = false;
                }

            }
            i++;
        }
        if(newItem)
        {
            setter->quanity = 1;
            setter->name = temp;
            setter->price = temp.getPrice() * setter->quanity;
            setter->side = *nullItem;
            setter->drink = *nullItem;
            individual.push_back(*setter);
        }
    }
}
void order::checkRepeatCombo()
{
    individualItem *checker = new individualItem;
    checker->name = individual.last().name;
    checker->drink = individual.last().drink;
    checker->side = individual.last().side;
    checker->price = individual.last().price;

    int i = 0;
    bool newItem = true;
    while(newItem && i < size()-1)
    {
        if(individual[i].name.getItem() == checker->name.getItem() &&
           individual[i].side.getItem() == checker->side.getItem() &&
           individual[i].drink.getItem() == checker->drink.getItem())
        {
                individual[i].quanity++;
                individual[i].price = individual[i].price + checker->price;
                individual.pop_back();
                newItem = false;
        }
        i++;
    }

}
void order::addSide(item temp)
{
    individual[size()-1].side = temp;
}
void order::addDrink(item temp)
{
    individual[size()-1].drink = temp;
}
void order::calculatePrice()
{
    subtotal = 0;
    total = 0;
    for(int i = 0; i < size(); i++)
    {
        subtotal += individual[i].price;
    }
    total = subtotal + getTax();
}
void order::addTime()
{
    int seconds = 0;
    for(int i = 0; i < size(); i++)
    {
        QString temp = individual[i].name.getType();
        if(temp == "drink")
        {
            seconds += 30 * individual[i].quanity;
        }
        else if(temp == "side")
        {
            seconds += 60 * individual[i].quanity;
        }
        else if(temp == "food")
        {
            seconds += 90 * individual[i].quanity;
        }
        else if (temp == "combo")
        {
            seconds += 120 * individual[i].quanity;
        }
    }
    *time = time->addSecs(seconds);
}
QString order::quanityLine(int i)
{
    QString temp = QString::number(individual[i].quanity) + "x";
    int spaces = 9 - temp.size();
    for(int j = 0; j < spaces; j++ )
    {
        temp = temp + " ";
    }
    return temp;
}
QString order::itemLine(int i)
{
    QString temp;
    if(ifCombo(i))
    {
        temp = individual[i].name.getItem() + " " + sideLine(i) + drinkLine(i);
    }
    else
    {
        temp = individual[i].name.getItem();
    }
    return temp;
}
QString order::priceLine(int i)
{
    QString temp = QString::number(individual[i].price,'f',2);
    QString returnLine = "$";
    int spaces = 8 - temp.size();
    for(int j = 0; j < spaces; j++ )
    {
        returnLine += " ";
    }
    returnLine = returnLine + temp;
    return returnLine;
}
bool order::ifCombo(int i)
{
    return(individual[i].name.getType() == "combo");
}
QString order::sideLine(int i)
{
    QString temp = "(" + individual[i].side.getItem()+"/";
    return temp;
}
QString order::drinkLine(int i)
{
    QString temp = individual[i].drink.getItem() + ")";
    return temp;
}
QString order::printItem(int i)
{
    QString temp = "";
    temp = temp + quanityLine(i);
    temp = temp + itemLine(i);
    return temp;
}
void order::removal(int i)
{
    individual.removeAt(i);
}
void order::print()
{
    calculatePrice();
    for(int i = 0; i < size(); i++)
    {
        qDebug() << printItem(i);
    }
}
void order::clear()
{
    individual.clear();
    subtotal = 0;
    total = 0;
    time = new QTime(0,0,0);
}
