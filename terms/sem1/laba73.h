#include <iostream>

int main()
{
    int  j, i, num[100][100];
    int mas[10000];
    int n,a;
    std::cin >> n;
    if (n>100)
    {
        std::cout << "vvedite cheslo menshe 100";
    }
    else
    {

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                std::cin >> num[i][j];
            }

        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                mas[i * n + j ] = num[i][j];
            }
        }
        for (int i = 0; i < n*n - 1; i++) {
            for (int j = 0; j < n*n - i - 1; j++) {
                if (mas[j] > mas[j + 1]) {
                    a = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = a;
                }
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                std::cout << mas[i * n + j] << ' ';
            }

            std::cout << '\n';
        }
    }
    return 0;
}