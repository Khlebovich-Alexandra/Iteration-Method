#include "Header.h"

std::pair<double, int> solveEquation(Polynomial & fi, double startApproximation, double epsilon)
{
		int k = 0;
		double result = fi.getValue(startApproximation);
		k++;
		while (abs(startApproximation - result) >= epsilon)
		{
			startApproximation = result;
			result = fi.getValue(startApproximation);
			k++;
		}
		return std::make_pair(result, k);
}
