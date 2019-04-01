#include "stdafx.h"
//#include"Element.h"
#include"Figure.h"
#include "Queue.h"
#include<iostream>
using namespace::std;

Queue::Queue()
{
	first = 0;
	last = 0;
	count = 0;
}


Queue::~Queue()
{
}

void Queue::Put(Figure* e)
{
	if (e == 0)
		return;
	e->prev = last;
	if (count < 1)
	{
		last = e;
		first = e;
	}
	last->next = e;
	last = e;
	count++;
	cout << "Element " << e->GetPerimetr() << " added to queue" << endl;
}
Figure* Queue::Get()
{
	Figure* e;
	if (first == 0)
		return 0;
	e = first;
	first = first->next;
	first->prev = 0;
	e->next = 0;
	count--;
	cout << "Element " << e->GetSquare() << "removed from queue" << endl;
	return e;
}

void Queue::ShowSquares()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	Figure* e;
	e = first;
	while (e != 0)
	{
		e->GetSquare();
		e = e->next;
	}
	cout << endl;
}

void Queue::ShowPerimetr()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	Figure* e;
	e = first;
	while (e != 0)
	{
		e->GetPerimetr();
		e = e->next;
	}
	cout << endl;
}
