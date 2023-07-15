#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x > 5 || y > 5 || x < 0 || y < 0) exit(0);
    int A[5][5], B[25];
    int mini,  maxi;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> A[i][j];
        }
    }
    int  max = A[0][0], min = A[0][0];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {

            if (A[i][j] >= max) {
                max = A[i][j];
            }

            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0, k = 0; j < y; j++, k++) {
            B[k] = A[i][j];
        }
    }
    for (int i = 0; i<x;i++){
        if (max==B[i]) maxi = i;
        if (min==B[i]) mini = i;
        if (maxi == mini +1 || maxi == mini - 1){
            B[maxi] = 0;
            B[mini] = 0;
        }
        if (maxi>mini){
            for (int j = mini +1; j<maxi; j++){
                B[j] = 0;
            }
        }
        if (maxi<mini){
            for (int j = maxi +1; j<mini; j++){
                B[j] = 0;
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0, k = 0; j < y; j++, k++) {
            A[i][j]=B[k] ;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

}

