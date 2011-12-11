#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
class Plotter:public QWidget
{
    Q_OBJECT
public:

    Plotter(QWidget *parent = 0);
    quint32 get_total_viewable_samples(void);
    quint32 get_starting_sample(void);
    QSize sizeHint();
    void set_sampled_data(QVector<quint8> sd);

public slots:
    void set_starting_sample(int);




protected:
    QVector <quint8> sampled_data;       //Holds the sampled data
    quint32 width;                      //Total width of waveform
    quint32 margin_left;
    quint32 margin_right;
    quint32 margin_top;
    quint32 margin_bottom;
    quint32 waveform_height;
    quint32 zoom;
    quint32 total_samples;
    quint32 height;
    quint32 start_sample;
    quint32 total_viewable_samples;
    bool draw_sample_bars;



    void paintEvent(QPaintEvent *event);

};

#endif
