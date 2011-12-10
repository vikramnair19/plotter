#include <QApplication>

#include "Plotter.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Plotter plot;
  plot.show();

  return app.exec();
}
