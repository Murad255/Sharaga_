#pragma once
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include<conio.h>

using namespace::std;


int* Generate(int n) {
	int* ch = new int[n];
	srand(GetTickCount());
	register long int i;
	for ( i = 0; i <n; i++) {
		ch[i] = rand();
	}
	return ch;
}

void Print(int* ch) {
	for (long int i = 0; i < (_msize(ch) / sizeof(ch[0])); i++) {
		std::cout << "element " << i << ": " << ch[i] << '\n';
	}
	return;
}


void Shell(int* A) //сортировка Шелла
{
	long int n = (_msize(A) / sizeof(A[0]));
	register int  j;
	int d = n;
	d = d / 2;
	while (d>0)
	{
		register long int i;
		for (i = 0; i<n - d; i++)
		{
			j = i;
			while (j >= 0 && A[j]>A[j + d])
			{
				int count = A[j];
				A[j] = A[j + d];
				A[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}

void choicesSort(int* arrayPtr) // сортировка выбором(ид. задание)
{
	long int length_array = _msize(arrayPtr) / sizeof(arrayPtr[0]);
	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
		for (long int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}
}