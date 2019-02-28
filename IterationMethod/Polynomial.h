#pragma once
#include <vector>
class Polynomial
{
private:
	std::vector<double> polynomial;
	Polynomial();
public:
	Polynomial(std::vector<double> polynomial);
	Polynomial(int count, ...);
	double getValue(double value)const;
	void devideAllCoeff(double value);
	std::string toString()const;
	~Polynomial();
};
