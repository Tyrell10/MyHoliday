#ifndef LIST_IP_H
#define LIST_IP_H

#include <QMainWindow>
#include <QObject>
#include <QUdpSocket>

namespace Ui {
class List_IP;
}

class List_IP : public QMainWindow
{
  Q_OBJECT

public:
  explicit List_IP(QWidget *parent = 0);
  ~List_IP();  

private slots:

private:
  Ui::List_IP *ui;
  QHostAddress IP;
  quint16 Port, tx, rx;
};

#endif // LIST_IP_H
