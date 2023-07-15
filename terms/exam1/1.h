#include<iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int n, m;
    cin >> n >> m;
    if (n<10 && m<10){
        int arr[SIZE][SIZE];
        double mean = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                mean += arr[i][j];
            }
        }
        mean = mean / (n * m);
        cout << mean<<endl;

        int count = 0, score=0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] > mean)
                {
                    count++;
                }

            }
            if (count == m)
            {
                cout << i;
                score++;
            }
            count = 0;
        }

        if (score == 0)
        {
            cout << 0;
        }
    }
    else cout <<0;
}