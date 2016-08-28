#ifndef GUARD_GRADE_H
#define GUARD_GRADE_H

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<Student_info>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);

#endif

