#ifndef PRACTICE2SEM_MODELLEGACY_H
#define PRACTICE2SEM_MODELLEGACY_H

#include <vector>
#include <cmath>
#include <string>
#include <fstream>

const double G = 9.81;

class Counter {
protected:
    int axis;
    std::vector<std::vector<double>> v;
    std::vector<std::vector<double>> a;
    std::vector<std::vector<double>> s;
    double time;

public:
    Counter() = default;

    ~Counter() = default;


    double get_s(double s0, double v, double dt, double a);

    void get_s(double *arr, double *s0, double *v, double *a, double dt);

    double get_v(double v0, double a, double t);

    void get_v(double *arr, double *v0, double *a);

    void set_v(int i, double v);

    void set_s(int i, double s0, double v, double dt, double a);

    void set_a(int i, double a);

    virtual void get_a(double *arr, double *v, double t, double k) = 0;

    virtual void
    initialize(double *initial_coordintaes, double *initial_speed, double *initial_acceleration, double dt, double k) {

    }

    double get_i_s(int axis, int i);

    double get_i_v(int axis, int i);

    double get_i_a(int axis, int i);

    double get_s(double *arr, double *s0, double *v, double *a, double dt, double k);

    void save_s(std::string filename);
};

class Modellegacy : public Counter {
public:
    Modellegacy(int axis) {
        this->axis = axis;
    };

    Modellegacy() = default;

    ~Modellegacy() = default;

    void get_a(double *arr, double *v, double t, double k);

    void initialize(double *initial_coordintaes, double *initial_speed, double *initial_acceleration, double dt, double k);

    //void get_s(double *arr, double *s0, double *v, double *a);
    //double get_s(double s0, double v, double dt, double a);
};

class Simple : public Counter {
public:

    Simple() = default;

    ~Simple() = default;

    Simple(int axis) {
        this->axis = axis;
    };

    void get_a(double *arr, double *v, double t, double k);

    void initialize(double *coordinates, double *speed, double *acceleration, double dt, double k);
};

#endif //PRACTICE2SEM_MODELLEGACY_H
