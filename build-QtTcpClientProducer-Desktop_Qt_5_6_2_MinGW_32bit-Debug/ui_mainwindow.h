/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit_Host;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider_min;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber_min;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider_max;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_max;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSlider *horizontalSlider_time;
    QLabel *label_time;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonPut;
    QPushButton *pushButton_stop;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(599, 373);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        lineEdit_Host = new QLineEdit(centralWidget);
        lineEdit_Host->setObjectName(QStringLiteral("lineEdit_Host"));

        horizontalLayout_6->addWidget(lineEdit_Host);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_5->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_5->addWidget(pushButton_disconnect);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSlider_min = new QSlider(centralWidget);
        horizontalSlider_min->setObjectName(QStringLiteral("horizontalSlider_min"));
        horizontalSlider_min->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_min);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lcdNumber_min = new QLCDNumber(centralWidget);
        lcdNumber_min->setObjectName(QStringLiteral("lcdNumber_min"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber_min->sizePolicy().hasHeightForWidth());
        lcdNumber_min->setSizePolicy(sizePolicy);
        lcdNumber_min->setSmallDecimalPoint(false);
        lcdNumber_min->setDigitCount(4);
        lcdNumber_min->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout->addWidget(lcdNumber_min);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSlider_max = new QSlider(centralWidget);
        horizontalSlider_max->setObjectName(QStringLiteral("horizontalSlider_max"));
        horizontalSlider_max->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_max);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lcdNumber_max = new QLCDNumber(centralWidget);
        lcdNumber_max->setObjectName(QStringLiteral("lcdNumber_max"));
        lcdNumber_max->setDigitCount(4);

        verticalLayout_2->addWidget(lcdNumber_max);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSlider_time = new QSlider(centralWidget);
        horizontalSlider_time->setObjectName(QStringLiteral("horizontalSlider_time"));
        horizontalSlider_time->setMinimum(1);
        horizontalSlider_time->setMaximum(60);
        horizontalSlider_time->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_time);

        label_time = new QLabel(centralWidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        QFont font;
        font.setPointSize(12);
        label_time->setFont(font);

        horizontalLayout_3->addWidget(label_time);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonPut = new QPushButton(centralWidget);
        pushButtonPut->setObjectName(QStringLiteral("pushButtonPut"));

        horizontalLayout_4->addWidget(pushButtonPut);

        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        horizontalLayout_4->addWidget(pushButton_stop);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 1, 6, 1);

        MainWindow->setCentralWidget(centralWidget);
        textBrowser->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 599, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider_min, SIGNAL(valueChanged(int)), lcdNumber_min, SLOT(display(int)));
        QObject::connect(horizontalSlider_max, SIGNAL(valueChanged(int)), lcdNumber_max, SLOT(display(int)));
        QObject::connect(horizontalSlider_time, SIGNAL(valueChanged(int)), label_time, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindow", "Host", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        label->setText(QApplication::translate("MainWindow", "Min", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max", 0));
        label_4->setText(QApplication::translate("MainWindow", "Timeout(s)", 0));
        label_time->setText(QApplication::translate("MainWindow", "1", 0));
        pushButtonPut->setText(QApplication::translate("MainWindow", "putData", 0));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
