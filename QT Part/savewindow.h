#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include "qcustomplot.h"
#include "qcpdocumentobject.h"

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *parent = nullptr);
    SaveWindow(QCustomPlot *F_T,QCustomPlot *n_T,QVector<double> F, QVector<double> T, QVector<double> n, QWidget *parent = nullptr);
    ~SaveWindow();

private slots:


    void on_saveGraphButtons_clicked();

    void on_saveToTxtButton_clicked();

private:
    //variable
    Ui::SaveWindow *ui;
    QCustomPlot *F_T;
    QCustomPlot *n_T;
    QVector<double> F;
    QVector<double> T;
    QVector<double> n;
    //func
    void insertGraphics();
};

#endif // SAVEWINDOW_H
