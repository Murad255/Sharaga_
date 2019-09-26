#include <iostream>
#include <conio.h>
//#include <windows.h>
#include "Figure.h"
#include "Rectangle.h"
#include "Rhombus.h";
#include "Circle.h"

using namespace std;

int GetNum();
Figure* getFigure();
void PrintParam(Figure**, int);


void main()

{
	setlocale(0, "");
	
	cout << "Сколько элементов вы хотите создать:?\t";
	int maxCount;
	cin >> maxCount;
	Figure** arr; //= new Figure[maxCount];

	
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
			
				
			cout << "	\nВыберите тип фигуры:\n\
				1 - Прямоугольник\n\
				2 - Ромб\n\
				3 - Круг\n\
			";
			int a;
			Figure* point;
			cin >> a;
			switch (a)
			{
			case 1:

				Rectangle* rec = new Rectangle();
				cout << "\nВведите пременную а\t";
				cin >> rec->a;
				cout << "\nВведите пременную b\t";
				cin >> rec->b;
				//return point;
				arr[figCount++] = rec;
			case 2:
				point = new Rhombus();
				cout << "Введите пременную а\t";
				cin >> ((Rhombus*)point)->a;
				cout << "Введите пременную h\t";
				cin >> ((Rhombus*)point)->h;
				//return point;
			case 3:
				point = new Circle();
				cout << "Введите пременную r\t";
				cin >> ((Circle*)point)->r;
				//return point;
			default:
				cout << "Вы ввели неверное значение";
				continue;
			}
		break;
		case 2:
			cout << "Выберите элемент до " << maxCount<<'\t';
			int b;
			cin >> b;
			if (b < 0 && b >= maxCount)
			{
				cout << "\nВы ввели неверное значение\n";
				continue;
			}
			else if (b>figCount)
			{
				cout << "\nЭтого элемента не существует\n";
				continue;
			}
			PrintParam(arr,b);
			break;
		case 3:
			return;
		default:
			cout << "Вы ввели неверное значение\n";
		}
	}
	_getch();
}


Figure * getFigure()
{
	//system("clr");
	

}

void PrintParam(Figure ** ptr, int arrNum)
{
	cout << "	\nКакой параметр фигуры вывести?: \n\
				1 - Имя\n\
				2 - Периметр\n\
				3 - Площадь\n\
			";
	int a;
	cin >> a;
	Figure* h = (ptr[arrNum]);
	switch (a)
	{
	case 1:
		h->PrintName();
		return;
	case 2:
		h->GetPerimetr();
		return;
	case 3:
		h->GetSquare();
		return;
	default:
		cout << "Вы ввели неверное значение!\n";
		return;
	}
}
