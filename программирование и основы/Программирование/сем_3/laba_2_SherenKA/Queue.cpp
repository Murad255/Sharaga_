
#include "Queue.h"
#include<iostream>
using namespace::std;


Queue::Queue()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}


Queue::~Queue()
{
}

void Queue::Put(PriorityHuman* e)
{
	if (e == 0)
		return;
	if (count < 1)
	{
		last = e;
		first = e;
	}
	else if (count == 1)
	{
		if (first->priority>=e->priority)
		{
			last = e;
			first->next = e;
			e->prev = first;
		}
		else 
		{
			first = e;
			last->prev = e;
			e->next = last;
		}
		
	}
	else
	{
		PriorityHuman* temp = last;
		int i = 0;
		while ((temp->priority < e->priority) && (count > i++)) {
			if (temp->prev == nullptr)
			{
				first->prev = e;
				e->next = first;
				first = e;

				count++;
				cout << "Element " << e->h->value << " with priority " << e->priority << " added to queue" << endl;
				return;
			}
			else temp = temp->prev;
		}

		PutAfter(temp,e);
	}
	count++;
	cout << "Element " << e->h->value <<" with priority " << e->priority << " added to queue" << endl;
	return;
}

 void Queue::PutAfter(PriorityHuman* afterH, PriorityHuman* e)
 {
	 if (e == 0)
		 return;
	// e->prev = last;

	 if (afterH->next != NULL) {
		 PriorityHuman* beforeH = afterH->next;
		 beforeH->prev = e;
		 e->next = beforeH;
	 }
	 else 		 last = e;


	 afterH->next = e;
	 e->prev = afterH;

 }

 PriorityHuman* Queue::Get()
{
	 PriorityHuman* e;
	if (first == nullptr)
		return 0;
	e = first;
	first = first->next;
	first->prev = nullptr;
	e->next = nullptr;
	count--;
	cout  << "Element " << e->h->value << " removed from queue" << endl;
	return e;
}

void Queue::Print()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	PriorityHuman* e;
	e = first;
	while (1)
	{
		cout << e->h->value << ", ";
		if ((e->next == 0) && (e->next == nullptr) && (e->next == NULL)) 
		{
			cout << endl; return;
		}
		else	e = e->next;
	}
	
}

void Queue::Mult() {
	if (count < 3) {
		cout << "Error: count < 3 \n";
		return;
	}

	PriorityHuman* e = first;
	int mult = 1;

	for (int i = 0; i < 3; i++)
	{
		mult *= e->h->value;
		e = e->next;
	}

	cout << "\nmult 3 elements:" << mult << endl;
}
