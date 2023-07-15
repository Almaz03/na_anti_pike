#include <iostream>
#include <string>

using namespace std;

bool pol(string s) {
    int leg = 0;
    bool flag = true;
    if (s.size() % 2 == 0) leg = int(s.size()) / 2;
    else if (s.size() % 2 != 0) leg = (-1) / 2;
    for (int i = 0, j = int(s.size()) - 1; i <= leg; i++, j--) {
        if (s[i] == s[j] and flag) flag = true;
        else flag = false;
    }
    return flag;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    if (n < 0 || n > 10) {
        cout << 0;
        return 0;
    }
    string s[10];
    for (int i = 0; i < n; i++) {
        getline(cin, s[i], '\n');
        if (s[i].size() > 50) {
            cout << 0;
            return 0;
        }
    }
    string a;
    for (int i = 0; i < n; i++) {
        a = {};
        for (int j = 0; j < s[i].size(); j++) {
            while (s[i][j] != ' ' || j == s[i].size() - 1) {
                a += s[i][j];
                break;
            }
            if (((s[i][j] == ' ' and pol(a)) or (j == s[i].size() - 1 and pol(a))) and a.size() != 1)
                cout << a << " ";
            if (s[i][j] == ' ') a = {};
        }
        cout << endl;
    }
}
