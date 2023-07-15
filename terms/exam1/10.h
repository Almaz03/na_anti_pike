#include <iostream>
#include <string>


using namespace std;


int main() {
    string a[10];
    int nx;
    nx = 2;
    int ss = 0, se = 0;
    char els,ele;
    if (nx < 0 || nx > 10) {
        cout << 0;
        exit(0);
    }
    for (int i = 0; i < nx+1; i++) {
        getline(cin, a[i], '\n');
        a[i].append(" ");
    }
    for (int i = 0; i < nx+1; i++) {
        els = a[i][0];
        ss = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == ' ' || a[i][j] == '\n') {
                ele = a[i][j-1];
                if (els == ele) {
                    for (int k = ss; k < se; k++) {
                        a[i][k] = toupper(a[i][k]);
                    }

                }
                els = a[i][j+1];
                ss = j+1;
                se = ss-1;
            }
            se++;
        }
    }
    for (int i=0;i<nx+1;i++){
        for (int j=0;j<a[i].size();j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}