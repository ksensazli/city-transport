#ifndef BUSSTOPS_H
#define BUSSTOPS_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QIntValidator>
#include <QTextStreamFunction>

namespace Ui {
class BusStops;
}

class BusStops : public QDialog
{
    Q_OBJECT

public:
    explicit BusStops(QWidget *parent = nullptr);
    ~BusStops();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BusStops *ui;
};

#endif // BUSSTOPS_H
