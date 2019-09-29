#include <iostream>
#include <conio.h>
//#include <windows.h>
#include "Figure.h"
#include "Rectangle.h"
#include "Rhombus.h";
#include "Circle.h"

using namespace std;

void putFigure(Figure**,int);	//вставляет в определённую ячейку массива фигур новую фигуру 
void PrintParam(Figure*);		//выводит параметр фигуры

void main()
{
	setlocale(0, "");

	cout << "Сколько элементов вы хотите создать:?\t";
	int maxCount;  //максимальное количество элементов в массиве(предел) 
	cin >> maxCount;
	Figure** arr = new Figure*[maxCount];
	int figCount = 0;
	while (1)
	{
		cout << "	Нажмите цифру для произведения оперaции\n\
					1 - создать фигуру \n \
					2 - вывести параметры фигуры\n\
					3 - выход из программы\n\
				";
		int num;
		cin >> num;

		switch (num)
		{
		case 1:
			if (figCount >= maxCount)
			{
				cout << "Массив переполнен!\n";
				continue;
			}
			
/////////////putFigure////////////////////
			cout << "	\nВыберите тип фигуры:\n\
				1 - Прямоугольник\n\
				2 - Ромб\n\
				3 - Круг\n\
			";
			int a;
			cin >> a;

			switch (a)
			{
			case 1:

				arr[figCount] = new Rectangle();	//ячейке массива (с типом Figure*) передаём \
													адрес на созданный элемент Rectangle
				cout << "\nВведите пременную а\t";
				cin >> ((Rectangle*)arr[figCount])->a;
				cout << "\nВведите пременную b\t";
				cin >> ((Rectangle*)arr[figCount])->b;
				break;
			case 2:
				arr[figCount] = new Rhombus();
				cout << "Введите пременную а\t";
				cin >> ((Rhombus*)arr[figCount])->a;
				cout << "Введите пременную h\t";
				cin >> ((Rhombus*)arr[figCount])->h;
				break;
			case 3:
				arr[figCount] = new Circle();
				cout << "Введите пременную r\t";
				cin >> ((Circle*)arr[figCount])->r;
				break;
			default:
				cout << "Вы ввели неверное значение";

			}
////////////////////////////////////////////////
			//putFigure(arr, figCount);
			figCount++;
			break;
		case 2:
			cout << "Выберите элемент до " << figCount << '\t';
			int b;
			cin >> b;
			--b;
				if (b < 0 && b >= maxCount)
				{

					cout << "\nВы ввели неверное значение\n";
					continue;
				}
				else if (b > figCount)
				{
					cout << "\nЭтого элемента не существует\n";
					continue;
				}
			arr[b]->PrintName();
			PrintParam(arr[b]);
			break;
		case 3:
			for (int i = 0; i < figCount; i++)  delete arr[i];
			_getch();
			return;
		default:
			cout << "Вы ввели неверное значение\n";
		}
	}
}


void putFigure(Figure** mas,int num)
{
	Figure* point = mas[num];
	//system("clr");
	cout << "	\nВыберите тип фигуры:\n\
				1 - Прямоугольник\n\
				2 - Ромб\n\
				3 - Круг\n\
			";
	int a;
	cin >>  a;


	switch (a)
	{
	case 1:

		point = new Rectangle();
		cout << "\nВведите пременную а\t";
		cin >> ((Rectangle*)point)->a;
		cout << "\nВведите пременную b\t";
		cin >> ((Rectangle*)point)->b;
		return;
	case 2:
		point = new Rhombus();
		cout << "Введите пременную а\t";
		cin >> ((Rhombus*)point)->a;
		cout << "Введите пременную h\t";
		cin >> ((Rhombus*)point)->h;
		return;
	case 3:
		point = new Circle();
		cout << "Введите пременную r\t";
		cin >> ((Circle*)point)->r;
		return;
	default:
		cout << "Вы ввели неверное значение";
	
	}
}

void PrintParam(Figure * ptr)
{
	cout << "	\nКакой параметр фигуры вывести?: \n\
				1 - Имя\n\
				2 - Периметр\n\
				3 - Площадь\n\
			";
	int a;
	cin >> a;
	//Figure* h = (ptr[arrNum]);
	switch (a)
	{
	case 1:
		ptr->PrintName();
		return;
	case 2:
		ptr->GetPerimetr();
		return;
	case 3:
		ptr->GetSquare();
		return;
	default:
		cout << "Вы ввели неверное значение!\n";
		return;
	}
}