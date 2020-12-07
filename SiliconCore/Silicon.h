//
// Created by Иван Ильин on 01.12.2020.
//

#ifndef SILICONCORE_SILICON_H
#define SILICONCORE_SILICON_H

#include "gnuplot.h"
#include "FermiDirac.h"

class Silicon {
private:
    /*
    // Физические константы:
    double h = 1.0f;
    double k = 1.0f;
    */
    bool defined = false;

    double h = 6.626e-27;
    double h_bar = 1.055e-27;
    double k = 1.381e-16;

    /*
     * Параметры для ввода в модель ( http://www.ioffe.ru/SVA/NSM/Semicond/Si/electric.html#Basic ):
     * 1) E_d - положение уровня донора
     * 2) E_g - ширина запрещённой зоны
     * 3) E_c - дно зоны проводимости
     * 4) me - эффективная масса носителей заряда
     * 5) N_d0 - концентрация доноров (задаётся от 10^15 до 10^22 на cm^3)
     * 6) T_0 - начальная температура
     * 7) T_1 - конечная температура
     * Все энергии отсчитывает от потолка валентной зоны, только энергия донора вниз от дна зоны проводимости.
     * TODO: Программа переводит все в единицы СГС (или в СИ по желанию).
    */

    double E_d = 0;
    double E_g = 0;
    double me = 0;
    double mh = 0;
    double N_d0 = 0;

    std::vector<double> v_F;
    std::vector<double> v_n;
    std::vector<double> v_T;

    std::vector<double> v_eq; // dependence eq on F

    [[nodiscard]] double eq(double F, double T) const {
        //return N_d0 * 1.0f / (1.0f + exp((E_g - E_d - F) / (k*T))) - n(F, T);
        return p(F, T) - n(F, T);
    }

public:
    Silicon(double E_d, double E_g, double me, double mh, double N_d0)
    {
        this->E_d = E_d;
        this->E_g = E_g;
        this->me = me;
        this->mh = mh;
        this->N_d0 = N_d0;
        this->defined = true;
    }

    Silicon() {
        this->defined = false;
    }

    [[nodiscard]] double n(double F, double T) const;
    [[nodiscard]] double p(double F, double T) const;

    [[nodiscard]] double effective_state_density(double m_eff, double T) const;

    void calculate_F_from_T(double T_0, double T_1, int NT = 1000);

    // qt style
    void setParameters(double T_0, double T_1, double E_d, double E_g, double m, double N_d0);
    [[nodiscard]] const std::vector<double>& get_F() const;
    [[nodiscard]] const std::vector<double>& get_n() const;
    [[nodiscard]] const std::vector<double>& get_T() const;

    // gnuplot style
    bool saveData();
    static void plotData();
    static void plotPNGData();
};


#endif //SILICONCORE_SILICON_H
