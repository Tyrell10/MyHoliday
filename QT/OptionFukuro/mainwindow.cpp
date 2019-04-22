#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  scene(new QGraphicsScene(this)),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //QString pixmap_map(":/lines.png");
  //lines = QPixmap(pixmap_map).scaledToHeight(50);

  scene->setBackgroundBrush(Qt::green);
  ui->graphicsView->setScene(scene);
  //ui->graphicsView->scale(0.55,0.55);
  //ui->graphicsView->setFixedSize(45,70);

  QStringList fukuroList;

  fukuroList.append("Fukuro 1");
  fukuroList.append("Fukuro 2");
  fukuroList.append("Fukuro 3");

  ui->fukuroList->addItems(fukuroList);

  //initialize
  QStringList strategyList1;
  ui->fukuroList->setCurrentIndex(0);

  strategyList1.append("strategy-Fukuro-1");
  strategyList1.append("strategy-Fukuro-1");
  strategyList1.append("strategy-Fukuro-1");

  ui->strategyList->addItems(strategyList1);

  QObject::connect(ui->fukuroList,&QComboBox::currentTextChanged,[&](){
    if(ui->fukuroList->currentText()=="Fukuro 1"){
      ui->Fukuro->setText("FUKURO 1");
      QStringList strategyList1;
      ui->strategyList->clear();

      strategyList1.append("strategy-Fukuro-1");
      strategyList1.append("strategy-Fukuro-1");
      strategyList1.append("strategy-Fukuro-1");

      ui->strategyList->addItems(strategyList1);
    }
    else if(ui->fukuroList->currentText()=="Fukuro 2"){
      ui->Fukuro->setText("FUKURO 2");
      QStringList strategyList2;
      ui->strategyList->clear();

      strategyList2.append("input-strategy");
      strategyList2.append("input-strategy");
      strategyList2.append("input-strategy");

      ui->strategyList->addItems(strategyList2);
    }
    else {
      ui->Fukuro->setText("FUKURO 3");
      QStringList strategyList3;
      ui->strategyList->clear();

      strategyList3.append("input-strategy");
      strategyList3.append("input-strategy");
      strategyList3.append("input-strategy");

      ui->strategyList->addItems(strategyList3);
    }
  });
}

MainWindow::~MainWindow()
{
  delete ui;
}

/*void MainWindow::paintEvent(QPaintEvent *event){
  QPainter painter(this);

  painter.setBrush(QColor(0,182,0));
  painter.setPen(Qt::white);
  painter.drawRect(50,50,100,100);
  painter.drawPixmap(50,50,lines);
}*/
