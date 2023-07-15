#include <iostream>

using namespace std;

int main() {
    int N = 100;
    int n; //The defined variable for matrix
    cin >> n;
    int a[N][N]; //array
    if (n <= N) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        bool flag = true;
        while (flag) {

            int i = 0, j = 0, c = 0;
            while (j < n - 1) {
                while (i < n - 1) {
                    if (a[i][j] > a[i + 1][j]) {
                        c = a[i][j];
                        a[i][j] = a[i + 1][j];
                        a[i + 1][j] = c;
                        flag = false;
                    }
                    i++;
                }
                if (i == n - 1) {
                    if (a[i][j] > a[0][j + 1]) {
                        c = a[i][j];
                        a[i][j] = a[0][j + 1];
                        a[0][j + 1] = c;
                        flag = false;
                    }
                    i = 0;
                    j++;

                }

                if (j == n - 1) {
                    for (int k = 0; k < n; k++) {
                        for (int i_2 = 0; i_2 < n - 1; i_2++) {
                            if (a[i_2][j] > a[i_2 + 1][j]) {
                                c = a[i_2][j];
                                a[i_2][j] = a[i_2 + 1][j];
                                a[i_2 + 1][j] = c;
                                flag = false;

                            }
                        }

                    }
                }


            }
            if (not(flag)) flag = true;
            else break;
        }
        int c;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                c = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = c;
            }
        }
        int d;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                d = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = d;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
