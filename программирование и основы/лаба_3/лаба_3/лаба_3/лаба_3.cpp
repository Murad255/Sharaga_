#include "stdafx.h"
#include "Header.h"
#include<iostream>
#include <windows.h>

#include <iostream>
#include <random>
//#include <utility>

//#include <chrono>   //Время
#include <time.h>

using namespace::std;

//Сортировка пузырьком
void sort(int* arr, int n) {
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
}

//Возвращает указатель на сгенерированный массив длинны n
int* generate(int n, int lim = 0) {
	int* arr = new int[n];     //Выделяем место под массив
	for (int i = 0; i < n; i++)
		if (lim == 0) arr[i] = rand();        //Заполняем массив псевдослучайными числами
		else arr[i] = rand() % lim;
	return  arr;    //Возвращаем указатель на сген. массив
}

//Выводит на экран n элементов массива arr
void print(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}



int main() {

	setlocale(0,"");
	cout << "Сортировка пузырьком" << endl << "Part 1: \n";
	srand(time(nullptr));			//инициализация seed генератора псевдослучайных чисел...

	DWORD t1, t2;
	int n = 20;						//Массив из 20 элементов

	int* arr = generate(n, 1000);	//Генерируем
	print(arr, n);					//Выводим

	t1 = GetTickCount();	//Засекаем время
	sort(arr, n);			//Сортируем
	t2 = GetTickCount();	//Сохраняем время завершения сортировки

																			
	print(arr, n);
	delete[] arr;       //Освобождаем память

	cout << "time: " << (int)(t2 - t1) << "ms" << endl << endl << "Part 2: \n";    //Выводим время (в мс)

	

	for (int n = 10; n <= 10000000; n *= 10) {
		//Где n - длинна тестируемого массива
		cout << n << "\t\t";

		int rounds = 10;    //Кол-во сортировок
		//Время выполнения round сортировок массивов из n элементов
		double time = 0;

		for (int i = 0; i < rounds; i++) {
			int* arr = generate(n);	//Создаем массив

			//СОРТИРОВКА
			t1 = GetTickCount();	//Засекаем время
			sort(arr, n);			//Сортируем
			t2 = GetTickCount();	//Сохраняем время завершения сортировки
																	 
			delete[] arr;			//Освобождаем память
		}
		cout << "Время обработки " << (double)(t2 - t1);

		cout << ((int)(t2 - t1)) / rounds << "ms" << std::endl;    //Выводим время (в мс)
	}
	return 0;
}