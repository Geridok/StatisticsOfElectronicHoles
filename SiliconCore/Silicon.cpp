//
// Created by Иван Ильин on 01.12.2020.
//

#include "Silicon.h"
#include "gnuplot.h"

double Silicon::n(double F, double T, int N) {
    double inf = 1000.0f * E_c;

    double dE = (inf - E_c) / N;
    double E = E_c;

    double S = 0.0f;

    while (E < inf) {
        S += f_mult_g(E, F, T) + 4.0f*f_mult_g(E + dE/2.0f, F, T) + f_mult_g(E + dE, F, T);
        E += dE;
    }

    return S * dE / 6.0f;
}

void Silicon::calcilate_F_from_T(double T_0, double T_1, double tol, int NT, int Nn){
    F_T.clear();
    n_T.clear();

    double dT = (T_1 - T_0) / NT;

    double T = T_0;
    while(T < T_1) {
        // Метод Ньютона
        double F_N = 0.0f; // искомое F
        double F1_N = 0.7f; // нулевое приближение
        double dF = 0.0001f; // шаг дифференцирования
        int s = 0; // число итераций

        while(abs(F_N - F1_N) > tol) {
            F_N = F1_N;
            F1_N = F_N - eq(F_N + dF, T, Nn) / deq(F_N + dF, T, dF, Nn);
            s++;
        }
        F_T.push(T, F_N);
        n_T.push(T, n(F_N, T, Nn));

        T += dT;
    }
}

void Silicon::plot_eq_from_F(double F0, double F1, double T, int NF, int Nn) {
    eq_F.clear();
    double F = F0;
    double dF = (F1 - F0) / NF;

    while(F < F1) {
        eq_F.push(F, eq(F, T, Nn));
        F += dF;
    }

    saveVectorPoint2DToFile(eq_F.real(), "eq_F.dat");
    GnuplotPipe gp;
    gp.sendLine(R"(plot "eq_F.dat" with lines)");
}

void Silicon::setParameters(double T_0, double T_1, double E_d, double E_g, double E_c, double m, double N_d0) {
    this->E_d = E_d;
    this->E_g = E_g;
    this->E_c = E_c;
    this->m = m;
    this->N_d0 = N_d0;

    calcilate_F_from_T(T_0, T_1);
}
[[nodiscard]] std::vector<std::pair<double, std::complex<double>>> Silicon::get_F_T() {
    return F_T.v_c;
}
[[nodiscard]] std::vector<std::pair<double, std::complex<double>>> Silicon::get_n_T() {
    return n_T.v_c;
}

bool Silicon::saveData() {
    return saveVectorPoint2DToFile(F_T.real(), "F_T.dat") && saveVectorPoint2DToFile(n_T.real(), "n_T.dat");
}

void Silicon::plotData() {
    GnuplotPipe gp;
    gp.sendLine(R"(set multiplot layout 2,1)");
    gp.sendLine(R"(plot "F_T.dat" with lines)");
    gp.sendLine(R"(plot "n_T.dat" with lines)");
}

void Silicon::plotPNGData() {
    GnuplotPipe gp;
    gp.sendLine(R"(set term png)");
    gp.sendLine(R"(set output "f_from_t.png")");
    gp.sendLine(R"(plot "F_T.dat" with lines)");
    gp.sendLine(R"(unset output)");

    gp.sendLine(R"(set term png)");
    gp.sendLine(R"(set output "n_from_t.png")");
    gp.sendLine(R"(plot "n_T.dat" with lines)");
    gp.sendLine(R"(unset output)");
}