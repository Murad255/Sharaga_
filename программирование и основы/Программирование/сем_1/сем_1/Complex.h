#pragma once
class Complex
{
	double Re, Im;
public:
	Complex();
	Complex(double Im, double Re);

	Complex operator+(Complex c); //��������
	Complex operator-(Complex c); //���������
	Complex operator*(Complex c); //���������
	Complex operator/(Complex c); //�������

	// �������� ��� �������������� ������

	Complex operator+(double c); //��������
	Complex operator-(double c); //���������
	Complex operator*(double c); //���������
	Complex operator/(double c); //���������

	bool operator==(Complex c); //���������
	double Mod(); //������


	void Print();

	~Complex(void);
};

