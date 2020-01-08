#include "Element.h"
#include "Queue.h"
#include <conio.h>
#include <iostream>
#include "Stack.h"

using namespace std;


int main()
{
	Element<float> e1, e2, e3, e4, e5;

	e1.value = 10.5;
	e2.value = 20.6;
	e3.value = 30.789;
	e4.value = 40.135;
	e5.value = 50.864;

	Queue<float> s;

	s.Put(&e2);
	s.Put(&e3);
	s.Put(&e1);
	s.Put(&e5);
	s.Put(&e4);


	s.Print();

	s.Get();
	s.Get();


	s.Print();
	s.Mult();

	_getch();
	return 0;
}