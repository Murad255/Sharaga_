#pragma once
#include "Human.h"

template <class T>
class Queue
{
	void PutAfter(PriorityHuman<T>* afterH, PriorityHuman<T>* e);
public:
	PriorityHuman<T>* first;
	PriorityHuman<T>* last;
	int count;
	Queue(void);
	~Queue(void);
	virtual void Put(PriorityHuman<T>* e);//вывод элемента из очереди
	PriorityHuman<T>* Get();		//вставка элемента в очередь
	void Print();	//печать в консоль всех элементов
	void Mult();
};


////////////////Queue.cpp///////////////////////////////


#include<iostream>
using namespace::std;

template <class T>
Queue<T>::Queue()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::Put(PriorityHuman<T>* e)
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
		if (first->priority >= e->priority)
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
		PriorityHuman<T>* temp = last;
		int i = 0;
		while ((temp->priority < e->priority) && (count > i++)) {
			if (temp->prev == nullptr)
			{
				first->prev = e;
				e->next = first;
				first = e;

				count++;
				cout << "Element\t" << e->h->value << "\twith priority " << e->priority << " added to queue" << endl;
				return;
			}
			else temp = temp->prev;
		}

		PutAfter(temp, e);
	}
	count++;
	cout << "Element\t" << e->h->value << "\twith priority " << e->priority << " added to queue" << endl;
	return;
}

template <class T>
void Queue<T>::PutAfter(PriorityHuman<T>* afterH, PriorityHuman<T>* e)
{
	if (e == 0)
		return;
	// e->prev = last;

	if (afterH->next != NULL) {
		PriorityHuman<T>* beforeH = afterH->next;
		beforeH->prev = e;
		e->next = beforeH;
	}
	else 		 last = e;


	afterH->next = e;
	e->prev = afterH;

}

template <class T>
PriorityHuman<T>* Queue<T>::Get()
{
	PriorityHuman<T>* e;
	if (first == nullptr)
		return 0;
	e = first;
	first = first->next;
	first->prev = nullptr;
	e->next = nullptr;
	count--;
	cout << "Element\t" << e->h->value << "\tremoved from queue" << endl;
	return e;
}

template <class T>
void Queue<T>::Print()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	PriorityHuman<T>* e;
	e = first;
	while (1)
	{
		cout << e->h->value << ",\t ";
		if ((e->next == 0) && (e->next == nullptr) && (e->next == NULL))
		{
			cout << endl; return;
		}
		else	e = e->next;
	}

}

template <class T>
void Queue<T>::Mult() {
	if (count < 3) {
		cout << "Error: count < 3 \n";
		return;
	}

	PriorityHuman<T>* e = first;
	int mult = 1;

	for (int i = 0; i < 3; i++)
	{
		mult *= e->h->value;
		e = e->next;
	}

	cout << "\nmult 3 elements:" << mult << endl;
}
