/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *tasksLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *toolbarlLayout;
    QLabel *statusLabel;
    QPushButton *removeButton;
    QPushButton *addTaskButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QStringLiteral("Task"));
        Task->resize(400, 300);
        centralWidget = new QWidget(Task);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 361, 221));
        tasksLayout = new QVBoxLayout(verticalLayoutWidget);
        tasksLayout->setSpacing(6);
        tasksLayout->setContentsMargins(11, 11, 11, 11);
        tasksLayout->setObjectName(QStringLiteral("tasksLayout"));
        tasksLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tasksLayout->addItem(verticalSpacer);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(22, 12, 361, 24));
        toolbarlLayout = new QHBoxLayout(widget);
        toolbarlLayout->setSpacing(6);
        toolbarlLayout->setContentsMargins(11, 11, 11, 11);
        toolbarlLayout->setObjectName(QStringLiteral("toolbarlLayout"));
        toolbarlLayout->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(widget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        toolbarlLayout->addWidget(statusLabel);

        removeButton = new QPushButton(widget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        toolbarlLayout->addWidget(removeButton);

        addTaskButton = new QPushButton(widget);
        addTaskButton->setObjectName(QStringLiteral("addTaskButton"));

        toolbarlLayout->addWidget(addTaskButton);

        Task->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Task);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        Task->setMenuBar(menuBar);
        statusBar = new QStatusBar(Task);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Task->setStatusBar(statusBar);

        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QMainWindow *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Task", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("Task", "Status:0 todo/ 0 done", Q_NULLPTR));
        removeButton->setText(QApplication::translate("Task", "Remove task", Q_NULLPTR));
        addTaskButton->setText(QApplication::translate("Task", "Add task", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
