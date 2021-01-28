#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->tabWidget->removeTab(1);
  ui->tabWidget->addTab(new Form, QString("form"));
/*
  QObject::connect(ui->tabWidget, &QTabWidget::currentChanged,[&]{
    if(ui->tabWidget->currentIndex()==1){
      ui->label->setText("Unicast Active");
    }
    else if(ui->tabWidget->currentIndex()==0){
      ui->label_2->setText("Multicast Active");
    }
  });
*/
  int i =0;
  switch(i){
  ui->label_2->setText("Multicast Not Active");
    case 0 :{
      ui->label_2->setText("Multicast Active");
    }
  }

}

MainWindow::~MainWindow()
{
  delete ui;
}
