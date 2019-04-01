#pragma once
#include"Element.h"
class Stack
{
public:
	Element * first;
	Element* last;
	int count;
	Stack(void);
	~Stack(void);
	void Put(Element* e);//вывод элемента из стека
	Element* Get();//вставка элемента в стека
	void Print();//печать в консоль всех элементов
};

