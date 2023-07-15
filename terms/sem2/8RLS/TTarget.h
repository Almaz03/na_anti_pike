#ifndef MAICS_TTARGET_H
#define MAICS_TTARGET_H

#include <cmath>
#include <string>

struct Coordinates {
    double x;
    double y;
};

enum Types {
    Aircraft, Missile
};


class TTarget {

protected:
    int index;
    Coordinates initial_coordinates;
    double speed;
    double course;
    double time;
    Types type;
    Coordinates current_coordinates;

public:
    TTarget() = default;

    ~TTarget() = default;

    std::string get_type_of_target() const;

    int get_index() const;

    //also can be used moove function if time is setted
    Coordinates get_current_coordinates() const;

    virtual Coordinates Move(double ti);

};


class TAircraft : public TTarget {

public:
    Coordinates Move(double ti);

    TAircraft() = default;

    ~TAircraft() = default;

    TAircraft(int index, Types type, double x, double y, double speed, double course, double time);
};


class TMissile : public TTarget {

private:
    double acceleration;
public:
    Coordinates Move(double ti);

    TMissile() = default;

    ~TMissile() = default;

    TMissile(int index, Types type, double x, double y, double speed, double course, double acceleration,
             double time);
};
#endif //MAICS_TTARGET_H
