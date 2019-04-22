#include "mythread.h"
#include <QtCore>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run(){
  for(int i=0; i<10; i++){
    qDebug() << this->name << " Running";
  }
}
