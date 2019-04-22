#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Task),
  mTasks()
{
  ui->setupUi(this);
  connect(ui->addTaskButton, &QPushButton::clicked, this, &Task::addTask);
  connect(ui->removeButton, &QPushButton::clicked, [this]{
    emit removed(this);
  });
}

Task::~Task()
{
  delete ui;
}

void Task::addTask(){
  // add new task
  /*qDebug() << "Adding new task";
  Task* task = new Task("untitled task");
  mTasks.append(task);
  ui->tasksLayout->addWidget(task);*/

  // add new task with QDialog
  bool ok;
  QString name = QInputDialog::getText(this, tr("Add task"), tr("Task name"), QLineEdit::Normal, tr("untitle task"), &ok);

  if(ok && !name.isEmpty()){
    qDebug() << "Adding new task";
    Task* task = new Task(this);
    connect(task, &Task::removed, this, &Task::removed);
    mTasks.append(task);
    ui->tasksLayout->addWidget(task);
  }
}

void Task::removed(Task* task){
  mTasks.removeOne(task);
  ui->tasksLayout->removeWidget(task);
  task->setParent(0);
  delete task;
}
