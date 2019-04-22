#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>

class MyServer : public QTcpServer
{
  Q_OBJECT
public:
  explicit MyServer(QObject *parent = 0);
  void StartServer();

protected:
  void incomingConnection(int socketDescriptor);

signals:

public slots:

};

#endif // MYSERVER_H
