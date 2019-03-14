#include "dialog.h"
#include "ui_dialog.h"
#include <QGraphicsItem>

Dialog::Dialog(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::paintEvent(QPaintEvent *event){
  QPainter painter(this);

  QPen linePen(Qt::red);
  linePen.setWidth(5);
  linePen.setJoinStyle(Qt::RoundJoin);
  //linePen.setJoinStyle(Qt::MiterJoin);
  QPolygon poly;
  QRect rec(60,50,275,200);

  //create polygon
  poly << QPoint(150, 100);
  poly << QPoint(150, 200);
  poly << QPoint(275,150);

  //make a brush
  QBrush brush(Qt::white, Qt::SolidPattern);
  QBrush brush1(Qt::red, Qt::SolidPattern);

  //make path
  QPainterPath path;
  path.addPolygon(poly);

  //draw polygon
  //painter.setPen(linePen);
  //painter.drawRect(rec);
  //painter.fillRect(rec, brush1);
  //painter.fillPath(path,brush);
  //painter.drawPolygon(poly);
  //painter.drawText(255, 275, "Follow, Like &");
  //painter.drawText(265,290,"SUBSCRIBE");

  auto m = painter.matrix();
  painter.setMatrix(m);
  painter.drawEllipse(rec);

}
