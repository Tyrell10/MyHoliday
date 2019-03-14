#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::paintEvent(QPaintEvent *e){
  QPainter painter(this);
  QPen PointPen(Qt::black);
  QPen LinePen(Qt::red);
  QPoint p1;
  p1.setX(125);
  p1.setY(50);
  QPoint p2;
  p2.setX(125);
  p2.setY(100);
  QPoint p3;
  p3.setX(100);
  p3.setY(75);
  QPoint p4;
  p4.setX(150);
  p4.setY(75);

  PointPen.setWidth(6);
  LinePen.setWidth(2);

  //Segitiga Siku-Siku
  painter.drawLine(25,125,100,125);
  painter.drawLine(25,25,25,125);
  painter.drawLine(25,25,100,125);

  //Segitiga Siku-Siku
  painter.drawLine(150,25,225,25);
  painter.drawLine(225,25,225,125);
  painter.drawLine(150,25,225,125);

  //Persegi Panjang
  /*painter.drawLine(100,150,225,150);
  painter.drawLine(100,250,225,250);
  painter.drawLine(100,150,100,250);
  painter.drawLine(225,150,225,250);*/
  QRect rec(100,150,100,100);
  QBrush brush(Qt::red, Qt::SolidPattern);
  QBrush brush1(Qt::green, Qt::SolidPattern);
  //painter.drawRect(rec);

  //painter.setPen(PointPen);
  //painter.drawPoint(162,200);

  //Create Path
  QPainterPath path;
  path.addEllipse(rec);

  painter.fillRect(rec, brush1);
  painter.setPen(LinePen);
  painter.drawEllipse(rec);
  painter.fillPath(path, brush);

  //Operasi +
  painter.drawLine(p1,p2);
  painter.drawLine(p3,p4);

  //Operasi =
  painter.drawLine(25,185,75,185);
  painter.drawLine(25,210,75,210);

}
