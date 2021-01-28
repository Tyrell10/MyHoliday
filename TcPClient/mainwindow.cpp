#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  tcpSocket = new QTcpSocket(this);

  ui->KotakPesan->setReadOnly(true);
  ui->KotakPesan->setPlainText("Connecting...");

  ui->IP->setText("127.0.0.1");
  ui->Port->setText("1234");

  connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
  connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
  delete ui;
  tcpSocket->close();
}

void MainWindow::connected(){
  ui->KotakPesan->setPlainText("Connected \n");
  connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
}

void MainWindow::readyRead(){
  ui->KotakPesan->append("Server : " + tcpSocket->readAll());
}

void MainWindow::on_Connect_clicked(){
  IP = ui->IP->text();
  Port = ui->Port->text().toInt();

  if(ui->Connect->text()=="Connect"){
     tcpSocket->connectToHost(IP, Port);

    if(!tcpSocket->waitForConnected(5000)){
      ui->KotakPesan->append("Connection Failure");
      ui->KotakPesan->append(tcpSocket->errorString());
    } else{
      ui->Connect->setText("Disconnect");
    }
  } else if(ui->Connect->text()=="Disconnect"){
    tcpSocket->disconnectFromHost();
    ui->Connect->setText("Connect");
  }
}

void MainWindow::on_Send_clicked()
{
    tcpSocket->write(ui->Pesan->text().toLatin1());
    tcpSocket->flush();

    ui->Pesan->clear();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError){
  switch(socketError){
    case QAbstractSocket::RemoteHostClosedError:
      break;

    case QAbstractSocket::HostNotFoundError:
      QMessageBox::information(this, tr("Fortune Client"), tr("The connection was refused by the peer"));
      break;

    case QAbstractSocket::ConnectionRefusedError:
      QMessageBox::information(this, tr("Fortune Client"), tr("The following error occured %1").arg(tcpSocket->errorString()));
  }
}

void MainWindow::disconnect(){
  if(ui->Connect->text() == "Disconnect")
    ui->Connect->setText("Connect");

  ui->KotakPesan->append("Disconnected");
}
