#ifndef TCPTEST_H
#define TCPTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class TcpTest : public QObject
{
    Q_OBJECT
public:
    explicit TcpTest(QObject *parent = nullptr);

    void Connect();
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *tcpSocket;

};

#endif // TCPTEST_H
