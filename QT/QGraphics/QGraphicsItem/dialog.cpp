#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);

  scene = new QGraphicsScene(this);

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);

  scene->setSceneRect(-100,-100,200,200);

  QPen myPen(Qt::red);

  QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
  QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
  QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
  QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

  scene->addLine(TopLine, myPen);
  scene->addLine(LeftLine, myPen);
  scene->addLine(RightLine, myPen);
  scene->addLine(BottomLine, myPen);

  int itemCount = 1;
  for(int i=0; i<itemCount; i++){
    MyItem *item = new MyItem();
    scene->addItem(item);
  }

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
  timer.start(100);

}

Dialog::~Dialog()
{
  delete ui;
}
