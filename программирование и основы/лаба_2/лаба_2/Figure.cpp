#include "stdafx.h"
#include "Figure.h"
#include<iostream>
using namespace::std;


Figure::Figure(void) 
	{
	cout << "Figure Constructor called!" << endl; 
	//prev=NULL;
	// next=NULL;
	}
Figure::~Figure(void) {	
	cout << "Figure Destructor called!" << endl; 
	}

double Figure::GetSquare() {
	cout << "Common Figure can't have a square!" << endl; return 0;
	}
double Figure::GetPerimetr()
{
	cout << "Common Figure can't have a Perimetr!" << endl; return 0;
}
void Figure::PrintName() {
	cout << "Abstract Figure" << endl;
	}


