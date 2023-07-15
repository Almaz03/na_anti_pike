#include <iostream>

const int THIS_YEAR = 2023;

using namespace std;

struct TRec {
    string fio;
    int year;
};

class Tobj {
private:
    TRec *p;
    int num;

public:

    void Init(int N) {
        p = new TRec[N];
        num = N;
    }

    double Mean() {
        double res = 0;
        for (int i = 0; i < num; i++) {
            res += THIS_YEAR - p[i].year;
        }
        res = res / num;
        return res;
    }

    void Done() {
        delete[]p;
    }

    void setter(int i, string fio, int year) {
        this->p[i].fio = fio;
        this->p[i].year = year;
    }


};

int main(int argc, char **argv) {
    Tobj obj;
    cout << "Enyer n:\n";
    int n;
    cin >> n;
    obj.Init(n);
    for (int i = 0; i < n; ++i) {
        cin.ignore();
        cout << "Enter first name:\n";
        string name;
        getline(cin, name);
        cout << "Enter year:\n";
        int year;
        cin >> year;
        obj.setter(i, name, year);
    }
    cout << obj.Mean();
    obj.Done();
}