#pragma once
#include"Element.h"
#include<iostream>
using namespace::std;

template <class T>
class Queue
{
public:
	Element<T>* first;
	Element<T>* last;

	int count;
	Queue(void);
	~Queue(void);
	void Put(Element<T>* e);//вывод элемента из очереди
	Element<T>* Get();		//вставка элемента в очередь
	void Print();	//печать в консоль всех элементов
	void Mult();
};



////////////////////Queue.cpp//////////////////////

template <typename T>
Queue<T>::Queue()
{
	first = 0;
	last = 0;
	count = 0;
}


template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::Put(Element<T>* e)
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

template <typename T>
Element<T>* Queue<T>::Get()
{
	Element<T>* e;
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

template <typename T>
void Queue<T>::Print()
{
	if (count < 1)
	{
		cout << "Queue is empty";
		return;
	}
	Element<T>* e;
	e = first;
	while (e != 0)
	{
		cout << e->value << ", ";
		e = e->next;
	}
	cout << endl;
}

template <typename T>
void Queue<T>::Mult() {
	if (count < 3) {
		cout << "Error: count < 3 \n";
		return;
	}

	Element<T>* e = first;
	T mult = 1;

	for (int i = 0; i < 3; i++)
	{
		mult *= e->value;
		e = e->next;
	}

	cout << "\nmult 3 elements:" << mult << endl;
}
