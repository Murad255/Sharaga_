#include "rhombus.h"
#include <iostream>
using namespace std;


Rhombus::Rhombus()
{
	cout << "Rhombus Constructor called!" << endl;
}


Rhombus::~Rhombus()
{
	cout << "Rhombus Destructor called!" << endl;
}

double Rhombus::GetSquare()
{
	cout << "Square of rhombus is " << (a*h) << endl;
	return (a*h);
}

double Rhombus::GetPerimetr()
{
	cout << "Perimetr of rhombus is " << (a * 4) << endl;
	return (a * 4);
}

void Rhombus::PrintName()
{
	cout << "Rhombus" << endl;
}