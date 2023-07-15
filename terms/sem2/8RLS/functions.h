#ifndef MAICS_FUNCTIONS_H
#define MAICS_FUNCTIONS_H

#include <iostream>
#include "TRLS.h"
#include "TTarget.h"
#include <random>


const double randomaizer(double min, double max);

int get_amount_target_from_file(std::string infile);

void console_initialization(double &t0, double &t1, double &dt, double &x, double &y, double &r);

#endif //MAICS_FUNCTIONS_H
