#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<QLineEdit>
#include<QTextBrowser>
#include<QTimer>
#include<QLabel>
#include<QLCDNumber>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tcpConnect();

    connect(ui->pushButtonPut,
            SIGNAL(clicked(bool)),
            this,
            SLOT(putData()));
    connect(ui->pushButton_connect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));
    connect(ui->pushButton_stop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopData());
}
//host default "127.0.0.1"

void MainWindow::tcpConnect(){
    socket->connectToHost(getHost(),1234); //PODE FUNÇÃO AQUI?
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }
}


void MainWindow::putData(){
    QDateTime datetime;
    QString str,timeStr;
    qint64 msecdate;
    QTextBrowser textbox;
    //QTimer timer;
    int max,min;

    max = ui->lcdNumber_max->digitCount();
    min = ui->lcdNumber_min->digitCount();


    timeStr = ui->label_time->text(); //É ASSIM MESMO?
    timer.start((time.toInt())*1000);

    while(timer.isActive()){ //CONFERIR

        if(socket->state()== QAbstractSocket::ConnectedState){

            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
            str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%((max + 1) - min) + min)+"\r\n"; //NÃO ENTENDIO RANDOM
            textbox.insertPlainText(str); //CONFERIR

            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            if(socket->waitForBytesWritten(3000)){
                qDebug() << "wrote";
            }
        }
    }
}

QString MainWindow::getHost(){ //NÃO ESTÁ FUNCIONANDO
    QString ip;

    ip = ui->lineEdit_Host->text();

    return ip;

}

void MainWindow::stopData(){ //CONFERIR
    timer.stop();
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}
