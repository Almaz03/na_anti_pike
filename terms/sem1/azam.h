#include <iostream>

using namespace std;

/*int main() {
    int const N = 100;
    bool flag, flag_e = false;
    int n; //The defined variable for matrix
    cout<<"Enter matrix size of matrix"<<endl;
    cin >> n;
    int a[N][N]; //array
    int b[N][N]; //array
    int min_a = a[0][0];
    int min_b = b[0][0];
    int c = 0, d = 0, e = 0;

    if (n <= N) {

        cout<<"Enter matrix A"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        cout<<"Enter matrix B"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i!=j && a[i][j]<0 && b[i][j]<0){
                    c += a[i][j];
                    d += b[i][j];
                    if (c>d){
                        flag = true;
                    }
                    else if (c==d){
                       min_a = min(a[i][j], min_a);
                       min_b = min(b[i][j], min_b);
                       e = min_a-min_b;
                       flag_e = true;
                    }
                    else flag = false;


                }
            }
        }
        if (flag){
            cout<<"Matrix A > Matrix B"<<endl;
        }
        else if (flag_e){
            cout<<"Matrix A = Matrix B and difference is "<<e<<endl;
        }
        else cout<<"Matrix B > Matrix A"<<endl;

    }
}*/


enum  Govno {fuck_azama = -10000, hui_azama, kall_azama = 100000000000, nadel_odezdu};
struct Azam {
    int hui;
    int vozrast;
    int ves;
    int procent_pidarasa;

};

int main(){
    Govno kall = kall_azama;
    cout<<fuck_azama<<"\n";
    cout<<hui_azama<<"\n";
    cout<<kall<<endl;
    cout<<nadel_odezdu;
    cout<<"Zdes zakOnchivaetsya enum"<<endl;

    Azam her_1 = {
            srand(9), 18, 70, 99
    };
    Azam her_2 = {11, 17, 65, 98

    };