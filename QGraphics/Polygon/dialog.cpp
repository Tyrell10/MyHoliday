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
  painter.setRenderHint(QPainter::Antialiasing, true);
  QPen linePen(Qt::red, 2, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setPen(linePen);

  QPolygon poly;
  QLine line_pass(100,100,180,70);

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
  painter.drawLine(line_pass);

}

void Dialog::on_pushButton_clicked()
{
//    if(ui->pushButton->text()=="Green"){
//      ui->label->setVisible(false);
//      ui->label_2->setVisible(true);
//      ui->pushButton->setText("Red");
//    } else {
//      ui->label_2->setVisible(false);
//      ui->label->setVisible(true);
//      ui->pushButton->setText("Green");
//    }
}
