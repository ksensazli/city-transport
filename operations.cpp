/*Operations.cpp file contains the functions of the
  navigation(bus/metro/ferry) screen after the mainwindow.*/

#include "operations.h"
#include "ui_operations.h"
#include "busnew.h"
#include "metronew.h"
#include "ferrynew.h"
#include "busstops.h"
#include "metrostops.h"
#include "ferrystops.h"
#include "buslines.h"
#include "metrolines.h"
#include "ferrylines.h"

Operations::Operations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Operations)
{
    ui->setupUi(this);                                                      //integration the user interface

    ui->comboBox->addItem("Seçiniz");                                       //for first line
    ui->comboBox->addItem("Otobüs");                                        //add the bus line
    ui->comboBox->addItem("Metro");                                         //add the metro line
    ui->comboBox->addItem("Feribot");                                       //add the ferry line
}

Operations::~Operations()
{
    delete ui;
}

void Operations::on_pushButton_clicked()
{
    BusNew busNew;                                                          //define the BusNew class and run it
    busNew.setModal(true);
    MetroNew metroNew;                                                      //define the MetroNew class and run it
    metroNew.setModal(true);
    FerryNew ferryNew;                                                      //define the FerryNew class and run it
    ferryNew.setModal(true);

    if(ui->comboBox->currentText()=="Otobüs"){                              //set the only bus_add
        qDebug() << "Otobüs Ekleme";                                        //check the if statement
        busNew.exec();                                                      //run the busnew.ui
    }

    if(ui->comboBox->currentText()=="Metro"){                               //set the only metro_add
        qDebug() << "Metro Ekleme";                                         //check the if statement
        metroNew.exec();                                                    //run the metronew.ui
    }

    if(ui->comboBox->currentText()=="Feribot"){                             //set the only ferry_add
        qDebug() << "Feribot Ekleme";                                       //check the if statement
        ferryNew.exec();                                                    //run the ferrynew.ui
    }
}


void Operations::on_pushButton_2_clicked()
{
    BusStops busStops;                                                      //define the BusStops class and run it
    busStops.setModal(true);
    MetroStops metroStops;                                                  //define the MetroStops class and run it
    metroStops.setModal(true);
    FerryStops ferryStops;                                                  //define the FerryStops class and run it
    ferryStops.setModal(true);

    if(ui->comboBox->currentText()=="Otobüs"){                              //set the only bus_stops
        qDebug() << "Otobüs Durak Ekleme";                                  //check the if statement
        busStops.exec();                                                    //run the busnew.ui
    }

    if(ui->comboBox->currentText()=="Metro"){                               //set the only metro_stations
        qDebug() << "Metro İstasyon Ekleme";                                //check the if statement
        metroStops.exec();                                                  //run the metronew.ui
    }

    if(ui->comboBox->currentText()=="Feribot"){                             //set the only ferry_ports
        qDebug() << "Feribot İskele Ekleme";                                //check the if statement
        ferryStops.exec();                                                  //run the ferrynew.ui
    }
}

void Operations::on_pushButton_3_clicked()
{
    BusLines busLines;                                                      //define the BusLines class and run it
    busLines.setModal(true);
    MetroLines metroLines;                                                  //define the MetroLines class and run it
    metroLines.setModal(true);
    FerryLines ferryLines;                                                  //define the FerryLines class and run it
    ferryLines.setModal(true);

    if(ui->comboBox->currentText()=="Otobüs"){                              //set the only bus_lines
        qDebug() << "Otobüs Hat Ekleme";                                    //check the if statement
        busLines.exec();                                                    //run the buslines.ui
    }

    if(ui->comboBox->currentText()=="Metro"){                               //set the only metro_lines
        qDebug() << "Metro Hat Ekleme";                                     //check the if statement
        metroLines.exec();                                                  //run the metrolines.ui
    }

    if(ui->comboBox->currentText()=="Feribot"){                             //set the only ferry_lines
        qDebug() << "Feribot Hat Ekleme";                                   //check the if statement
        ferryLines.exec();                                                  //run the ferrylines.ui
    }
}
