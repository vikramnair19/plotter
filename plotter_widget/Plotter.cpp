#include <QtGui>
#include <stdlib.h>
#include <iostream>
#include <QRect>

using namespace std;
#include "Plotter.h"

int sample_data[]={0,1,1,1,0,1,0,0,1,0};


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
    const int width = QApplication::desktop()->width();
    const int height= 100;
    float sample_freq = 10;  //Frequency in Hz
    float signal_time = 1;  //Signal length in seconds
    float total_samples = signal_time*sample_freq;
    float distance_between_samples=width/total_samples;
    float currx=1; float curry=height-5;
    float nextx,nexty;
    painter.setRenderHint(QPainter::Antialiasing,true);

    QSizeF size=this->size();
    QPoint p;
    //printf("%f,%f\n",size.width(),size.height());
    //printf("distance between samples = %f",distance_between_samples);
    painter.drawRect(1,1,size.width()-3,size.height()-3);
    //this->setMinimumSize(width,height);
    //this->setMaximumSize(width,height);
    for(int i=0;i<total_samples;i++)
    {
        nextx=currx+distance_between_samples;
        painter.drawLine(nextx,0,nextx,height);
        currx=nextx;
    }
    currx=1;curry=height-5;
    for(int i=0;i<total_samples;i++)
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
        painter.drawLine(currx,curry,nextx,nexty);
        //printf("(%f,%f),(%f,%f)",currx,curry,nextx,nexty);
        currx=nextx;
        curry=nexty;

    }

}
