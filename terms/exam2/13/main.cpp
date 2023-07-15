#include <iostream>
#include <fstream>

using namespace std;

class TObj {
private:
    int n;
    string *Pstr;
public:
    void LoadFile(ifstream &file) {
        n = 0;
        string line;
        while (getline(file, line)) {
            n++;
        }
        Pstr = new string[n];
        file.clear();
        file.seekg(0, ios::beg);
        for (int i = 0; i < n; ++i) {
            getline(file, Pstr[i]);
        }
    }

    void Work() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < Pstr[i].size(); j++) {
                if (isdigit(Pstr[i][j])) {
                    Pstr[i].erase(j, 1);
                    j--;
                }
            }
        }
    }

    void SafeFile(ofstream &outfile) {
        for (int i = 0; i < n; ++i) {
            outfile << Pstr[i] << endl;
        }
    }

    void Done() {
        delete[] Pstr;
    }
};

int main(int argc, char **argv) {
    ifstream file("..\\input.txt");
    TObj tobj;
    tobj.LoadFile(file);
    file.close();
    tobj.Work();

    ofstream outfile("..\\output.txt");
    if (!outfile) cout << "File not created yet -> creating \n";
    else tobj.SafeFile(outfile);

    tobj.Done();
    outfile.close();
    system("pause");
    return 0;
}
