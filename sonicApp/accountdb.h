#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include <QString>

class accountDB
{
public:
    accountDB();
    accountDB(QString f, QString l, QString e, QString p, double r);
    QString getFname() {return Fname;}
    QString getLname(){return Lname;}
    QString getEmail(){return email;}
    QString getPassword(){return password;}
    double getRewadpts(){return rewardpts;}

    void setRewardpts(double r) {rewardpts = r;}

    void operator = (const accountDB &A);
private:
    QString Fname;
    QString Lname;
    QString email;
    QString password;
    double rewardpts;
};

#endif // ACCOUNTDB_H
