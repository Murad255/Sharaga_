#pragma once
class Figure {
public:
	Figure();
	virtual ~Figure();
	virtual double GetSquare();
	virtual void PrintName();
	virtual double GetPerimetr();
};