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
    QLineEdit *Pesan;
    QPushButton *Send;
    QTextEdit *KotakPesan;
    QLabel *Status;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *IP;
    QLineEdit *Port;
    QPushButton *Btn_Start;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Pesan = new QLineEdit(centralWidget);
        Pesan->setObjectName(QStringLiteral("Pesan"));
        Pesan->setGeometry(QRect(50, 230, 251, 22));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(310, 230, 51, 22));
        KotakPesan = new QTextEdit(centralWidget);
        KotakPesan->setObjectName(QStringLiteral("KotakPesan"));
        KotakPesan->setGeometry(QRect(50, 60, 301, 161));
        Status = new QLabel(centralWidget);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setGeometry(QRect(50, 31, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 31, 21, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 31, 33, 16));
        IP = new QLineEdit(centralWidget);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(130, 31, 71, 22));
        Port = new QLineEdit(centralWidget);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setGeometry(QRect(238, 31, 51, 22));
        Btn_Start = new QPushButton(centralWidget);
        Btn_Start->setObjectName(QStringLiteral("Btn_Start"));
        Btn_Start->setGeometry(QRect(299, 31, 51, 22));
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
        Send->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        Status->setText(QApplication::translate("MainWindow", "STATUS", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "IP :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Port :", Q_NULLPTR));
        Btn_Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
