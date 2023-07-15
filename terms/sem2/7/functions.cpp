#include <cmath>
#include <iostream>
#include "functions.h"
#include <fstream>
#include <iomanip>

using namespace std;

int fact(int i) {
    if (i < 0) return 0;
    if (i == 0) return 1;
    else return i * fact(i - 1);
}

double slag(double x, int i) {
    if (i == 1) return 1;
    return (-1 * ((pow(x, i) * slag(x, i - 1)) / (i * pow(2, i))));
}

double sum(int n, double x, double &pres) {
    ofstream twofile("..\\out2.txt");
    ofstream file("..\\out.txt", ios::out | ios::binary);
    double *result;
    result = new double[n];
    double res = 0;
    int j = 0;
    for (int i = 1; i <= n; i++, j++) {
        if (i == 1) {
            res = 1;
            result[j] = res;
            twofile <<left<<setw(16)<< result[i];
        } else {
            res += slag(x, i);
            result[j] = res;
            file.write((char *) &(result[j]), sizeof(double));
            twofile <<left<<setw(16)<< result[j];
        }
    }
    file.close();
    delete[]result;
    return res;
}
