#pragma once
class Complex
{
	double Re, Im;
public:
	Complex();
	Complex(double Im, double Re);

	Complex operator+(Complex c); //сложение
	Complex operator-(Complex c); //вычитание
	Complex operator*(Complex c); //умножение
	Complex operator/(Complex c); //деление

	// операции над действительной частью

	Complex operator+(double c); //сложение
	Complex operator-(double c); //вычитание
	Complex operator*(double c); //вычитание
	Complex operator/(double c); //вычитание

	bool operator==(Complex c); //сравнение
	double Mod(); //модуль


	void Print();

	~Complex(void);
};

