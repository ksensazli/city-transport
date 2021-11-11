#include "metrostops.h"
#include "ui_metrostops.h"

MetroStops::MetroStops(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetroStops)
{
    ui->setupUi(this);
}

MetroStops::~MetroStops()
{
    delete ui;
}

void MetroStops::on_pushButton_clicked()
{
    QString line_edit_metroStops = ui->lineEdit->text();                                            //assigning the string value written in lineEdit to the function
    QString line_edit_stopDist = ui->lineEdit_2->text();                                            //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_metroStops << line_edit_stopDist;

        QFile metroStops("C:/Qt/CityTransport/metroStops.csv");                                     //where to save the created .csv file

        if(metroStops.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&metroStops);                                                          //create the stream function

          stream << line_edit_metroStops << "," << line_edit_stopDist << Qt::endl ;                 //what to write into the stream function
        }

        metroStops.close();                                                                         //close the .csv file

        qDebug() << "Yeni metro istasyonu kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Durak ID veya durak uzaklığı boş bırakılamaz.");            //Warning
    }
}

