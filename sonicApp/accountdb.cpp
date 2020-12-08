#include "accountdb.h"
accountDB::accountDB()
{

}
accountDB::accountDB(QString f, QString l, QString e, QString p, double r)
{
    Fname = f;
    Lname = l;
    email = e;
    password = p;
    rewardpts = r;
}
void accountDB::operator= (const accountDB &A)
{
    Fname = A.Fname;
    Lname = A.Lname;
    email = A.email;
    password = A.password;
    rewardpts = A.rewardpts;
}
