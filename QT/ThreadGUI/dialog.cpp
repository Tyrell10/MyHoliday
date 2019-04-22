#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  thread(new MyThread(this)),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
  //thread = new MyThread(this);

  connect(thread, SIGNAL(NumberChanged(int)), this, SLOT(onNumberChanged(int)));

}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::onNumberChanged(int num){
  ui->Number->setText(QString::number(num));
}

void Dialog::on_btn_start_clicked()
{
  // Start Thread
  thread->start();
  thread->Stop = false;
}

void Dialog::on_btn_stop_clicked()
{
  // Stop Thread
  thread->Stop = true;
}
