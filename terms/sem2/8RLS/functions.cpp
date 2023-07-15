#include "functions.h"

const double randomaizer(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return static_cast<double> (dist(gen));
}

void console_initialization(double &t0, double &t1, double &dt, double &x, double &y, double &r) {

    std::cout << "Enter start time: " << std::endl;
    std::cin >> t0;
    std::cout << "Enter end time: " << std::endl;
    std::cin >> t1;
    std::cout << "Enter time step: " << std::endl;
    std::cin >> dt;
    std::cout << "\nEnter Radio Location System coordinates \nX: " << std::endl;
    std::cin >> x;
    std::cout << "Y: " << std::endl;
    std::cin >> y;
    std::cout << "\n" << "Enter Radio location system detection radius: " << std::endl;
    std::cin >> r;
    if (t0 < 0 or t1 < 0 or dt < 0 or r < 0) {
        std::cout << "Error: negative value entered";
        system("pause");
        exit(1);
    }
}

int get_amount_target_from_file(std::string infile) {
    std::ifstream input(infile);
    std::string line;
    int amount = 0;
    while (std::getline(input, line)) {
        if (line.find("Aircraft") != std::string::npos || line.find("Missile") != std::string::npos) {
            amount++;
        }
    }
    input.close();
    return amount;
}


