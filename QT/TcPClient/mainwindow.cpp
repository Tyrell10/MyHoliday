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
  ui->Port->setText("12345");

  connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
  connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
  connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
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

void MainWindow::readyRead(){
  if(tcpSocket->bytesAvailable())
    ui->KotakPesan->append("Server : " + tcpSocket->readAll());
}

void MainWindow::on_Connect_clicked(){
  IP = ui->IP->text();
  Port = ui->Port->text().toInt();

  if(ui->Connect->text()=="Connect" && tcpSocket->state()==QTcpSocket::UnconnectedState){
    tcpSocket->connectToHost(IP, Port);

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
    ui->Connect->setText("Connect");
    tcpSocket->disconnected();
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
