#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  enum {CONNECT, DISCONNECT};
  bool status;
  ~MainWindow();

public slots:
  void newConnection();
  void readData();
  void disconnect();

private slots:
  void on_Send_clicked();
  void on_Btn_Start_clicked();

private:
  Ui::MainWindow *ui;
  QTcpServer *server;
  QTcpSocket *socket;
  QHostAddress IP;
  quint16 Port;
};

#endif // MAINWINDOW_H
