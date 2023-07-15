#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int x;
    cin >> x;
    long int a = x;
    short int b = x;
    double c = x;
    float d = x;
    cout << "1. = " << "x=" << x << endl;
    cout << "1. = " << "a=" << a << endl;
    cout << "1. = " << "b=" << b << endl;
    cout << "1. = " << "c=" << c << endl;
    cout << "1. = " << "d =" << d << endl;
    const double e = 47.1 * pow(10,2);
    const float f = 6.73;
    const int g = 66003;
    int(x + g);
    float(d + f + e);
    double hui = (c + f);
    cout << std::setprecision(20)<< "2. = "  << x + g << endl << "3. = " << d + f + e << endl << "4. = " << hui << endl;
    long int g1;
    g1 = b - a;
    long int g2;
    g2 = b - c;
    double g3;
    g3 = b - d;
    float g4;
    g4 = b - e;
    cout << "6. = " << g1 << endl << "6. = " << g2 << endl << "6. = " << g3 << endl << "6. = " << g4;
}