#include <iostream>
using namespace std;
int main(){
    int const N = 10;
    int a[N][N][N][N];
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
    if (n<N){
        cout << "Enter Matrix"<<endl;
        for (int u = 0; u,n; u++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cin >> a[u][i][j][k];
                    }
                }
            }
        }
        cout << "Matrix"<<endl;
        for (int u = 0; u<n; u++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cout << a[u][i][j][k];
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
            cout<<endl;
        }

    }
}