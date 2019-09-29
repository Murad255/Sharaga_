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
	
	cout << "������� ��������� �� ������ �������:?\t";
	int maxCount;
	cin >> maxCount;
	Figure** arr; //= new Figure[maxCount];

	
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
			
				
			cout << "	\n�������� ��� ������:\n\
				1 - �������������\n\
				2 - ����\n\
				3 - ����\n\
			";
			int a;
			Figure* point;
			cin >> a;
			switch (a)
			{
			case 1:

				Rectangle* rec = new Rectangle();
				cout << "\n������� ��������� �\t";
				cin >> rec->a;
				cout << "\n������� ��������� b\t";
				cin >> rec->b;
				//return point;
				arr[figCount++] = rec;
			case 2:
				point = new Rhombus();
				cout << "������� ��������� �\t";
				cin >> ((Rhombus*)point)->a;
				cout << "������� ��������� h\t";
				cin >> ((Rhombus*)point)->h;
				//return point;
			case 3:
				point = new Circle();
				cout << "������� ��������� r\t";
				cin >> ((Circle*)point)->r;
				//return point;
			default:
				cout << "�� ����� �������� ��������";
				continue;
			}
		break;
		case 2:
			cout << "�������� ������� �� " << maxCount<<'\t';
			int b;
			cin >> b;
			if (b < 0 && b >= maxCount)
			{
				cout << "\n�� ����� �������� ��������\n";
				continue;
			}
			else if (b>figCount)
			{
				cout << "\n����� �������� �� ����������\n";
				continue;
			}
			PrintParam(arr,b);
			break;
		case 3:
			return;
		default:
			cout << "�� ����� �������� ��������\n";
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
	cout << "	\n����� �������� ������ �������?: \n\
				1 - ���\n\
				2 - ��������\n\
				3 - �������\n\
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
		cout << "�� ����� �������� ��������!\n";
		return;
	}
}
