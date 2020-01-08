#pragma once
#include "Human.h"

class Queue
{
public:
	PriorityHuman* first;
	PriorityHuman* last;
	int count;
	Queue(void);
	~Queue(void);
	virtual void Put(PriorityHuman* e);//вывод элемента из очереди
	void PutAfter(PriorityHuman* afterH, PriorityHuman* e);
	PriorityHuman* Get();		//вставка элемента в очередь
	void Print();	//печать в консоль всех элементов
	void Mult();
};
