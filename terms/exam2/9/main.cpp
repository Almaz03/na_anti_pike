#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int readfile_and_fill_array(string filename, string *a) {

    string stroka;
    ifstream infile(filename);
    int words = 0;
    getline(infile, stroka);

    string tmp = "";
    for (int i = 0; i < stroka.size(); i++) {
        if (stroka[i] != ' ') {
            {
                tmp += stroka[i];

            }
        } else if (stroka[i] == ' ') {
            a[words] = tmp;
            tmp = "";
            words++;
        }
        if (stroka.size() - 1 == i) {
            a[words] = tmp;
            words++;

        }

    }
    infile.close();
    return words;

}

int main() {
    int b = 5;
    int *pa = &b;
    cout<<*pa<<endl;
    *pa = b;
    cout<<*pa<<endl;

}