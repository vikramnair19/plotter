#include <QtGui>
#include <stdlib.h>
#include <iostream>
#include <QRect>

using namespace std;
#include "Plotter.h"

Plotter::Plotter(QWidget *parent)
  : QWidget(parent)
{
    width = 10000;
    margin_left=1;
    margin_right=3;
    margin_top=1;
    margin_bottom=3;
    waveform_height=20;
    zoom = 1000;
    total_samples = 1000;

    setWindowTitle(tr("Plotter"));
    const int height= 50;
    resize(QApplication::desktop()->width(),height);
    for(int i=0;i<total_samples;i++)
        sampled_data.append(rand() & 1);
}

void Plotter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QSizeF size=this->size();

    quint32 height= size.height();
    quint32 waveform_base=height-5;
    quint32 waveform_top=waveform_base-waveform_height;
    quint32 start_sample=0;
    float distance_between_samples=width/zoom;
    float currx=margin_left; float curry=waveform_height;
    float nextx,nexty;
    float halfway;
    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.drawRect(margin_left,margin_top,size.width()-margin_right,size.height()-margin_bottom);
    for(quint32 i=0;i<total_samples-1;i++)
    {
        nextx=currx+distance_between_samples;
        painter.drawLine(nextx,0,nextx,height);
        currx=nextx;
    }
    currx=margin_left;
    curry=sampled_data.at(start_sample) ? waveform_top:waveform_base;
    for(quint32 i=1+start_sample;i<total_samples-start_sample;i++)
    {
        if(sampled_data.at(i))
        {
            nexty=waveform_top;
        }
        else
        {
            nexty=waveform_base;
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
