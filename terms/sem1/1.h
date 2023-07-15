#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main(){


    char str[100];
    bool a = true;
    gets(str);


    for (int i = 0; str[i]; i++) {
        while (a) {

            if (str[i] >= '0' && str[i]< '7') a = true;
            else a = false;
            break;
        }

    }
    if (a){
        int b = atoi(str);
        if ((b%2 == 0))  a = true;
        else a = false;
    }
    cout<<a<<endl;

}
/*{
    char surnames[3][100], tmp[100];
    for(int i=0; i<3; i++) {
        cin.getline(surnames[i], 100);
    }

    for(int i=0;i<3-1;i++){
        for(int j=i+1;j<3;j++){
            if(strcmp(surnames[i],surnames[j])>0)
            {   strcpy(tmp,surnames[i]);
                strcpy(surnames[i],surnames[j]);
                strcpy(surnames[j],tmp);
            }
        }
    }

    for( int i=0;i<3;i++){
        cout<<surnames[i]<<"\n";
    }
}*/
