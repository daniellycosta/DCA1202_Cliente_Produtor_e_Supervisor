#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include<vector>

class Plotter : public QWidget
{
  Q_OBJECT
private:
  std::vector<double> times;
  std::vector<double> datas;
  float time;
public:
  explicit Plotter(QWidget *parent = 0);
  void paintEvent(QPaintEvent *e);
  //void timerEvent(QTimerEvent *e);
  void loadData(std::vector <double>,std::vector <double>);
};

#endif // PLOTTER_H
