#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  server = new QTcpServer(this);

  connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));


  if(!server->listen(QHostAddress::LocalHost, 1234)){
    ui->TextServer->setPlainText("Server Not Connected");
    ui->TextServer->append("Error : " + server->errorString());
  }
  else {
    ui->TextServer->setPlainText("Connecting...");
  }

}

MainWindow::~MainWindow()
{
  delete ui;
  socket->close();
  server->close();
}

void MainWindow::newConnection(){
  while(server->hasPendingConnections()){
      socket = server->nextPendingConnection();
      ui->TextServer->setPlainText("Connected");

      socket->write("Hello Client \r\n");
      socket->flush();

      socket->waitForBytesWritten(3000);
      socket->waitForReadyRead(5000);
  }
}

void MainWindow::on_Send_clicked()
{
  socket->write(ui->Pesan->text().toLatin1()+"\n");
  socket->flush();
  ui->Pesan->clear();
}
