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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *choose;
    QComboBox *fukuroList;
    QListWidget *strategyList;
    QLabel *Fukuro;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(383, 304);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        choose = new QPushButton(centralWidget);
        choose->setObjectName(QStringLiteral("choose"));
        choose->setGeometry(QRect(260, 240, 111, 22));
        QFont font1;
        font1.setPointSize(9);
        choose->setFont(font1);
        fukuroList = new QComboBox(centralWidget);
        fukuroList->setObjectName(QStringLiteral("fukuroList"));
        fukuroList->setGeometry(QRect(260, 160, 111, 22));
        QFont font2;
        font2.setFamily(QStringLiteral("Sans Serif"));
        font2.setPointSize(10);
        fukuroList->setFont(font2);
        strategyList = new QListWidget(centralWidget);
        strategyList->setObjectName(QStringLiteral("strategyList"));
        strategyList->setGeometry(QRect(260, 190, 111, 41));
        QFont font3;
        font3.setPointSize(8);
        strategyList->setFont(font3);
        strategyList->setLayoutDirection(Qt::LeftToRight);
        strategyList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        strategyList->setLayoutMode(QListView::SinglePass);
        Fukuro = new QLabel(centralWidget);
        Fukuro->setObjectName(QStringLiteral("Fukuro"));
        Fukuro->setGeometry(QRect(260, 0, 111, 31));
        QFont font4;
        font4.setPointSize(16);
        Fukuro->setFont(font4);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 221, 251));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 383, 24));
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
        choose->setText(QApplication::translate("MainWindow", "Choose", Q_NULLPTR));
        Fukuro->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">FUKURO 1</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
