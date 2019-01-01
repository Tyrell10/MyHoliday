#include <QCoreApplication>
#include "tcptest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpTest test;
    test.Connect();

    return a.exec();
}
