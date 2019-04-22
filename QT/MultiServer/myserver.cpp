#include "myserver.h"
#include <QDebug>
#include "mythread.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}

void MyServer::StartServer(){
  if(!this->listen(QHostAddress::LocalHost,1234)){
    qDebug() << "Couldn't Start Server";
  }
  else {
    qDebug() << "Listening...";
  }
}

void MyServer::incomingConnection(int socketDescriptor){
  qDebug() << socketDescriptor << " Connecting...";
  MyThread *thread = new MyThread(socketDescriptor, this);
  connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

  thread->start();
}
