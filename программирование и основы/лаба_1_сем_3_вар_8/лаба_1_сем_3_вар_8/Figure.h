#pragma once
class Figure {
public:
	Figure();
	 ~Figure();
	virtual double GetSquare();
	virtual void PrintName();
	virtual double GetPerimetr();
};