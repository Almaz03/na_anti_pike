#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int **p;
    int a[10], b[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    p = new int *[10];

    for (int i = 0; i < 10; i++) {
        p[i] = new int[a[i]];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i]; j++) {
            p[i][j] = rand() % 20;
        }
    }
    int min;
    for (int i = 0; i < 10; i++) {
        min = *p[i];
        for (int j = 0; j < a[i]; j++) {
            if (p[i][j] < min) {
                min = p[i][j];
            }
        }
        b[i] = min;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;

    }
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
    for (int i = 0; i < 10; i++) {
        delete[]p[i];
    }
    delete[]p;
}
