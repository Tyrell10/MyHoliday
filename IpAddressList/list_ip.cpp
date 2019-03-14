#include "list_ip.h"
#include "ui_list_ip.h"

List_IP::List_IP(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::List_IP)
{
  ui->setupUi(this);
  QObject::connect(ui->Save, &QPushButton::clicked,[&]{
    QStringList IP_List;
    QStringList Port_List;
    tx = ui->tx->text().toInt();
    rx = ui->rx->text().toInt();

    IP = ui->IP->text();
    Port = ui->Port->text().toInt();

    IP_List.append(QHostAddress(IP).toString());
    ui->ListIP->addItems(IP_List);

    Port_List.append(QString("%1").arg(Port));
    ui->ListPort->addItems(Port_List);

    ui->view_tx->setPlainText(QString("%1").arg(tx));
    ui->view_rx->setPlainText(QString("%1").arg(rx));

    ui->IP->clear();
    ui->Port->clear();
  });

  //QObject::connect(ui->ListIP, &QComboBox::currentTextChanged, [&]{

  //});
}

List_IP::~List_IP()
{
  delete ui;
}
