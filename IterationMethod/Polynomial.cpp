#include "Polynomial.h"
#include <algorithm>
#include <cstdarg>
#include <string>


Polynomial::Polynomial()
{
}

Polynomial::Polynomial(std::vector<double> polynomial)
{
	std::copy(polynomial.begin(), polynomial.end(), this->polynomial.begin());
}

Polynomial::Polynomial(int count, ...)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		double num = va_arg(args, double);
		polynomial.push_back(num);
	}
	va_end(args);
}

double Polynomial::getValue(double value) const
{
	double result = 0;
	for (size_t i = 0; i < polynomial.size(); i++)
	{
		result += polynomial.at(i) * pow(value, polynomial.size() - i - 1);
	}
	return result;;
}

void Polynomial::devideAllCoeff(double value)
{
	for (std::vector<double>::iterator it = polynomial.begin(); it != polynomial.end(); it++)
	{
		(*it) /= value;
	}
}

std::string Polynomial::toString() const
{
	std::string s;
	for (size_t i = 0; i < polynomial.size() - 2; i++)
	{
		if (polynomial.at(i) != 0)
		{
			s += std::to_string((i == 0) ? polynomial.at(i) : abs(polynomial.at(i))) + 
				"x^" + std::to_string(polynomial.size() - i - 1) + 
				(polynomial.at(i + 1) > 0 ? " + " : polynomial.at(i + 1) < 0 ? " - " : "");
		}
	}
	if (polynomial.at(polynomial.size() - 2) != 0)
	{
		s += std::to_string(abs(polynomial.at(polynomial.size() - 2))) + "x" + 
			(polynomial.at(polynomial.size() - 1) > 0 ? " + " :
				polynomial.at(polynomial.size() - 1) < 0 ? " - " : "");
	}
	if (polynomial.at(polynomial.size() - 1) != 0)
	{
		s += std::to_string(abs(polynomial.at(polynomial.size() - 1)));
	}
	return s;
}


Polynomial::~Polynomial()
{
}
