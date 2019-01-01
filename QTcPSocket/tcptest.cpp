#include "tcptest.h"

/*TcpTest::TcpTest(QObject *parent) : QObject(parent)
{
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("Google.com",80);
}

void TcpTest::Connect(){
    // Connected
    if(tcpSocket->waitForConnected(3000)){
        qDebug() << "Connected!";

        // send
        tcpSocket->write("Hello Server\r\n\r\n\r\n");

        tcpSocket->waitForBytesWritten(1000);
        tcpSocket->waitForReadyRead(3000); //response time

        // Got message
        qDebug() << "Reading: " << tcpSocket->bytesAvailable();

        qDebug() << tcpSocket->readAll();

        // Closed
        tcpSocket->close();
    }
    else{
        qDebug() << "Not Connected!";
    }
}*/


TcpTest::TcpTest(QObject *parent) : QObject(parent){
  tcpSocket = new QTcpSocket(this);

  connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
  connect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
  connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void TcpTest::Connect(){
  qDebug() << "Connecting...";
  tcpSocket->connectToHost("Google.com",80);

  if(!tcpSocket->waitForConnected(5000)){
      qDebug() << "Error : " << tcpSocket->errorString();
  }
}

void TcpTest::connected(){
  qDebug() << "Connected.";
  tcpSocket->write("Head / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void TcpTest::disconnected(){
  qDebug() << "Disconnected";
  tcpSocket->close();
}

void TcpTest::bytesWritten(qint64 bytes){
  qDebug() << bytes << " bytes written..";
}

void TcpTest::readyRead(){
  qDebug() << "Reading...";
  qDebug() << tcpSocket->readAll();
}
