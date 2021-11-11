#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operations.h"
#include "passenger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Operations operations;                      //define the Operations class and run it
    operations.setModal(true);
    operations.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Passenger passenger;                        //define the Passenger class and run it
    passenger.setModal(true);
    passenger.exec();
}
