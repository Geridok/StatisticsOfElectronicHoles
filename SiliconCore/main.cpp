//
// Created by Иван Ильин on 28.11.2020.
//

#include <cmath>
#include <iostream>
#include "Silicon.h"

using namespace std;

int main() {

    /*
     * Параметры для ввода в модель ( http://www.ioffe.ru/SVA/NSM/Semicond/Si/electric.html#Basic ):
     * 1) E_d - положение уровня донора (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 2) E_g - ширина запрещённой зоны (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 3) E_c - дно зоны проводимости   (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 4) m - эффективная масса носителей заряда (от 1.0e-31 до 10.0e-31)
     * 5) N_d0 - концентрация доноров (от 1e15 до 1e22)
     * 6) T_0 - начальная температура (0 до 100)
     * 7) T_1 - конечная температура (T_0 до 100)
     * Все энергии отсчитывает от потолка валентной зоны, только энергия донора вниз от дна зоны проводимости.
     * TODO: Программа переводит все в единицы СГС (или в СИ по желанию).
    */

    /*
    double E_d = 1.0f;
    double E_g = 1.0f;
    double E_c = 1.0f;
    double m = 1.0f;
    double N_d0 = 1.0f;
    double T_0 = 0.0f;
    double T_1 = 100.0f;
    */
    double E_d = 2.0f * 1.60e-19;
    double E_g = 1.5f * 1.60e-19;
    double E_c = 1.5f * 1.60e-19;
    double m = 9.1093837015e-31;
    double N_d0 = 1e22;
    double T_0 = 0.0f;
    double T_1 = 100.0f;

    // TODO: solve main equation: F = E_g - E_d - k*T * ln(N_d0/n(F) - 1)
    int Nn = 1000;
    int NT = 1000;
    double tol = 0.001f;

    Silicon silicon(E_d, E_g, E_c, m, N_d0);
    silicon.calcilate_F_from_T(T_0, T_1, tol, NT, Nn);
    silicon.saveData();

    Silicon::plotPNGData();
    Silicon::plotData();

    //silicon.plot_eq_from_F(-60, 60, 30);
}
