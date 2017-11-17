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
  amp = 1;
  freq = 1;
  angulo = 0;
  startTimer();
}

void Plotter::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  int x1, x2, y1, y2;

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

  // desenha a senoide
  x1 = 0;
  y1 = height()/2;

  // desenha o grid
  pen.setColor(QColor(0,0,255));
  pen.setWidth(2);
  pen.setStyle(Qt::SolidLine);
  painter.setPen(pen);

  for(int i=1; i<width(); i++){
    x2=i;
    y2=height()/2*(1-amp*sin(2*PI*i*freq/width()+angulo));
    painter.drawLine(x1,y1,x2,y2);
    x1 = x2;
    y1 = y2;
  }

}

void Plotter::timerEvent(QTimerEvent *e){
  repaint();
}

