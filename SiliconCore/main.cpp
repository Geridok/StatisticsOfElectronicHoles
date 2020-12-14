//
// Created by Иван Ильин on 28.11.2020.
//

#include <cmath>
#include <iostream>
#include "Silicon.h"

using namespace std;

double bisection(double f(double x), double a, double b, double tol) {

    double root = (b + a) / 2.0f;

    if (abs(b - a) < tol) // interval already 'found'
        return root;

    do {
        root = (a + b) / 2.0;

        if (f(root) == 0) {
            a = root;
            b = root;
        } else {
            if (f(a) * f(root) > 0)
                a = root;
            else
                b = root;
        }


    } while (f(root) != 0 || abs(b - a) > tol);

    return root;
}

double f(double x) {
    return (x-2)*(x-5)*(x-6);
}

int main() {

    /*
     * Параметры для ввода в модель ( http://www.ioffe.ru/SVA/NSM/Semicond/Si/electric.html#Basic ):
     * 1) E_d - положение уровня донора (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 2) E_g - ширина запрещённой зоны (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 3) E_c - дно зоны проводимости   (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
     * 4) me - эффективная масса носителей заряда (от 1.0e-31 до 10.0e-31)
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
    double me = 1.0f;
    double mh = 1.0f;
    double N_d0 = 10.0f;
    double T_0 = 10.0f;
    double T_1 = 1200.0f;
    */
    double eV = 1.602e-12;
    double me = 9.109e-28;

    double E_g = 1.12 * eV;
    double E_d = E_g - 0.054 * eV;
    double me_eff = 0.36 * me;
    double mh_eff = 0.81 * me;
    double T_0 = 10.0f;
    double T_1 = 1200.0f;

    double N_d0 = 1e15;

    // TODO: solve main equation: F = E_g - E_d - k*T * ln(N_d0/n(F) - 1)
    int NT = 1000;

    Silicon silicon(E_d, E_g, me_eff, mh_eff, N_d0);
    silicon.calculate_F_from_T(T_0, T_1, NT);
    cout << "save data ... " << silicon.saveData() << endl;

    Silicon::plotPNGData();
    Silicon::plotData();


}
