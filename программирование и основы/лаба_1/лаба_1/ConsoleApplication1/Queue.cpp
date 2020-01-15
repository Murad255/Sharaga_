
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

void Queue::Put(Element* e)
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

Element* Queue::Get()
{
	Element* e;
	if (first == 0)
		return 0;
	e = first;
	first = first->next;
	first->prev = 0;
	e->next = 0;
	count--;
	cout << "Element " << e->value << " removed from queue" << endl;
	return e;
}

void Queue::Print()
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

void Queue::Mult(){
	if (count < 3) {
		cout << "Error: count < 3 \n";
		return;
	}

	Element* e = first;
	int mult =1;
	
	for (int i = 0; i < 3; i++)
	{
		mult*= e->value;
		e = e->next;
	}

	cout <<"\nmult 3 elements:"<< mult << endl;
}
