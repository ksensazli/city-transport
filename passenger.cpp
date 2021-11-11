#include "passenger.h"
#include "ui_passenger.h"

Passenger::Passenger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passenger)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator());

    ui->comboBox_2->addItem("Seçiniz.");
    ui->comboBox_2->addItem("Otobüs");
    ui->comboBox_2->addItem("Metro");
    ui->comboBox_2->addItem("Feribot");
}

Passenger::~Passenger()
{
    delete ui;
}

void Passenger::on_pushButton_clicked()
{
    QString selectedStop = ui->comboBox->currentText();

    QString countPassenger = ui->lineEdit->text();

    if(ui->lineEdit->text().isEmpty()==0){                                                          //check if the lineEdit(s) is empty

        qDebug() << countPassenger;

        QFile countPass("C:/Qt/CityTransport/countPassenger.csv");                                  //where to save the created .csv file

        if(countPass.open(QIODevice::ReadWrite | QIODevice::Append))
        {
          QTextStream stream(&countPass);                                                           //create the stream function

          stream << selectedStop << "," << countPassenger << Qt::endl ;                             //what to write into the stream function
        }

        countPass.close();                                                                          //close the .csv file

        qDebug() << "Yeni yolcu kayıt tamamlandı.";
    }

    else
    {
        QMessageBox::about(this,"Hata","Kayıt edilecek yolcu sayısı boş girilemez.");               //Warning
    }

}

void Passenger::on_comboBox_2_textActivated(const QString &arg1)
{
    if(ui->comboBox_2->currentText()=="Otobüs"){
        ui->comboBox->clear();
        QFile file("C:/Qt/CityTransport/busLines.csv");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

        file.readLine();                                                                                // read first line and ignore
        while (!file.atEnd()) {
            QString line = file.readLine();                                                             // read wavelength line and store it
            QString fields = line.split(',').first();
            ui->comboBox->addItem(fields);
        }
    }

    if(ui->comboBox_2->currentText()=="Metro"){
        ui->comboBox->clear();
        QFile file("C:/Qt/CityTransport/metroLines.csv");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

        file.readLine();                                                                                // read first line and ignore
        while (!file.atEnd()) {
            QString line = file.readLine();                                                             // read wavelength line and store it
            QString fields = line.split(',').first();
            ui->comboBox->addItem(fields);
        }
    }

    if(ui->comboBox_2->currentText()=="Feribot"){
        ui->comboBox->clear();
        QFile file("C:/Qt/CityTransport/ferryLines.csv");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

        file.readLine();                                                                                // read first line and ignore
        while (!file.atEnd()) {
            QString line = file.readLine();                                                             // read wavelength line and store it
            QString fields = line.split(',').first();
            ui->comboBox->addItem(fields);
        }
    }

    if(ui->comboBox_2->currentText()=="Seçiniz."){
        ui->comboBox->clear();
    }
}
