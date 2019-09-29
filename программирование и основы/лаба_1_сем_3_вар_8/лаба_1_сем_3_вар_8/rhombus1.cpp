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
	cout << "Square of êhombus is " << (a*h) << endl; return 0;
}

void Rhombus::PrintName()
{
	cout << "Rhombus" << endl;
}