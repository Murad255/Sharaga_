#include "Header.h"
#include <windows.h>
#include <iostream>
#include <random>

using namespace::std;



int main()
{
	//system("color F0");
	setlocale(0,"");
	DWORD t1, t2;
	int * c = Generate(100000);
	//Print(c);
	t1 = GetTickCount();
	Shell(c);
	t2 = GetTickCount();
	//Print(c);
	cout << "Время обработки "<<(int)(t2-t1);
	_getch();
	delete c;
    return 0;
}
