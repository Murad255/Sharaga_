#include "stdafx.h"
#include "Triangle.h"
#include <iostream>
using namespace::std;
Triangle::Triangle()
{
	cout << "Triangle constructor called! \n";
}


Triangle::~Triangle()
{
	cout << "Triangle Destructor called! \n";
}

double Triangle::GetSquare()
{
	double sum;
	sum = a * h/2;
	cout << "\n Square = " << sum << '\n';
	return sum;
}

double Triangle::GetPerimetr()
{
	double sum;
	sum = (a + 2 * (a*a / 4 + h * h));
	cout << "\n Perimetr = " << sum << '\n';
	return sum;
}

void Triangle::PrintName()
{
	cout << "Triangle " << '\n';
}
