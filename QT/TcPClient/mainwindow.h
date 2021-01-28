#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QObject>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void connected();
  void connected2();
  void disconnect();
  void disconnect2();
  void readyRead();
  void readyRead2();
  //void readData();
  void displayError(QAbstractSocket::SocketError socketError);
  //void newConnection();

private slots:
  void on_Connect_clicked();
  void on_Send_clicked();

private:
  Ui::MainWindow *ui;
  QTcpSocket *tcpSocket, *tcpSocket2;
  QString IP[2];
  quint16 Port, Port2;
};

#endif // MAINWINDOW_H
