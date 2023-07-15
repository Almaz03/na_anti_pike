#include <iostream>
#include <vector>
#include "Model.h"

int main() {
    std::cout << "3. Simple model o aircraft.\n\n";


    double t = 0, dt = 0.1, k = 0.1;

//     std::cout << "Enter t, dt, k separated by space:\n";
//    double t, dt, k;
//    std::cin>>t>>dt>>k;

    std::string filename = "..\\output.csv";

    std::vector<double> data(6);


    data[0] = 0;
    data[1] = 0;
    data[2] = 10;
    data[3] = 1;
    data[4] = 2;
    data[5] = 3;

// std::cout<<"Enter Sx, Sy, Sz separated by space:\n";
//    for (int i = 0; i<3; i++) {
//        std::cin>>data[i];
//    }
//    std::cout<<"Enter Vx, Vy, Vz separated by space:\n";
//    for (int i = 3; i<6; i++) {
//        std::cin>>data[i];
//    }

    Counter counter;

    Model *pmodel;
    SimpleModel model;
    pmodel = &model;

    counter.count(filename, t, dt, data, pmodel, k);

    std::cout << "Done!" << std::endl;
    return 0;
}