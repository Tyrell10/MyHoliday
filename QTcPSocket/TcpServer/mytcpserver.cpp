#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
  server = new QTcpServer(this);

  connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

  if(!server->listen(QHostAddress::Any, 9999)){
    qDebug() << "Server couldn't Start, " << server->errorString();
  }
  else {
    qDebug() << "Server Start";
  }
}

void MyTcpServer::newConnection(){
  socket = server->nextPendingConnection();

  socket->write("Hello Client \r\n");
  socket->flush();

  socket->waitForBytesWritten(3000);

  socket->close();
}
