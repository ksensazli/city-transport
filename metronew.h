#ifndef METRONEW_H
#define METRONEW_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QFile>

namespace Ui {
class MetroNew;
}

class MetroNew : public QDialog
{
    Q_OBJECT

public:
    explicit MetroNew(QWidget *parent = nullptr);
    ~MetroNew();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MetroNew *ui;
};

#endif // METRONEW_H
