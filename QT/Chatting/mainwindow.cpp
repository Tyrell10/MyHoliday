#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  udpSocket = new QUdpSocket(this); // create a new QUdpSocket

  connect(udpSocket, SIGNAL(readyRead()), this, SLOT(Socket()));

  ui->KotakPesan->setReadOnly(true);
  ui->KotakPesan->setPlainText("Connecting...");

  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
  udpSocket->leaveMulticastGroup(IP);
  udpSocket->close();
}

void MainWindow::Socket(){
  while(udpSocket->hasPendingDatagrams()){
    QByteArray datagram;
    QHostAddress sender;
    quint16 senderPort;

    datagram.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram.data(), datagram.size(),
                            &sender, &senderPort);

    ui->KotakPesan->append("Chat 2: " + QString(datagram));
  }

}

void MainWindow::on_Connect_clicked(){
  IP = ui->IP->text();
  Port = ui->Port->text().toInt();

  //udpSocket->bind(IP,Port);
  udpSocket->bind(QHostAddress(QHostAddress::AnyIPv4), Port, QAbstractSocket::ShareAddress);
  udpSocket->joinMulticastGroup(IP);

  ui->KotakPesan->setPlainText("Connected");

  ui->KotakPesan->append("IP : " + QHostAddress(IP).toString());
  ui->KotakPesan->append("Port :" + QString("%1").arg(Port));
}

void MainWindow::on_Send_clicked(){
  udpSocket->writeDatagram(ui->Pesan->text().toLatin1(), IP, Port);
  ui->Pesan->clear();
}
