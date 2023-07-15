#include "functions.h"
#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {
    double x;
    int n;
    std::ifstream input("..\\in.txt", ios::in | ios::binary);

    if (!input) {
        std::cout << "File not include" << std::endl;
        system("pause");
        return 1;
    }
    //std::cout << "Enter number:" << std::end
    //std::cout << "Enter x:" << std::endl;
    input >> n >> x;
    input.close();
    double *pres;
    pres = new double [n];
    int j = sum(n, x, *pres);
    ifstream output("..\\out.txt", std::ios::in | std::ios::binary);
    if (!output) return 1;
    double *res;
    res = new double[n];
//    output.read((char *) &res, sizeof res);
    //std::cout << "Execution: " << std::endl;
    for (int i = 0; i < n; i++) {
        output.read((char *) &res[i], sizeof(double));
        cout << res[i] << " ";
    }


    output.close();
    delete[]res;

}
