#include <iostream>
#include <string>
#include "Polynomial.h"
#include "Header.h"
using namespace std;

int main()
{
	Polynomial startFunction(5, 1.0, 2.83, -4.5, -64.0, -20.0);
	Polynomial firstFi(5, 1.0, 2.83, -4.5, 0.0, -20.0);
	firstFi.devideAllCoeff(64);
	Polynomial secondFi(5, 1.0, 2.83, -4.5, -286.0, -20.0);
	secondFi.devideAllCoeff(-222.0);
	const double EPSILON = 0.00001;
	pair<double, int> firstRoot = solveEquation(firstFi, -0.35, EPSILON);
	cout << "Start function: " << startFunction.toString() << endl;
	cout << endl;
	cout << "First section: " << "[-0.4; -0.3]" << endl;
	cout << "Canonical equation: " << "x = " << firstFi.toString() << endl;
	cout << "Prior estimate of the number of operations: " << 77 << endl;
	cout << "Start approximation: " << -0.35 << endl;
	cout << "Root: " << firstRoot.first << endl;
	cout << "Real number of operations: " << firstRoot.second << endl;
	cout << "Solution residual: " << startFunction.getValue(firstRoot.first) << endl;
	cout << endl;
	pair<double, int> secondRoot = solveEquation(secondFi, 3.65, EPSILON);
	cout << "Second section: " << "[3.6; 3.7]" << endl;
	cout << "Canonical equation: " << "x = " << secondFi.toString() << endl;
	cout << "Prior estimate of the number of operations: " << 689 << endl;
	cout << "Start approximation: " << 3.65 << endl;
	cout << "Root: " << secondRoot.first << endl;
	cout << "Real number of operations: " << secondRoot.second << endl;
	cout << "Solution residual: " << startFunction.getValue(secondRoot.first) << endl;

	system("pause");
	return 0;
}

