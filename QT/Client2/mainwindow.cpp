#include "mainwindow.h"
#include "ui_mainwindow.h"

//#define localdir QHostAddress::LocalHost
//#define localPort 1244

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpsocket = new QUdpSocket(this);

    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(Socket()));

    ui->KotakPesan2->setReadOnly(true);
    ui->KotakPesan2->setPlainText("Connection...");

    connect(ui->Pesan2,SIGNAL(returnPressed()),this,SLOT(on_TmbKirim2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    udpsocket->close();
}
void MainWindow::Socket(){
    while(udpsocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpsocket->pendingDatagramSize());

        QHostAddress sender;

        quint16 senderPort;

        udpsocket->readDatagram(datagram.data(),datagram.size(),
                                &sender, &senderPort);
        ui->KotakPesan2->append("Chat 1: "+QString(datagram) + " <ip->" + sender.toString() + ", port->" +     QString("%1").arg(senderPort) +">");
    }

}

void MainWindow::on_TmbKirim2_clicked()
{
    udpsocket->writeDatagram(ui->Pesan2->text().toLatin1(),IP,Port);
    ui->Pesan2->clear();
}

void MainWindow::on_Connect_clicked()
{
    IP = ui->IP->text();
    Port = ui->Port->text().toInt();

    //ui->KotakPesan2->clear();

    udpsocket->bind(IP,Port);
    ui->KotakPesan2->append("IP: "+ QHostAddress(IP).toString());
    ui->KotakPesan2->append("Port:" + QString("%1").arg(Port));

}
