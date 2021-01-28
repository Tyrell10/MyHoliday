#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  server = new QTcpServer(this);

  ui->IP->setText("127.0.0.1");
  ui->Port->setText("1234");

  status = DISCONNECT;
  ui->KotakPesan->setReadOnly(true);

  connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
  connect(ui->Pesan, SIGNAL(returnPressed()), this, SLOT(on_Send_clicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
  socket->close();
  server->close();
}

void MainWindow::newConnection(){
  while(server->hasPendingConnections()){
      socket = server->nextPendingConnection(); //to accept the pending connection as a connected QTcpSocket

      ui->KotakPesan->setPlainText("Connected \n");
      connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
      connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));

      socket->write("Hello Client");
      socket->flush();

      //socket->waitForBytesWritten(3000);  //suggest for non-GUI app
      //socket->waitForReadyRead(5000);  //suggest for non-GUI app
  }
}

void MainWindow::on_Send_clicked(){
  socket->write(ui->Pesan->text().toLatin1());
  socket->flush();

  ui->Pesan->clear();
}

void MainWindow::readData(){
  QByteArray Data = socket->readAll();
  ui->KotakPesan->append("Client : " + socket->readAll());
}

void MainWindow::on_Btn_Start_clicked(){
  IP = ui->IP->text();
  Port = ui->Port->text().toInt();

  if(ui->Btn_Start->text()== "Start" && status == DISCONNECT){
    if(!server->listen(IP, Port)){
       ui->KotakPesan->setPlainText("Server Not Connected");
       ui->KotakPesan->append("Error : " + server->errorString());
    }
    else {
      ui->KotakPesan->setPlainText("Connecting...");
      ui->Btn_Start->setText("Stop");

      status = CONNECT;
    }
  }
  else if(ui->Btn_Start->text()== "Stop" && status == CONNECT){
    socket->disconnectFromHost();
    ui->Btn_Start->setText("Start");

    status = DISCONNECT;
  }
}

void MainWindow::disconnect(){
  status = DISCONNECT;
  server->close();
  if(ui->Btn_Start->text() == "Stop")
    ui->Btn_Start->setText("Start");

  ui->KotakPesan->append("Disconnected");
}
