#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <random>

using namespace::std;

//���������� ��������� �� ��������������� ������ ������ n
int * generate(int n, int lim = 0) {
	int * arr = new int[n];     //�������� ����� ��� ������
	for (int i = 0; i < n; i++)
		if (lim == 0) arr[i] = rand();        //��������� ������ ���������������� �������
		else arr[i] = rand() % lim;
	return  arr;    //���������� ��������� �� ����. ������
}

//������� �� ����� n ��������� ������� arr
void print(int * arr, int n) {
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}


void Shell(int* arr, int n) //���������� �����
{
	register int  j;
	int d = n;
	d = d / 2;
	while (d > 0)
	{
		register long int i;
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && arr[j] > arr[j + d])
			{
				int count = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}


//���������� ���������
void sort(int* arr, int n) {
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
}