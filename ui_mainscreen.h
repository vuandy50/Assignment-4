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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
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
    QLabel *Burger1;
    QLabel *Burger1Price;
    QLabel *Burger1Des;
    QPushButton *addBurger1;
    QLabel *Burger2;
    QLabel *Burger2Price;
    QLabel *Burger2Des;
    QPushButton *addBurger2;
    QPushButton *addBurger3;
    QLabel *Burger3;
    QLabel *Burger3Price;
    QLabel *Burger3Des;
    QPushButton *cokeB;
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
    QLabel *combo1;
    QLabel *combo2;
    QLabel *combo3;
    QLabel *combo1Des;
    QLabel *combo2Des;
    QLabel *combo3Des;
    QPushButton *comboA;
    QPushButton *comboB;
    QPushButton *comboC;
    QLabel *combo1Price;
    QLabel *combo2Price;
    QLabel *combo3Price;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *message;
    QWidget *cart;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollBar *verticalScrollBar;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *subtotal;
    QLabel *tax;
    QLabel *total;
    QFrame *line_5;
    QPushButton *completeOrder;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *makingOrder;
    QProgressBar *progressBar;
    QLabel *progress;
    QLabel *estTime;
    QPushButton *orderReceived;
    QLabel *hourLimit;
    QLabel *timer;
    QLabel *timeUnit;
    QLabel *timeRemain;
    QPushButton *end;
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
        label_4->setGeometry(QRect(230, 50, 191, 16));
        label_4->setAlignment(Qt::AlignCenter);
        fries = new QLabel(menu);
        fries->setObjectName(QString::fromUtf8("fries"));
        fries->setGeometry(QRect(440, 190, 61, 41));
        chips = new QLabel(menu);
        chips->setObjectName(QString::fromUtf8("chips"));
        chips->setGeometry(QRect(440, 310, 61, 41));
        label_5 = new QLabel(menu);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(440, 10, 191, 16));
        label_5->setAlignment(Qt::AlignCenter);
        coke = new QLabel(menu);
        coke->setObjectName(QString::fromUtf8("coke"));
        coke->setGeometry(QRect(440, 70, 51, 41));
        water = new QLabel(menu);
        water->setObjectName(QString::fromUtf8("water"));
        water->setGeometry(QRect(580, 70, 51, 41));
        sprite = new QLabel(menu);
        sprite->setObjectName(QString::fromUtf8("sprite"));
        sprite->setGeometry(QRect(510, 70, 51, 41));
        label_6 = new QLabel(menu);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 160, 191, 16));
        label_6->setAlignment(Qt::AlignCenter);
        Burger1 = new QLabel(menu);
        Burger1->setObjectName(QString::fromUtf8("Burger1"));
        Burger1->setGeometry(QRect(20, 30, 91, 16));
        Burger1Price = new QLabel(menu);
        Burger1Price->setObjectName(QString::fromUtf8("Burger1Price"));
        Burger1Price->setGeometry(QRect(160, 30, 47, 13));
        Burger1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Burger1Des = new QLabel(menu);
        Burger1Des->setObjectName(QString::fromUtf8("Burger1Des"));
        Burger1Des->setGeometry(QRect(110, 50, 101, 41));
        Burger1Des->setWordWrap(true);
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
        Burger3->setGeometry(QRect(20, 270, 111, 16));
        Burger3Price = new QLabel(menu);
        Burger3Price->setObjectName(QString::fromUtf8("Burger3Price"));
        Burger3Price->setGeometry(QRect(160, 270, 47, 13));
        Burger3Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Burger3Des = new QLabel(menu);
        Burger3Des->setObjectName(QString::fromUtf8("Burger3Des"));
        Burger3Des->setGeometry(QRect(110, 290, 101, 41));
        Burger3Des->setWordWrap(true);
        cokeB = new QPushButton(menu);
        cokeB->setObjectName(QString::fromUtf8("cokeB"));
        cokeB->setGeometry(QRect(434, 120, 61, 23));
        spriteB = new QPushButton(menu);
        spriteB->setObjectName(QString::fromUtf8("spriteB"));
        spriteB->setGeometry(QRect(500, 120, 61, 23));
        waterB = new QPushButton(menu);
        waterB->setObjectName(QString::fromUtf8("waterB"));
        waterB->setGeometry(QRect(570, 120, 61, 23));
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
        addFries->setGeometry(QRect(440, 240, 191, 23));
        addChips = new QPushButton(menu);
        addChips->setObjectName(QString::fromUtf8("addChips"));
        addChips->setGeometry(QRect(440, 360, 191, 23));
        chips1 = new QLabel(menu);
        chips1->setObjectName(QString::fromUtf8("chips1"));
        chips1->setGeometry(QRect(440, 290, 91, 16));
        chips1Price = new QLabel(menu);
        chips1Price->setObjectName(QString::fromUtf8("chips1Price"));
        chips1Price->setGeometry(QRect(580, 290, 47, 13));
        chips1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        chips1Des = new QLabel(menu);
        chips1Des->setObjectName(QString::fromUtf8("chips1Des"));
        chips1Des->setGeometry(QRect(530, 300, 101, 51));
        chips1Des->setWordWrap(true);
        combo1 = new QLabel(menu);
        combo1->setObjectName(QString::fromUtf8("combo1"));
        combo1->setGeometry(QRect(230, 70, 71, 16));
        combo1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        combo2 = new QLabel(menu);
        combo2->setObjectName(QString::fromUtf8("combo2"));
        combo2->setGeometry(QRect(230, 190, 71, 16));
        combo2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        combo3 = new QLabel(menu);
        combo3->setObjectName(QString::fromUtf8("combo3"));
        combo3->setGeometry(QRect(230, 310, 71, 16));
        combo3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        combo1Des = new QLabel(menu);
        combo1Des->setObjectName(QString::fromUtf8("combo1Des"));
        combo1Des->setGeometry(QRect(230, 90, 191, 31));
        combo1Des->setTextFormat(Qt::AutoText);
        combo1Des->setWordWrap(true);
        combo2Des = new QLabel(menu);
        combo2Des->setObjectName(QString::fromUtf8("combo2Des"));
        combo2Des->setGeometry(QRect(230, 210, 191, 31));
        combo2Des->setTextFormat(Qt::AutoText);
        combo2Des->setWordWrap(true);
        combo3Des = new QLabel(menu);
        combo3Des->setObjectName(QString::fromUtf8("combo3Des"));
        combo3Des->setGeometry(QRect(230, 330, 191, 31));
        combo3Des->setTextFormat(Qt::AutoText);
        combo3Des->setWordWrap(true);
        comboA = new QPushButton(menu);
        comboA->setObjectName(QString::fromUtf8("comboA"));
        comboA->setGeometry(QRect(230, 120, 191, 23));
        comboB = new QPushButton(menu);
        comboB->setObjectName(QString::fromUtf8("comboB"));
        comboB->setGeometry(QRect(230, 240, 191, 23));
        comboC = new QPushButton(menu);
        comboC->setObjectName(QString::fromUtf8("comboC"));
        comboC->setGeometry(QRect(230, 360, 191, 23));
        combo1Price = new QLabel(menu);
        combo1Price->setObjectName(QString::fromUtf8("combo1Price"));
        combo1Price->setGeometry(QRect(370, 70, 47, 13));
        combo1Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        combo2Price = new QLabel(menu);
        combo2Price->setObjectName(QString::fromUtf8("combo2Price"));
        combo2Price->setGeometry(QRect(370, 190, 47, 16));
        combo2Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        combo3Price = new QLabel(menu);
        combo3Price->setObjectName(QString::fromUtf8("combo3Price"));
        combo3Price->setGeometry(QRect(370, 310, 47, 13));
        combo3Price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(menu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(212, 10, 21, 371));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(menu);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(420, 10, 21, 371));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(menu);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(440, 150, 201, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(menu);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(230, 40, 191, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        message = new QLabel(menu);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(230, 20, 191, 16));
        message->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(menu, QString());
        cart = new QWidget();
        cart->setObjectName(QString::fromUtf8("cart"));
        verticalLayoutWidget = new QWidget(cart);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 60, 251, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalScrollBar = new QScrollBar(verticalLayoutWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setLayoutDirection(Qt::LeftToRight);
        verticalScrollBar->setSingleStep(1);
        verticalScrollBar->setSliderPosition(0);
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalScrollBar->setInvertedAppearance(false);
        verticalScrollBar->setInvertedControls(true);

        verticalLayout->addWidget(verticalScrollBar);

        label_2 = new QLabel(cart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 20, 251, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(cart);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 280, 51, 16));
        label_8 = new QLabel(cart);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 300, 51, 16));
        label_9 = new QLabel(cart);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 320, 51, 16));
        subtotal = new QLabel(cart);
        subtotal->setObjectName(QString::fromUtf8("subtotal"));
        subtotal->setGeometry(QRect(240, 280, 81, 16));
        subtotal->setLayoutDirection(Qt::LeftToRight);
        subtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tax = new QLabel(cart);
        tax->setObjectName(QString::fromUtf8("tax"));
        tax->setGeometry(QRect(240, 300, 81, 16));
        tax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        total = new QLabel(cart);
        total->setObjectName(QString::fromUtf8("total"));
        total->setGeometry(QRect(240, 320, 81, 16));
        total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_5 = new QFrame(cart);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(60, 270, 271, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        completeOrder = new QPushButton(cart);
        completeOrder->setObjectName(QString::fromUtf8("completeOrder"));
        completeOrder->setGeometry(QRect(70, 350, 251, 23));
        line_6 = new QFrame(cart);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(60, 330, 271, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(cart);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(350, 20, 16, 351));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        makingOrder = new QLabel(cart);
        makingOrder->setObjectName(QString::fromUtf8("makingOrder"));
        makingOrder->setGeometry(QRect(380, 20, 251, 31));
        makingOrder->setLayoutDirection(Qt::LeftToRight);
        makingOrder->setFrameShape(QFrame::Box);
        makingOrder->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(cart);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(380, 80, 251, 23));
        progressBar->setValue(24);
        progress = new QLabel(cart);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setGeometry(QRect(380, 60, 211, 16));
        estTime = new QLabel(cart);
        estTime->setObjectName(QString::fromUtf8("estTime"));
        estTime->setGeometry(QRect(380, 110, 221, 16));
        orderReceived = new QPushButton(cart);
        orderReceived->setObjectName(QString::fromUtf8("orderReceived"));
        orderReceived->setGeometry(QRect(380, 130, 251, 23));
        hourLimit = new QLabel(cart);
        hourLimit->setObjectName(QString::fromUtf8("hourLimit"));
        hourLimit->setGeometry(QRect(370, 220, 271, 20));
        hourLimit->setAlignment(Qt::AlignCenter);
        timer = new QLabel(cart);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(380, 270, 251, 51));
        timer->setFrameShape(QFrame::Box);
        timer->setLineWidth(5);
        timer->setMidLineWidth(0);
        timer->setAlignment(Qt::AlignCenter);
        timeUnit = new QLabel(cart);
        timeUnit->setObjectName(QString::fromUtf8("timeUnit"));
        timeUnit->setGeometry(QRect(386, 320, 241, 16));
        timeUnit->setAlignment(Qt::AlignCenter);
        timeRemain = new QLabel(cart);
        timeRemain->setObjectName(QString::fromUtf8("timeRemain"));
        timeRemain->setGeometry(QRect(376, 250, 251, 20));
        timeRemain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        end = new QPushButton(cart);
        end->setObjectName(QString::fromUtf8("end"));
        end->setGeometry(QRect(380, 350, 251, 23));
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
        label_3->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">BURGERS</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">COMBOS</span></p></body></html>", nullptr));
        fries->setText(QCoreApplication::translate("mainScreen", "p4", nullptr));
        chips->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        label_5->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">DRINKS</span></p></body></html>", nullptr));
        coke->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        water->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        sprite->setText(QCoreApplication::translate("mainScreen", "p5", nullptr));
        label_6->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">SIDES</span></p></body></html>", nullptr));
        Burger1->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger1Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        addBurger1->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        Burger2->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger2Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        addBurger2->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        addBurger3->setText(QCoreApplication::translate("mainScreen", "Select", nullptr));
        Burger3->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        Burger3Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        Burger3Des->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p>asdfasf s dfasd fas d sad fasdf asd sdf as</p></body></html>", nullptr));
        cokeB->setText(QCoreApplication::translate("mainScreen", "Coke", nullptr));
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
        combo1->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        combo2->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        combo3->setText(QCoreApplication::translate("mainScreen", "NAME", nullptr));
        combo1Des->setText(QCoreApplication::translate("mainScreen", "TextLabel", nullptr));
        combo2Des->setText(QCoreApplication::translate("mainScreen", "TextLabel", nullptr));
        combo3Des->setText(QCoreApplication::translate("mainScreen", "TextLabel", nullptr));
        comboA->setText(QCoreApplication::translate("mainScreen", "COMBO A", nullptr));
        comboB->setText(QCoreApplication::translate("mainScreen", "COMBO B", nullptr));
        comboC->setText(QCoreApplication::translate("mainScreen", "COMBO C", nullptr));
        combo1Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        combo2Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        combo3Price->setText(QCoreApplication::translate("mainScreen", "$", nullptr));
        message->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(menu), QCoreApplication::translate("mainScreen", "MENU", nullptr));
        label_2->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">YOUR ORDER</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("mainScreen", "SUBTOTAL", nullptr));
        label_8->setText(QCoreApplication::translate("mainScreen", "TAX", nullptr));
        label_9->setText(QCoreApplication::translate("mainScreen", "TOTAL", nullptr));
        subtotal->setText(QCoreApplication::translate("mainScreen", "0.00", nullptr));
        tax->setText(QCoreApplication::translate("mainScreen", "0.00", nullptr));
        total->setText(QCoreApplication::translate("mainScreen", "0.00", nullptr));
        completeOrder->setText(QCoreApplication::translate("mainScreen", "COMPLETE ORDER", nullptr));
        makingOrder->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">MAKING YOUR ORDER NOW</span></p></body></html>", nullptr));
        progress->setText(QCoreApplication::translate("mainScreen", "<html><head/><body><p><span style=\" text-decoration: underline;\">IN PROGRESS</span></p></body></html>", nullptr));
        estTime->setText(QCoreApplication::translate("mainScreen", "ESTIMATED TIME: ~10 mins", nullptr));
        orderReceived->setText(QCoreApplication::translate("mainScreen", "I RECEIVED MY ORDER", nullptr));
        hourLimit->setText(QCoreApplication::translate("mainScreen", "YOU HAVE A 2 HOUR LIMIT TO EAT AT SUPERSONIC", nullptr));
        timer->setText(QCoreApplication::translate("mainScreen", "hr:min", nullptr));
        timeUnit->setText(QCoreApplication::translate("mainScreen", "HOUR:MINUTE", nullptr));
        timeRemain->setText(QCoreApplication::translate("mainScreen", "TIME REMAINING:", nullptr));
        end->setText(QCoreApplication::translate("mainScreen", "I HAVE LEFT SUPERSONIC", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cart), QCoreApplication::translate("mainScreen", "CART", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
