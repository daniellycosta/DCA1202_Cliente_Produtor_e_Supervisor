#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>

using namespace std;

Plotter::Plotter(QWidget *parent) :
    QWidget(parent){
    for(int i=0; i<30; i++){
        tempos.push_back(i);
        dados.push_back(i);
    }
}

void Plotter::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    double x1, x2, y1, y2;
    vector<double>dadosnorm;
    vector<double>temposnorm;
//    double max_x, min_x, min_y, max_y;

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(255,255,200));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,0,0));
    pen.setWidth(3);

    painter.setBrush(brush);
    painter.setPen(pen);

    // desenha o fundo do plotter
    painter.drawRect(0,0,width(), height());

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

//    //achando valores maximos e minimos
//    max_x = tempos[0], min_x = tempos[0];
//    min_y = dados[0], max_y = dados[0];

//    for(int i = 1 ; i < 30; i++){
//        if(tempos[i] < min_x){
//            min_x = tempos[i];
//        }
//        else if(tempos[i] > max_x){
//            max_x = tempos[i];
//        }
//        if(dados[i] < min_y){
//            min_y = dados[i];
//        }
//        else if(dados[i] > max_y){
//            max_x = dados[i];
//        }
//    }

//    //normalizando dados

//    for(int i = 0; i<30; i++){
//        temposnorm[i] = (tempos[i] - min_x)/(max_x - min_x);
//        dadosnorm[i] = (dados[i] - min_y)/(max_y - min_y);
//    }


    //plotando graficos

    x1 = tempos[0]*width();
    y1 = dados[0]*(height()-dados[0]);

    for(int i=1; i<30; i++){
        x2=tempos[i]*width();
        y2=dados[i]*(height()-dados[i]);
        painter.drawLine(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }

}

void Plotter::loadData(vector<double> t, vector<double> d){
    tempos=t;
    dados=d;
    repaint();
}

