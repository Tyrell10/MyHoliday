#ifndef OPTIONFUKURO_H
#define OPTIONFUKURO_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class OptionFukuro;
}

class OptionFukuro : public QMainWindow
{
  Q_OBJECT

public:
  explicit OptionFukuro(QWidget *parent = 0);
  ~OptionFukuro();
  void paintEvent(QPaintEvent *event);

private:
  Ui::OptionFukuro *ui;
  QGraphicsScene *scene;
  QGraphicsPixmapItem *lines, *ball, *fukuro, *arrow1, *arrow2;
  QPixmap fukuroPic;
  //QPixmap lines, ball, fukuro, fukuroPic;
};

#endif // OPTIONFUKURO_H
