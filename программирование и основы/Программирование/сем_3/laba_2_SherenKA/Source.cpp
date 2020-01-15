#include "Human.h"
#include "Queue.h"
#include <conio.h>
#include"Queue.h"
#include<iostream>

int main()
{
	Human e1, e2, e3, e4, e5,e6;
	e1.value = 10;
	e2.value = 20;
	e3.value = 30;
	e4.value = 40;
	e5.value = 50;
	e6.value = 60;
	PriorityHuman ph1(&e1, 3);
	PriorityHuman ph2(&e2, 6);
	PriorityHuman ph3(&e3, 3);
	PriorityHuman ph4(&e4, 2);
	PriorityHuman ph5(&e5, 10);
	PriorityHuman ph6(&e6, 5);

	Queue q;		//создаёт очередь
	q.Put(&ph1);	//вставляет в очередь e2
	q.Print();		//печать всех значений
	q.Put(&ph2);
	q.Print();
	q.Put(&ph3);
	q.Print();
	q.Put(&ph4);
	q.Print();
	q.Put(&ph5);
	q.Print();
	q.Put(&ph6);
	q.Print();

	q.Mult();//выводит сумму последних 3-х элементов

	q.Print();//печать всех значений
	q.Get();//вывод значения из очереди
	q.Get();
	q.Print();
	q.Mult();

	_getch();
	return 0;
}

