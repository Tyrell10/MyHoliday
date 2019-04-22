#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyObject : public QObject
{
  Q_OBJECT
public:
  explicit MyObject(QObject *parent = nullptr);
  void setThread(QThread &cThread);

signals:

public slots:
  void doThread();
};

#endif // MYOBJECT_H
