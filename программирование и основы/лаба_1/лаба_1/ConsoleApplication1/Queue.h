#pragma once
#include"Element.h"
class Queue
{
public:
	Element * first;
	Element* last;
	int count;
	Queue(void);
	~Queue(void);
	void Put(Element* e);//вывод элемента из очереди
	Element* Get();		//вставка элемента в очередь
	void Print();	//печать в консоль всех элементов
	void Mult(); 
};


