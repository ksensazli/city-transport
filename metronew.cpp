#include "metronew.h"
#include "ui_metronew.h"

MetroNew::MetroNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetroNew)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QDoubleValidator());
}

MetroNew::~MetroNew()
{
    delete ui;
}

void MetroNew::on_pushButton_2_clicked()
{
    QString line_edit_metroNew = ui->lineEdit->text();                                              //assigning the string value written in lineEdit to the function
    QString line_edit_metroPrice = ui->lineEdit_2->text();                                          //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_metroNew << line_edit_metroPrice;

        QFile metroNew("C:/Qt/CityTransport/metroNew.csv");                                         //where to save the created .csv file

        if(metroNew.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&metroNew);                                                            //create the stream function

          stream << line_edit_metroNew << "," << line_edit_metroPrice << Qt::endl ;                 //what to write into the stream function
        }

        metroNew.close();                                                                           //close the .csv file

        qDebug() << "Yeni metro kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Metro ID veya araç bazında ücreti boş bırakılamaz.");       //Warning
    }
}
