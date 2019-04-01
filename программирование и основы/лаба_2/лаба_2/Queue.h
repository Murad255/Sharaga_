#pragma once
//определение класса очереди
class Queue
{
public:
	Figure * first;
	Figure* last;
	int count;
	Queue(void);
	~Queue(void);
	void Put(Figure* e);
	Figure* Get();
	void ShowSquares();
	void ShowPerimetr(); //ид. задание
};


