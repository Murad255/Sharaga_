#pragma once
#include <Arduino.h>

/*
	Класс для поиска и  возврата значения после ключевого слова.
	Для поиска требуется в буфер buf записать строку и
	в bufLength указать её длину, и затем вызвать нужный метод.
*/
class Parser
{
private:
	char findBuf[100];

public:
	static const int bufMaxLength = 100; // максимальное число символов
	char buf[bufMaxLength];				 // буфер строки поиска
	int bufLength;						 // длина заданной строки

	int findSymbol(const char findContext); // возвращает индекс искомого символа, если не найден, то -1
	int findStr(const char *findContext);	// возвращает индекс искомой строки, если не найден, то -1
	bool isFind(const char *findContext);	// возвращает true, если искомая строка найдена, иначе false
	bool findInt(int *result);				// считывает значение int от -32760 до 32760
	bool findFloat(float *result);			// считывает значение float до 2х знаков после запятой
	bool findStr8(char *findStr8);			// считывает первые 8 символов после команды setStr
	void bufClean();						//отчистка буфера
};

// String Parser::findTextXML( String str, String findContext)
// {
// 	int find1 = str.indexOf("<" + findContext + ">");
// 	int find2 = str.indexOf("</" + findContext + ">");
// 	if ((find1 < 1) || (find2 < 1))
// 		return "";
// 	String findStr = "";
// 	for (int i = find1 + ("<" + findContext + ">").length(); i < find2; i++)
// 	{
// 		findStr += str[i];
// 	}
// 	return findStr;
// }

///отчистка буфера
void Parser::bufClean()
{
	//посимвольно зануляем символы в буфере
	for (int i = 0; i < bufMaxLength; i++)
		buf[i] = 0;
}

/* поиск  символа findContext в строке
 * возвращает индекс найденого символа, иначе -1 */
int Parser::findSymbol(const char findContext)
{
	//проверяем каждый символ
	for (int i = 0; i < bufLength; i++)
	{
		// при нахождении возвращаем индекс
		if (findContext == Parser::buf[i])
			return i;
	}
	return -1;
}

/* поиск строки в буфере
 * аналог indexOf, возвращает -1, если строка не найдена,
 * или индекс первого символа найденной строки */
int Parser::findStr(const char *findContext)
{
	// проверяем буфер до
	for (int i = 0; i < bufLength - (int)strlen(findContext) + 1; i++)
	{
		// копируем равную по длинне с искомой строку из буфера
		// со сдвигом на i символов во временный буфер
		strncpy(findBuf, &buf[i], (int)strlen(findContext));
		//обозначаем конец
		findBuf[(int)strlen(findContext)] = 0;
		// если строки равны, то возвращаем её индекс в буфере
		if (strcmp(findContext, findBuf) == 0)
			return i;
	}
	return -1; // если не найдена
}

bool Parser::findStr8(char *findContext)
{
	// int mult = 1;
	// const int naxNum = 6;
	// char *strNum[naxNum];
	int start;	  // начальный индекс
	int cNum = 0; // индекс записи
	// начинаем поиск с пробела
	start = findSymbol(' ') + 1;

	for (int i = 0; i < 8; i++) // cNum <= 8; i++)
	{
		char c = buf[start + i];
		// проверка, это латинский символ или число
		if ((c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z'))
		{
			// записываем во временный буфер и сдвигаем индекс
			findContext[cNum] = c;
			cNum++;
		}
	}
	findContext[cNum] = 0; //обозначаем конец
	return 1;
}

///возвращает true если строка найдена
bool Parser::isFind(const char *findContext)
{
	if (findStr(findContext) >= 0)
		return true;
	else
		return false;
}

/* считывает значение int от -32760 до 32760
 * если найдено значение, то возвращиет true
 * результат возвращает через ссылку result	*/
bool Parser::findInt(int *result)
{
	int mult = 1;		  //множитель для отрицательного числа
	const int naxNum = 6; //предел для int16
	// char *strNum[naxNum];
	int start;	 // начальный индекс
	int num = 0; // индекс записи
	// начинаем поиск с пробела или знака -
	if ((start = findSymbol('-')) >= 0)
	{
		mult = -1; // полученное число в конце сделаем отрицательным
		++start;
	}
	else
	{
		start = findSymbol(' ') + 1;
	}

	int i = 0;
	//продолжаем поиск со старта до конца буфера
	while (buf[start + i] != 0) //(( i < naxNum) &&(buf[start + i]!=0))
	{
		// определяем, число ли это
		int n = buf[start + i] - '0';
		if (n >= 0 && n <= 9)
		{
			if (num >= 3276) // проверка на выход за пределы int16
				return 0;
			num *= 10; // десятичный сдвиг влево текущего значения
			num += n;  // в конец прибавляем число
		}
		//если следующий символ не пробел (его пропускаем), то выходим из цикла
		else if (buf[start + i] != ' ')
			break;

		i++;
	}
	if (!i)
		return 0;  // если не было цифр
	num *= mult;   // при необходимости делаем отрицательным
	*result = num; // присваиваем ссылку на число
	return 1;
}

/* считывает значение float до 2х знаков после запятой
 * если найдено значение, то возвращиет true
 * результат возвращает через ссылку result	*/
bool Parser::findFloat(float *result)
{
	int mult = 1;
	const int naxNum = 6;
	char *strNum[naxNum];
	int start;
	float num1 = 0; // число до запятой
	float num2 = 0; // число после запятой
	float fNum = 0;
	// начинаем поиск с пробела или знака -
	if ((start = findSymbol('-')) >= 0)
	{
		mult = -1;
		++start;
	}
	else
	{
		start = findSymbol(' ') + 1;
	}

	//находим целое число
	int i = 0;
	while (buf[start + i] != 0)
	{
		int n = buf[start + i] - '0';
		if (n >= 0 && n <= 9)
		{
			if (num1 >= 3276)
				return 0;
			num1 *= 10;
			num1 += n;
		}
		// выходим из цикла при достижении запятой, точки или пробела
		else if (
			buf[start + i] != ' ' ||
			buf[start + i] != '.' ||
			buf[start + i] != ',')
		{
			break;
		}

		i++;
	}

	// находим дробь
	// если найдена точка иля запятая, отмечаем начало дробной части
	if ((start = findSymbol('.')) >= 0)
		++start;
	else if ((start = findSymbol(',')) >= 0)
		++start;
	// если не найдена точка или запятая, возвращаем найденное число
	else
	{
		num1 *= mult;
		*result = num1;
		return 1;
	}

	i = 0;
	int dev = 1; // делитель дробной части
	while ((i < naxNum) && (buf[start + i] != 0))
	{
		int n = buf[start + i] - '0';
		if (n >= 0 && n <= 9)
		{
			dev *= 10;
			num2 *= 10;
			num2 += n;
		}
		else if (buf[start + i] != ' ')
			break;

		i++;
	}
	// делим целое число на делитель для получения дробной части
	num2 /= dev;
	fNum = num1 + num2; // складываем целую и дробную части
	fNum *= mult;
	*result = fNum;
	return 1;
}
