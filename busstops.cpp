#include "busstops.h"
#include "ui_busstops.h"

BusStops::BusStops(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BusStops)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QIntValidator());
}

BusStops::~BusStops()
{
    delete ui;
}

void BusStops::on_pushButton_clicked()
{
    QString line_edit_busStops = ui->lineEdit->text();                                              //assigning the string value written in lineEdit to the function
    QString line_edit_stopDist = ui->lineEdit_2->text();                                            //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_busStops << line_edit_stopDist;

        QFile busStops("C:/Qt/CityTransport/busStops.csv");                                         //where to save the created .csv file

        if(busStops.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&busStops);                                                            //create the stream function

          stream << line_edit_busStops << "," << line_edit_stopDist << Qt::endl ;                   //what to write into the stream function
        }

        busStops.close();                                                                           //close the .csv file

        qDebug() << "Yeni otobüs durağı kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Durak ID veya durak uzaklığı boş bırakılamaz.");            //Warning
    }
}
