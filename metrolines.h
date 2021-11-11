#ifndef METROLINES_H
#define METROLINES_H

#include <QDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QStringListModel>

namespace Ui {
class MetroLines;
}

class MetroLines : public QDialog
{
    Q_OBJECT

public:
    explicit MetroLines(QWidget *parent = nullptr);
    ~MetroLines();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MetroLines *ui;
};

#endif // METROLINES_H
