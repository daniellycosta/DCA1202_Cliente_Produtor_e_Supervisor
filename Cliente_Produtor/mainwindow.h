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
  
  void tcpConnect();
public slots:
  void putData();
  QString getHost();
  void stopData();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QTimer timer;

};

#endif // MAINWINDOW_H
