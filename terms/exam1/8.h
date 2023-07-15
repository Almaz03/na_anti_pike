#include <iostream>

using namespace std;

int main() {
    int const size = 20;
    int NX;
    cin>>NX;
    if (NX<0 || NX>20) exit(0);
    double a[size];
    double max=a[0];
    double maxil = 0;
    double maxir = 0;
    double tmp;
    for (int i = 0; i<NX;i++){
        cin>>a[i];
        if(a[i]>max) {
            max = a[i];
        }
    }
    for (int i = 0; i<NX;i++){
        if (a[i] == max){
            if (i==NX-1){
                maxil = a[i-1];
                maxir = 0;
            }
            else if (i==0){
                maxir = a[i+1];
                maxil = 0;
            }
            else {
                maxir = a[i+1];
                maxil = a[i-1];

            }

        }
    }
    for (int i = 0; i<NX;i++){
        if (a[i] == max) {
            tmp = a[NX - 1];
            a[NX - 1] = a[i];
            a[i] = tmp;
        }

    }

    cout<<maxil<<" "<< maxir<<endl;
    for (int i = 0; i<NX;i++) cout<<a[i]<<" ";
}

