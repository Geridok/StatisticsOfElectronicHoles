#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QPixmap>
#include "adapterforvectozavr.h"
#include "../SiliconCore/Silicon.h"
#include <memory>
namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private slots:

    void on_E_gSlider_valueChanged(int value);

    void on_E_dSlider_valueChanged(int value);

    void on_E_cSlider_valueChanged(int value);

    void on_mSlider_valueChanged(int value);

    void on_N_d0Slider_valueChanged(int value);

    void on_T_0Slider_valueChanged(int value);

    void on_T_1Slider_valueChanged(int value);

    void on_cancelButton_clicked();

    void on_ApplyButton_clicked();

private:
    Ui::Application *ui;
    std::shared_ptr<Silicon> solver;
private:
    //Multipliers
    double multiplier_E_d = 1.6e-19;
    double multiplier_E_g = 1.6e-19;
    double multiplier_E_c = 1.6e-19;
    double multiplier_m = 1.0e-36;
    //Changeble values
    double E_d = 1.6e-19;
    double E_g = 1.6e-19;
    double E_c = 1.6e-19;
    double m = 1.0e-36;
    double N_d0 = 1.0e15;
    double N_d0Pow = 15;
    int T_0 = 0;
    int T_1 = 50;
    //const Value
    int Nn = 1000;
    int NT = 1000;
    double tol = 0.001;
    //func
    void setInitialValue();
    void setSlidersLimit();
};

#endif // APPLICATION_H
