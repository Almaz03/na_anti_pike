#include <iostream>
#include <string>
#include <cstring>


using namespace std;


int main() {
    string a[10];
    int nx;
    int curpos = 0, maxlen = 0, curlen = 0, maxpos = 0, c;
    bool flag = true;
    nx=1;
    for (int i = 0; i < nx + 1; i++) {
        getline(cin, a[i], '\n');
        a[i].append(" ");
        c = 0;
        for (int j = 0; j < a[i].length(); j++) {
            if (a[i][j] == ' ') {
                if (maxlen < curlen) {
                    if (maxlen == curlen) {
                        flag = false;
                    }
                    maxlen = curlen;
                    maxpos = curpos - 1;
                }

                curpos = j + 1;
                curlen = 0;
                continue;
            }
            curlen += 1;
        }
        if (flag) {
            a[i].erase(maxpos, maxlen);
            break;
        } else {
            int maxlen2 = 0, maxpos2 = 0;
            for (int j = 0; j < a[i].length(); j++) {
                for (int k = 0; k < a[i].length(); k++) {
                    if (a[i][k] == ' ') {
                        if (maxlen2 < curlen) {
                            maxlen = curlen;
                            maxpos = curpos - 1;
                        }

                        curpos = j + 1;
                        curlen = 0;
                        continue;
                    }
                    curlen += 1;
                }
                if (maxlen == maxlen2) {
                    a[i].erase(maxpos2, maxlen2);
                    maxpos2 = 0;
                    maxlen2 = 0;
                    continue;
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < nx + 1; i++) cout << a[i] << endl;


    return 0;
}