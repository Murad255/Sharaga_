
#include <iostream>
#include "Complex.h"
#include <conio.h>

using namespace::std;

int main()
{
	Complex c1(23.8, -17.6);
	Complex c2(10, 5.5);
	Complex c3;


	c3 = c1 + c2;

	c1.Print();
	cout << '+';
	c2.Print();
	cout<< '=';
	c3.Print();
	cout <<'\n';

	c3 = c1 - c2;
	c1.Print();
	cout<< '-';
	c2.Print();
	cout<< '=';
	c3.Print();
	cout <<'\n';

	c3 = c1 * c2;
	c1.Print();
	cout<< '*';
	c2.Print();
	cout << '=';
	c3.Print();
	cout << '\n';

	c3 = c1 / c2;
	c1.Print();
	cout << '/';
	c2.Print();
	cout << '=';
	c3.Print();
	cout << '\n';

	cout<< "\n|c3|="<<c3.Mod();


	_getch();
	return 0;

}