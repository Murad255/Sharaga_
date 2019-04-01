#include "stdafx.h"

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
	cout << "Element " << e->value << "added to queue" << endl;
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
	cout << "Element " << e->value << "removed from queue" << endl;
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

void Queue::Sum(){
	if (count < 1) return;

	Element* e;
	int sum=0,i=0;
	int temp = 0;
	e = first;
	while (e != 0)
	{
		if (i++ != 3) {

			sum += e->value;
			e = e->next;
			temp++;
		}
		else break;
	}

	if(temp>=3)cout <<"\nsum 3 elements:"<< sum << endl;
}