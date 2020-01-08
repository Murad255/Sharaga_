#pragma once
#include <cstddef>

template <class T>
class Human
{
public:
	T value;
	Human() :value(0) //prev = NULL; next = NULL; value = 0;
	{ };
};

template <class T>
class PriorityHuman
{
public:

	PriorityHuman* prev;// ссылка на предыдущее значение
	PriorityHuman* next;//ссылка на следующее значение

	Human<T>* h;
	int priority;
	PriorityHuman() :prev(nullptr), next(nullptr), h(nullptr),priority(0) //prev = NULL; next = NULL; value = 0;
	{ };
	PriorityHuman(Human<T>* h,int priority) :prev(nullptr), next(nullptr) //prev = NULL; next = NULL; value = 0;
	{ 
		this->h = h;
		this->priority = priority;
	};
};
