//
// Created by Иван Ильин on 01.12.2020.
//

#include "Silicon.h"
#include "gnuplot.h"

double Silicon::effective_state_density(double m_eff, double T) const {
    if(!defined)
        return -1;

    return 2.0f * pow((2.0f * M_PI * m_eff * k * T / pow(2.0f * M_PI * h_bar, 2.0f)), 1.5f);
}

double Silicon::n(double F, double T) const {
    if(!defined)
        return -1;

    return effective_state_density(me, T) * fd1((F - E_g) / (k * T));
}

double Silicon::p(double F, double T) const {
    if(!defined)
        return -1;

    return effective_state_density(mh, T) * fd1(-F / (k * T));
}

void Silicon::calculate_F_from_T(double T_0, double T_1, int NT){
    if(!defined)
        return;

    v_n.clear();
    v_F.clear();
    v_T.clear();

    double dT = (T_1 - T_0) / NT;

    double T = T_0;
    while(T < T_1) {
        /*
        // Метод Ньютона
        double F_N = 0.0f; // искомое F
        double F1_N = 0.7f; // нулевое приближение
        double dF = 0.0001f; // шаг дифференцирования
        int s = 0; // число итераций

        // Real computation (is not workable now)

        while(abs(F_N - F1_N) > tol) {
            F_N = F1_N;
            F1_N = F_N - eq(F_N + dF, T, Nn) / deq(F_N + dF, T, dF, Nn);
            s++;
        }

        // for debug
        //v_F.push_back(E_d * E_g * E_c * me * N_d0 * T * T);
        //v_n.push_back(E_d * E_g * E_c * me * N_d0 * T * sin(T * T / 100.0f));
        //v_T.push_back(T);
        */
        int iter = 0;
        double a = -1.0f * E_g;
        double b = +2.0f * E_g;

        double tol = 1e-6 * E_g;

        double F;

        do {
            F = (a + b) / 2.0;

            if (eq(F, T) == 0) {
                a = F;
                b = F;
            } else {
                if (eq(a, T) * eq(F, T) > 0)
                    a = F;
                else
                    b = F;
            }
            iter++;

        } while (eq(F, T) != 0 && b - a > tol && iter < 1000);

        v_F.push_back(F);
        v_n.push_back(n(F, T));
        v_T.push_back(T);

        T += dT;
    }
}

void Silicon::setParameters(double T_0, double T_1, double E_d, double E_g, double me, double N_d0) {
    this->E_d = E_d;
    this->E_g = E_g;
    this->me = me;
    this->N_d0 = N_d0;
    this->defined = true;

    calculate_F_from_T(T_0, T_1);
}

[[nodiscard]] const std::vector<double>& Silicon::get_F() const {
    return v_F;
}
[[nodiscard]] const std::vector<double>& Silicon::get_n() const {
    return v_n;
}
[[nodiscard]] const std::vector<double>& Silicon::get_T() const {
    return v_T;
}

bool Silicon::saveData() {
    std::ofstream _ofstreamF("F_T.dat");
    std::ofstream _ofstreamN("n_T.dat");

    if (!_ofstreamF.is_open() || !_ofstreamN.is_open() || v_F.size() != v_T.size() || v_n.size() != v_T.size())
        return false;

    for(int i = 0; i < v_T.size(); i++) {
        _ofstreamF << v_T[i] << "\t" << v_F[i] << std::endl;
        _ofstreamN << v_T[i] << "\t" << v_n[i] << std::endl;
    }

    _ofstreamF.close();
    _ofstreamN.close();
    return true;
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