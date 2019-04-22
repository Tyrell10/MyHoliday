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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *KotakPesan;
    QLineEdit *IP;
    QLineEdit *Port;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Connect;
    QLineEdit *Pesan;
    QPushButton *Send;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        KotakPesan = new QTextEdit(centralWidget);
        KotakPesan->setObjectName(QStringLiteral("KotakPesan"));
        KotakPesan->setGeometry(QRect(50, 60, 291, 161));
        IP = new QLineEdit(centralWidget);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(70, 30, 111, 22));
        Port = new QLineEdit(centralWidget);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setGeometry(QRect(220, 30, 51, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 30, 33, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 30, 19, 16));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(280, 30, 61, 22));
        Pesan = new QLineEdit(centralWidget);
        Pesan->setObjectName(QStringLiteral("Pesan"));
        Pesan->setGeometry(QRect(50, 230, 231, 22));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(290, 230, 51, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Port:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "IP :", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        Send->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
