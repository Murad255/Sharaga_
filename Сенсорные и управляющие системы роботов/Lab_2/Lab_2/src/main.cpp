#include <Arduino.h>

#define IRpin A0

#define echoPin 2
#define trigPin 3

// Фильтр, основанный на вычислении среднего арифметического
int f1(int *vals, int count)
{
  long val = 0;
  for (int i = 0; i < count; i++)
  {
    val += vals[i];
  }
  // float volts = (float)(val / count) * 0.0048828125;
  return (val / count);
}

unsigned long D(int *vals, int count, int Mint)
{
  unsigned long D = 0;
  for (int i = 0; i < count; i++)
  {
    D += ((vals[i] - Mint)*(vals[i] - Mint))/10;
  }
  return (D / (count - 1))*10; // * 0.0048828125*0.0048828125;
  //return Df;
}

// Фильтр, основанный на вычислении среднего геометрического
int f2(int *vals, int count)
{
  uint64_t temp = 1;

  for (int i = 0; i < count / 10; i++)
  {
    uint64_t tempC = 1;
    for (int j = 0; j < count / 10; j++)
    {
      tempC *= vals[i * count / 10 + j] / 10;
    }
    temp *= pow(tempC, 1.0 / ((double)count / 10.0));
  }
  return pow(temp, 1.0 / ((double)count / 10.0)) * 10; // * 0.0048828125;
}

int ArrayCompare(const int *AFirst, const int *ASecond)
{
  if (*AFirst < *ASecond)
    return -1;
  return (*AFirst == *ASecond) ? 0 : 1;
}

// Медианный фильтр
int f3(int *vals, int count)
{
  size_t M_Size = sizeof(vals) / sizeof(vals[0]);
  qsort(vals, M_Size, sizeof(vals[0]), ArrayCompare);

  return vals[50]; //* 0.0048828125;
}

// Фильтр, основанный на вычислении среднего гармонического
int f4(int *vals, int count)
{
  double val = 0;
  for (int i = 0; i < count; i++)
  {
    val += 1.0 / (double)vals[i];
  }
  return (int)(((double)count) / val); //* 0.0048828125;
}

// Фильтр срединной точки:
int f5(int *vals, int count)
{
  size_t M_Size = sizeof(vals) / sizeof(vals[0]);
  qsort(vals, M_Size, sizeof(vals[0]), ArrayCompare);

  return (vals[0] + vals[count - 1]) / 2; //* 0.0048828125;
}

void SelectionSort(int *sensArr, int count)
{
  for (int j = 0; j < count; ++j)
  {
    int temp = sensArr[j];
    int ind = j;
    for (int i = j + 1; i < count; ++i)
    {
      if (temp > sensArr[i])
      {
        temp = sensArr[i];
        ind = i;
      }
    }
    sensArr[ind] = sensArr[j];
    sensArr[j] = temp;
  }
}

void setup()
{
  pinMode(IRpin, 0);
  Serial.begin(9600);
  Serial.println("Start");
}
void loop(){

  Serial.println("test");
  delay(1000);
}


// void loop()
// {
//   long count = 100;
//   int durations[100];

//   for (int i = 0; i < count; i++)
//   {
//     // Генерация короткого импульса длительностью 2 микросекунды
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);

//     // В течении 10 микросекунд датчик посылает сигналы в 40 кГц
//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigPin, LOW);

//     // Получаем время задержки с выхода Echo
//     durations[i] = pulseIn(echoPin, HIGH);
//    // delay(10);
//   }


//   // фильтрация показаний
//   int f11 = f1(durations, count);
//   double duration1 = (double)f11/58.0;
//   double duration2 = (double)f2(durations, count) / 58.0;
//   double duration3 = (double)f3(durations, count) / 58.0;
//   double duration4 = (double)f4(durations, count) / 58.0;
//   double duration5 = (double)f5(durations, count) / 58.0;

//   // // Находим расстояние в сантиметрах и дюймах
//   // cm = duration / 58;
//   // inch = duration / 148;
//    double Df = (double)D(durations, count, f11)*100.0/ (58.0*58.0);
//   // // среднеквадратичное отклонение
//   // double Q = 0; // pow(Df, 2);
//   // // ОСШ
//   // double Relation = duration1 / Q;

//   // Выводим информацию в COM порт
//   Serial.print(durations[0]/58);
//   Serial.print('\t');

//   Serial.print(duration1);
//   Serial.print('\t');

//   Serial.print(duration2);
//   Serial.print('\t');

//   Serial.print(duration3);
//   Serial.print('\t');

//   Serial.print(duration4);
//   Serial.print('\t');

//   Serial.print(duration5);
//   Serial.print('\t');
//     Serial.println(Df);
//   // Serial.print('\t');
//   //   Serial.print(Q);
//   // Serial.print('\t');
//   //   Serial.println(Relation);
// }

// void loop()
// {
//   long val = 0;
//   long count = 100;
//   int vals[100];

//   for (int i = 0; i < count; i++)
//   {
//     vals[i] = (long)analogRead(IRpin);
//     delay(10);
//   }
//   int volts1 = f1(vals, count);
//   Serial.print(volts1);
//   Serial.print('\t');

//   int volts2 = f2(vals, count);
//   Serial.print(volts2);
//   Serial.print('\t');

//   int volts3 = f3(vals, count);
//   Serial.print(volts3);
//   Serial.print('\t');

//   int volts4 = f4(vals, count);
//   Serial.print(volts4);
//   Serial.print('\t');

//   int volts5 = f5(vals, count);
//   Serial.println(volts5);
// }

// void loop()
// {
//   long val = 0;
//   long count = 100;
//   int vals[100];

//   for (int i = 0; i < count; i++)
//   {
//     vals[i] = (long)analogRead(IRpin);
//     delay(10);
//   }
//   int volts = f1(vals, count); //(float)(val / count) * 0.0048828125;

//   long D = 0;
//   for (int i = 0; i < count; i++)
//   {
//     D += (vals[i] - (val / count)) * (vals[i] - (val / count));
//   }
//   int Df = (D / (count - 1)); // * 0.0048828125*0.0048828125;
//   Serial.print(volts);
//   Serial.println("\t " + String(Df));
// }
