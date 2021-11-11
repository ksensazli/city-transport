#include "metrolines.h"
#include "ui_metrolines.h"

MetroLines::MetroLines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetroLines)
{
    ui->setupUi(this);

    QStringList stringList;

    QFile textFile("C:/Qt/CityTransport/metroStops.csv");
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

MetroLines::~MetroLines()
{
    delete ui;
}

void MetroLines::on_pushButton_clicked()
{
    if( ui->listWidget->count() == 0 )                                                      // nothing to transfer...
    return;

    QListWidgetItem *widget = ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget_2->addItem(widget);
    ui->listWidget_2->sortItems(Qt::AscendingOrder);
}


void MetroLines::on_pushButton_3_clicked()
{
    QString lineNo = ui->lineEdit->text();

    if(ui->lineEdit->text().isEmpty()==0){                                                  //check if the lineEdit(s) is empty

        QFile metroLine("C:/Qt/CityTransport/metroLines.csv");                                  //where to save the created .csv file

        if(metroLine.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream stream(&metroLine);                                                   //create the stream function
            stream << lineNo << ',' ;

            for (int i = 0; i < ui->listWidget_2->count(); i++)
            {
                QListWidgetItem *item = ui->listWidget_2->item(i);
                stream << item->text() << ',';
            }
            stream << Qt::endl;
        }

        metroLine.close();                                                                    //close the .csv file

        qDebug() << "Yeni metro hat kayıt tamamlandı.";
    }

    else
    {
        QMessageBox::about(this,"Hata","Metro hat numarası boş bırakılamaz.");             //Warning
    }
}

