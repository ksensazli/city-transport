#ifndef FERRYLINES_H
#define FERRYLINES_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QStringListModel>

namespace Ui {
class FerryLines;
}

class FerryLines : public QDialog
{
    Q_OBJECT

public:
    explicit FerryLines(QWidget *parent = nullptr);
    ~FerryLines();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FerryLines *ui;
};

#endif // FERRYLINES_H
