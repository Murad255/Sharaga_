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
	PriorityHuman() :prev(nullptr), next(nullptr), h(nullptr),priority(0) //prev = NULL; next = NULL; value = 0;
	{ };
	PriorityHuman(Human* h,int priority) :prev(nullptr), next(nullptr) //prev = NULL; next = NULL; value = 0;
	{ 
		this->h = h;
		this->priority = priority;
	};
};
