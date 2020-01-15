#pragma once
#include <cstddef>
class Human
{
public:
	int value;
	Human() :value(0) //prev = NULL; next = NULL; value = 0;
	{ };
};

class PriorityHuman
{
public:

	PriorityHuman* prev;// ссылка на предыдущее значение
	PriorityHuman* next;//ссылка на следующее значение

	Human* h;
	int priority;
	PriorityHuman() : priority(0), prev(NULL), next(NULL), h(NULL) //prev = NULL; next = NULL; value = 0;
	{ };

	PriorityHuman(Human* h, int priority) :prev(NULL), next(NULL)
	{
		this->h = h;
		this->priority = priority;
	};
};
