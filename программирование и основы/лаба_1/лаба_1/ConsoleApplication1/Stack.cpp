#include "stdafx.h"
#include "Stack.h"
#include<iostream>
using namespace::std;

Stack::Stack()
{
	first = 0;	//первый
	last = 0;	//последний
	count = 0;
}

Stack::~Stack()
{
}

void Stack::Put(Element* e)
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
	cout << "Element " << e->value << " added to queue" << endl;
}
Element* Stack::Get()
{
	Element* e;
	if (last == 0)
		return 0;
	e = last;
	last = last->prev;//next;
	last->next = 0;//prev = 0;
	e->prev = 0;
	count--;
	cout << "Element " << e->value << "removed from queue" << endl;
	return e;
}
void Stack::Print()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	Element* e;
	e = first;
	while (e != 0)
	{
		cout << e->value << ", ";
		e = e->next;
	}
	cout << endl;
}