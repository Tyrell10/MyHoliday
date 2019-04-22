#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::setThread(QThread &cThread){
  connect(&cThread, SIGNAL(started()), this, SLOT(doThread()));
}

void MyObject::doThread(){
  for(int i=0; i<20; i++){
    qDebug() << i;
  }
  qDebug() << "Done!";
}
