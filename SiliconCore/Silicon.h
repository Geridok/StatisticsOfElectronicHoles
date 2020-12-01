//
// Created by Иван Ильин on 01.12.2020.
//

#ifndef SILICONCORE_SILICON_H
#define SILICONCORE_SILICON_H

#include "vemath.h"
#include "gnuplot.h"

using namespace vemath;

class Silicon {
private:
    /*
    // Физические константы:
    double h = 1.0f;
    double k = 1.0f;
    */
    double h = 6.62607015e-34;
    double k = 1.380649e-23;

    /*
     * Параметры для ввода в модель ( http://www.ioffe.ru/SVA/NSM/Semicond/Si/electric.html#Basic ):
     * 1) E_d - положение уровня донора
     * 2) E_g - ширина запрещённой зоны
     * 3) E_c - дно зоны проводимости
     * 4) m - эффективная масса носителей заряда
     * 5) N_d0 - концентрация доноров (задаётся от 10^15 до 10^22 на cm^3)
     * 6) T_0 - начальная температура
     * 7) T_1 - конечная температура
     * Все энергии отсчитывает от потолка валентной зоны, только энергия донора вниз от дна зоны проводимости.
     * TODO: Программа переводит все в единицы СГС (или в СИ по желанию).
    */

    double E_d;
    double E_g;
    double E_c;
    double m;
    double N_d0;

    ComplexPlot F_T; // dependence F on T
    ComplexPlot n_T; // dependence n on T

    ComplexPlot eq_F; // dependence eq on F

    [[nodiscard]] double f_mult_g(double E, double F, double T) const {
        return 1.0f/(2.0f*M_PI*M_PI)*pow(2.0f*m/(h*h), 1.5f) * sqrt(E - E_c)/(exp((E - F) / (k*T)) + 1);
    }

    double eq(double F, double T, int Nn = 1000) {
        return E_g - E_d - k*T*log(N_d0/n(F, T, Nn) - 1) - F;
    }

    double deq(double F, double T, double dF = 0.0001f, int Nn = 1000){
        double eq2 = eq(F + dF, T, Nn);
        double eq1 = eq(F - dF, T, Nn);

        return (eq2 - eq1) / (2.0f * dF);
    }

public:
    Silicon(double E_d, double E_g, double E_c, double m, double N_d0)
    {
        this->E_d = E_d;
        this->E_g = E_g;
        this->E_c = E_c;
        this->m = m;
        this->N_d0 = N_d0;
    }

    double n(double F, double T, int N = 1000);

    void calcilate_F_from_T(double T_0, double T_1, double tol = 0.001f, int NT = 1000, int Nn = 1000);

    void plot_eq_from_F(double F0, double F1, double T, int NF = 1000, int Nn = 1000);

    bool saveData();

    static void plotData();

    static void plotPNGData();

};


#endif //SILICONCORE_SILICON_H
