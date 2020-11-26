/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainScreen
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *ads;
    QWidget *qrCode;
    QWidget *update;
    QWidget *oderHist;
    QWidget *menu;
    QLabel *burger;
    QLabel *cheese;
    QLabel *impossible;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *fries;
    QLabel *chips;
    QLabel *label_5;
    QLabel *coke;
    QLabel *water;
    QLabel *sprite;
    QLabel *label_6;
    QPushButton *cokeB;
    QLabel *Burger1;
    QLabel *Burger1Price;
    QLabel *Bruger1Des;
    QPushButton *addBurger1;
    QLabel *Burger2;
    QLabel *Burger2Price;
    QLabel *Burger2Des;
    QPushButton *addBurger2;
    QPushButton *addBurger3;
    QLabel *Burger3;
    QLabel *Burger3Price;
    QLabel *Burger3Des;
    QPushButton *pushButton_2;
    QPushButton *spriteB;
    QPushButton *waterB;
    QLabel *label;
    QLabel *fries1;
    QLabel *fries1Price;
    QLabel *fries1Des;
    QPushButton *addFries;
    QPushButton *addChips;
    QLabel *chips1;
    QLabel *chips1Price;
    QLabel *chips1Des;
    QWidget *cart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainScreen)
    {
        if (mainScreen->objectName().isEmpty())
            mainScreen->setObjectName(QString::fromUtf8("mainScreen"));
        mainScreen->resize(659, 453);
        centralwidget = new QWidget(mainScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 661, 411));
        ads = new QWidget();
        ads->setObjectName(QString::fromUtf8("ads"));
        tabWidget->addTab(ads, QString());
        qrCode = new QWidget();
        qrCode->setObjectName(QString::fromUtf8("qrCode"));
        tabWidget->addTab(qrCode, QString());
        update = new QWidget();
        update->setObjectName(QString::fromUtf8("update"));
        tabWidget->addTab(update, QString());
        oderHist = new QWidget();
        oderHist->setObjectName(QString::fromUtf8("oderHist"));
        tabWidget->addTab(oderHist, QString());
        menu = new QWidget();
        menu->setObjectName(QString::fromUtf8("menu"));
        burger = new QLabel(menu);
        burger->setObjectName(QString::fromUtf8("burger"));
        burger->setGeometry(QRect(20, 50, 81, 61));
        cheese = new QLabel(menu);
        cheese->setObjectName(QString::fromUtf8("cheese"));
        cheese->setGeometry(QRect(20, 170, 81, 61));
        impossible = new QLabel(menu);
        impossible->setObjectName(QString::fromUtf8("impossible"));
        impossible->setGeometry(QRect(20, 290, 81, 61));
        label_3 = new QLabel(menu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 10, 171, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(menu);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 10, 191, 16));
        label_4->setAlignment(Qt::AlignCenter);
        fries = new QLabel(menu);
        fries->setObjectName(QString::fromUtf8("fries"));
        fries->setGeometry(QRect(440, 190, 71, 51));
        chips = new QLabel(menu);
        chips->setObjectName(QString::fromUtf8("chips"));
        chips->setGeometry(QRect(440, 300, 71, 51));
        label_5 = new QLabel(menu);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(440, 10, 191, 16));
        label_5->setAlignment(Qt::AlignCenter);
        coke = new QLabel(menu);
        coke->setObjectName(QString::fromUtf8("coke"));
        coke->setGeometry(QRect(440, 60, 51, 41));
        water = new QLabel(menu);
        water->setObjectName(QString::fromUtf8("water"));
        water->setGeometry(QRect(580, 60, 51, 41));
        sprite = new QLabel(menu);
        sprite->setObjectName(QString::fromUtf8("sprite"));
        sprite->setGeometry(QRect(510, 60, 51, 41));
        label_6 = new QLabel(menu);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 150, 191, 16));
        label_6->setAlignment(Qt::AlignCenter);
        cokeB = new QPushButton(menu);
        cokeB->setObjectName(QString::fromUtf8("cokeB"));
        cokeB->setGeometry(QRect(230, 30, 191, 331));
        Burger1 = new QLabel(menu);
        Burger1->setObjectName(QString::fromUtf8("Burger1"));
        Burger1->setGeometry(QRect(20, 30, 91, 16));
        Burger1Price = new QLabel(menu);
        Burger1Price->setObjectName(QString::fromUtf8("Burger1Price"));
        Burger1Price->setGeometry(QRect(160, 30, 47, 13));
        Burger1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Bruger1Des = new QLabel(menu);
        Bruger1Des->setObjectName(QString::fromUtf8("Bruger1Des"));
        Bruger1Des->setGeometry(QRect(110, 50, 101, 41));
        Bruger1Des->setWordWrap(true);
        addBurger1 = new QPushButton(menu);
        addBurger1->setObjectName(QString::fromUtf8("addBurger1"));
        addBurger1->setGeometry(QRect(20, 120, 191, 23));
        Burger2 = new QLabel(menu);
        Burger2->setObjectName(QString::fromUtf8("Burger2"));
        Burger2->setGeometry(QRect(20, 150, 91, 16));
        Burger2Price = new QLabel(menu);
        Burger2Price->setObjectName(QString::fromUtf8("Burger2Price"));
        Burger2Price->setGeometry(QRect(160, 150, 47, 13));
        Burger2Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Burger2Des = new QLabel(menu);
        Burger2Des->setObjectName(QString::fromUtf8("Burger2Des"));
        Burger2Des->setGeometry(QRect(110, 170, 101, 41));
        Burger2Des->setWordWrap(true);
        addBurger2 = new QPushButton(menu);
        addBurger2->setObjectName(QString::fromUtf8("addBurger2"));
        addBurger2->setGeometry(QRect(20, 240, 191, 23));
        addBurger3 = new QPushButton(menu);
        addBurger3->setObjectName(QString::fromUtf8("addBurger3"));
        addBurger3->setGeometry(QRect(20, 360, 191, 23));
        Burger3 = new QLabel(menu);
        Burger3->setObjectName(QString::fromUtf8("Burger3"));
        Burger3->setGeometry(QRect(20, 270, 91, 16));
        Burger3Price = new QLabel(menu);
        Burger3Price->setObjectName(QString::fromUtf8("Burger3Price"));
        Burger3Price->setGeometry(QRect(160, 270, 47, 13));
        Burger3Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Burger3Des = new QLabel(menu);
        Burger3Des->setObjectName(QString::fromUtf8("Burger3Des"));
        Burger3Des->setGeometry(QRect(110, 290, 101, 41));
        Burger3Des->setWordWrap(true);
        pushButton_2 = new QPushButton(menu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(434, 110, 61, 23));
        spriteB = new QPushButton(menu);
        spriteB->setObjectName(QString::fromUtf8("spriteB"));
        spriteB->setGeometry(QRect(500, 110, 61, 23));
        waterB = new QPushButton(menu);
        waterB->setObjectName(QString::fromUtf8("waterB"));
        waterB->setGeometry(QRect(570, 110, 61, 23));
        label = new QLabel(menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(466, 30, 141, 21));
        label->setAlignment(Qt::AlignCenter);
        fries1 = new QLabel(menu);
        fries1->setObjectName(QString::fromUtf8("fries1"));
        fries1->setGeometry(QRect(440, 170, 91, 16));
        fries1Price = new QLabel(menu);
        fries1Price->setObjectName(QString::fromUtf8("fries1Price"));
        fries1Price->setGeometry(QRect(580, 170, 47, 13));
        fries1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fries1Des = new QLabel(menu);
        fries1Des->setObjectName(QString::fromUtf8("fries1Des"));
        fries1Des->setGeometry(QRect(530, 190, 101, 41));
        fries1Des->setWordWrap(true);
        addFries = new QPushButton(menu);
        addFries->setObjectName(QString::fromUtf8("addFries"));
        addFries->setGeometry(QRect(440, 250, 191, 23));
        addChips = new QPushButton(menu);
        addChips->setObjectName(QString::fromUtf8("addChips"));
        addChips->setGeometry(QRect(440, 360, 191, 23));
        chips1 = new QLabel(menu);
        chips1->setObjectName(QString::fromUtf8("chips1"));
        chips1->setGeometry(QRect(440, 280, 91, 16));
        chips1Price = new QLabel(menu);
        chips1Price->setObjectName(QString::fromUtf8("chips1Price"));
        chips1Price->setGeometry(QRect(580, 280, 47, 13));
        chips1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        chips1Des = new QLabel(menu);
        chips1Des->setObjectName(QString::fromUtf8("chips1Des"));
        chips1Des->setGeometry(QRect(530, 300, 101, 41));
        chips1Des->setWordWrap(true);
        tabWidget->addTab(menu, QString());
        cart = new QWidget();
        cart->setObjectName(QString::fromUtf8("cart"));
        tabWidget->addTab(cart, QString());
        mainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 659, 21));
        mainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(mainScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainScreen->setStatusBar(statusbar);

        retranslateUi(mainScreen);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(mainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *mainScreen)
    {
        mainScreen->setWindowTitle(QCoreApplication::translate("mainScreen", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ads), QCoreApplication::translate("mainScreen", "SPECIALS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(qrCode), QCoreApplication::translate("mainScreen", "QR REWARDS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(update), QCoreApplication::translate("mainScreen", "UPDATES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(oderHist), QCoreApplication::translate("mainScreen", "ORDER HISTORY", nullptr));
        burger->setText(QCoreApplication::translate("mainScreen", "p1", nullptr));
        cheese->setText(QCoreApplication::translate("mainScreen", "p2", nullptr));
        impossible->setText(QCoreApplication::translate("mainScreen", "p3", nullptr));
        label_3->setText(QCoreApplication::translate("mainScreen", "BURGERS", nullptr));
        label_4->setText(QCoreApplication::translate("mainScreen", "COMBOS", nullptr));
        fries->setText(QCoreApplication::translate("mainScreen", "p4", nullptr));
        chips->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        label_5->setText(QCoreApplication::translate("mainScreen", "DRINKS", nullptr));
        coke->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        water->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        sprite->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        label_6->setText(QCoreApplication::translate("mainScreen", "SIDES", nullptr));
        cokeB->setText(QCoreApplication::translate("mainScreen", "PushButton", nullptr));
        Burger1->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger1Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        Bruger1Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        addBurger1->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        Burger2->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger2Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        Burger2Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        addBurger2->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        addBurger3->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        Burger3->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger3Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        Burger3Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainScreen", "Coke", nullptr));
        spriteB->setText(QCoreApplication::translate("mainScreen", "Sprite", nullptr));
        waterB->setText(QCoreApplication::translate("mainScreen", "Water", nullptr));
        label->setText(QCoreApplication::translate("mainScreen", "ALL DRINKS ARE $1.50", nullptr));
        fries1->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        fries1Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        fries1Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        addFries->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        addChips->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        chips1->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        chips1Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        chips1Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(menu), QCoreApplication::translate("mainScreen", "MENU", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cart), QCoreApplication::translate("mainScreen", "CART", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
