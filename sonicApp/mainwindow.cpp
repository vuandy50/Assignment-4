#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.openDB();
    QPalette palette1 = ui->label->palette();
    QPalette palette2 = ui->label_2->palette();
    QPalette palette3 = ui->label_3->palette();
    palette1.setColor(ui->label->foregroundRole(), Qt::white);
    palette2.setColor(ui->label_2->foregroundRole(), Qt::white);
    palette3.setColor(ui->label_3->foregroundRole(), Qt::white);
    ui->label->setPalette(palette1);
    ui->label_2->setPalette(palette2);
    ui->label_3->setPalette(palette3);
    populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::populate()
{
    accountDB *newAccount;
    QString first;
    QString last;
    QString email;
    QString password;
    double points;
    QSqlQuery *qry = new QSqlQuery(data);

    qry->prepare("SELECT * FROM account ");

    if(qry->exec())
    {
        while(qry->next())
        {
            first = qry->value(0).toString();
            last = qry->value(1).toString();
            email = qry->value(2).toString();
            password = qry->value(3).toString();
            points = qry->value(4).toDouble();
            newAccount = new accountDB(first,last,email,password,points);
            accounts.push_back(*newAccount);
        }
    }
    else
    {
         qDebug() << qry->lastError().text();
    }
}
void MainWindow::on_login_clicked()
{
    int i;
    for(i = 0; i < accounts.size(); i++)
    {
        if(ui->email->text() == accounts[i].getEmail() && ui->password->text() == accounts[i].getPassword())
        {
            mainScreen = new class mainScreen();
            mainScreen->setAccount(accounts[i]);
            mainScreen->show();
        }
    }
    if(i == accounts.size())
    {
        ui->label_3->setText("INVALID EMAIL/PASSWORD");
    }

}
