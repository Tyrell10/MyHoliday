#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QObject>

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
  void Socket();

private slots:
  void on_Send_clicked();
  void on_Connect_clicked();

private:
  Ui::MainWindow *ui;
  QUdpSocket *udpSocket;
  QHostAddress IP;
  quint16 Port;
};

#endif // MAINWINDOW_H
