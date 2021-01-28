#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  tcpSocket(new QTcpSocket(this)),
  tcpSocket2(new QTcpSocket(this)),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->KotakPesan->setReadOnly(true);
  ui->KotakPesan->setPlainText("Connecting...");

  ui->IP->setText("127.0.0.1");
  ui->Port->setText("1234");

  connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
  connect(tcpSocket2, SIGNAL(connected()), this, SLOT(connected2()));
  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
  connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
  connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(tcpSocket2, SIGNAL(readyRead()), this, SLOT(readyRead2()));
}

MainWindow::~MainWindow()
{
  delete ui;
  tcpSocket->close();
}

void MainWindow::connected(){
  ui->KotakPesan->setPlainText("Connected \n");
  connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
}

void MainWindow::connected2(){
  ui->KotakPesan->setPlainText("Connected \n");
  connect(tcpSocket2, SIGNAL(disconnected()), this, SLOT(disconnect2()));
}

void MainWindow::readyRead(){
  if(tcpSocket->bytesAvailable())
    ui->KotakPesan->append("Server1 : " + tcpSocket->readAll());
}

void MainWindow::readyRead2(){
  if(tcpSocket2->bytesAvailable())
    ui->KotakPesan->append("Server2 : " + tcpSocket2->readAll());
}

void MainWindow::on_Connect_clicked(){
  IP[0] = ui->IP->text();
  Port = ui->Port->text().toInt();
  IP[1] = "127.0.0.2";
  Port2 = 1233;

  if(ui->Connect->text()=="Connect" && tcpSocket->state()==QTcpSocket::UnconnectedState){
    tcpSocket->connectToHost(IP[0], Port);
    tcpSocket2->connectToHost(IP[1], Port2);

    if(!tcpSocket->HostLookupState){
      tcpSocket->HostNotFoundError;
    }
    else if(!tcpSocket->waitForConnected(3000)){
      ui->KotakPesan->append("Connection Failure");
      ui->KotakPesan->append(tcpSocket->errorString());
      tcpSocket->ConnectionRefusedError;
    }
    else{
      ui->Connect->setText("Disconnect");
    }
  }
  else if(ui->Connect->text()=="Disconnect" && tcpSocket->state()==QTcpSocket::ConnectedState){
    tcpSocket->disconnectFromHost();
    tcpSocket2->disconnectFromHost();
    ui->Connect->setText("Connect");
    tcpSocket->disconnected();
    tcpSocket2->disconnected();
  }
}

void MainWindow::on_Send_clicked()
{
    tcpSocket->write(ui->Pesan->text().toLatin1());
    tcpSocket->flush();

    tcpSocket2->write(ui->Pesan->text().toLatin1());
    tcpSocket2->flush();

    ui->Pesan->clear();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError){
  switch(socketError){
    case QAbstractSocket::RemoteHostClosedError:
      QMessageBox::warning(this, tr("Remote Host Closed Error"), tr("The connection was disable by server"));
      break;

    case QAbstractSocket::HostNotFoundError:
      QMessageBox::warning(this, tr("Host Not Found Error"), tr("The host was not found. Please check "
                                                          "the host name and setting."));
      break;

    case QAbstractSocket::ConnectionRefusedError:
      QMessageBox::warning(this, tr("Connection Refused Error"), tr("The connection was refused by the peer. "
                                    "Make sure the server is already running, "
                                    "and check the hostname and port "
                                    "setting are correct."));
      break;

    default:
      QMessageBox::information(this, tr("Unknown Error"), tr("The Following Error Occured: %1.").arg(tcpSocket->errorString()));
  }
}

void MainWindow::disconnect(){
  if(ui->Connect->text() == "Disconnect"){
    ui->Connect->setText("Connect");
    tcpSocket->disconnectFromHost();
    tcpSocket->RemoteHostClosedError;
  }
  tcpSocket->close();

  ui->KotakPesan->append("Disconnected");
}

void MainWindow::disconnect2(){
  if(ui->Connect->text() == "Disconnect"){
    ui->Connect->setText("Connect");
    tcpSocket2->disconnectFromHost();
    tcpSocket2->RemoteHostClosedError;
  }
  tcpSocket2->close();

  ui->KotakPesan->append("Disconnected");
}
