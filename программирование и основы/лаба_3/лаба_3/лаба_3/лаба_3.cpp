#include "stdafx.h"
#include "Header.h"
#include<iostream>
#include <windows.h>

#define countCort 1000000
int*	Generate(int n);	//it returns the pointer to the arr with	[n] elem
void	Print(int* ch);
void	Shell(int* A);
void	choicesSort(int* arrayPtr);

using namespace::std;

int main()
{
	system("color F0");
	setlocale(0,"");
	DWORD t1, t2;
	int * c = Generate(countCort);
	//Print(c);  
	t1 = GetTickCount();
	Shell(c);
	//choicesSort(c);
	t2 = GetTickCount();
	//Print(c);
	cout << "Время обработки "<< countCort <<" сортировкой Шелла:\t"<<(int)(t2-t1);
	_getch();
	delete[] c;
    return 0;
}
