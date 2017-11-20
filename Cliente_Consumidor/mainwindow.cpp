#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>
#include <QListWidget>
#include <QWidget>
#include <QSlider>
#include <vector>
#include<plotter.h>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();

  connect(ui->pushButtonGet,
          SIGNAL(clicked(bool)),
          this,
          SLOT(getData()));
  connect(ui->pushButton_Stop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopData()));
  connect(ui->pushButton_Connect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));
  connect(ui->pushButton_Disconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));
  connect(ui->pushButton_Update,
          SIGNAL(clicked(bool)),
          this,
          SLOT(updateIp()));
}

void MainWindow::tcpConnect(){
  socket->connectToHost(getHost(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }

  updateIp();
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
}

QString MainWindow::getHost(){
    QString ip;

    ip = ui->lineEdit_Host->text();


    return ip;
}

void MainWindow::getData(){
  QString timeStr;

  timeStr = ui->label_Timing->text();
  idTimer = startTimer((timeStr.toInt())*1000);

}

void MainWindow::timerEvent(QTimerEvent *e){
    QString str;
    QStringList list;
    qint64 thetime, num;
    Plotter p;
    std::vector<double> time;
    std::vector<double> data;

    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
      if(socket->isOpen()){
        qDebug() << "reading...";
        str = "get" + ui->listWidget_ListaDeClients->currentItem()->text() + "30\r\n";
        socket->write(str.toStdString().c_str());
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        qDebug() << socket->bytesAvailable();
        while(socket->bytesAvailable()){
          str = socket->readLine().replace("\n","").replace("\r","");
          list = str.split(" ");
          if(list.size() == 2){
            bool ok;
            str = list.at(0);
            thetime = str.toLongLong(&ok);
            time.push_back(thetime);

            str = list.at(1);
            num = str.toLongLong(&ok);
            data.push_back(num);
            qDebug() << thetime << ": " << str;
          }
        }
      }
    }
    p.loadData(time,data);
}

void MainWindow::stopData(void){
    killTimer(idTimer);
}

void MainWindow::updateIp(void){
    QString str;

    socket->write("list \r\n");
    while(socket->bytesAvailable()){
      str = socket->readLine().replace("\n","").replace("\r","");
      ui->listWidget_ListaDeClients->addItem(str);
    }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
