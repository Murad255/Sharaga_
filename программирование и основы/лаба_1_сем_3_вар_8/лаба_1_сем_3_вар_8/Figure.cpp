#include <iostream>
using namespace std;
#include "Figure.h"
Figure::Figure(void)
{
	cout << "Figure Constructor called!" << endl;
}

Figure::~Figure(void)
{
	cout << "Figure Destructor called!" << endl;
}

double Figure::GetSquare()
{
	cout << "Common Figure can't have a square!" << endl;
	return 0;
}

void Figure::PrintName()
{
	cout << "Abstract Figure" << endl;
}