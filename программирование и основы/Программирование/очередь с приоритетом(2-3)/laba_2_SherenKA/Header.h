#pragma once
class Element
{
public:
	Element* prev;// ������ �� ���������� ��������
	Element* next;//������ �� ��������� ��������
	int value;
	Element() :prev(NULL), next(NULL), value(0) //prev = NULL; next = NULL; value = 0;
	{ };
};