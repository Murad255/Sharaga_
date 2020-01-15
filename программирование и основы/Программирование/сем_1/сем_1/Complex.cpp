#include "Complex.h"
#include <iostream>
using namespace std;


Complex::Complex()
{
	this->Im = 0;
	this->Re = 0;
}

Complex::Complex(double Im, double Re)
{
	this->Im = Im;
	this->Re = Re;
}


Complex::~Complex(void)
{
}

void Complex::Print()
{
	if (Re == 0) cout << Im << "i ";
	else if (Im == 0) cout << Re;
	else if (Im < 0) cout << '(' << Re << Im << "i) ";
	else cout << '(' << Re << '+' << Im << "i) ";
}


Complex Complex::operator+(Complex c)
{
	Complex result;
	result.Re = c.Re + this->Re;
	result.Im = c.Im + this->Im;
	return result;
}

Complex Complex::operator-(Complex c)
{
	Complex result;
	result.Re = this->Re - c.Re;
	result.Im = this->Im - c.Im;
	return result;
}

Complex Complex::operator*(Complex c)
{
	Complex result;
	result.Re = this->Re * c.Re - this->Im * c.Im;
	result.Im = this->Re * c.Im + this->Im * c.Re;
	return result;
}

Complex Complex::operator/(Complex p)
{
	double a = this->Re;
	double b = this->Im;
	double c = p.Re;
	double d = p.Im;

	Complex result;

	result.Re = (a * c + b * d) / (c * c + d * d);
	result.Im = (c * b - a * d) / (c * c + d * d);
	return result;
}


Complex Complex::operator+(double c)
{
	Complex result;
	result.Re = this->Re + c;
	result.Im = this->Im;
	return result;
}

Complex Complex::operator-(double c)
{
	Complex result;
	result.Re = this->Re - c;
	result.Im = this->Im;
	return result;
}

Complex Complex::operator*(double c)
{
	Complex result;
	result.Re = this->Re * c;
	result.Im = this->Im * c;
	return result;
}

Complex Complex::operator/(double c)
{

	Complex result;
	result.Re = this->Re / c;
	result.Im = this->Im / c;
	return result;
}

bool Complex::operator==(Complex c)
{
	if ((this->Im == c.Im) && (this->Re == c.Re))return true;
}

double Complex::Mod()
{
	return sqrt(Re * Re + Im * Im);
}