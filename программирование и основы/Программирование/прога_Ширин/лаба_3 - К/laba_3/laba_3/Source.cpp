#include "Header.h"
#include <windows.h>
#include <iostream>
#include <random>

using namespace::std;

int main() {

	setlocale(0, "");
	cout << "Сортировка Шелла" << endl << "Part 1: \n";

	DWORD t1, t2;
	int n = 20;

	int* arr = generate(n, 1000);
	print(arr, n);

	t1 = GetTickCount();
	Shell(arr, n);
	t2 = GetTickCount();

	print(arr, n);
	delete[] arr;

	cout << "\ntime: " << (int)(t2 - t1) << "ms" << endl << endl << "Part 2: \n";

	for (int n = 10; n <= 10000000; n *= 10) {
		cout << n << "\t\t";

		double time = 0;
		int* arr = generate(n);

		t1 = GetTickCount();
		Shell(arr, n);
		t2 = GetTickCount();

		cout << "Время обработки " << (double)(t2 - t1) << "ms" << endl;

		delete[] arr;
	}
	return 0;
}