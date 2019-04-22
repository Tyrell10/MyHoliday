#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);

  scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);

  QBrush grayBrush(Qt::gray);
  QBrush blueBrush(Qt::blue);
  QPen myPen(Qt::NoPen);

  myPen.setWidth(6);

  ellipse = scene->addEllipse(10,10,20,20,myPen,grayBrush);
  rec = scene->addRect(-100,-100,75,75,myPen,blueBrush);
  ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}

Dialog::~Dialog()
{
  delete ui;
}
