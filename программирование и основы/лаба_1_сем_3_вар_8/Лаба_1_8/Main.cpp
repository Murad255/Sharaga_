#include <iostream>
#include <conio.h>
//#include <windows.h>
#include "Figure.h"
#include "Rectangle.h"
#include "Rhombus.h";
#include "Circle.h"

using namespace std;

void putFigure(Figure**,int);	//��������� � ����������� ������ ������� ����� ����� ������ 
void PrintParam(Figure*);		//������� �������� ������

void main()
{
	setlocale(0, "");

	cout << "������� ��������� �� ������ �������:?\t";
	int maxCount;  //������������ ���������� ��������� � �������(������) 
	cin >> maxCount;
	Figure** arr = new Figure*[maxCount];
	int figCount = 0;
	while (1)
	{
		cout << "	������� ����� ��� ������������ ����a���\n\
					1 - ������� ������ \n \
					2 - ������� ��������� ������\n\
					3 - ����� �� ���������\n\
				";
		int num;
		cin >> num;

		switch (num)
		{
		case 1:
			if (figCount >= maxCount)
			{
				cout << "������ ����������!\n";
				continue;
			}
			
/////////////putFigure////////////////////
			cout << "	\n�������� ��� ������:\n\
				1 - �������������\n\
				2 - ����\n\
				3 - ����\n\
			";
			int a;
			cin >> a;

			switch (a)
			{
			case 1:

				arr[figCount] = new Rectangle();	//������ ������� (� ����� Figure*) ������� \
													����� �� ��������� ������� Rectangle
				cout << "\n������� ��������� �\t";
				cin >> ((Rectangle*)arr[figCount])->a;
				cout << "\n������� ��������� b\t";
				cin >> ((Rectangle*)arr[figCount])->b;
				break;
			case 2:
				arr[figCount] = new Rhombus();
				cout << "������� ��������� �\t";
				cin >> ((Rhombus*)arr[figCount])->a;
				cout << "������� ��������� h\t";
				cin >> ((Rhombus*)arr[figCount])->h;
				break;
			case 3:
				arr[figCount] = new Circle();
				cout << "������� ��������� r\t";
				cin >> ((Circle*)arr[figCount])->r;
				break;
			default:
				cout << "�� ����� �������� ��������";

			}
////////////////////////////////////////////////
			//putFigure(arr, figCount);
			figCount++;
			break;
		case 2:
			cout << "�������� ������� �� " << figCount << '\t';
			int b;
			cin >> b;
			--b;
				if (b < 0 && b >= maxCount)
				{

					cout << "\n�� ����� �������� ��������\n";
					continue;
				}
				else if (b > figCount)
				{
					cout << "\n����� �������� �� ����������\n";
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
			cout << "�� ����� �������� ��������\n";
		}
	}
}


void putFigure(Figure** mas,int num)
{
	Figure* point = mas[num];
	//system("clr");
	cout << "	\n�������� ��� ������:\n\
				1 - �������������\n\
				2 - ����\n\
				3 - ����\n\
			";
	int a;
	cin >>  a;


	switch (a)
	{
	case 1:

		point = new Rectangle();
		cout << "\n������� ��������� �\t";
		cin >> ((Rectangle*)point)->a;
		cout << "\n������� ��������� b\t";
		cin >> ((Rectangle*)point)->b;
		return;
	case 2:
		point = new Rhombus();
		cout << "������� ��������� �\t";
		cin >> ((Rhombus*)point)->a;
		cout << "������� ��������� h\t";
		cin >> ((Rhombus*)point)->h;
		return;
	case 3:
		point = new Circle();
		cout << "������� ��������� r\t";
		cin >> ((Circle*)point)->r;
		return;
	default:
		cout << "�� ����� �������� ��������";
	
	}
}

void PrintParam(Figure * ptr)
{
	cout << "	\n����� �������� ������ �������?: \n\
				1 - ���\n\
				2 - ��������\n\
				3 - �������\n\
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
		cout << "�� ����� �������� ��������!\n";
		return;
	}
}