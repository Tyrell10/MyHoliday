#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private:
  Ui::Dialog *ui;
  QGraphicsScene *scene;
  QGraphicsEllipseItem *ellipse;
  QGraphicsRectItem *rec;
};

#endif // DIALOG_H
