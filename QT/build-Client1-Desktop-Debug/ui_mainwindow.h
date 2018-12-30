/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *Pesan;
    QPushButton *TmbKirim;
    QTextEdit *KotakPesan;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *IP;
    QLineEdit *Port;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Connect;
    QMenuBar *menuBar;
    QMenu *menuChat_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Pesan = new QLineEdit(centralWidget);
        Pesan->setObjectName(QStringLiteral("Pesan"));
        Pesan->setGeometry(QRect(50, 60, 231, 21));
        TmbKirim = new QPushButton(centralWidget);
        TmbKirim->setObjectName(QStringLiteral("TmbKirim"));
        TmbKirim->setGeometry(QRect(280, 50, 71, 41));
        KotakPesan = new QTextEdit(centralWidget);
        KotakPesan->setObjectName(QStringLiteral("KotakPesan"));
        KotakPesan->setGeometry(QRect(50, 110, 301, 141));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 90, 59, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 41, 16));
        IP = new QLineEdit(centralWidget);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(70, 10, 111, 21));
        Port = new QLineEdit(centralWidget);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setGeometry(QRect(220, 10, 51, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 10, 21, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 10, 31, 16));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(270, 0, 81, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuChat_1 = new QMenu(menuBar);
        menuChat_1->setObjectName(QStringLiteral("menuChat_1"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuChat_1->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        TmbKirim->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Balasan", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Pesan", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "IP :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Port :", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        menuChat_1->setTitle(QApplication::translate("MainWindow", "Chat 1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
