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
	virtual void Put(PriorityHuman* e);//����� �������� �� �������
	void PutAfter(PriorityHuman* afterH, PriorityHuman* e);
	PriorityHuman* Get();		//������� �������� � �������
	void Print();	//������ � ������� ���� ���������
	void Mult();
};
