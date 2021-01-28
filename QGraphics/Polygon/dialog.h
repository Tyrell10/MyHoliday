#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QRectF>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private:
  Ui::Dialog *ui;

protected:
  void paintEvent(QPaintEvent *event);
private slots:
  void on_pushButton_clicked();
};

#endif // DIALOG_H
