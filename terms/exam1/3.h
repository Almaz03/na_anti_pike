#include<iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int n, m;
    cin >> n >> m;
    int tmp_min, min, tmp_max, max, B[10],tmp;
    if (n < 10 && m < 10) {

        int A[SIZE][SIZE];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];

            }
        }
//
//        for (int i = 0; i < n; i++) {
//            tmp = 0;
//            for (int j = 0; j < m; j++) {
//                tmp +=A[i][j]*A[i][j];
//
//            }
//            B[i] = tmp;
//        }
//        for (int i = 0, k = n-1; i < n; i++, k--) {
//            A[i][k] = B[i];
//        }
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                cout << A[i][j] << " ";
//            }
//            cout << endl;

//        }
        for (int i = 0 ;i<n; i++ ){
            for (int j = 0, k = m-1; j<m;j++, k--){
                A[j][j] = A[i][k];
            }
        }
        for (int i = 0 ;i<n; i++ ){
            for (int j = 0; j<m;j++){
                cout<<A[i][j];
            }
        }


    }

    else cout << 0;
    return 0;
}