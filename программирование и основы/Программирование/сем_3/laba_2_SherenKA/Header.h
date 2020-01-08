#pragma once
class Element
{
public:
	Element* prev;// ссылка на предыдущее значение
	Element* next;//ссылка на следующее значение
	int value;
	Element() :prev(NULL), next(NULL), value(0) //prev = NULL; next = NULL; value = 0;
	{ };
};