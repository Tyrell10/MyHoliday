#include "optionfukuro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  OptionFukuro w;
  w.show();

  return a.exec();
}
