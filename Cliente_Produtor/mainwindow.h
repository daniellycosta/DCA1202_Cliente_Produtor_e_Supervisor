#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include<QTimer>

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
    /**
   * @brief Se conecta com o server
   */
  void tcpConnect();
  /**
 * @brief Se desconecta do server
 */
  void tcpDisconnect();
  /**
 * @brief Envia dados para o sever
 */
  void putData();
  /**
 * @brief Pega host fornecido pelo usuário e usa na função tcpConnect()
 */
  QString getHost();
  /**
 * @brief Para de enviar dados para o sever
 */
  void stopData();
  /**
 * @brief Timer event para repetir o putData() de acordo com a quantidade de milissegundos fornecidos pelo usuário
 */
  void timerEvent(QTimerEvent *e);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTimer;

};

#endif // MAINWINDOW_H
