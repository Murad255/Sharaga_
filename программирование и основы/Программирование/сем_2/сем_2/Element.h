#pragma once
using namespace std;
template <class T>
class Element
{
public:
	Element<T>* prev;
	Element<T>* next;
	T value;

	Element<T>()
	{
		prev = nullptr; next = nullptr; value = 0;
	};
};
