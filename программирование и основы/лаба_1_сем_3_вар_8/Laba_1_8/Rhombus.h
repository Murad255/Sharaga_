#pragma once
#include "Figure.h"
class Rhombus :public Figure
{
public:

	double a, h;

	Rhombus();
	~Rhombus();
	
	double GetSquare();
	double GetPerimetr();
	void PrintName();
};