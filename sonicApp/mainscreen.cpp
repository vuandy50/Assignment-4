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
void mainScreen::setVectors()
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].getType() == "food")
        {
            food.push_back(items[i]);
        }
        else if(items[i].getType() == "drink")
        {
            drink.push_back(items[i]);
        }
        else if(items[i].getType() == "side")
        {
            sides.push_back(items[i]);
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

    }
    else if (index == 4)
    {
        if(turnOnTimer && makingOrder)
        {
            if(ui->progressBar->maximum() > time->second())
            {
                makingOrder = false;
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
        else
        {
            hideMakeOrder();
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
    qDebug() << "OKAY";
    *timeOrder = timeOrder->addSecs(1);

    if(*timeOrder == orders->getTime())
    {
        timerOrder->stop();
        ui->progressBar->setValue(timeOrder->second());
        ui->progress->setText("COMPLETE");
    }
    double calculate;
    if(orders->getTime().minute() == 0)
    {
        calculate =  orders->getTime().second() / 60.0;
    }
    else
    {
        calculate = orders->getTime().minute();
    }

    QString timeLeft = "ESTIMATED TIME: ~" + QString::number(calculate,'f',0) + " mins";
    ui->estTime->setText(timeLeft);
    ui->progressBar->setValue(timeOrder->second());

}
void mainScreen::on_completeOrder_clicked()
{
    if(orders->size() == 0)
    {
        ui->notify->setText("PLEASE GO TO MENU AND SELECT AN ITEM TO ORDER");
    }
    else if(turnOnTimer)
    {
        ui->progressBar->setRange(0,orders->getTime().second());
        if(ui->progressBar->maximum() > time->second())
        {
            ui->notify->setText("NOT ENOUGH TIME TO COMPLETE ORDER");
        }
    }
    else
    {
        showMakeOrder();
        makingOrder = true;
        on_tabWidget_currentChanged(5);

        orders->addTime();


        timeOrder = new QTime(0,0,0);
        timerOrder = new QTimer(this);

        ui->progressBar->setRange(0,orders->getTime().second());
        connect(timerOrder,SIGNAL(timeout()),this,SLOT(update()));
        timerOrder->start(1000);
    }
}
void mainScreen::update2()
{
    *time = time->addSecs(-1);
    ui->timer->setText(time->toString("h:mm"));
}
void mainScreen::on_orderReceived_clicked()
{
    timerOrder->stop();
    ui->progress->setText("COMPLETE");
    ui->progressBar->setValue(orders->getTime().second());
    showTimer();
    makingOrder = false;

    if(!turnOnTimer)
    {
        time = new QTime(2,0,0);
        timer = new QTimer(this);
        turnOnTimer = true;
    }
    ui->progressBar->setRange(0,orders->getTime().second());
    connect(timer,SIGNAL(timeout()),this,SLOT(update2()));
    timer->start(1000);

}

void mainScreen::on_end_clicked()
{
    orders->clear();
    close();
}
