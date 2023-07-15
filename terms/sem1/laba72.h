#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int mas1[100][100];
    int temp;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas1[i][j];
        }
    }
    // идем по столбцам - у нас их как раз столько, сколько элементов в строке
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if ((mas1[j][i] < mas1[k][i]) && (mas1[j][i] < 0) && (mas1[k][i] < 0))
                {
                    temp = mas1[k][i];
                    mas1[k][i] = mas1[j][i];
                    mas1[j][i] = temp;
                }
            }
        }
    }

    cout << "Sorted matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << mas1[i][j] << setw(3);
        }
        cout << endl;
    }

    return 0;
}