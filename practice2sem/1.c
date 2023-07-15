#include <stdio.h>
#include <math.h>

double const LIMIT = 100000000;

struct limits {
    double a, b;
};

double func(double x) {
    return x * x;
}

double x_i(double x, int i, double eps) {
    return x + i * eps;
}

struct limits findGlobalMinimum(double a, double b, double eps, double (*func)(double x)) {
    int i = 0;
    struct limits limit;
    eps = (b - a) /LIMIT;

    while (func(x_i(a, i + 1, eps)) <= func(x_i(a, i, eps)) && x_i(a, i, eps) < b) {
        a += eps;
        i++;
    }
    limit.a = x_i(a, i - 1, eps);
    limit.b = x_i(a, i + 1, eps);
    //printf("Min global limits:%lf, %lf\n", limit.a, limit.b);

    return limit;
}


struct limits findGlobalMaximum(double a, double b, double eps, double (*func)(double x)) {
    int i = 0;
    struct limits limit;
    eps = (b - a) * 0.01;

    while (func(x_i(a, i + 1, eps)) >= func(x_i(a, i, eps)) && x_i(a, i, eps) < b) {
        a += eps;
        i++;
    }
    limit.a = x_i(a, i - 1, eps);
    limit.b = x_i(a, i + 1, eps);
    //printf("Max Global limits:%lf, %lf\n", limit.a, limit.b);

    return limit;
}

double findMinimum(double a, double b, double epsilon, double (*func)(double x)) {
    double c;
    struct limits limit = findGlobalMinimum(a, b, epsilon * 10, func);
    a = limit.a;
    b = limit.b;

    while ((b - a) > epsilon) {
        c = (a + b) / 2.0;

        if (func(c) < func(b))
            b = c;
        else
            a = c;
    }

    return (a + b) / 2.0;
}


double findMaximum(double a, double b, double epsilon, double (*func)(double x)) {
    double c;
    struct limits limit = findGlobalMaximum(a, b, epsilon * 10, func);
    a = limit.a;
    b = limit.b;

    while ((b - a) > epsilon) {
        c = (a + b) / 2.0;

        if (func(c) > func(b))
            b = c;
        else
            a = c;
    }

    return (a + b) / 2.0;
}

int main() {
    printf("1. Find MIN and MAX of the function\n\n");
    double a, b, epsilon;
    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter precision epsilon: ");
    scanf("%lf", &epsilon);


    double min = findMinimum(a, b, epsilon, func);
    double max = findMaximum(a, b, epsilon, func);

    printf("Max: %lf\n", max);
    printf("Min: %lf\n", min);


    return 0;
}
