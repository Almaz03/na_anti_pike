#include <iostream>
#include <cstring>


using namespace std;
int main()
{
    const short a = 2, b = 32;
    char A[a][b];
    int capitals = 0, lowers = 0, even = 0, odd = 0;

    for (int i = 0; i<a; i++) {
        gets(A[i]);

    }

    for (int j = 0; j < strlen(A[0]); j++) {
        if (isalpha(A[0][j]) && isupper(A[0][j])) {
            capitals++;
        }
    }
    for (int j = 0; j < strlen(A[1]); j++) {
        if (isalpha(A[1][j]) && !isupper(A[1][j])) {
            lowers++;
        }
    }
    for (int j = 0; j < strlen(A[1]); j++) {
        if (isdigit(A[1][j]) && A[1][j]%2 == 0){
            even++;
        }
        if (isdigit(A[1][j]) && A[1][j]%2 == 0) {
            odd++;

        }
    }
    for (int i = 0; i<a; i++) {
        for (int j = 0; j < strlen(A[j]); j++) {
            if (!isalpha(A[i][j]) && !isdigit(A[i][j])) { //возможная проверка НЕ на буквы
                cout << 0;
                return 0;
            }
            else {
                cout << capitals <<" "<<lowers<< endl<<even<<" "<< odd;
                return 0;
            }
        }
    }

}