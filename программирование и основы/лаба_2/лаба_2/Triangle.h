#pragma once
#include"Figure.h"
// ����� ������������
class Triangle:
	public Figure
{
public:
	double a, h;//a-��������� ,h -������

	Triangle();
	~Triangle();
	double GetSquare();
	double GetPerimetr();
	void PrintName();
};

