#include "Modellegacy.h"


double Counter::get_s(double s0, double v, double dt, double a) {

    return (s0 + v * dt + ((a * pow(dt, 2)) / 2));
}

void Counter::get_s(double *arr, double *s0, double *v, double *a, double dt) {

    for (int i = 0; i < axis; ++i) {
        arr[i] = (s0[i] + v[i] * dt + ((a[i] * pow(dt, 2)) / 2));
    }

}

double Counter::get_v(double v0, double a, double t) {
    return v0 + a * t;
}

void Counter::get_v(double *arr, double *v0, double *a) {

    for (int i = 0; i < axis; ++i) {
        arr[i] = v0[i] + a[i] * time;
    }
}

void Counter::set_v(int i, double v) {
    this->v[i].push_back(v);
}

void Counter::set_a(int i, double a) {
    this->a[i].push_back(a);
}

void Counter::set_s(int i, double s0, double v, double dt, double a) {
    s[i].push_back(get_s(s0, v, dt, a));
}

void Counter::save_s(std::string filename) {
    std::fstream outfile(filename);

    for (int i = 0; i < axis; ++i) {
        for (auto j: s[i]) {
            outfile << j << std::endl;

        }
    }
}

void Modellegacy::initialize(double *coordinates, double *speed, double *acceleration, double dt, double k) {

    for (int i = 0; i < axis; i++) {
        s[i][0] = coordinates[i];
        a[i][0] = acceleration[i];
        v[i][0] = speed[i];
    }
    int i = 1;
    time = 0;

    while (s[2][i - 1] > 0) {
        for (int j = 0; j < axis; ++j) {

            coordinates[i] = s[j][i];
            acceleration[i] = a[j][i];
            speed[i] = v[j][i];

            get_a(acceleration, speed, time, k);
            get_v(speed, coordinates, acceleration);
            get_s(coordinates, coordinates, speed, acceleration, dt, k);

            s[j][i] = coordinates[i];
            a[j][i] = acceleration[i];
            v[j][i] = speed[i];

        }
        time += dt;
        i++;
    }
}

void Simple::initialize(double *coordinates, double *speed, double *acceleration, double dt, double k) {

    for (int i = 0; i < axis; i++) {
        s[i][0] = coordinates[i];
        a[i][0] = acceleration[i];
        v[i][0] = speed[i];
    }
    int i = 1;
    time = 0;

    while (s[2][i - 1] > 0) {
        for (int j = 0; j < axis; ++j) {

            coordinates[i] = s[j][i];
            acceleration[i] = a[j][i];
            speed[i] = v[j][i];

            get_a(acceleration, speed, time, k);
            get_v(speed, coordinates, acceleration);
            get_s(coordinates, coordinates, speed, acceleration, dt, k);

            s[j][i] = coordinates[i];
            a[j][i] = acceleration[i];
            v[j][i] = speed[i];

        }
        time += dt;
        i++;
    }
}

void Modellegacy::get_a(double *arr, double *v, double t, double k) {

    for (int i = 0; i < axis; ++i) {
        if (i != 2) arr[i] = 0;
        else arr[i] = -G;
    }
}


void Simple::get_a(double *arr, double *v, double t, double k) {

    for (int i = 0; i < axis; ++i) {
        if (i != 0) arr[i] = k * v[i] / t;
        else arr[i] = k * v[i] / t + G;
    }

}
