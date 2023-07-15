#include <iostream>
#include <string>
using namespace std;

int main() {
    const short size = 255;
    string a;
    getline(cin, a);
    if (a.size()>size) exit(0);
    int max, min;
    max = a[0], min = a[0];
    for (int i = 0; i<a.size(); i++){
        if (a[i]>max) max = int(a[i]);
        if (a[i]<min) min = int(a[i]);
    }

    for (int i = 0; i<a.size(); i++){
        if (int(a[i])==max)
        {
            a.insert(i,to_string(max));
            i+=to_string(max).size()







                    ;
            a.erase(i,1);
            i--;
        }
        if (int(a[i])==min)
        {
            a.insert(i,to_string(min));
            i+=to_string(min).size();
            a.erase(i,1);
            i--;
        }
    }
    cout<<a;
}


