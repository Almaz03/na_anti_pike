#include "TRLS.h"

double TRLS::calculate_distance(Coordinates coordinates) const {
    double distance;
    distance = pow(pow((coordinates.x - this->coordinates.x), 2) +
                   pow((coordinates.y - this->coordinates.y), 2), 1.0 / 2);
    return distance; 
}

bool TRLS::is_range_valid(Coordinates coordinates) const {
    double distance = calculate_distance(coordinates);
    if (distance > range) return false;
    else {
        return true;
    }
}

double TRLS::calculate_angle(Coordinates coordinates) const {
    double angle;
    if (coordinates.y-this->coordinates.y < 0 and coordinates.x - this->coordinates.x>0) {
        angle = (atan((coordinates.y - this->coordinates.y) / (coordinates.x - this->coordinates.x)) * 180 / M_PI) +
                360;
        return angle;
    } else if ((coordinates.x - this->coordinates.x) < 0) {
        angle = ((M_PI + (atan((coordinates.y - this->coordinates.y) / (coordinates.x - this->coordinates.x)))) * 180 /
                 M_PI);
        return angle;
    } else {
        angle = (((atan((coordinates.y - this->coordinates.y) / (coordinates.x - this->coordinates.x)))) * 180 / M_PI);
        return angle;
    }
}

bool TRLS::is_angle_valid(Coordinates coordinates) const {
    double angle = calculate_angle(coordinates);
    if (angle < 0 or angle > 360) return false;
    else {
        return true;
    }
}

TRLS::TRLS(int amount_target, double x, double y, double range, double t0) {
    this->coordinates.x = x;
    this->coordinates.y = y;
    this->range = range;
    this->amount_target = amount_target;
    target = new TTarget *[amount_target];

    for (int i = 0; i < this->amount_target; ++i) {
        int choice = randomaizer(0, 1);
        switch (choice) {
            case 0:
                target[i] = new TAircraft(i, Aircraft, randomaizer(-MIN_COORDINATE, MAX_COORDINATE),
                                          randomaizer(MIN_COORDINATE, MAX_COORDINATE),
                                          randomaizer(MIN_SPEED, MAX_SPEED), randomaizer(MIN_COURSE, MAX_COURSE), t0);
                break;
            case 1:
                target[i] = new TMissile(i, Missile, randomaizer(-MIN_COORDINATE, MAX_COORDINATE),
                                         randomaizer(MIN_COORDINATE, MAX_COORDINATE),
                                         randomaizer(MIN_SPEED, MAX_SPEED), randomaizer(MIN_COURSE, MAX_COURSE),
                                         randomaizer(MIN_ACCELERATION, MAX_ACCELERATION), t0);
                break;
        }
    }
}

TRLS::TRLS(const std::string& input_file_name, double x, double y, double range, double t0, int amount) {
    this->coordinates.x = x;
    this->coordinates.y = y;
    this->range = range;
    this->amount_target = amount;
    target = new TTarget *[amount_target];
    std::ifstream infile(input_file_name);

    std::string line;
    int i = 0;
    while (infile >> line && i < amount_target) {
        if (!line.empty()) {
            if (line == "Aircraft") {
                double x_a, y_a, speed, course;
                infile >> x_a >> y_a >> speed >> course;
                target[i] = new TAircraft(i, Aircraft, x_a, y_a, speed, course, t0);
                i++;

            } else if (line == "Missile") {
                double x_a, y_a, speed, course, acceleration;
                infile >> x_a >> y_a >> speed >> course >> acceleration;
                target[i] = new TMissile(i, Missile, x_a, y_a, speed, course, acceleration, t0);
                i++;
            }
        }
    }
    infile.close();
}


int TRLS::Peleng(std::ofstream &outfile, double t0, double t1, double dt) const {
    int found_targets = 0;
    outfile << "#####################################" << std::endl;
    outfile << "##### THERE ARE " << get_amount_target() << " TARGETS ###########" << std::endl;
    outfile << "RLS range: " << range << std::endl;
    outfile << "RLS coordinates: " << coordinates.x << ":" << coordinates.y << std::endl;
    outfile << "###########STARTING PELENG###########" << std::endl;
    for (double t = t0; t <= t1; t += dt) {
        for (int i = 0; i < amount_target; i++) {
            Coordinates coordinates = target[i]->Move(t);
            if (is_range_valid(coordinates) and is_angle_valid(coordinates)) {
                outfile << "Time: " << t << ", Target #" << target[i]->get_index() << ", Type: "
                        << target[i]->get_type_of_target() << ", Distance: "
                        << calculate_distance(coordinates) << ", Angle: "
                        << calculate_angle(coordinates) << ", Coordinates: " << coordinates.x << ":" << coordinates.y
                        << std::endl;
                found_targets++;
            }
        }
    }
    outfile << "########### FOUND " << found_targets << " TIMES ###########" << std::endl;

    return found_targets;
}

int TRLS::Peleng(std::ofstream &outfile, std::ofstream &outcsv, double t0, double t1, double dt) const {
    int found_targets = 0;
    outcsv << "Time,Target #,Type,Distance,Angle,Coordinates" << std::endl;
    outfile << "#####################################" << std::endl;
    outfile << "##### THERE ARE " << get_amount_target() << " TARGETS ###########" << std::endl;
    outfile << "RLS range: " << range << std::endl;
    outfile << "RLS coordinates: " << coordinates.x << ":" << coordinates.y << std::endl;
    outfile << "###########STARTING PELENG###########" << std::endl;
    for (double t = t0; t <= t1; t += dt) {
        for (int i = 0; i < amount_target; i++) {
            Coordinates coordinates = target[i]->Move(t);
            if (is_range_valid(coordinates) and is_angle_valid(coordinates)) {
                outfile << "Time: " << t << ", Target #" << target[i]->get_index() << ", Type: "
                        << target[i]->get_type_of_target() << ", Distance: "
                        << calculate_distance(coordinates) << ", Angle: "
                        << calculate_angle(coordinates) << ", Coordinates: " << coordinates.x << ":" << coordinates.y
                        << std::endl;
                outcsv << t << "," << target[i]->get_index() << ","
                       << target[i]->get_type_of_target() << ","
                       << calculate_distance(coordinates) << ","
                       << calculate_angle(coordinates) << "," << coordinates.x << ":" << coordinates.y
                       << std::endl;
                found_targets++;
            }
        }
    }
    outfile << "########### FOUND " << found_targets << " TIMES ###########" << std::endl;

    return found_targets;
}

int TRLS::get_amount_target() const { return amount_target; }

TRLS::~TRLS() {
    for (int i = 0; i < amount_target; i++) {
        delete target[i];
    }
    delete[] target;
}




