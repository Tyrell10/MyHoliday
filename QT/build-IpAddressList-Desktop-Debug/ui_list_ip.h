/********************************************************************************
** Form generated from reading UI file 'list_ip.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_IP_H
#define UI_LIST_IP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_List_IP
{
public:
    QWidget *centralWidget;
    QComboBox *ListIP;
    QLabel *IP_label;
    QLineEdit *IP;
    QLabel *Port_label;
    QLineEdit *Port;
    QPushButton *Save;
    QComboBox *ListPort;
    QSpinBox *tx;
    QSpinBox *rx;
    QLabel *lable;
    QLabel *label_2;
    QPlainTextEdit *view_tx;
    QPlainTextEdit *view_rx;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *List_IP)
    {
        if (List_IP->objectName().isEmpty())
            List_IP->setObjectName(QStringLiteral("List_IP"));
        List_IP->resize(400, 300);
        centralWidget = new QWidget(List_IP);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ListIP = new QComboBox(centralWidget);
        ListIP->setObjectName(QStringLiteral("ListIP"));
        ListIP->setGeometry(QRect(170, 30, 101, 22));
        IP_label = new QLabel(centralWidget);
        IP_label->setObjectName(QStringLiteral("IP_label"));
        IP_label->setGeometry(QRect(40, 30, 31, 16));
        IP = new QLineEdit(centralWidget);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(60, 30, 81, 22));
        Port_label = new QLabel(centralWidget);
        Port_label->setObjectName(QStringLiteral("Port_label"));
        Port_label->setGeometry(QRect(40, 60, 41, 16));
        Port = new QLineEdit(centralWidget);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setGeometry(QRect(90, 60, 51, 22));
        Save = new QPushButton(centralWidget);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setGeometry(QRect(300, 30, 51, 22));
        ListPort = new QComboBox(centralWidget);
        ListPort->setObjectName(QStringLiteral("ListPort"));
        ListPort->setGeometry(QRect(170, 60, 61, 22));
        tx = new QSpinBox(centralWidget);
        tx->setObjectName(QStringLiteral("tx"));
        tx->setGeometry(QRect(70, 100, 47, 23));
        rx = new QSpinBox(centralWidget);
        rx->setObjectName(QStringLiteral("rx"));
        rx->setGeometry(QRect(70, 130, 47, 23));
        lable = new QLabel(centralWidget);
        lable->setObjectName(QStringLiteral("lable"));
        lable->setGeometry(QRect(40, 100, 21, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 21, 16));
        view_tx = new QPlainTextEdit(centralWidget);
        view_tx->setObjectName(QStringLiteral("view_tx"));
        view_tx->setGeometry(QRect(170, 100, 101, 21));
        view_rx = new QPlainTextEdit(centralWidget);
        view_rx->setObjectName(QStringLiteral("view_rx"));
        view_rx->setGeometry(QRect(170, 130, 101, 21));
        List_IP->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(List_IP);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        List_IP->setMenuBar(menuBar);
        mainToolBar = new QToolBar(List_IP);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        List_IP->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(List_IP);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        List_IP->setStatusBar(statusBar);

        retranslateUi(List_IP);

        QMetaObject::connectSlotsByName(List_IP);
    } // setupUi

    void retranslateUi(QMainWindow *List_IP)
    {
        List_IP->setWindowTitle(QApplication::translate("List_IP", "List_IP", Q_NULLPTR));
        IP_label->setText(QApplication::translate("List_IP", "IP :", Q_NULLPTR));
        Port_label->setText(QApplication::translate("List_IP", "Port  :", Q_NULLPTR));
        Save->setText(QApplication::translate("List_IP", "Save", Q_NULLPTR));
        lable->setText(QApplication::translate("List_IP", "tx :", Q_NULLPTR));
        label_2->setText(QApplication::translate("List_IP", "rx :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class List_IP: public Ui_List_IP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_IP_H
