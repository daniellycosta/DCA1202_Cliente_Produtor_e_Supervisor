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
  void tcpConnect(void);
  void tcpDisconnect(void);
  void getData(void);
  QString getHost(void);
  void stopData(void);
  void updateIp(void);
  void timerEvent(QTimerEvent *e);
  void paintEvent(QPaintEvent *e);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTimer;
};

#endif // MAINWINDOW_H
