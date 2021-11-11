#ifndef FERRYSTOPS_H
#define FERRYSTOPS_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QIntValidator>

namespace Ui {
class FerryStops;
}

class FerryStops : public QDialog
{
    Q_OBJECT

public:
    explicit FerryStops(QWidget *parent = nullptr);
    ~FerryStops();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FerryStops *ui;
};

#endif // FERRYSTOPS_H
