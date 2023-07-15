#ifndef PRACTICE2SEM_MODEL_H
#define PRACTICE2SEM_MODEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double const M = 5.9736 * std::pow(10, 24);
double const G = 6.67 * std::pow(10, -11);
double const R = 6378000;


class Model {
public:
    std::vector<double> data;
public:
    virtual void calculateAcceleration(std::vector<double> &data, std::vector<double> &datanew, double k);
    double getData(int i);
    std::vector <double> getData();
    void setData(int i, double data);
};

class SimpleModel : public Model {
    void calculateAcceleration(std::vector<double> &data, std::vector<double> &datanew, double k);
};

class Counter {

public:
    double calculateCoordinates(double s0, double v, double dt, double a);

    double calculateSpeed(double v0, double a, double t);

    void count(std::string filename, double t, double dt, std::vector<double> data,
               Model *model, double k);
};
#endif //PRACTICE2SEM_MODEL_H
