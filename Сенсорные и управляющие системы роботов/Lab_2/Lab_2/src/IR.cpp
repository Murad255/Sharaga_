// #include <Arduino.h>

// #define IRpin A0

// #define echoPin 2
// #define trigPin 3

// // Фильтр, основанный на вычислении среднего арифметического
// int f1(int *vals, int count)
// {
// 	long val = 0;
// 	for (int i = 0; i < count; i++)
// 	{
// 		val += vals[i];
// 	}
// 	// float volts = (float)(val / count) * 0.0048828125;
// 	return (val / count);
// }

// double D(int *vals, int count, int Mint)
// {
// 	long D = 0;
// 	for (int i = 0; i < count; i++)
// 	{
// 		D += pow(vals[i] - Mint, 2);
// 	}
// 	int Df = (D / (count - 1)); // * 0.0048828125*0.0048828125;
// 	return Df;
// }

// // Фильтр, основанный на вычислении среднего геометрического
// int f2(int *vals, int count)
// {
// 	uint64_t temp = 1;

// 	for (int i = 0; i < count / 10; i++)
// 	{
// 		uint64_t tempC = 1;
// 		for (int j = 0; j < count / 10; j++)
// 		{
// 			tempC *= vals[i * count / 10 + j] / 10;
// 		}
// 		temp *= pow(tempC, 1.0 / ((double)count / 10.0));
// 	}
// 	return pow(temp, 1.0 / ((double)count / 10.0)) * 10; // * 0.0048828125;
// }

// int ArrayCompare(const int *AFirst, const int *ASecond)
// {
// 	if (*AFirst < *ASecond)
// 		return -1;
// 	return (*AFirst == *ASecond) ? 0 : 1;
// }

// // Медианный фильтр
// int f3(int *vals, int count)
// {
// 	size_t M_Size = sizeof(vals) / sizeof(vals[0]);
// 	qsort(vals, M_Size, sizeof(vals[0]), ArrayCompare);

// 	return vals[50]; //* 0.0048828125;
// }

// // Фильтр, основанный на вычислении среднего гармонического
// int f4(int *vals, int count)
// {
// 	double val = 0;
// 	for (int i = 0; i < count; i++)
// 	{
// 		val += 1.0 / (double)vals[i];
// 	}
// 	return (int)(((double)count) / val); //* 0.0048828125;
// }

// // Фильтр срединной точки:
// int f5(int *vals, int count)
// {
// 	size_t M_Size = sizeof(vals) / sizeof(vals[0]);
// 	qsort(vals, M_Size, sizeof(vals[0]), ArrayCompare);

// 	return (vals[0] + vals[count - 1]) / 2; //* 0.0048828125;
// }

// void SelectionSort(int *sensArr, int count)
// {
// 	for (int j = 0; j < count; ++j)
// 	{
// 		int temp = sensArr[j];
// 		int ind = j;
// 		for (int i = j + 1; i < count; ++i)
// 		{
// 			if (temp > sensArr[i])
// 			{
// 				temp = sensArr[i];
// 				ind = i;
// 			}
// 		}
// 		sensArr[ind] = sensArr[j];
// 		sensArr[j] = temp;
// 	}
// }

// void setup()
// {
// 	pinMode(IRpin, 0);
// 	Serial.begin(9600);
// }

// void loop()
// {
// 	long val = 0;
// 	long N = 100; // выборка неа основе 100 значений
// 	int vals[100];

// 	// считывание показаний АЦП
// 	for (int i = 0; i < N ; i++)
// 	{
// 		vals[i] = (long)analogRead(IRpin);
// 		delay(10);
// 	}
// 	// вычисление математического ожидания
// 	long val = 0;
// 	for (int i = 0; i < N ; i++)
// 	{
// 		val += vals[i];
// 	}
// 	double M = ((double)val / (double)N ) * 0.0048828125;

// 	double D = 0;
// 	for (int i = 0; i < N ; i++)
// 	{
// 		D += (vals[i] - (val / N )) * (vals[i] - (val / N ));
// 	}
// 	double Df = (D / (N  - 1)) * 0.0048828125*0.0048828125;
// 	// среднеквадратичное отклонение
// 	double Q = pow(Df,2);
// 	// ОСШ
// 	double Relation = M /Q ;
// 	Serial.print(M);
// 	Serial.println("\t " + String(Df));

// 	// Выводим информацию в COM порт
// 	Serial.print(M);
// 	Serial.println('\t');
// 	Serial.print(D);
// }
