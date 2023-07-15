#include <iostream>
№

using namespace std;

int main() {
    int N = 100, c , d, e;
    int n; //The defined variable for matrix
    cin >> n;
    int a[N][N]; //array
    if (n <= N) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        for ( int k = 0; k < (n*n-1); k++){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (i == n-1 && j == n-1){
                        continue;
                    }
                    if (a[i][j]>a[i][j+1]){
                        c = a[i][j];
                        a[i][j] = a[i][j+1];
                        a[i][j+1]= c;
                    }
                    if (a[i][j] > a[0][j + 1]) {
                        d = a[i][j];
                        a[i][j] = a[0][j + 1];
                        a[0][j + 1] = d;
                    }
                    if (a[i][j] > a[i + 1][j]) {
                        e = a[i][j];
                        a[i][j] = a[i + 1][j];
                        a[i + 1][j] = e;

                    }
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
}


/*enum  Govno {fuck_azama = -10000, hui_azama, kall_azama = 100000000000, nadel_odezdu};
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
    cout<<her_1.hui<<"\n"<<her_1.procent_pidarasa<<endl;
    cout<<her_2.hui<<endl;





}*/