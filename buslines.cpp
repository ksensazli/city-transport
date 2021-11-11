#include "buslines.h"
#include "ui_buslines.h"

BusLines::BusLines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BusLines)
{
    ui->setupUi(this);

    QStringList stringList;

    QFile textFile("C:/Qt/CityTransport/busStops.csv");
    if(!textFile.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0,"Error",textFile.errorString());
    }

    QTextStream textStream(&textFile);
    while (true)
    {
        QString line = textStream.readLine();
        QString fields = line.split(',').first();
        if (line.isNull())
            break;
        else
            stringList.append(fields);
    }
    ui->listWidget->addItems(stringList);
}

BusLines::~BusLines()
{
    delete ui;
}


void BusLines::on_pushButton_clicked()
{
    if( ui->listWidget->count() == 0 )                                                      // nothing to transfer...
    return;

    QListWidgetItem *widget = ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget_2->addItem(widget);
    ui->listWidget_2->sortItems(Qt::AscendingOrder);
}


void BusLines::on_pushButton_3_clicked()
{
    QString lineNo = ui->lineEdit->text();

    if(ui->lineEdit->text().isEmpty()==0){                                                  //check if the lineEdit(s) is empty

        QFile busLine("C:/Qt/CityTransport/busLines.csv");                                  //where to save the created .csv file

        if(busLine.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream stream(&busLine);                                                   //create the stream function
            stream << lineNo << ',' ;

            for (int i = 0; i < ui->listWidget_2->count(); i++)
            {
                QListWidgetItem *item = ui->listWidget_2->item(i);
                stream << item->text() << ',';
            }
            stream << Qt::endl;
        }

        busLine.close();                                                                    //close the .csv file

        qDebug() << "Yeni otobüs hat kayıt tamamlandı.";
    }

    else
    {
        QMessageBox::about(this,"Hata","Otobüs hat numarası boş bırakılamaz.");             //Warning
    }
}

