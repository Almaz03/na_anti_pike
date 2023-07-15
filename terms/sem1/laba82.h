#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    string str;
    int index = 0;
    getline(cin, str);
    for (int i=0; i<str.size(); i++) {
        for (int j = 0; j<i; j++) {
            if (str[i] == str[j]) break;
            if (j == i) str[index++] = str[i];
        }
    }
    for (int i=0; i<str.size(); i++) {
        for (int j=0; j<i; j++)
            if (str[i] == str[j])
                break;
        if (j == i)
            str[index++] = str[i];
    }

    return str[str.size()];
    cout<<str;
}

