#pragma once
#include "Figure.h"

class Circle :public Figure
{
public:

	double r;

	Circle();
	~Circle();

	double GetSquare();
	double GetPerimeter();
	void PrintName();
};