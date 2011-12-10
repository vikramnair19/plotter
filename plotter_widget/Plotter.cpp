#include <QtGui>
#include <stdlib.h>
#include <iostream>
#include <QRect>

using namespace std;
#include "Plotter.h"

int sample_data[]={0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0};


Plotter::Plotter(QWidget *parent)
  : QWidget(parent)
{
    setWindowTitle(tr("Plotter"));
    //resize(200, 200);
    const int width = QApplication::desktop()->width();
    const int height= 100;
    resize(width,height);
}

void Plotter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QSizeF size=this->size();
    const int width = 10000;
    const int height= size.height();
    int zoom = 10;
    float total_samples = sizeof(sample_data)/sizeof(int);
    float distance_between_samples=width/zoom;
    float currx=1; float curry=height-5;
    float nextx,nexty;
    float halfway;
    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.drawRect(1,1,size.width()-3,size.height()-3);
    for(int i=0;i<total_samples;i++)
    {
        nextx=currx+distance_between_samples;
        painter.drawLine(nextx,0,nextx,height);
        currx=nextx;
    }
    currx=1;
    curry=sample_data[0] ? height-50:height-5;
    for(int i=1;i<total_samples;i++)
    {
        if(sample_data[i])
        {
            nexty=height-50;
        }
        else
        {
            nexty=height-5;
        }
        nextx=currx+distance_between_samples;
        halfway=currx+distance_between_samples/2;
        painter.drawLine(currx,curry,halfway,curry);
        painter.drawLine(halfway,curry,halfway,nexty);
        painter.drawLine(halfway,nexty,nextx,nexty);

        currx=nextx;
        curry=nexty;

    }

}
