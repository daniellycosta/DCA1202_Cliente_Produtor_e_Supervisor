#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>
#include <QListWidget>
#include <QWidget>
#include <QSlider>

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
          SIGNAL(clicked(bool),
          this,
          SLOT(stopData());
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
    QByteArray array;
    QStringList list;
    qint64 thetime;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
      if(socket->isOpen()){
        qDebug() << "reading...";
        socket->write("get" + ui->listWidget_ListaDeClients->currentItem()->text() + "30\r\n");
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
            str = list.at(1);
            qDebug() << thetime << ": " << str;
          }
        }
      }
    }

}

void MainWindow::stopData(void){
    killTimer(idTimer);
}

void MainWindow::updateIp(void){
    QString str;

    socket->write("list \r\n");
    while(socket->bytesAvailable()){
      str = socket->readLine().replace("\n","").replace("\r","");
      list = str.split(" ");
      if(list.size() == 2){
        bool ok;
        str = list.at(0);
        thetime = str.toLongLong(&ok);
        str = list.at(1);
        qDebug() << thetime << ": " << str;
    }

    ui->listWidget_ListaDeClients->
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
