#include "list_ip.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  List_IP w;
  w.show();

  return a.exec();
}
