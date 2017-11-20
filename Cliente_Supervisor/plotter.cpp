#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>

using namespace std;

Plotter::Plotter(QWidget *parent) :
    QWidget(parent)
{
    startTimer();
}

void Plotter::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    double x1, x2, y1, y2;
    vector<double>datanorm;
    vector<double>timenorm;
    double max_x, min_x, min_y, max_y;

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(255,255,200));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,0,0));
    pen.setWidth(3);

    painter.setBrush(brush);
    painter.setPen(pen);

    // desenha o fundo do plotter
    painter.drawRect(0,0,width(), height());

    // desenha a reta horizontal
    painter.drawLine(0,height()/2,width(),height()/2);

    // desenha o grid
    pen.setColor(QColor(200,200,0));
    pen.setWidth(1);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);

    for(int i=width()/6; i<5*width()/6; i+=width()/6){
        painter.drawLine(i,0,i,height());
    }

    // desenha o grid
    pen.setColor(QColor(0,0,255));
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    //achando valores maximos e minimos
    max_x = time[0], min_x = time[0];
    min_y = data[0], max_y = data[0];

    for(int i = 1 ; i < times.size(); i++){
        if(times[i] < min_x){
            min_x = times[i];
        }
        else if(times[i] > max_x){
            max_x = times[i];
        }
        if(data[i] < min_y){
            min_y = data[i];
        }
        else if(data[i] > max_y){
            max_x = data[i];
        }
    }

    //normalizando dados

    for(int i = 0; i<times.size(); i++){
        timesnorm[i] = (times[i] - min_x)/(max_x - min_x);
        datanorm[i] = (data[i] - min_y)/(max_y - min_y);
    }


    //plotando graficos

    x1 = timesnorm[0];
    y1 = datanorm[0];

    for(int i=1; i<width(); i++){
        x2=timenorm[i];
        y2=datanorm[i];
        painter.drawLine(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }

}

void Plotter::loadData(vector<double> t, vector<double> d){

    for(vector<int>::iterator it = t.begin() ; it != t.end(); ++it){
        times.push_back(*it);
    }
    for(vector<int>::iterator it = d.begin() ; it != d.end(); ++it){
        datas.push_back(*it);
    }

    repaint();
}

