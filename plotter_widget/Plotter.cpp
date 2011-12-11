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
    margin_right=2;
    margin_top=1;
    margin_bottom=3;
    waveform_height=20;
    zoom = 1000;
    total_samples = 100;
    height = 50;
    start_sample=0;
    draw_sample_bars=false;
    setWindowTitle(tr("Plotter"));
    resize(QApplication::desktop()->width(),height);
    for(quint32 i=0;i<total_samples;i++)
        sampled_data.append(rand() & 1);
    this->setMaximumHeight(height);
    this->setMinimumHeight(height);
}

void Plotter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QSizeF size=this->size();
//    QBrush brush(QColor(0,0,0));
//    painter.setBackground(brush);
    quint32 height= size.height();
    quint32 waveform_base=height-5;
    quint32 waveform_top=waveform_base-waveform_height;
    float distance_between_samples=width/zoom;
    total_viewable_samples=size.width()/distance_between_samples;
    float currx=margin_left; float curry=waveform_height;
    float nextx,nexty;
    float halfway;
    //painter.setRenderHint(QPainter::Antialiasing,true);
    QRect rect(margin_left,margin_top,size.width()-margin_right,size.height()-margin_bottom);
    painter.fillRect(rect,QColor(0,0,0));
    painter.drawRect(rect);
    painter.setPen(QColor(255,255,255));
    if(draw_sample_bars==true){
        for(quint32 i=0;i<total_samples-1-start_sample;i++)
        {
            nextx=currx+distance_between_samples;
            painter.drawLine(nextx,0,nextx,height-margin_bottom);
            currx=nextx;
        }
    }
    currx=margin_left;
    curry=sampled_data.at(start_sample) ? waveform_top:waveform_base;
    painter.setPen(QColor(0,255,0));
    for(quint32 i=1+start_sample;i<total_samples;i++)
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
void Plotter::set_starting_sample(int sample){
    start_sample=sample;
    this->update();
}

quint32 Plotter::get_starting_sample(void){
    return start_sample;
}

quint32 Plotter::get_total_viewable_samples(void){
    return total_viewable_samples;
}

QSize Plotter::sizeHint(){
    return this->size();
}
void Plotter::set_sampled_data(QVector<quint8> sd){
    this->sampled_data=sd;
}
