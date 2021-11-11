#ifndef METROSTOPS_H
#define METROSTOPS_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QIntValidator>

namespace Ui {
class MetroStops;
}

class MetroStops : public QDialog
{
    Q_OBJECT

public:
    explicit MetroStops(QWidget *parent = nullptr);
    ~MetroStops();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MetroStops *ui;
};

#endif // METROSTOPS_H
