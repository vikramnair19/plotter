#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
class Plotter:public QWidget
{
    Q_OBJECT
public:

    Plotter(QWidget *parent = 0);

protected:
  void paintEvent(QPaintEvent *event);

};

#endif
