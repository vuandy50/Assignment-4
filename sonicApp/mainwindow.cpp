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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    if(ui->email->text() == "username" && ui->password->text() == "password")
    {
        mainScreen = new class mainScreen();
        mainScreen->show();
    }
    else
    {
        ui->label_3->setText("INVALID EMAIL/PASSWORD");
    }
}
