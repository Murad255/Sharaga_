#pragma once
#include "Element.h"
#include <iostream>
using namespace std;


template <class T>
class Stack
{
public:
	Element<T>* first;
	Element<T>* last;
	int count;

	Stack(void);
	~Stack(void);
	void Put(Element<T>* e);
	Element<T>* Get();
	void Print();
	void Mult();
};

////////////////////Stack.cpp//////////////////////

template <typename T>
Stack<T>::Stack(void)
{
	first = 0;
	last = 0;
	count = 0;
}
template <typename T>
Stack<T>::~Stack(void)
{
}

template <typename T>
void Stack<T>::Put(Element<T>* e)
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
}
template <typename T>
Element<T>* Stack<T>::Get()
{
	Element<T>* e;
	if (first == 0)
		return 0;
	e = first;
	first = first->next;
	first->prev = 0;
	e->next = 0;
	count--;
	cout << "Element " << e->value << "removed from stack" << endl;
	return e;
}
template <typename T>
void Stack<T>::Print()
{
	if (count < 1)
	{
		cout << "Queue is stack";
		return;
	}
	Element<T>* e;
	e = last;

	while (e != 0)
	{
		cout << e->value << ";";
		e = e->prev;
	}
	cout << endl;
}

template <typename T>
void Stack<T>::Mult()
{
	Element<T>* e;
	e = first;
	unsigned long int m = 1;
	while (e != 0)
	{
		m = m * e->value;
		e = e->next;
	}

	cout << m << endl;
}