#include <iostream>
#include<string>
using namespace std;

int main()
{
    int nx, sum=0;
    char arr[10][5];
    cin>>nx;
    if(nx<1||nx>10)
    {
        cout<<0;
        exit(0);
    }
    for(int i=0;i<nx;i++)
    {
        cin>>arr[i];
        string count={};
        for(int j=0;j<5;j++)
        {
            if(isdigit(arr[i][j]))
            {
                count+=arr[i][j];
                if(isdigit(arr[i][j+1])== false)
                {
                    sum+=stoi(count);
                    count={};
                }
            }

        }

    }
    cout<<sum;
    return 0;
}

