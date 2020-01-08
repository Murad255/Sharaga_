#include "stdafx.h"
#include "Header.h"
#include<iostream>
#include <windows.h>

#define countElem 10000
int* Generate(int n);
void Print(int* ch);
void Shell(int* A);
void choicesSort(int* arrayPtr);
using namespace::std;

int main()
{
	//system("color F0");
	setlocale(0,"");
	DWORD t1, t2;
	for (int i = 10000; i <= 1000000; i *= 10) {

		int* c = Generate(i/2);
		//Print(c);
		t1 = GetTickCount();
		choicesSort(c);
		t2 = GetTickCount();
		//Print(c);
		cout << "Время обработки " << i/2 << "\tэлеменитов:\t" << (int)(t2 - t1)<<'\n';
		delete[] c;

		c = Generate(i);
		//Print(c);
		t1 = GetTickCount();
		choicesSort(c);
		t2 = GetTickCount();
		//Print(c);
		cout << "Время обработки " << i << "\tэлеменитов:\t" << (int)(t2 - t1) << '\n';
		delete[] c;
	}
	_getch();
	
    return 0;
}
