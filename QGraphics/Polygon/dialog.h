#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private:
  Ui::Dialog *ui;

protected:
  void paintEvent(QPaintEvent *event);
};

#endif // DIALOG_H
