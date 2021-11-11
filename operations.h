#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>

namespace Ui {
class Operations;
}

class Operations : public QDialog
{
    Q_OBJECT

public:
    explicit Operations(QWidget *parent = nullptr);
    ~Operations();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Operations *ui;
};

#endif // OPERATIONS_H
