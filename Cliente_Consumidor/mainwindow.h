#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
    /** @brief Conecta com o servidor
    **/
  void tcpConnect(void);
  /** @brief Desconecta do servidor
  **/
  void tcpDisconnect(void);
  /** @brief Começa a pegar dados do servidor
   * @details Pega de 30 em 30 amostras a um tempo determinado pelo usuário
  **/
  void getData(void);
  /** @brief Para de pegar dados do servidor
  **/
  void stopData(void);
  /** @brief Atualiza lista de clientes produtores conectados
  **/
  void updateIp(void);
  /** @brief Time event
   * @details função que faz o getData(void) ser chamado no tempo determinado pelo usuário
  **/
  void timerEvent(QTimerEvent *e);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTimer;
};

#endif // MAINWINDOW_H
