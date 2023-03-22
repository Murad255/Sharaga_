/*
 * Queue.h
 *
 * Created: 19.04.2019 13:24:58
 *  Author: murad
 */

// мой старый код, использованный для stm32
// как работает точно не помню

#ifndef QUEUE_H_
#define QUEUE_H_

#define MaxData  40 //4086
//#define NULL '\0'
//#define Qen char

template <class Qen>
class Queue
{

	Qen data[MaxData];
	int getLoc, setLoc, coint;

public:

	Queue()
	{
		setLoc = getLoc = coint = 0;
	}

	//для вставки значения в очередь
	bool set(Qen inData)
	{
		// if (coint == MaxData)
		// 	return 1;
		// else if (setLoc == MaxData)
		// 	setLoc = 0;

		coint++;
		data[setLoc++] = inData;
		return 0;
	}

	//возвращает ээлемент из очереди
	Qen get()
	{
		if ((getLoc == setLoc) && (coint != MaxData))
			return 0;
		else if (getLoc == MaxData)
			getLoc = 0;

		coint--;
		return data[getLoc++];
	}

	//возвращает 1, если в очереди есть елементы
	bool Available()
	{
		return (bool)coint;
	}
};

#endif /* QUEUE_H_ */