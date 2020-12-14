#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QPixmap>
#include "adapterforvectozavr.h"
#include "../SiliconCore/Silicon.h"
#include <memory>
#include "../Time/Time.h"
#include "savewindow.h"
#include "information.h"
namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();
    void foo(){

    };

private slots:

    void on_E_gSlider_valueChanged(int value);

    void on_E_dSlider_valueChanged(int value);

    void on_N_d0Slider_valueChanged(int value);

    void on_T_0Slider_valueChanged(int value);

    void on_T_1Slider_valueChanged(int value);

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void on_logScaleButton_clicked();

private:
    Ui::Application *ui;
    std::shared_ptr<Silicon> solver;
    QVector<double> F;
    QVector<double> T;
    QVector<double> n;
    QVector<double> TP;
    QVector<double> E_dP;
    QVector<double> E_gP;
private:
    //Multipliers
    double multiplier_E_d = 1.602e-12;
    double multiplier_E_g = 1.603e-12;
    //Changeble values
    double E_d = 0;
    double E_g = 1.12 * 1.602e-12;
    double N_d0 = 1.0e15;
    double N_d0Pow = 1.0e16;
    int T_0 = 50.0f;
    int T_1 = 1200.0f;
    //const Value
    //func
    void setInitialValue();
    void setSlidersLimit();
    void updateGraph();
    void reculculate();
};

#endif // APPLICATION_H
