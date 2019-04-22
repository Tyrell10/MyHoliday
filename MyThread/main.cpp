#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  MyThread thread1;
  thread1.name = "thread1";
  thread1.start(QThread::LowestPriority);

  MyThread thread2;
  thread2.name = "thread2";
  thread2.start();

  MyThread thread3;
  thread3.name = "thread3";
  thread3.start(QThread::HighestPriority);

  return a.exec();
}
