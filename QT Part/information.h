#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>

static int pornCount = 1;

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_OkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Information *ui;
    //if u want to relax pres tutorial more than three times))))
};

#endif // INFORMATION_H
