#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include<vector>

class Plotter : public QWidget
{
  Q_OBJECT
private:
  std::vector<double> tempos;
  std::vector<double> dados;
  float time;
public:
  /** @brief Construtor do Plotter
   * @details seta valores aos vectors tempos e dados para evitar problemas com "lixos"
  **/
  explicit Plotter(QWidget *parent = 0);
  /** @brief Paint event
   * @details desenha retas usando dois pontos por vez. Além disso, o eixo y para que a origem se encontre no canto
   * inferior esquerdo.
  **/
  void paintEvent(QPaintEvent *e);
  /** @brief Função que carrega dados
   * @details pega os 30 ultimos dados e envia para o paintEvent
  **/
  void loadData(std::vector <double>,std::vector <double>);
};

#endif // PLOTTER_H
