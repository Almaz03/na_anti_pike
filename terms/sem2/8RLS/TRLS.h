#ifndef MAICS_TRLS_H
#define MAICS_TRLS_H

#include "TTarget.h"
#include "functions.h"
#include <fstream>
#include <sstream>


const short MIN_TARGETS = 10;
const short MAX_TARGETS = 50;
const short MIN_COORDINATE = -2000;
const short MAX_COORDINATE = 2000;
const short MIN_SPEED = 10;
const short MAX_SPEED = 100;
const short MIN_COURSE = 0;
const short MAX_COURSE = 360;
const short MIN_ACCELERATION = 1;
const short MAX_ACCELERATION = 10;


class TRLS {

private:
    Coordinates coordinates;
    double range;
    int amount_target;
    TTarget **target;

public:
    TRLS() = default;

    TRLS(int amount_target, double x, double y, double range, double t0);

    TRLS(const std::string &input_file_name, double x, double y, double range, double t0, int amount);

    int Peleng(std::ofstream &outfile, double t0, double t1, double delta_t) const;

    int Peleng(std::ofstream &outfile, std::ofstream &outcsv, double t0, double t1, double delta_t) const;

    double calculate_distance(Coordinates coordinates) const;

    bool is_range_valid(Coordinates coordinates) const;

    double calculate_angle(Coordinates coordinates) const;

    bool is_angle_valid(Coordinates coordinates) const;

    int get_amount_target() const;

    ~TRLS();
};

#endif //MAICS_TRLS_H
