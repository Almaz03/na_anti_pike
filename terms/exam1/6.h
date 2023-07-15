#include <iostream>
#include<string>
using namespace std;

int main()
{
    const short size = 15;
    char A[size], B[size], C[size];
    short n;
    int tmp = 0,sr = 0;
    cin>>n;
    if (0>n || n>size){
        exit(0);
    }
    cin>>A;
    for (int i = 0; i<n;i++){
        tmp += A[i];
    }
    sr=tmp/n;
    for (int i = 0; i<n;i++){
        if (A[i]>sr) B[0]=A[i];

    }
    for (int i = 0; i<n;i++){
        if (A[i]<sr) C[0]=A[i];

    }
    cout<<sr<<endl<<B<<endl<<C<<endl;

}

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char a[2][30];
    for (int i = 0; i < 2; i++) {
        gets(a[i]);
    }
    string tmp = {};
    int A[100];
    int count = 0;
    for (int i = 0; i < strlen(a[0]); i++) {
        if (isdigit(a[0][i])) {
            tmp += a[0][i];
            if (!isdigit(a[0][i + 1])) {
                A[count] = stoi(tmp);
                count++;
            }
        } else if (!isdigit(a[0][i])) tmp = {};
    }
    int max = A[0];
    for (int i = 0; i < count; i++) {
        if (A[i] > max) max = A[i];
    }
    cout << max;
    return 0;
}