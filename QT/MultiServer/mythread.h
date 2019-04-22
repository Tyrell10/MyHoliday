#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyThread : public QThread
{
  Q_OBJECT
public:
  explicit MyThread(int ID, QObject *parent = 0);
  void run();

signals:
  void error(QTcpSocket::SocketError socket);

public slots:
  void readyToRead();
  void disconnected();

private:
  QTcpSocket *socket;
  int socketDescriptor;

};

#endif // MYTHREAD_H
