#include "date.h"

date::date()
{

}
void date::populateDates()
{
    QString dateTime;
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("SELECT DateTime FROM orderHistory WHERE Email ='"+email+"'" );
    if(qry->exec())
    {
        while(qry->next())
        {
            dateTime = qry->value(0).toString();
            dates.push_back(dateTime);
        }
    }
    else
    {
        qDebug("CANNOT POPULATE ITEMS");
    }
}
void date::organize()
{
    QVector<QString> temp;
    bool newItem = true;
    for(int i = 0; i < dates.size(); i++)
    {
        if(temp.isEmpty())
        {
            temp.push_back(dates[i]);

        }
        else
        {
            for(int j = 0; j < temp.size(); j++)
            {
                if(dates[i] == temp[j])
                {
                    newItem = false;
                    break;
                }
            }
            if(newItem)
            {
                temp.push_back(dates[i]);
            }
            newItem = true;
        }
    }
    dates = temp;
}
QVector<QString> date::getDates()
{
    return dates;
}
void date:: clear()
{
    dates.clear();
}
