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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QWidget *cart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainScreen)
    {
        if (mainScreen->objectName().isEmpty())
            mainScreen->setObjectName(QString::fromUtf8("mainScreen"));
        mainScreen->resize(658, 436);
        centralwidget = new QWidget(mainScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 661, 391));
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
        tabWidget->addTab(menu, QString());
        cart = new QWidget();
        cart->setObjectName(QString::fromUtf8("cart"));
        tabWidget->addTab(cart, QString());
        mainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 658, 21));
        mainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(mainScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainScreen->setStatusBar(statusbar);

        retranslateUi(mainScreen);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *mainScreen)
    {
        mainScreen->setWindowTitle(QCoreApplication::translate("mainScreen", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ads), QCoreApplication::translate("mainScreen", "SPECIALS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(qrCode), QCoreApplication::translate("mainScreen", "QR REWARDS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(update), QCoreApplication::translate("mainScreen", "UPDATES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(oderHist), QCoreApplication::translate("mainScreen", "ORDER HISTORY", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(menu), QCoreApplication::translate("mainScreen", "MENU", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cart), QCoreApplication::translate("mainScreen", "CART", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
