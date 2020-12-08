#ifndef DATE_H
#define DATE_H

#include <QVector>
#include <QDateTime>
#include <QtAlgorithms>
#include <database.h>
class date
{
public:
    date();
    void populateDates();
    void setEmail(QString e){email = e;}
    QVector<QString> getDates();
    void organize();
    void clear();
private:
    QVector<QString> dates;
    QSqlDatabase db;
    QString email;
};

#endif // DATE_H
