#pragma once
#include"Element.h"
class Stack
{
public:
	Element* first;
	Element* last;
	int count;
	Stack(void);
	~Stack(void);

	void	  Put(Element* e);	//вставка элемента в стек
	Element*  Get();			//вывод элемента из стека
	void Print();//печать в консоль всех элементов
};

