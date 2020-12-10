#include "mainscreen.h"
#include "ui_mainscreen.h"

mainScreen::mainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainScreen)
{
    populateItems();
    setVectors();
    ui->setupUi(this);
    setMenu();
    forCombo = false;
    makingOrder = false;
    turnOnTimer = false;
    orders = new order();
    date = new class date();
    currentIndex = -1;
    updateIndex = 5;
    ui->tabWidget->setCurrentIndex(0);

}
mainScreen::~mainScreen()
{
    delete ui;
}
void mainScreen::populateItems()
{
    QString food;
    QString type;
    QString description;
    double price;
    QByteArray pic;
    item *newItem;

    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("SELECT * FROM menu");

    if(qry->exec())
    {
        while(qry->next())
        {
            food = qry->value(0).toString();
            type = qry->value(1).toString();
            description = qry->value(2).toString();
            price = qry->value(3).toDouble();
            pic = qry->value(4).toByteArray();

            newItem = new item(food,type,description,price,pic);
            items.push_back(*newItem);
        }
    }
    else
    {
        qDebug("CANNOT POPULATE ITEMS");
    }

}
void mainScreen::addOrdertoHistory()
{
    QDateTime dateTime = QDateTime::currentDateTime();

    QSqlQuery *qry = new QSqlQuery(db);

    for(int i = 0; i < orders->size(); i++)
    {
        qry->prepare("INSERT INTO orderHistory (Email, Quanity, Item, Side, Drink, DateTime, Price) "
                     "VALUES(?,?,?,?,?,?,?)");

        qry->addBindValue(A.getEmail());
        qry->addBindValue(orders->getItems()[i].quanity);
        qry->addBindValue(orders->getItems()[i].name.getItem());
        qry->addBindValue(orders->getItems()[i].side.getItem());
        qry->addBindValue(orders->getItems()[i].drink.getItem());
        qry->addBindValue(dateTime.toString());
        qry->addBindValue(orders->getItems()[i].price);
        if (qry->exec()) {}
        else {
            qDebug() << qry->lastError().text();
        }
    }
}
void mainScreen::populateOrderHistory()
{
    QSqlQuery *qry = new QSqlQuery(db);
    individualItem *items;
    QVector<individualItem> temp;
    QVector<QString> dateTime;
    orderHistory *ord;

    qry->prepare("SELECT Quanity, Item, Side, Drink, DateTime, Price FROM orderHistory WHERE Email = '"+A.getEmail()+"'");

    if(qry->exec())
    {
        while(qry->next())
        {
            items = new individualItem;
            items->quanity = qry->value(0).toInt();
            items->name.setItem(qry->value(1).toString());
            items->side.setItem(qry->value(2).toString());
            items->drink.setItem(qry->value(3).toString());
            dateTime.push_back(qry->value(4).toString());
            items->price = qry->value(5).toDouble();
            temp.push_back(*items);
        }
    }
    else
    {
         qDebug() << qry->lastError().text();
    }
    QVector<individualItem> test;
    QString currentTime = "";
    for(int j = 0; j < temp.size(); j++)
    {
        if(test.isEmpty())
        {
            test.push_back(temp[j]);
            currentTime = dateTime[j];
        }
        else if(dateTime[j] == currentTime)
        {

            test.push_back(temp[j]);
        }
        else
        {
            ord = new orderHistory(test,currentTime);
            oh.push_back(*ord);
            test.clear();
            test.push_back(temp[j]);
            currentTime = dateTime[j];

        }
    }
    ord = new orderHistory(test,currentTime);
    oh.push_back(*ord);
}
void mainScreen::setNewRP()
{
    QString rewards = QString::number(A.getRewadpts() - orders->getRewardsPts() + orders->calculateRewards());
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("UPDATE account SET RewardPoints = '"+rewards+"' WHERE Email = '"+A.getEmail()+"'");

    if(qry->exec())
    {

    }
    else
    {
        qDebug() << "Whoops";
    }

}
void mainScreen::setVectors()
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].getType() == "food")
        {
            food.push_back(items[i]);
            noCombo.push_back(items[i]);
        }
        else if(items[i].getType() == "drink")
        {
            drink.push_back(items[i]);
            noCombo.push_back(items[i]);
        }
        else if(items[i].getType() == "side")
        {
            sides.push_back(items[i]);
            noCombo.push_back(items[i]);
        }
        else if(items[i].getType() == "combo")
        {
            combo.push_back(items[i]);
        }
    }
}
void mainScreen::onlySides()
{
    ui->addBurger1->setVisible(false);
    ui->addBurger2->setVisible(false);
    ui->addBurger3->setVisible(false);

    ui->addChips->setVisible(true);
    ui->addFries->setVisible(true);

    ui->cokeB->setVisible(false);
    ui->spriteB->setVisible(false);
    ui->waterB->setVisible(false);
    ui->comboA->setVisible(false);
    ui->comboB->setVisible(false);
    ui->comboC->setVisible(false);

    ui->fries1Price->hide();
    ui->chips1Price->hide();

}
void mainScreen::onlyDrinks()
{
    ui->addBurger1->setVisible(false);
    ui->addBurger2->setVisible(false);
    ui->addBurger3->setVisible(false);
    ui->addChips->setVisible(false);
    ui->addFries->setVisible(false);

    ui->cokeB->setVisible(true);
    ui->spriteB->setVisible(true);
    ui->waterB->setVisible(true);

    ui->comboA->setVisible(false);
    ui->comboB->setVisible(false);
    ui->comboC->setVisible(false);

    ui->fries1Price->show();
    ui->chips1Price->show();

    ui->label->hide();
}
void mainScreen::normal()
{
    ui->addBurger1->setVisible(true);
    ui->addBurger2->setVisible(true);
    ui->addBurger3->setVisible(true);
    ui->addChips->setVisible(true);
    ui->addFries->setVisible(true);
    ui->cokeB->setVisible(true);
    ui->spriteB->setVisible(true);
    ui->waterB->setVisible(true);
    ui->comboA->setVisible(true);
    ui->comboB->setVisible(true);
    ui->comboC->setVisible(true);

    ui->label->show();
}
void mainScreen::setMenu()
{
    setFood();
    setDrink();
    setSides();
    setCombo();
}
void mainScreen::setFood()
{
    QPixmap pict1 = QPixmap();
    ui->burger->setAlignment(Qt::AlignCenter);
    if(!pict1.loadFromData(food[2].getPic())){
        qDebug() << ("Whoops.");
    }
    pict1 = pict1.scaled(ui->burger->size(),Qt::KeepAspectRatio);
    ui->burger->setPixmap(pict1);

    ui->Burger1->setText(food[2].getItem());
    ui->Burger1Price->setText("$ " + QString::number(food[2].getPrice()));
    ui->Burger1Des->setText(food[2].getDescription());

    QPixmap pict2 = QPixmap();
    ui->cheese->setAlignment(Qt::AlignCenter);
    if(!pict2.loadFromData(food[1].getPic())){
        qDebug() << ("Whoops.");
    }
    pict2 = pict2.scaled(ui->cheese->size(),Qt::KeepAspectRatio);
    ui->cheese->setPixmap(pict2);

    ui->Burger2->setText(food[1].getItem());
    ui->Burger2Price->setText("$ " +QString::number(food[1].getPrice()));
    ui->Burger2Des->setText(food[1].getDescription());

    QPixmap pict3 = QPixmap();
    ui->impossible->setAlignment(Qt::AlignCenter);
    if(!pict3.loadFromData(food[0].getPic())){
        qDebug() << ("Whoops.");
    }
    pict3 = pict3.scaled(ui->impossible->size(),Qt::KeepAspectRatio);
    ui->impossible->setPixmap(pict3);

    ui->Burger3->setText(food[0].getItem());
    ui->Burger3Price->setText("$ " +QString::number(food[0].getPrice()));
    ui->Burger3Des->setText(food[0].getDescription());
}
void mainScreen::setDrink()
{
    QPixmap pict1 = QPixmap();
    ui->coke->setAlignment(Qt::AlignCenter);
    if(!pict1.loadFromData(drink[2].getPic())){
        qDebug() << ("Whoops.");
    }
    pict1 = pict1.scaled(ui->coke->size(),Qt::KeepAspectRatio);
    ui->coke->setPixmap(pict1);

    QPixmap pict2 = QPixmap();
    ui->sprite->setAlignment(Qt::AlignCenter);
    if(!pict2.loadFromData(drink[1].getPic())){
        qDebug() << ("Whoops.");
    }
    pict2 = pict2.scaled(ui->sprite->size(),Qt::KeepAspectRatio);
    ui->sprite->setPixmap(pict2);

    QPixmap pict3 = QPixmap();
    ui->water->setAlignment(Qt::AlignCenter);
    if(!pict3.loadFromData(drink[0].getPic())){
        qDebug() << ("Whoops.");
    }
    pict3 = pict3.scaled(ui->water->size(),Qt::KeepAspectRatio);
    ui->water->setPixmap(pict3);
}
void mainScreen::setSides()
{
    QPixmap pict1 = QPixmap();
    ui->fries->setAlignment(Qt::AlignCenter);
    if(!pict1.loadFromData(sides[1].getPic())){
        qDebug() << ("Whoops.");
    }
    pict1 = pict1.scaled(ui->fries->size(),Qt::KeepAspectRatio);
    ui->fries->setPixmap(pict1);

    ui->fries1->setText(sides[1].getItem());
    ui->fries1Price->setText("$ " +QString::number(sides[1].getPrice()));
    ui->fries1Des->setText(sides[1].getDescription());

    QPixmap pict2 = QPixmap();
    ui->chips->setAlignment(Qt::AlignCenter);
    if(!pict2.loadFromData(sides[0].getPic())){
        qDebug() << ("Whoops.");
    }
    pict2 = pict2.scaled(ui->chips->size(),Qt::KeepAspectRatio);
    ui->chips->setPixmap(pict2);

    ui->chips1->setText(sides[0].getItem());
    ui->chips1Price->setText("$ " +QString::number(sides[0].getPrice()));
    ui->chips1Des->setText(sides[0].getDescription());
}
void mainScreen::setCombo()
{
    ui->combo1->setText(combo[2].getItem());
    ui->combo1Price->setText("$ " + QString::number(combo[2].getPrice()));
    ui->combo1Des->setText(combo[2].getDescription());

    ui->combo2->setText(combo[1].getItem());
    ui->combo2Price->setText("$ " +QString::number(combo[1].getPrice()));
    ui->combo2Des->setText(combo[1].getDescription());

    ui->combo3->setText(combo[0].getItem());
    ui->combo3Price->setText("$ " +QString::number(combo[0].getPrice()));
    ui->combo3Des->setText(combo[0].getDescription());
}


void mainScreen::on_addBurger1_clicked()
{
    orders->addItem(food[2]);
    QString message = food[2].getItem() + " ADDED";
    ui->message->setText(message);
}

void mainScreen::on_addBurger2_clicked()
{
     orders->addItem(food[1]);
     QString message = food[1].getItem() + " ADDED";
     ui->message->setText(message);
}

void mainScreen::on_addBurger3_clicked()
{
     orders->addItem(food[0]);
     QString message = food[0].getItem() + " ADDED";
     ui->message->setText(message);
}

void mainScreen::on_comboA_clicked()
{
     orders->addItem(combo[2]);
     forCombo = true;
     comboName = combo[2].getItem();
     onlySides();
     QString message = "PLEASE SELECT A SIDE";
     ui->message->setText(message);
}

void mainScreen::on_comboB_clicked()
{
     orders->addItem(combo[1]);
     forCombo = true;
     comboName = combo[1].getItem();
     onlySides();
     QString message = "PLEASE SELECT A SIDE";
     ui->message->setText(message);
}

void mainScreen::on_comboC_clicked()
{
     orders->addItem(combo[0]);
     forCombo = true;
     comboName = combo[0].getItem();
     onlySides();
     QString message = "PLEASE SELECT A SIDE";
     ui->message->setText(message);
}

void mainScreen::on_addFries_clicked()
{
    if(forCombo)
    {
        orders->addSide(sides[1]);
        QString message = "PLEASE SELECT A DRINK";
        onlyDrinks();
        ui->message->setText(message);
    }
    else
    {
         orders->addItem(sides[1]);
         QString message = sides[1].getItem() + " ADDED";
         ui->message->setText(message);
    }
}

void mainScreen::on_addChips_clicked()
{
    if(forCombo)
    {
        orders->addSide(sides[0]);
        onlyDrinks();
        QString message = "PLEASE SELECT A DRINK";
        ui->message->setText(message);
    }
    else
    {
        orders->addItem(sides[0]);
        QString message = sides[0].getItem() + " ADDED";
        ui->message->setText(message);
    }

}

void mainScreen::on_cokeB_clicked()
{
    if(forCombo)
    {
        orders->addDrink(drink[2]);
        forCombo = false;
        normal();
        orders->checkRepeatCombo();
        QString message = comboName + " ADDED";
        ui->message->setText(message);
    }
    else
    {
        orders->addItem(drink[2]);
        QString message = drink[2].getItem() + " ADDED";
        ui->message->setText(message);
    }
}

void mainScreen::on_spriteB_clicked()
{
    if(forCombo)
    {
        orders->addDrink(drink[1]);
        forCombo = false;
        normal();
        orders->checkRepeatCombo();
        QString message = comboName + " ADDED";
        ui->message->setText(message);
    }
    else
    {
        orders->addItem(drink[1]);
        QString message = drink[1].getItem() + " ADDED";
        ui->message->setText(message);
    }

}

void mainScreen::on_waterB_clicked()
{
    if(forCombo)
    {
        orders->addDrink(drink[0]);
        forCombo = false;
        normal();
        orders->checkRepeatCombo();
        QString message = comboName + " ADDED";
        ui->message->setText(message);
    }
    else
    {
        orders->addItem(drink[0]);
        QString message = drink[0].getItem() + " ADDED";
        ui->message->setText(message);
    }

}

void mainScreen::on_tabWidget_currentChanged(int index)
{
    if(index == 0)
    {
        QMovie *movie1 = new QMovie("impossible.gif");
        movie1->setScaledSize(ui->gifAd->size());
        ui->gifAd->setMovie(movie1);
        movie1->start();

    }
    else if (index == 1)
    {
        ui->greetings->setText("WELCOME " + A.getFname());
        updateRP();
        hideAll();
        showBigButtons();
    }
    else if(index == 2)
    {
        displayBurgers();
    }
    else if (index == 3)
    {
        date->clear();
        date->setEmail(A.getEmail());
        date->populateDates();
        date->organize();
        oh.clear();
        populateOrderHistory();
        ui->orderhistory->clear();
        ui->orderList->clear();
        ui->priceList->clear();
        for(int i = 0; i < oh.size(); i++)
        {
            QListWidgetItem *Hitem = new QListWidgetItem();
            QString output ="ORDER " + QString::number(i+1) + " (" + oh[i].getDateTime()+")";
            Hitem->setText(output);
            ui->orderhistory->addItem(Hitem);
        }


    }
    else if (index == 4)
    {
        if(turnOnTimer)
        {
            int max = orders->getTime().second() + (orders->getTime().minute() * 60) + (orders->getTime().hour() * 120);
            if(max > (time->second() + (time->minute() * 60) + (time->hour() * 120)))
            {
                ui->addBurger1->hide();
                ui->addBurger2->hide();
                ui->addBurger3->hide();
                ui->addChips->hide();
                ui->addFries->hide();
                ui->cokeB->hide();
                ui->spriteB->hide();
                ui->waterB->hide();
                ui->comboA->hide();
                ui->comboB->hide();
                ui->comboC->hide();
                ui->message->setText("CANNOT ORDER");
            }
        }
        else if(makingOrder)
        {
            ui->addBurger1->hide();
            ui->addBurger2->hide();
            ui->addBurger3->hide();
            ui->addChips->hide();
            ui->addFries->hide();
            ui->cokeB->hide();
            ui->spriteB->hide();
            ui->waterB->hide();
            ui->comboA->hide();
            ui->comboB->hide();
            ui->comboC->hide();
            ui->message->setText("WAITING FOR ORDER");
        }
        else
        {
            ui->addBurger1->show();
            ui->addBurger2->show();
            ui->addBurger3->show();
            ui->addChips->show();
            ui->addFries->show();
            ui->cokeB->show();
            ui->spriteB->show();
            ui->waterB->show();
            ui->comboA->show();
            ui->comboB->show();
            ui->comboC->show();
        }

    }
    else if(index == 5)
    {
        if(makingOrder)
        {
            ui->remove->hide();
        }
        else if(turnOnTimer)
        {
            hideMakeOrder();
            showTimer();
            orders->addToMain();
            orders->calculatePrice();
            ui->listWidget->clear();
            ui->listWidget2->clear();
            ui->remove->clear();
            for(int i = 0; i < orders->size(); i++)
            {
                QListWidgetItem *item = new QListWidgetItem();
                item->setText(orders->printItem(i));
                ui->listWidget->addItem(item);
                QListWidgetItem *cost = new QListWidgetItem();
                cost->setText(orders->priceLine(i));
                ui->listWidget2->addItem(cost);
                QListWidgetItem *removal = new QListWidgetItem();
                removal->setText("REMOVE");
                ui->remove->addItem(removal);
            }
            ui->subtotal->setText(QString::number(orders->getSubTotal(),'f',2));
            ui->tax->setText(QString::number(orders->getTax(),'f',2));
            ui->total->setText(QString::number(orders->getTotal(),'f',2));
        }
        else
        {
            hideMakeOrder();
            orders->addToMain();
            orders->calculatePrice();
            ui->listWidget->clear();
            ui->listWidget2->clear();
            ui->remove->clear();
            for(int i = 0; i < orders->size(); i++)
            {
                QListWidgetItem *item = new QListWidgetItem();
                item->setText(orders->printItem(i));
                ui->listWidget->addItem(item);
                QListWidgetItem *cost = new QListWidgetItem();
                cost->setText(orders->priceLine(i));
                ui->listWidget2->addItem(cost);
                QListWidgetItem *removal = new QListWidgetItem();
                removal->setText("REMOVE");
                ui->remove->addItem(removal);
            }
            ui->subtotal->setText(QString::number(orders->getSubTotal(),'f',2));
            ui->tax->setText(QString::number(orders->getTax(),'f',2));
            ui->total->setText(QString::number(orders->getTotal(),'f',2));
        }

    }
}

void mainScreen::on_listWidget_clicked(const QModelIndex &index)
{
    ui->listWidget2->setCurrentRow(index.row());
}

void mainScreen::on_listWidget2_clicked(const QModelIndex &index)
{
    ui->listWidget->setCurrentRow(index.row());
}

void mainScreen::on_remove_clicked(const QModelIndex &index)
{
    ui->listWidget->setCurrentRow(index.row());
    ui->listWidget2->setCurrentRow(index.row());
    ui->remove->setCurrentRow(index.row());

    ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
    ui->listWidget2->removeItemWidget(ui->listWidget2->currentItem());
    ui->remove->removeItemWidget(ui->remove->currentItem());

    orders->removal(index.row());
    on_tabWidget_currentChanged(5);
}
void mainScreen::hideMakeOrder()
{
    ui->makingOrder->hide();
    ui->progress->hide();
    ui->progressBar->hide();
    ui->estTime->hide();
    ui->orderReceived->hide();
    ui->cancelOrder->hide();
    ui->hourLimit->hide();
    ui->timeRemain->hide();
    ui->timer->hide();
    ui->timeUnit->hide();
    ui->end->hide();
}
void mainScreen::showMakeOrder()
{
    ui->progress->setText("IN PROGRESS");
    ui->makingOrder->show();
    ui->progress->show();
    ui->progressBar->show();
    ui->estTime->show();
    ui->orderReceived->show();
    ui->cancelOrder->show();
}
void  mainScreen::showTimer()
{
    ui->hourLimit->show();
    ui->timeRemain->show();
    ui->timer->show();
    ui->timeUnit->show();
    ui->end->show();
}
void mainScreen::update()
{
    *timeOrder = timeOrder->addSecs(1);

    if(*timeOrder == orders->getTime())
    {
        timerOrder->stop();
        ui->progressBar->setValue(timeOrder->second() + (timeOrder->minute() * 60) + (timeOrder->hour() * 120));
        ui->progress->setText("COMPLETE");
    }
    double calculate;
    if(orders->getTime().hour() - timeOrder->hour() != 0)
    {
        calculate =  orders->getTime().hour() - timeOrder->hour() ;
        QString timeLeft = "ESTIMATED TIME: ~" + QString::number(calculate) + " hrs";
        ui->estTime->setText(timeLeft);
    }
    else if(orders->getTime().minute() - timeOrder->minute()  != 0)
    {
        calculate =  orders->getTime().minute() - timeOrder->minute();
        QString timeLeft = "ESTIMATED TIME: ~" + QString::number(calculate) + " mins";
        ui->estTime->setText(timeLeft);
    }
    else if (orders->getTime().second() - timeOrder->second() != 0)
    {
        calculate = orders->getTime().second() - timeOrder->second();
        QString timeLeft = "ESTIMATED TIME: ~" + QString::number(calculate) + " secs";
        ui->estTime->setText(timeLeft);
    }
    ui->progressBar->setValue(timeOrder->second() + (timeOrder->minute() * 60) + (timeOrder->hour() * 120));

}
void mainScreen::on_completeOrder_clicked()
{
    ui->completeOrder->hide();
    ui->notify2->setText("");
    if(orders->size() == 0)
    {
        ui->notify->setText("PLEASE GO TO MENU AND SELECT AN ITEM TO ORDER");
        ui->completeOrder->show();
    }
    else if(turnOnTimer)
    {
        ui->notify->setText("");
        int max = orders->getTime().second() + (orders->getTime().minute() * 60) + (orders->getTime().hour() * 120);
        if(max > (time->second() + (time->minute() * 60) + (time->hour() * 120)))
        {
            ui->completeOrder->hide();
            ui->notify->setText("CANNOT COMPLETE ORDER IN TIME");
        }
        else
        {
            showMakeOrder();
            makingOrder = true;
            on_tabWidget_currentChanged(5);

            orders->addTime();


            timeOrder = new QTime(0,0,0);
            timerOrder = new QTimer(this);

            int max = orders->getTime().second() + (orders->getTime().minute() * 60) + (orders->getTime().hour() * 120);
            ui->progressBar->setRange(0, max);
            connect(timerOrder,SIGNAL(timeout()),this,SLOT(update()));
            timerOrder->start(1000);
        }
    }
    else
    {
        ui->notify->setText("");
        showMakeOrder();
        makingOrder = true;
        on_tabWidget_currentChanged(5);

        orders->addTime();


        timeOrder = new QTime(0,0,0);
        timerOrder = new QTimer(this);

        int max = orders->getTime().second() + (orders->getTime().minute() * 60) + (orders->getTime().hour() * 120);
        ui->progressBar->setRange(0, max);
        connect(timerOrder,SIGNAL(timeout()),this,SLOT(update()));
        timerOrder->start(1000);
    }
}
void mainScreen::update2()
{
    *time = time->addSecs(-1);
    ui->timer->setText(time->toString("h:mm"));
    if(time->hour() == 0 && time->minute() == 0 && time->second() == 0)
    {
        //CANNOT USE ANYTHING ON APP
    }
}
void mainScreen::on_orderReceived_clicked()
{
    timerOrder->stop();
    ui->progress->setText("COMPLETE");
    int max = orders->getTime().second() + (orders->getTime().minute() * 60) + (orders->getTime().hour() * 120);
    ui->progressBar->setValue(max);
    if(!turnOnTimer)
    {
        hideMakeOrder();
        showTimer();
        makingOrder = false;
        time = new QTime(2,0,0);
        timer = new QTimer(this);
        turnOnTimer = true;
        connect(timer,SIGNAL(timeout()),this,SLOT(update2()));
        timer->start(1000);

    }
    else
    {
        hideMakeOrder();
        showTimer();
        makingOrder = false;
    }
    addOrdertoHistory();
    setNewRP();
    orders->clear();
    ui->listWidget->clear();
    ui->listWidget2->clear();
    ui->remove->clear();
    ui->remove->show();
    ui->subtotal->setText("0.00");
    ui->tax->setText("0.00");
    ui->total->setText("0.00");
    ui->completeOrder->show();
}

void mainScreen::on_end_clicked()
{
    if(makingOrder)
    {
        ui->notify2->setText("ORDER IS BEING MADE, PLEASE CANCEL ORDER");
    }
    else
    {
        orders->clear();
        close();
    }

}

void mainScreen::on_cancelOrder_clicked()
{
    orders->clear();
    ui->listWidget->clear();
    ui->listWidget2->clear();
    ui->remove->clear();
    ui->remove->show();
    ui->subtotal->setText("0.00");
    ui->tax->setText("0.00");
    ui->total->setText("0.00");
    ui->completeOrder->show();
    makingOrder = false;
    ui->notify2->setText("YOUR ORDER HAS BEEN CANCELED");
    timerOrder->stop();
    if(turnOnTimer)
    {
        hideMakeOrder();
        showTimer();
    }
    else
    {
        hideMakeOrder();
    }



}

void mainScreen::on_orderhistory_clicked(const QModelIndex &index)
{
    currentIndex = index.row();
}

void mainScreen::on_viewOrderB_clicked()
{
    if(currentIndex == -1)
    {
        ui->OHlabel->setText("PLEASE SELECT AN ORDER TO VIEW");
    }
    else
    {
        ui->orderList->clear();
        ui->priceList->clear();
        for(int i = 0; i < oh[currentIndex].getItems().size(); i++)
        {
            QListWidgetItem *item = new QListWidgetItem();
            item->setText(oh[currentIndex].printItem(i));
            ui->orderList->addItem(item);
            QListWidgetItem *cost = new QListWidgetItem();
            cost->setText(oh[currentIndex].priceLine(i));
            ui->priceList->addItem(cost);
        }
        ui->OHsub->setText(QString::number(oh[currentIndex].calSub(),'f',2));
        ui->OHtax->setText(QString::number(oh[currentIndex].calTax(),'f',2));
        ui->OHtotal->setText(QString::number(oh[currentIndex].calTotal(),'f',2));
    }
}
void mainScreen::displayBurgers()
{
    QPixmap pict1 = QPixmap();
    ui->pic->setAlignment(Qt::AlignCenter);
    if(!pict1.loadFromData(noCombo[updateIndex].getPic())){
        qDebug() << ("Whoops.");
    }
    pict1 = pict1.scaled(ui->pic->size(),Qt::KeepAspectRatio);
    ui->pic->setPixmap(pict1);

    ui->cost->setText(QString::number(noCombo[updateIndex].getPrice(),'f',2));
    ui->name->setText(noCombo[updateIndex].getItem());
    ui->description->setText(noCombo[updateIndex].getDescription());
}

void mainScreen::on_left_clicked()
{
    if(updateIndex == 0)
    {
        updateIndex = noCombo.size() - 1;
    }
    else
    {
        updateIndex--;
    }
    on_tabWidget_currentChanged(2);
}

void mainScreen::on_right_clicked()
{
    if(updateIndex + 1 < noCombo.size())
    {
        updateIndex++;
    }
    else
    {
        updateIndex = 0;
    }
    on_tabWidget_currentChanged(2);
}
void mainScreen::showBigButtons()
{
    ui->freeBurger->show();
    ui->freeCombo->show();
    ui->freeDrink->show();
    ui->freeMask->show();
    ui->freeSide->show();

    ui->pts1->show();
    ui->pts2->show();
    ui->pts3->show();
    ui->pts4->show();
    ui->pts5->show();

    ui->freeBurger->setDisabled(false);
    ui->freeCombo->setDisabled(false);
    ui->freeDrink->setDisabled(false);
    ui->freeMask->setDisabled(false);
    ui->freeSide->setDisabled(false);

}
void mainScreen::hideAll()
{
    ui->AButton->hide();
    ui->BButton->hide();
    ui->CButton->hide();

    ui->AButton->setDisabled(false);
    ui->BButton->setDisabled(false);
    ui->CButton->setDisabled(false);

    ui->chipsButton->hide();
    ui->friesButton->hide();

    ui->chipsButton->setDisabled(false);
    ui->friesButton->setDisabled(false);

    ui->waterButton->hide();
    ui->spriteButton->hide();
    ui->cokeButton->hide();

    ui->waterButton->setDisabled(false);
    ui->spriteButton->setDisabled(false);
    ui->cokeButton->setDisabled(false);

    ui->burgerButton->hide();
    ui->cheeseButton->hide();
    ui->impButton->hide();

    ui->freeBurger->hide();
    ui->freeCombo->hide();
    ui->freeDrink->hide();

    ui->freeSide->hide();
    ui->freeMask->hide();
    ui->SButton->hide();
    ui->MButton->hide();
    ui->LButton->hide();

    ui->pts1->hide();
    ui->pts2->hide();
    ui->pts3->hide();
    ui->pts4->hide();
    ui->pts5->hide();
}
void mainScreen::updateRP()
{
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("SELECT RewardPoints FROM account WHERE Email ='"+A.getEmail()+"'" );
    if(qry->exec())
    {
        while(qry->next())
        {
            A.setRewardpts( qry->value(0).toDouble());
        }
    }
    else
    {
        qDebug("CANNOT POPULATE ITEMS");
    }
    ui->points->setText("REWARD POINTS: " + QString::number(A.getRewadpts()));
}

void mainScreen::on_freeDrink_clicked()
{
    if(A.getRewadpts() < 5)
    {
        ui->directions->setText("NOT ENOUGH POINTS!");
    }
    else
    {
        hideAll();
        ui->directions->setText("");
        ui->waterButton->show();
        ui->spriteButton->show();
        ui->cokeButton->show();
        ui->freeDrink->show();
        ui->freeDrink->setDisabled(true);
    }
}

void mainScreen::on_freeSide_clicked()
{
    if(A.getRewadpts() < 15)
    {
        ui->directions->setText("NOT ENOUGH POINTS!");
    }
    else
    {
        hideAll();
        ui->directions->setText("");
        ui->chipsButton->show();
        ui->friesButton->show();
        ui->freeSide->show();
        ui->freeSide->setDisabled(true);
    }
}

void mainScreen::on_freeBurger_clicked()
{
    if(A.getRewadpts() < 30)
    {
        ui->directions->setText("NOT ENOUGH POINTS!");
    }
    else
    {
        hideAll();
        ui->directions->setText("");
        ui->burgerButton->show();
        ui->cheeseButton->show();
        ui->impButton->show();
        ui->freeBurger->show();
        ui->freeBurger->setDisabled(true);
    }
}

void mainScreen::on_freeCombo_clicked()
{
    if(A.getRewadpts() < 50)
    {
        ui->directions->setText("NOT ENOUGH POINTS!");
    }
    else
    {
        hideAll();
        ui->directions->setText("");
        ui->AButton->show();
        ui->BButton->show();
        ui->CButton->show();
        ui->freeCombo->show();
        ui->freeCombo->setDisabled(true);
    }
}

void mainScreen::on_freeMask_clicked()
{
    if(A.getRewadpts() < 75)
    {
        ui->directions->setText("NOT ENOUGH POINTS!");
    }
    else
    {
        hideAll();
        ui->directions->setText("");
        ui->freeMask->show();
        ui->SButton->show();
        ui->MButton->show();
        ui->LButton->show();
        ui->freeMask->setDisabled(true);
    }
}

void mainScreen::on_cokeButton_clicked()
{
    if(!ui->freeCombo->isEnabled())
    {
        freeItem->drink.setItem("COKE");
        orders->addFreeItem(*freeItem);
    }
    else
    {
        freeItem = new individualItem();
        freeItem->name.setItem("COKE");
        freeItem->name.setType("drink");
        freeItem->name.setPrice(0);
        freeItem->quanity = 1;
        orders->addFreeItem(*freeItem);

    }
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_spriteButton_clicked()
{

    if(!ui->freeCombo->isEnabled())
    {
        freeItem->drink.setItem("SPRITE");
        orders->addFreeItem(*freeItem);

    }
    else
    {
        freeItem = new individualItem();
        freeItem->name.setItem("SPRITE");
        freeItem->name.setType("drink");
        freeItem->name.setPrice(0);
        freeItem->quanity = 1;
        orders->addFreeItem(*freeItem);

    }
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_waterButton_clicked()
{
    if(!ui->freeCombo->isEnabled())
    {
        freeItem->drink.setItem("DASANI WATER");
        orders->addFreeItem(*freeItem);

    }
    else
    {
        freeItem = new individualItem();
        freeItem->name.setItem("DASANI WATER");
        freeItem->name.setType("drink");
        freeItem->name.setPrice(0);
        freeItem->quanity = 1;
        orders->addFreeItem(*freeItem);

    }
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_friesButton_clicked()
{
    if(!ui->freeCombo->isEnabled())
    {
        freeItem->side.setItem("FRIES");
        ui->waterButton->show();
        ui->spriteButton->show();
        ui->cokeButton->show();
        ui->freeDrink->show();
        ui->freeDrink->setDisabled(true);
        ui->chipsButton->setDisabled(true);
        ui->friesButton->setDisabled(true);

    }
    else
    {
        freeItem = new individualItem();
        freeItem->name.setItem("FRIES");
        freeItem->name.setType("side");
        freeItem->name.setPrice(0);
        freeItem->quanity = 1;
        orders->addFreeItem(*freeItem);
        ui->tabWidget->setCurrentIndex(5);
    }

}

void mainScreen::on_chipsButton_clicked()
{
    if(!ui->freeCombo->isEnabled())
    {
        freeItem->side.setItem("CHIPS");
        ui->waterButton->show();
        ui->spriteButton->show();
        ui->cokeButton->show();
        ui->freeDrink->show();
        ui->freeDrink->setDisabled(true);
        ui->chipsButton->setDisabled(true);
        ui->friesButton->setDisabled(true);

    }
    else
    {
        freeItem = new individualItem();
        freeItem->name.setItem("CHIPS");
        freeItem->name.setType("side");
        freeItem->name.setPrice(0);
        freeItem->quanity = 1;
        orders->addFreeItem(*freeItem);
        ui->tabWidget->setCurrentIndex(5);
    }

}

void mainScreen::on_burgerButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("BURGER");
    freeItem->name.setType("food");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_cheeseButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("CHEESEBURGER");
    freeItem->name.setType("food");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_impButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("IMPOSSIBLE BURGER");
    freeItem->name.setType("food");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_AButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("COMBO A");
    freeItem->name.setType("combo");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;


    ui->chipsButton->show();
    ui->friesButton->show();
    ui->freeSide->show();
    ui->AButton->setDisabled(true);
    ui->BButton->setDisabled(true);
    ui->CButton->setDisabled(true);
    ui->freeSide->setDisabled(true);
}

void mainScreen::on_BButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("COMBO B");
    freeItem->name.setType("combo");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;


    ui->chipsButton->show();
    ui->friesButton->show();
    ui->freeSide->show();
    ui->AButton->setDisabled(true);
    ui->BButton->setDisabled(true);
    ui->CButton->setDisabled(true);
    ui->freeSide->setDisabled(true);
}

void mainScreen::on_CButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("COMBO C");
    freeItem->name.setType("combo");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;


    ui->chipsButton->show();
    ui->friesButton->show();
    ui->freeSide->show();
    ui->AButton->setDisabled(true);
    ui->BButton->setDisabled(true);
    ui->CButton->setDisabled(true);
    ui->freeSide->setDisabled(true);
}

void mainScreen::on_SButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("FACEMASK S");
    freeItem->name.setType("");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);

}

void mainScreen::on_MButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("FACEMASK M");
    freeItem->name.setType("");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);
}

void mainScreen::on_LButton_clicked()
{
    freeItem = new individualItem();
    freeItem->name.setItem("FACEMASK L");
    freeItem->name.setType("");
    freeItem->name.setPrice(0);
    freeItem->quanity = 1;
    orders->addFreeItem(*freeItem);
    ui->tabWidget->setCurrentIndex(5);
}
