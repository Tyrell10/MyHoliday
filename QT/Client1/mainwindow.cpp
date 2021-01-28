#include "mainwindow.h"
#include "ui_mainwindow.h"

//define localdir QHostAddress::LocalHost //define QHostAddress to IPv4 localhost address
//#define localPort 1234

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpsocket = new QUdpSocket(this); //created UdpSocket Object

    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(Socket())); //connect Socket to udpsocket

    ui->KotakPesan->setReadOnly(true);
    ui->KotakPesan->setPlainText("Connection...");

    connect(ui->Pesan,SIGNAL(returnPressed()),this,SLOT(on_TmbKirim_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    udpsocket->close();
}

void MainWindow::Socket(){
    while(udpsocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(int(udpsocket->pendingDatagramSize()));
        QHostAddress Sender;
        quint16 SenderPort;
        udpsocket->readDatagram(datagram.data(),datagram.size(),
                                &Sender,&SenderPort);
        ui->KotakPesan->append("Chat 2: "+QString(datagram) + " <ip->"+Sender.toString() +", port->" +     QString("%1").arg(SenderPort) + ">");
    }
}

void MainWindow::on_Connect_clicked()
{
    IP = ui->IP->text();
    Port = ui->Port->text().toInt();

    //ui->KotakPesan->clear();

    udpsocket->bind(IP,Port);
    ui->KotakPesan->append("IP: " +QHostAddress(IP).toString());
    ui->KotakPesan->append("Port: " +QString("%1").arg(Port));
}

void MainWindow::on_TmbKirim_clicked()
{
    udpsocket->writeDatagram(ui->Pesan->text().toLatin1(),IP,Port);
    ui->Pesan->clear();
}
