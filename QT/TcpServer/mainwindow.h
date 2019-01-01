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
  ~MainWindow();

public slots:
  void newConnection();

private slots:
  void on_Send_clicked();

private:
  Ui::MainWindow *ui;
  QTcpServer *server;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
