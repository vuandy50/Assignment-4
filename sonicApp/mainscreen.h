#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTimer>
#include <database.h>
#include <QMap>
#include <item.h>
#include <order.h>
#include <date.h>
#include <orderhistory.h>
namespace Ui {
class mainScreen;
}

class mainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainScreen(QWidget *parent = nullptr);
    ~mainScreen();
    void populateItems();
    void setMenu();
    void setFood();
    void setDrink();
    void setSides();
    void setCombo();
    void setVectors();

    void onlySides();
    void onlyDrinks();
    void normal();

    void hideMakeOrder();
    void showMakeOrder();
    void showTimer();

    void setEmail(QString e) {email = e;}
    void addOrdertoHistory();
    void populateOrderHistory();

private slots:
    void on_addBurger1_clicked();

    void on_addBurger2_clicked();

    void on_addBurger3_clicked();

    void on_comboA_clicked();

    void on_comboB_clicked();

    void on_comboC_clicked();

    void on_addFries_clicked();

    void on_addChips_clicked();

    void on_cokeB_clicked();

    void on_spriteB_clicked();

    void on_waterB_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_listWidget2_clicked(const QModelIndex &index);

    void on_remove_clicked(const QModelIndex &index);

    void on_completeOrder_clicked();

    void on_orderReceived_clicked();

    void on_end_clicked();

    void on_cancelOrder_clicked();

    void on_orderhistory_clicked(const QModelIndex &index);

    void on_viewOrderB_clicked();

public slots:
    void update();
    void update2();
private:
    Ui::mainScreen *ui;
    QSqlDatabase db;
    QVector<item> items;
    QVector<item> food;
    QVector<item> drink;
    QVector<item> sides;
    QVector<item> combo;

    order *orders;
    bool forCombo;
    QString comboName;

    bool makingOrder;

    QTime *timeOrder;
    QTimer *timerOrder;

    QTime *time;
    QTimer *timer;
    bool turnOnTimer;

    date *date;
    QString email;
    QVector<orderHistory> oh;
    int currentIndex;
};

#endif // MAINSCREEN_H
