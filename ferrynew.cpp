#include "ferrynew.h"
#include "ui_ferrynew.h"

FerryNew::FerryNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FerryNew)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QDoubleValidator());
}

FerryNew::~FerryNew()
{
    delete ui;
}

void FerryNew::on_pushButton_2_clicked()
{
    QString line_edit_ferryNew = ui->lineEdit->text();                                              //assigning the string value written in lineEdit to the function
    QString line_edit_ferryPrice = ui->lineEdit_2->text();                                          //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_ferryNew << line_edit_ferryPrice;

        QFile ferryNew("C:/Qt/CityTransport/ferryNew.csv");                                         //where to save the created .csv file

        if(ferryNew.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&ferryNew);                                                            //create the stream function

          stream << line_edit_ferryNew << "," << line_edit_ferryPrice << Qt::endl ;                 //what to write into the stream function
        }

        ferryNew.close();                                                                           //close the .csv file

        qDebug() << "Yeni metro kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Feribot ID veya araç bazında ücreti boş bırakılamaz.");     //Warning
    }
}
