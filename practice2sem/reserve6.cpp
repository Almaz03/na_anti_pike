#include <iostream>
#include <fstream>
#include <cmath>
#include "sofa.h"


void integrator(double *x, double *eps, double dt, int n);
void model(double *x, double *dx);
void graph();

int main() {
    int n;
#define GRAPH2
    #ifdef GRAPH2
    n = 4;
    #endif

    #ifdef GRAPH1
    n = 3;
    #endif

    double dt = 0.0001;
    double *x = new double[n];
    double *eps = new double[n];

    #ifdef GRAPH1
    x[0] = 2.5;
    x[1] = 1.7;
    x[2] = 21;
    eps[0] = 0.01;
    eps[1] = 0.01;
    eps[2] = 0.01;
    #endif

    #ifdef GRAPH2
    x[0] = 0.994;
    x[1] = 0;
    x[2] = 0;
    x[3] = -2.00158510637908252240537862224;
    eps[0] = 0.00001;
    eps[1] = 0.0000001;
    eps[2] = 0.000001;
    eps[3] = 0.000001;
    #endif

    integrator(x, eps, dt, n);
    //graph();

    delete[] x;
    delete[] eps;

    return 0;
}

void integrator(double *x, double *eps, double dt, int n) {
    std::ofstream out("..\\output.csv");
    double *dx1 = new double[n];
    double *xpred = new double[n];
    double *dxpred = new double[n];
    double *x2 = new double[n];
    double *buf = new double[n];
    out << "X[1],X[2]\n";

    for (double t = 0; t < 34; t += dt) {
        out << x[0] << "," << x[1] << "\n";
        //std::cout << x[0] << "," << x[1] << "\n";
        model(x, dx1);

        for (int i = 0; i < n; i++) {
            xpred[i] = x[i] + dt * dx1[i];
            x2[i] = xpred[i];
        }
#define TEST
#ifndef TEST
        bool flag = true;
        do {
            for (int i = 0; i < n; i++) {
                buf[i] = x2[i];
            }

            model(xpred, dxpred);

            for (int i = 0; i < n; i++) {
                x2[i] = x[i] + dt * (dx1[i] + dxpred[i]) / 2;
                buf[i] -= x2[i];
            }

            flag = false;
            for (int i = 0; i < n; i++) {
                if (std::abs(buf[i]) > eps[i]) {
                    flag = true;
                    break;
                }
            }
        } while (flag);
#endif
#ifdef TEST
         bool flag = true;
        while (flag) {
            for (int i = 0; i < n; i++) {
                buf[i] = x2[i];
            }

            model(xpred, dxpred);

            for (int i = 0; i < n; i++) {
                x2[i] = x[i] + dt * (dx1[i] + dxpred[i]) / 2;
                buf[i] -= x2[i];
            }


            for (int i = 0; i < n; i++) {
                if (std::abs(buf[i]) < eps[i]) {
                    flag = false;
                    break;
                }
            }
        };
#endif

        for (int i = 0; i < n; i++) {
            x[i] = x2[i];
        }
    }

    delete[] dx1;
    delete[] xpred;
    delete[] dxpred;
    delete[] x2;
    delete[] buf;

    out.close();
}

void model(double *x, double *dx) {
    #ifdef GRAPH1
    double a = 10, b = 28, c = 8 / 3;
    dx[0] = a * (x[1] - x[0]);
    dx[1] = b * x[0] - x[1] - x[0] * x[2];
    dx[2] = x[0] * x[1] - c * x[2];
    #endif

    #ifdef GRAPH2
    double mu = 0.012277471;
    double dmu = 1 - mu;
    double d1 = std::pow(std::pow(x[0] + mu, 2) + std::pow(x[1], 2), 1.5);
    double d2 = std::pow(std::pow(x[0] - dmu, 2) + std::pow(x[1], 2), 1.5);
    dx[0] = x[2];
    dx[1] = x[3];
    dx[2] = x[0] + 2 * x[3] - dmu * (x[0] + mu) / d1 - mu * (x[0] - dmu) / d2;
    dx[3] = x[1] - 2 * x[2] - dmu * x[1] / d1 - mu * x[1] / d2;
    #endif
}

void graph() {
    system(R"(cd C:\Users\akbar\PycharmProjects\practice2sem && venv\Scripts\activate && python 4ShowGraph.py)");
}
