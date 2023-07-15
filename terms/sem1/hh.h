//22/12/2022
#include <iostream>

using namespace std;

int main() {

    int const N = 100;
    int c = 0, d = 0;
    int n; //The defined variable for matrix
    cin >> n;
    int a[N][N]; //array
    int b[N]; //temp array

    if (n <= N) {

        cout<< "Enter Matrix"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        cout<< "Enter Array"<<endl;
        for (int i = 0; i < n; i++){
            cin >>b[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]>a[i][i]){
                    a[i][j] += b[i];
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout << "Number exceed maximum size of matrix";
}