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
  void disconnect();
  void readyRead();
  void displayError(QAbstractSocket::SocketError socketError);

private slots:
  void on_Connect_clicked();
  void on_Send_clicked();

private:
  Ui::MainWindow *ui;
  QTcpSocket *tcpSocket;
  QString IP;
  quint16 Port;
};

#endif // MAINWINDOW_H
