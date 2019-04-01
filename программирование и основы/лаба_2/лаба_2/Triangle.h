#pragma once
#include"Figure.h"
// класс треугольника
class Triangle:
	public Figure
{
public:
	double a, h;//a-основание ,h -высота

	Triangle();
	~Triangle();
	double GetSquare();
	double GetPerimetr();
	void PrintName();
};

