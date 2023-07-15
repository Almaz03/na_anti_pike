#include <iostream>
#include <cmath>

using namespace std;

struct TRec {
    int X;
    double Y, Z;
};

int fact(int x);

int calc_x(int n);

double calc_y(double n);

double calc_z(double n);

TRec create_TRec(TRec trec, int N);

void create_TRec_to_all(TRec *trec, int *N, int n);

void calc_mid_values(TRec *trec, int n);

int main() {

    cout << "Enter size of array: \n";
    int n;
    cin >> n;

    int *N = new int[n];
    cout << "Enter array: \n";
    for (int i = 0; i < n; ++i) {
        cin >> N[i];
    }
    TRec *A;
    A = new TRec[n];

//    for (int i = 0; i < n; ++i) {
//        A[i] = create_TRec(A[i], N[i]);
//
//    }
    create_TRec_to_all(A, N, n);
    calc_mid_values(A, n);
    delete[] A;
    delete[] N;

}

TRec create_TRec(TRec trec, int N) {
    trec.X = calc_x(N);
    trec.Y = calc_y(N);
    trec.Z = calc_z(N);
    return trec;
}

void create_TRec_to_all(TRec *trec, int *N, int n) {
    for (int i = 0; i < n; ++i) {

        trec[i].X = calc_x(N[i]);
        trec[i].Y = calc_y(N[i]);
        trec[i].Z = calc_z(N[i]);
    }
}

void calc_mid_values(TRec *trec, int n) {
    int mid_x = 0;
    double mid_y = 0, mid_z = 0;

    for (int i = 0; i < n; ++i) {
        mid_x += trec[i].X;
        mid_y += trec[i].Y;
        mid_z += trec[i].Z;
    }
    mid_x = mid_x / n;
    mid_y = mid_y / double(n);
    mid_z = mid_z / double(n);

    cout << "Resulit is: \n" << mid_x << endl << mid_y << endl << mid_z << endl;
}

int calc_x(int n) {
    return (fact(n));
}

double calc_y(double n) {
    return (1.0 / (2 * n - 1));
}

double calc_z(double n) {
    return (3 * sin(n));
}

int fact(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    else return x * fact(x - 1);
}