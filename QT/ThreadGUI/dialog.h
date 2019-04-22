#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mythread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  MyThread *thread;
  ~Dialog();

public slots:
  void onNumberChanged(int);

private slots:
  void on_btn_start_clicked();
  void on_btn_stop_clicked();

private:
  Ui::Dialog *ui;

};

#endif // DIALOG_H
