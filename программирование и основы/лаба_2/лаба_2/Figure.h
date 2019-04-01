#pragma once
//#include"Element.h"
class Figure
{
public:
	Figure * prev;
	Figure* next;
	Figure();
	virtual ~Figure();
	virtual double GetSquare(); 
	virtual double GetPerimetr();
	virtual void PrintName();
	//void operator=(Figure *fug);
};

