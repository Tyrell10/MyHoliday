#include "optionfukuro.h"
#include "ui_optionfukuro.h"

OptionFukuro::OptionFukuro(QWidget *parent) :
  QMainWindow(parent),
  scene(new QGraphicsScene(this)),
  ui(new Ui::OptionFukuro)
{
  ui->setupUi(this);
  setWindowTitle("Fukuro Option");
  setFixedSize(this->size());

  QString pixmap_path  = "/home/tyrell/Documents/OptionFukuro/lines.png";
  QString pixmap_path2 = "/home/tyrell/Documents/OptionFukuro/ball.png";
  QString pixmap_path3 = "/home/tyrell/Documents/OptionFukuro/fukuro.png";
  QString pixmap_path4 = "/home/tyrell/Documents/OptionFukuro/arrow3.png";
  QString fukuro_pic   = "/home/tyrell/Documents/OptionFukuro/fukuro_logo.png";

  int w = ui->fukuro_pic->width();
  int h = ui->fukuro_pic->height();
  fukuroPic = QPixmap(fukuro_pic).scaled(w,h,Qt::KeepAspectRatio);

  scene->setBackgroundBrush(QColor(0,182,0));
  ui->Field->setScene(scene);
  ui->Field->setRenderHints(QPainter::Antialiasing |
                                    QPainter::HighQualityAntialiasing |
                                    QPainter::SmoothPixmapTransform);

  //ui->Field->scale(0.55,0.55);
  ui->Field->setFixedSize(200,290);

  lines = scene->addPixmap(QPixmap(pixmap_path).scaledToHeight(270));
  arrow1 = scene->addPixmap(QPixmap(pixmap_path4).scaledToHeight(60));
  ball = scene->addPixmap(QPixmap(pixmap_path2).scaledToHeight(7));
  fukuro = scene->addPixmap(QPixmap(pixmap_path3).scaledToHeight(15));
  //arrow2 = scene->addPixmap(QPixmap(pixmap_path4).scaledToHeight(45));

  arrow1->setRotation(-35);
  arrow1->setPos(82, 100);
  ball->setPos(86,132);
  fukuro->setPos(81,145);
  //arrow2->setRotation(-45);
  //arrow2->setPos(110, 90);

  fukuro->setFlag(QGraphicsItem::ItemIsMovable);
  //QString pixmap_map(":/lines.png");

  //lines = QPixmap(pixmap_path).scaledToHeight(270);
  //ball  = QPixmap(pixmap_path2).scaledToHeight(10);
  //fukuro = QPixmap(pixmap_path3).scaledToHeight(20);

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

OptionFukuro::~OptionFukuro()
{
  delete ui;
}

void OptionFukuro::paintEvent(QPaintEvent *event){
  //painter.setPen(Qt::transparent);
  //painter.setBrush(QColor(0,182,0));
  //painter.setPen(Qt::white);
  //painter.drawRect(25,5,200,290);
  //painter.drawPixmap(35,15,lines);
  //painter.drawPixmap(240/2, 290/2, ball);
  //painter.drawPixmap(228/2, 330/2, fukuro);
  ui->fukuro_pic->setPixmap(fukuroPic);
}
