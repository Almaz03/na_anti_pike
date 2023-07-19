#include "stdio.h"
#include "sofa/20210512/c/src/sofa.h"

int main() {

    double k;



    k = iauS00b(2460133.02388, 2460129.02388);
    printf_s("%lf\n", k);


    k = iauS00b(2450123.7, 0.);
    printf("%lf\n", k);


    k = iauS00b(2450123.5, 0.2);
    printf("%lf\n", k);


    return 0;
}