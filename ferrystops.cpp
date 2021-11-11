#include "ferrystops.h"
#include "ui_ferrystops.h"

FerryStops::FerryStops(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FerryStops)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QIntValidator());
}

FerryStops::~FerryStops()
{
    delete ui;
}

void FerryStops::on_pushButton_clicked()
{
    QString line_edit_ferryStops = ui->lineEdit->text();                                            //assigning the string value written in lineEdit to the function
    QString line_edit_stopDist = ui->lineEdit_2->text();                                            //assigning the string value written in lineEdit_2 to the function

    if(ui->lineEdit->text().isEmpty()==0 && ui->lineEdit_2->text().isEmpty()==0){                   //check if the lineEdit(s) is empty
        qDebug() << line_edit_ferryStops << line_edit_stopDist;

        QFile ferryStops("C:/Qt/CityTransport/ferryStops.csv");                                     //where to save the created .csv file

        if(ferryStops.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&ferryStops);                                                          //create the stream function

          stream << line_edit_ferryStops << "," << line_edit_stopDist << Qt::endl ;                 //what to write into the stream function
        }

        ferryStops.close();                                                                         //close the .csv file

        qDebug() << "Yeni feribot iskelesi kayıt tamamlandı.";
    }

    else{
        QMessageBox::about(this,"Hata","Durak ID veya durak uzaklığı boş bırakılamaz.");            //Warning
    }
}

