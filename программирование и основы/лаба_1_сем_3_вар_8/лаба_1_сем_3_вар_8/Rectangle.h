#pragma once
#include "Figure.h"
class Rectangle :public Figure
{
public:

	double a, b;

	Rectangle();
	~Rectangle();

	double GetSquare();
	void PrintName();
};