#include <iostream>
#include <vector>
#include <fstream>
#include "Modellegacy.h"

int main() {

    int axis;
    std::cout << "Enter amount of axis:\n";
    std::cin >> axis;

    Modellegacy model(axis);

    double k;
    std::cout << "Enter k:\n";
    std::cin >> k;
    double t = 0;

    std::vector<double> v(axis);
    std::cout << "Enter speed by X Y Z:\n";
    for (int i = 0; i < axis; ++i) {
        std::cin >> v[i];
       // model.set_v(i, v[i]);
    }

    std::vector<double> a(axis);
    std::cout << "Enter acceleration by X Y Z:\n";
    for (int i = 0; i < axis; ++i) {
        std::cin >> a[i];
       // model.set_a(i, a[i]);
    }


}