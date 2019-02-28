#pragma once
#include <iostream>
#include "Polynomial.h"

std::pair<double, int> solveEquation(Polynomial& fi, double startApproximation, double epsilon);

