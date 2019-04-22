#ifndef TASK_H
#define TASK_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QInputDialog>

namespace Ui {
class Task;
}

class Task : public QMainWindow
{
  Q_OBJECT

public:
  explicit Task(QWidget *parent = 0);
  ~Task();

public slots:
  void addTask();
  void removed(Task* task);

private:
  Ui::Task *ui;
  QVector<Task *> mTasks;
};

#endif // TASK_H
