#include <stdio.h>
#include <math.h>
#include <mshtmlc.h>
double F(double x)
{
    return 2 * pow(x, 2) - 12 * x;
}
double rav_min(double eps){
    double x, fx, temp = 10000000000;
    x = 0;
    while(True){
        if (F(x) < temp){
            temp = x;
        }

        if (x > 1000){
            break;
        }
        x+=eps;
    }
    return temp;
}

double rav_max(double eps){
    double x, fx, temp = -10000000000000;
    x = 0;
    while(True){
        if (F(x) > temp){
            temp = x;
        }

        if (x > 1000){
            break;
        }
        x+=eps;
    }
    return temp;
}

double minn(double x, double l, double eps){
    double a = rav_min(eps) - 5; double b = rav_min(eps) + 5; double y; double z;  double fx; double fy; double fz;
    double L; double c = 0;
    x = (b - a)/2;
    fx = F(x);

    while (True) {

        L = b - a;
        y = a + L/4;
        z = b - L/4;
        fy = F(y);
        fz = F(z);
        if (fy < fx)
        {
            b = x;
            x = y;
        }
        else if (fz < fx){
            a = x;
            x = z;
        }
        else if (fz >= fx){
            a = y;
            b = z;
        }

        if (fabs(b - a) <= l){
            fx = F(x);
            printf("Min Znach = %f\n", fx);

            break;
        }
        else{
            fx = F(x);
            c += 1;
        }
    }
}

double maxx(double x, double l, double eps){
    double a = rav_max(eps) - 5;; double b = rav_max(eps) + 5; double y; double z;  double fx; double fy; double fz;
    double L; double c = 0;
    x = (b - a) / 2;
    fx = F(x);

    while (True) {

        L = b - a;
        y = a + L/4;
        z = b - L/4;
        fy = F(y);
        fz = F(z);
        if (fy > fx)
        {
            b = x;
            x = y;
        }
        else if (fz > fx){
            a = x;
            x = z;
        }
        else if (fz <= fx){
            a = y;
            b = z;
        }

        if (fabs(b - a) <= l){
            fx = F(x);
            printf("Max Znach = %f\n", fx);
            break;
        }
        else{
            fx = F(x);
            c += 1;
        }
    }
}

int main() {
    double x; double l = 1, eps = 1;
    minn(x, l, eps);
    maxx(x, l, eps);
    return 0;
}