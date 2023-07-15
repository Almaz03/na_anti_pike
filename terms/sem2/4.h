#include <iostream>
#include <cmath>

typedef double (*function)(double);

typedef double (*main_function)(double start, double end, double step, function func);

using namespace std;

double (*which_func)(double start, double end, double step, function func);

double func(double x);

double left_rectangle(double start, double end, double step, function func);

double right_rectangle(double start, double end, double step, function func);

double trap(double start, double end, double step, function func);

double isn();

double method(main_function final_func, function func) {

    double t0, t1, h;
    cout << "Enter start: " << endl;
    cin >> t0;
    cout << "Enter end: " << endl;
    cin >> t1;
    cout << "Enter step: " << endl;
    cin >> h;

    return (final_func(t0, t1, h, func));

}


int main() {


    short choose;
    cout << "Enter method, 1 - left_rectangle, 2 - right rectangle, 3 - trap: " << endl;
    cin >> choose;
    switch (choose) {
        case 1:
            cout << method(left_rectangle, func);
            break;
        case 2:
            cout << method(main_function(right_rectangle), function(func));
            break;
        case 3:
            cout << method(main_function(trap), function(func));
            break;
        default:
            cout << "Wrong choice, left reactangle method set as default" << endl;
            which_func = left_rectangle;
    }
    return 0;

}

double func(double x) {
    return (sin(x) * cos(x)) / (5 + x);
}

double isn(double t0, double t1, double h) {
    return (t1 - t0) / h;
}

double isti(double t0, int i, double h) {
    return t0 + i * h;
}

double left_rectangle(double start, double end, double step, double (*func)(double)) {
    double res = 0;

    for (int i = 0; isn(start, end, step) - 1 >= i; i++) {
        res += step * func(isti(start, i, step));

    }
    return res;
}

double right_rectangle(double start, double end, double step, double (*func)(double)) {
    double res = 0;
    for (int i = 0; isn(start, end, step) - 1 >= i; i++) {
        res += step * func(isti(start, i + 1, step));

    }
    return res;
}

double trap(double start, double end, double step, double (*func)(double)) {
    double res = 0;
    for (int i = 0; isn(start, end, step) - 1 >= i; i++) {
        res += step / 2 * (func(isti(start, i, step)) + func(isti(start, i + 1, step)));

    }
    return res;
}
