#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainscreen.h>
#include "accountdb.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void populate();

private slots:
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    mainScreen *mainScreen;
    QSqlDatabase data;
    QVector<accountDB> accounts;
    database db;
};
#endif // MAINWINDOW_H
