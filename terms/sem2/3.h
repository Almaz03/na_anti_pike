#include <iostream>
#include <cmath>

using namespace std;

double slag();

void sum(int N, double x);

int fact();

int main() {
    double x;
    int N;
    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter N:" << endl;
    cin >> N;
    sum(N, x);
    return 0;
}


double slag(double x, double i) {
    double res;
    res = pow(-1, i - 1) * ((i - 1) / fact(i)) * pow(x, i);
    return res;

}

void sum(int N, double x) {
    double res = 1;
    cout << "\ni \tslag" << endl;
    for (int i = 1; i <= N; i++) {
        res += slag(x, i);
        cout << i << "\t" << slag(x, i) << endl;
    }
    cout << "\nres: " << res << endl;
}

int fact(int i) {
    if (i < 0) return 0;
    if (i == 0) return 1;
    else return i * fact(i - 1);

}
