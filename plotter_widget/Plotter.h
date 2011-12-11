#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
class Plotter:public QWidget
{
    Q_OBJECT
public:

    Plotter(QWidget *parent = 0);

protected:
    QVector <qint8> sampled_data;       //Holds the sampled data
    quint32 width;                      //Total width of waveform
    quint32 margin_left;
    quint32 margin_right;
    quint32 margin_top;
    quint32 margin_bottom;
    quint32 waveform_height;
    quint32 zoom;
    quint32 total_samples;


    void paintEvent(QPaintEvent *event);

};

#endif
