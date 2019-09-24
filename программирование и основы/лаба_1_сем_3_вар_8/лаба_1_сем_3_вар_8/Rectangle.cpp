#include "Rectangle.h"
#include <iostream>
using namespace std;


Rectangle::Rectangle()
{
	cout << "Rectangle Constructor called!" << endl;
}


Rectangle::~Rectangle()
{
	cout << "Rectangle Destructor called!" << endl;
}

double Rectangle::GetSquare()
{
	cout << "Square of rectangle is " <<(a*b) << endl; 
	return (a * b);
}

void Rectangle::PrintName()
{
	cout << "Rectangle" << endl;
}