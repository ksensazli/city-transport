#ifndef FERRYNEW_H
#define FERRYNEW_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QFile>

namespace Ui {
class FerryNew;
}

class FerryNew : public QDialog
{
    Q_OBJECT

public:
    explicit FerryNew(QWidget *parent = nullptr);
    ~FerryNew();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::FerryNew *ui;
};

#endif // FERRYNEW_H
