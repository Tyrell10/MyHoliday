#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);
  udpSocket = new QUdpSocket(this); // create a new QUdpSocket

  connect(udpSocket, SIGNAL(readyRead()), this, SLOT(Socket()));

  ui->KotakPesan->setReadOnly(true);
  ui->KotakPesan->setPlainText("Connecting...");

  // Add default IP address
  ui->IP->setText("127.0.0.1");

  // Add Port Number
  QStringList Port_List;
  Port_List.append("1234");
  Port_List.append("1233");
  Port_List.append("1232");
  Port_List.append("1231");

  ui->Port->addItems(Port_List);

  //Manual Signal to Slot
  /*QObject::connect(ui->Port, &QComboBox::currentTextChanged, [&]{
    if(ui->Port->currentText()=="1234")
      Port = 1234;
    else if(ui->Port->currentText()=="1233")
      Port = 1233;
    else if(ui->Port->currentText()=="1232")
      Port = 1232;
    else if(ui->Port->currentText()=="1231")
      Port = 1231;
  });
  */

  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
}

MainWindow::~MainWindow(){
  delete ui;
  if(udpSocket->state() == QUdpSocket::BoundState)
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
  //Port = ui->Port->text().toInt();

  //udpSocket->bind(IP,Port);
  udpSocket->bind(QHostAddress(QHostAddress::AnyIPv4), Port, QAbstractSocket::ReuseAddressHint|QAbstractSocket::ShareAddress);
  udpSocket->joinMulticastGroup(IP);

  ui->KotakPesan->setPlainText("Connected");

  ui->KotakPesan->append("IP : " + QHostAddress(IP).toString());
  ui->KotakPesan->append("Port :" + QString("%1").arg(Port));
}

void MainWindow::on_Send_clicked(){
  udpSocket->writeDatagram(ui->Pesan->text().toLatin1(), IP, Port);
  ui->Pesan->clear();
}

void MainWindow::on_Port_currentTextChanged(){
  if(ui->Port->currentText()=="1234")
    Port = 1234;
  else if(ui->Port->currentText()=="1233")
    Port = 1233;
  else if(ui->Port->currentText()=="1232")
    Port = 1232;
  else if(ui->Port->currentText()=="1231")
    Port = 1231;
}
