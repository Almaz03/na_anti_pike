#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void graph(string filename);

void func1(double *data, double *ddata, int size);

void func2(double *data, double *ddata, int size);

void integrate(string filename, double *data, double *eps, int size, double start, double end, double step,
               void (*func)(double *data, double *ddata, int size));


int main() {


#define GRAPH1
    string filename = R"(C:\Users\akbar\CLionProjects\practice2sem\output.csv)";
    double start = 0, end = 30, step = 0.0001;
    int size;


#ifdef GRAPH1
    size = 3;
#endif
#ifdef GRAPH2
    size = 4;
#endif
    

    double *data = new double[size];
    double *eps = new double[size];

#ifdef GRAPH1
    data[0] = 2.1;
    data[1] = 1.5;
    data[2] = 15;
    eps[0] = 0.001;
    eps[1] = 0.001;
    eps[2] = 0.001;
    integrate(filename, data, eps, size, start, end, step, func1);

#endif

#ifdef GRAPH2
    data[0] = 0.994;
    data[1] = 0;
    data[2] = 0;
    data[3] = -2.00158510637908252240537862224;
    eps[0] = 0.00001;
    eps[1] = 0.0000001;
    eps[2] = 0.000001;
    eps[3] = 0.000001;
    integrate(filename, data, eps, size, start, end, step, func2);
#endif

    graph(filename);

    delete[] data;
    delete[] eps;
}

void integrate(string filename, double *data, double *eps, int size, double start, double end, double step,
               void (*func)(double *data, double *ddata, int size)) {
    ofstream outfile(filename);

    double *ddata = new double[size];
    double *pdata = new double[size];
    double *pddata = new double[size];
    double *data2 = new double[size];
    double *tmp = new double[size];

    outfile << "X[1],X[2]\n";

    for (double i = start; i < end; i += step) {

        outfile << data[0] << "," << data[1] << "\n";

        func(data, ddata, size);

        for (int j = 0; j < size; ++j) {
            pdata[j] = data[j] + step * ddata[j];
            data2[j] = pdata[j];
        }
        bool flag = true;
        while (flag) {
            for (int j = 0; j < size; ++j) {
                tmp[j] = data2[j];
            }
            func(pdata, pddata, size);

            for (int j = 0; j < size; ++j) {
                data2[j] = data[j] + step * (ddata[j] + pddata[j]) / 2;
                tmp [j] -= data2[j];
            }


            for (int j = 0; j < size; ++j) {
                if (fabs(tmp[j]) < eps[j]) {
                    flag = false;
                    break;
                }
            }

        }
        for (int j = 0; j < size; ++j) {
            data[j] = data2[j];
        }


    }


    delete[] ddata;
    delete[] pdata;
    delete[] pddata;
    delete[] data2;
    delete[] tmp;

    outfile.close();

}

void graph(string filename) {

    std::string command = R"(cd C:\Users\akbar\PycharmProjects\practice2sem && venv\Scripts\activate && python 6ShowGraph.py )";
    command += filename;


    int exitCode = std::system(command.c_str());

    if (exitCode != 0) {
        std::cout << "Error" << std::endl;
    }
}
void func1(double *data, double *ddata, int size) {
    //ATTRACTOR OF LORENCE

    double a = 10, b = 28, c = 8. / 3;
    ddata[0] = a * (data[1] - data[0]);
    ddata[1] = b * data[0] - data[1] - data[0] * data[2];
    ddata[2] = data[0] * data[1] - c * data[2];
}

void func2(double *data, double *ddata, int size) {
    //ORBITS OF ARENSTORF

    double mu = 0.012277471;
    double dmu = 1 - mu;
    double d1 = std::pow(std::pow(data[0] + mu, 2) + std::pow(data[1], 2), 1.5);
    double d2 = std::pow(std::pow(data[0] - dmu, 2) + std::pow(data[1], 2), 1.5);
    ddata[0] = data[2];
    ddata[1] = data[3];
    ddata[2] = data[0] + 2 * data[3] - dmu * (data[0] + mu) / d1 - mu * (data[0] - dmu) / d2;
    ddata[3] = data[1] - 2 * data[2] - dmu * data[1] / d1 - mu * data[1] / d2;
}


#ifdef TEST
double integrate(string filename, double x, double eps, double h, double (*func)(double x), double (*pfunc)(double x)) {
    ofstream file(filename);
    double x_p;

    x_p = func(x) + (h * pfunc(x));
    x = func(x) + (h / 2) * (pfunc(x_p) - pfunc(x));


    do {

        x_p = func(x) + (h / 2) * (pfunc(x_p) - pfunc(x));
        x = func(x) + (h / 2) * (pfunc(x) - pfunc(x_p));

        cout << x << " " << func(x) << endl;
        file << x << " " << func(x) << endl;
    } while
            (fabs(x - x_p) > eps);
    file.close();
    return 0;

}
#endif