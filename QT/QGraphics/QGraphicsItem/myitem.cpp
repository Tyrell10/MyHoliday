#include "myitem.h"

MyItem::MyItem()
{
  //random start rotation
  angle = (qrand() % 360);
  setRotation(angle);

  //set speed
  speed = 5;

  //random start position
  int StartX = 0;
  int StartY = 0;

  if(qrand() % 1){
    StartX = (qrand() % 200);
    StartY = (qrand() % 200);
  } else {
    StartX = (qrand() % -100);
    StartY = (qrand() % -100);
  }

  setPos(mapToParent(StartX,StartY);)
}

QRectF MyItem::boundingRect() const
{
  return QRect(0,0,20,20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  QRectF rec = boundingRect();
  QBrush brush(Qt::gray);

  //basic colliison detection
  if(scene()->collidingItems(this).isEmpty()){
    // no collision
    brush.setColor(Qt::red);
  } else{
    // collision
    brush.setColor(Qt::green);

    doCollision();
  }
}

void MyItem::advance(int phase)
{
  if(!phase) return;

  QPoint location = this->pos();
  setPos(mapToParent(0,-(speed)));
}

void MyItem::doCollision(){
  // get a new position

  // change the angle with little randomers
  if((qrand() % 1)){
    setRotation(rotation() + (180 + (qrand() % 10)));
  } else {
    setRotation(rotation() + (180 + (qrand() % -10)));
  }
}
