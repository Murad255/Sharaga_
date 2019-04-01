#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>
using namespace::std;
Rectangle::Rectangle()
{
	cout << "Rectangle constructor called! \n";
}


Rectangle::~Rectangle()
{
	cout << "Destructor called! \n";
}

double Rectangle::GetSquare()
{
	double sum;
	sum = a * b;
	std::cout << "\n Square = " << sum<<'\n';
	return sum;
}

double Rectangle::GetPerimetr()
{
	double sum;
	sum = (2 * a + 2 * b);
	std::cout << "\n Perimetr = " << sum << '\n';
	return sum;
}

void Rectangle::PrintName()
{
	std::cout << "Rectangle " << '\n';
}
