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
    QLineEdit *IP2;
    QLineEdit *Port2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Pesan2;
    QPushButton *Connect;
    QPushButton *Send;
    QTextEdit *KotakPesan2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(367, 283);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IP2 = new QLineEdit(centralWidget);
        IP2->setObjectName(QStringLiteral("IP2"));
        IP2->setGeometry(QRect(70, 20, 101, 22));
        Port2 = new QLineEdit(centralWidget);
        Port2->setObjectName(QStringLiteral("Port2"));
        Port2->setGeometry(QRect(210, 20, 41, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 19, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 20, 31, 16));
        Pesan2 = new QLineEdit(centralWidget);
        Pesan2->setObjectName(QStringLiteral("Pesan2"));
        Pesan2->setGeometry(QRect(50, 60, 201, 22));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(260, 20, 61, 22));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(260, 60, 61, 22));
        KotakPesan2 = new QTextEdit(centralWidget);
        KotakPesan2->setObjectName(QStringLiteral("KotakPesan2"));
        KotakPesan2->setGeometry(QRect(50, 90, 271, 151));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 367, 19));
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
        label->setText(QApplication::translate("MainWindow", "IP :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port:", Q_NULLPTR));
        Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        Send->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
