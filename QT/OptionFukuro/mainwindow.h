#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}
class QGraphicsScene;

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  //void paintEvent(QPaintEvent *event);

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  //QPixmap lines;
};

#endif // MAINWINDOW_H
