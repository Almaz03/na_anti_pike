#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color DF");
    const int SIZE = 10;
    string arr[SIZE], word="";
    int n, count=0, all=0;
    cin >> n;
    if (n > 10 || n < 1)
    {
        cout << 0;
    }
    else
    {
        getline(cin, arr[0]);
        for (int i = 0; i < n; i++)
        {
            getline(cin, arr[i]);
            arr[i] += " ";
            if (arr[i].size() > 50)
            {
                cout << 0;
                goto theEnd;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] != ' ')
                {
                    word += arr[i][j];
                }
                else if(arr[i][j]==' ')
                {

                    for (int k = word.size() - 1, l = 0; k >= 0; k--, l++)
                    {
                        if (word[k] == word[l])
                        {
                            count++;
                            if (count == word.size())
                            {
                                cout << word << " ";
                                all++;
                            }
                        }
                    }
                    count = 0;
                    word = "";
                }
            }
            if (all == 0)
            {
                cout << 0;
            }
            all = 0;
            cout << endl;
        }

    }



    theEnd:
    return 0;
}