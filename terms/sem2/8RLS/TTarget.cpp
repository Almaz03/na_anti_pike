#include "TTarget.h"

Coordinates TTarget::Move(double ti) {
    return {};
};

int TTarget::get_index() const { return index; }

Coordinates TTarget::get_current_coordinates() const { return current_coordinates; }

std::string TTarget::get_type_of_target() const {
    if (type == Aircraft) {
        return "Aircraft";
    } else {
        return "Missile";
    }
}

TAircraft::TAircraft(int index, Types type, double x, double y, double speed, double course, double time) {
    this->initial_coordinates.x = x;
    this->initial_coordinates.y = y;
    this->speed = speed;
    this->course = course;
    this->type = type;
    this->time = time;
    this->index = index;
}

Coordinates TAircraft::Move(double ti) {
    current_coordinates = initial_coordinates;
    double heading = atan(current_coordinates.y / current_coordinates.x);

        current_coordinates.x = (initial_coordinates.x - speed * cos(heading) * (ti - time));
        current_coordinates.y = (initial_coordinates.y - speed * sin(heading) * (ti - time));

    return current_coordinates;
}


TMissile::TMissile(int index, Types type, double x, double y, double speed, double course, double acceleration,
                   double time) {
    this->initial_coordinates.x = x;
    this->initial_coordinates.y = y;
    this->speed = speed;
    this->course = course;
    this->type = type;
    this->acceleration = acceleration;
    this->time = time;
    this->index = index;
}


Coordinates TMissile::Move(double ti) {
    current_coordinates = initial_coordinates;
    double heading = atan(current_coordinates.y / current_coordinates.x);
        current_coordinates.x = (initial_coordinates.x -
                                 ((speed + acceleration * (ti - time)) * cos(heading)) * (ti - time));
        current_coordinates.y = (initial_coordinates.y -
                                 ((speed + acceleration * (ti - time)) * sin(heading)) * (ti - time));
        return current_coordinates;
}