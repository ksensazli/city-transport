#ifndef PASSENGER_H
#define PASSENGER_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QIntValidator>
#include <QTextStream>
#include <QFile>
#include <QDir>

namespace Ui {
class Passenger;
}

class Passenger : public QDialog
{
    Q_OBJECT

public:
    explicit Passenger(QWidget *parent = nullptr);
    ~Passenger();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_textActivated(const QString &arg1);

private:
    Ui::Passenger *ui;
};

#endif // PASSENGER_H
