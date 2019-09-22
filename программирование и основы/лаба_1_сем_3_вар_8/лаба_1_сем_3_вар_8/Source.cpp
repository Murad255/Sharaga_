#include <iostream>
#include <conio.h>

#include "Figure.h"
#include "Rectangle.h"
#include "rhombus.h"

void main()
{
	Figure* lego[9];

	lego[0] = new Figure();		
	lego[1] = new Figure();		
	lego[2] = new Figure();
	lego[3] = new Rectangle();	
	lego[4] = new Rectangle();	
	lego[5] = new Rectangle();
	lego[3] = new Rhombus();
	lego[4] = new Rhombus();
	lego[5] = new Rhombus();

	((Rectangle*)lego[3])->a = 10;
	((Rectangle*)lego[3])->b = 20;

	((Rectangle*)lego[4])->a = 15;
	((Rectangle*)lego[4])->b = 20;

	((Rectangle*)lego[5])->a = 10;
	((Rectangle*)lego[5])->b = 45;

	((Rhombus*)lego[6])->a = 20;
	((Rhombus*)lego[6])->h = 20;

	((Rhombus*)lego[7])->a = 15;
	((Rhombus*)lego[7])->h = 20;

	((Rhombus*)lego[8])->a = 13;
	((Rhombus*)lego[8])->h = 45;


	for (int i = 0; i < 6; i++) {

		lego[i]->PrintName();
		lego[i]->GetSquare();

		std::cout << '\n';
	}

	delete lego;

	std::cout << "Hello World!\n";
	_getch();


}