#ifndef BUSLINES_H
#define BUSLINES_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QStringListModel>
#include <QStandardItem>

namespace Ui {
class BusLines;
}

class BusLines : public QDialog
{
    Q_OBJECT

public:
    explicit BusLines(QWidget *parent = nullptr);
    ~BusLines();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::BusLines *ui;
};

#endif // BUSLINES_H
