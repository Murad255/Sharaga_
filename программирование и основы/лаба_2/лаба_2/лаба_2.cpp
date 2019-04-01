#include "stdafx.h"
#include <conio.h>
#include "Figure.h"
#include "Rectangle.h"
#include "Queue.h"
#include "Triangle.h"
void main()
{
	Figure *f1, *f2, *f3;
	Triangle *r1, *r2, *r3;
	r1 = new Triangle();
	r2 = new Triangle();
	r3 = new Triangle();
	r1->a = 1; r1->h = 2;
	r2->a = 5; r2->h = 7;
	r3->a = 15; r3->h = 3;
	f1 = (Figure*)r1;
	f2 = (Figure*)r2;
	f3 = (Figure*)r3;
	Queue q;	//создаём очередь
	q.Put(f1); q.Put(f3); q.Put(f2);
	q.ShowPerimetr();//вывод значений периметров в очереди
	delete f1; delete f2; delete f3;
	_getch();
}