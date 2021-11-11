#include "busnew.h"
#include "ui_busnew.h"

BusNew::BusNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BusNew)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QDoubleValidator());
}

BusNew::~BusNew()
{
    delete ui;
}

void BusNew::on_pushButton_2_clicked()
{
    QString line_edit_busNew = ui->lineEdit->text();                                                //assigning the string value written in lineEdit to the function
    QString line_edit_busPrice = ui->lineEdit_2->text();                                            //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_busNew << line_edit_busPrice;

        QFile busNew("C:/Qt/CityTransport/busNew.csv");                                             //where to save the created .csv file

        if(busNew.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&busNew);                                                              //create the stream function

          stream << line_edit_busNew << "," << line_edit_busPrice << Qt::endl ;                     //what to write into the stream function
        }

        busNew.close();                                                                             //close the .csv file

        qDebug() << "Yeni otobüs kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Otobüs ID veya araç bazında ücreti boş bırakılamaz.");      //Warning
    }
}
