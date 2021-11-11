#ifndef BUSNEW_H
#define BUSNEW_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QFile>

namespace Ui {
class BusNew;
}

class BusNew : public QDialog
{
    Q_OBJECT

public:
    explicit BusNew(QWidget *parent = nullptr);
    ~BusNew();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::BusNew *ui;
};

#endif // BUSNEW_H
