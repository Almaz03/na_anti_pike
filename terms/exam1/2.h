#include<iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int n, m;
    cin >> n >> m;
    int tmp_min, min, tmp_max, max, tmp;
    if (n < 10 && m < 10) {

        int A[SIZE][SIZE];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];

            }
        }

        tmp_min = A[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] < tmp_min) {
                    tmp_min = A[i][j];
                    min = i;
                }


            }
        }

        tmp_max = A[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] > tmp_max) {
                    tmp_max = A[i][j];
                    max = i;
                }


            }
        }

        for (int j = 0; j < m; j++) {

            tmp = A[min][j];
            A[min][j] = A[max][j];
            A[max][j] = tmp;

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

    }

    else cout << 0;
    return 0;
}