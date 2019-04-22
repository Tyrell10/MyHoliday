#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>

class MyThread : public QThread
{
  Q_OBJECT
public:
  explicit MyThread(QObject *parent = 0);
  void run();
  bool Stop = false;

public slots:

signals:
  void NumberChanged(int);

private:

};

#endif // MYTHREAD_H
