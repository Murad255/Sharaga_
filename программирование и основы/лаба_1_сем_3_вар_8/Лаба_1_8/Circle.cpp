#include "Circle.h"
#include <iostream>
using namespace std;
#define PI 3.14

Circle::Circle()
{
	cout << "Circle Constructor called!" << endl;
}


Circle::~Circle()
{
	cout << "Circle Destructor called!" << endl;
}

double Circle::GetSquare()
{
	cout << "Square of circle is " << (PI*r*r) << endl;
	return (PI*r*r);
}

void Circle::PrintName()
{
	cout << "Circle" << endl;


}
double Circle::GetPerimeter()
{
	cout << "Circle's perimetr is " << (PI*r*r) << endl;
	return (PI*r*r);
}