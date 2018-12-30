#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void Socket();

private slots:
    void on_TmbKirim2_clicked();
    void on_Connect_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpsocket;
    QHostAddress IP;
    quint16 Port;

};

#endif // MAINWINDOW_H
