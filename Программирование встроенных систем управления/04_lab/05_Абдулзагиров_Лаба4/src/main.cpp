#include <Arduino.h>
/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №3
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */
#include <Adafruit_Sensor.h> // требуется для бибилиотеки DHT
#include <DHT.h>
#define bRate 115200 // Скорость COM порта
#define BlueLed 13	  // светодиод, который включается при включении регулятора
#define RedLed 12	  // светодиод, используемый как нагревательный элемент

#define BlueRGBLed 11
#define GreenRGBLed 10   //светодиоды для отображения текущего состояния
#define RedRGBLed 9

#define Res_Sens A0 // переменный резистор
#define DHTButton 2 // кнопка D2 для вкл/выкл регулятора
#define DHTPIN 4 //пин подключения датчика

////Значения температур,влажности, гистерезиса, ошибки и диапазона(*10)
int Td = 0;
int Tc = 0;
int GT = 20;
int ERR = 0;
int Tmin = 20;
int Tmax = 350;

boolean regulator = 0;
boolean device = 1;

String command; // строка для интерпретатора

boolean prevValue = 0;
  DHT dht(DHTPIN,DHT11);

void rgb(int val);
void state(void);
void Help(void);
void SetGT(void);
void SetERR(void) ;
void heater_On_Off(boolean val);
void device_On_Off(boolean val);


void setup()
{
	Serial.begin(bRate);					//Открывает последовательный порт,устанавливает скорость 115200
	Serial.print(millis());					//Выводит значение функции millis()
	Serial.print(F(" : Hello user \n"));	// выводит Hello user и переносит строку
	Serial.print(F(" : Enter command \n")); // выводит фразу введите команду

	//Устанавливаем нужные пины как входы/выходы
	pinMode(BlueLed, OUTPUT);
	pinMode(DHTButton, INPUT_PULLUP);
	pinMode(Res_Sens, INPUT);

	pinMode(BlueRGBLed, OUTPUT);
	pinMode(GreenRGBLed, OUTPUT);
	pinMode(RedRGBLed, OUTPUT);
  
  dht.begin();

  //Передаем на пин значение 1
	digitalWrite(BlueLed, 1);
}

void loop()
{
	if (Serial.available()) //получаем данные из последовательного порта
	{											
		command = Serial.readStringUntil('\n'); //Читаем буфер порта и формируем строку из данных, заканчивает работу после нажатия Enter
		if (command.equals("help")) //Проверяем две строки на равенство
		{							   
			Serial.println(F("HELP")); //выводит на экран HELP
			Help();					   //переход в функцию Help
		}							       //Ниже все аналогично
		if (command.equals("state"))
		{								
			Serial.println(F("state")); 
			state();					
		}
		else if (command.equals("setGT"))
		{
			Serial.println(F("Enter number "));
			SetGT();
		}

		else if (command.equals("setERR"))
		{
			Serial.println(F("Enter number "));
			SetERR();
		}

		else if (command.equals("ON"))
		{
			Serial.println(F("device ON"));
			device_On_Off(1);
		}
		else if (command.equals("OFF"))
		{
			Serial.println(F("device OFF"));
			device_On_Off(0);
		}
		else
		{
			Serial.println(F("command not found")); //Если строки не равны выдает фразу: "команда не найдена"
		}
		Serial.print(millis());
		Serial.print(F(" : Enter command \n  ")); //выдает время прошедшее с запуска(мс) и фразу "введите команду"
	}
 // Обработка кнопки D2
	boolean currentValue = !digitalRead(DHTButton);
	if (currentValue != prevValue && currentValue) // Что-то изменилось, здесь возможно зона неопределенности
	{
		delay(50); // Делаем задержку
		currentValue = digitalRead(DHTButton);
		device_On_Off(!device);
	}
	prevValue = currentValue;

	//ОБРАБОТКА ПОКАЗАНИЙ ДАТЧИКА
	int valReg = analogRead(Res_Sens);
	Tc = map(valReg, 0, 1023, Tmin, Tmax);

  float t = dht.readTemperature();
  if (isnan(t)) 
  {
    Serial.println("Error");
  }
  else
  {
    Td = t*10;
  }
	if (Td <= (Tc - GT))
	{
		//Включаем нагревательный элемент
		heater_On_Off(1);
		rgb(1); //Передаем значение в конструкцию switch 
	}
	else if (Td >= (Tc))
	{
		//Выключаем нагревательный элемент
		heater_On_Off(0);
		rgb(3);
	}
	else
	{
		rgb(2);
	}

	delay(100);
}

void state(void) //Выдает список строк представленных ниже
{
	Serial.println(F("\nstate:"));
	Serial.println("Td = " + String(Td / 10));
	Serial.println("Tc = " + String(Tc / 10));
	Serial.println("GT = " + String(GT / 10));
	Serial.println("ERR = " + String(ERR / 10));
	Serial.println("regulator = " + String(regulator));
}

void Help(void) //Выдает список строк представленных ниже
{
	Serial.println(F("\nThe following commands are described:"));
	Serial.println(F(" setGT - enter hysteresis"));
	Serial.println(F(" state - status"));
	Serial.println(F(" setERR - enter error"));
	Serial.println(F(" ON - turn on the device"));
	Serial.println(F(" OFF - turn off the device"));
	Serial.println(F(" help - list of commands"));
}

void SetGT(void) //Функция выводит целое число, если оно прошло проверку, иначе ошибка
{
	bool isErr = false;			  //Создаем логическую переменную
	String ch = "";				  //Создаем строку
	String order = "0123456789-"; //Создаем строку с допустимыми символами

	do
	{
		ch = Serial.readString(); //Читаем буфер порта и формируем из данных строку ch, пока не нажат Enter
	} while (ch.indexOf('\n') == -1);

	ch.replace("\n", ""); //Заменяем в строке ch нулевой символ на пустой
	if ((ch.toInt() > -5) and (ch.toInt() < 5))//Переводим содержимое строки в тип данных int и производим проверку(входит ли число в диапазон)
	{ 
		for (int i = 0; i < ch.length(); i++)
		{ //Если условия сработали, то создаем цикл в котором проверяем все ли элементы строки ch разрешены
			if ((order.indexOf(ch[i]) == -1))
			{
				Serial.println(F("Error")); //Если имеется неразрешенный символ, то выдаем ошибку
				isErr = true;				//Меняем значение переменной
				break;						//Принудительный выход из цикла
			}
		}
		if (!isErr)
		{						  //Если выполняется условие, то все проверки пройдены
			GT = ch.toInt() * 10; //Переводим строку и int и умножаем на 10
		}
	}
	else
	{
		Serial.println(F("Error")); //Если число не входит в диапазон выводим ошибку
	}
}

void SetERR(void) 
{
	bool isErr = false;			  
	String ch = "";				  
	String order = "0123456789-"; 
	do
	{
		ch = Serial.readString(); 
	} while (ch.indexOf('\n') == -1);
	ch.replace("\n", ""); 
	if ((ch.toInt() > -4) and (ch.toInt() < 4))
	{ 
		for (int i = 0; i < ch.length(); i++)
		{ 
			if ((order.indexOf(ch[i]) == -1))
			{
				Serial.println(F("Error")); 
				isErr = true;				
				break;						
			}
		}
		if (!isErr)
		{						   
			ERR = ch.toInt() * 10; 
		}
	}
	else
	{
		Serial.println(F("Error")); 
	}
}

void heater_On_Off(boolean val)
{
	// когда устройство включено, работаем в штатном режиме
	if (device)
	{
		digitalWrite(RedLed, val);
		regulator = val;
	}
	// иначе можем только выключить нагреватель
	else
	{
		digitalWrite(RedLed, 0);
		regulator = 0;
	}
}
//Вкл/выкл устройства
void device_On_Off(boolean val)
{
	device = val;
	digitalWrite(BlueLed, val);
	heater_On_Off(val);
	if (val==0) rgb(0);
}
// Конструкция switch для отображения текущего состояния
void rgb(int val)
{
	if (!device) val = 0;
	
	switch (val)
	{
	case 0:
		digitalWrite(RedRGBLed, 0);
		digitalWrite(GreenRGBLed, 0);
		digitalWrite(BlueRGBLed, 0);
		break;
	case 1:
		digitalWrite(RedRGBLed, 1);
		digitalWrite(GreenRGBLed, 0);
		digitalWrite(BlueRGBLed, 0);
		break;
	case 2:
		digitalWrite(RedRGBLed, 0);
		digitalWrite(GreenRGBLed, 1);
		digitalWrite(BlueRGBLed, 0);
		break;
	case 3:
		digitalWrite(RedRGBLed, 0);
		digitalWrite(GreenRGBLed, 0);
		digitalWrite(BlueRGBLed, 1);
		break;
	}
}

// #include "Parser.h" //созданный для парсинга класс

// #define baudRate 9600 // Скорость COM порта
// //#define DEBUG

// #define heater_out 12
// #define work_status_led 13

// #define LED_R 9
// #define LED_G 10
// #define LED_B 11

// #define setings_pot A0
// #define job_status_bt 2
// #define DHTPIN 4

// Parser pCommand;            // объект класса для храниения и распознавания строки
// boolean buttonWasUp = true; // была ли кнопка отпущена?

// // пространство имён нагревателя (вместо синглетон класса)
// namespace Heater
// {
//     DHT dht(DHTPIN, DHT11);

//     const int dev = 10; // точность значений - 1 числа после запятой
//     int _Tdht = 0;      // показания датчика температуры
//     int _Hdht = 0;      // показания датчика влажности
//     int _Tc = 0;
//     const int Tmin = 2 * dev;
//     const int Tmax = 35 * dev;

//     int GT = 2 * dev;
//     int ERR = 0;

//     boolean isWork = 1;   // статус работы устройства
//     boolean isHeated = 0; // статус работы нагревателя
//     boolean isError = 0;  // true, если есть ошибки в работе

//     void Begin()
//     {
//         pinMode(heater_out, OUTPUT);
//         pinMode(work_status_led, OUTPUT);
//         pinMode(setings_pot, INPUT);

//         pinMode(job_status_bt, INPUT_PULLUP);
//         digitalWrite(work_status_led, 1);

//         dht.begin();
//     }

//     void SetTc(int temp)
//     {
//         // if (temp>=Tmin && temp<= Tmax)
//         _Tc = map(temp, 0, 1023, Tmin, Tmax);
//     }

//     int GetTt() { return _Tdht; }

//     int GetTc() { return _Tc; }

//     // установить статус работы нагревателя
//     void SetWorkStatus(boolean);

//     // установить статус ошибки
//     void SetErrorStatus(boolean status);

//     // включить или выключить нагрев
//     void Switch(boolean);

//     void Update()
//     {
//         float h = dht.readHumidity();    //Измеряем влажность
//         float t = dht.readTemperature(); //Измеряем температуру
//         if (isnan(h) || isnan(t))
//         { //Проверка. Если не удается считать показания,выводится «Ошибка считывания», и программа завершает работу
//             Serial.println("Error read DHT11");
//             SetErrorStatus(true);
//         }
//         else
//         {
//             SetErrorStatus(false);
//             _Tdht = t * dev;
//             _Hdht = h * dev;
//         }
//     }
// }

// //прототипы функций
// void help();
// void state();
// void rgbLedOn(boolean R, boolean G, boolean B); // установка нужного цвета

// void setup()
// {
//     //Устанавливаем режимы работы пинов как выходы
//     pinMode(LED_BUILTIN, OUTPUT);
//     Serial.begin(baudRate); //инициализируем последовательный порт и устанавливаем скорость 9600
//     help();                 // вывод помощи

//     pinMode(LED_R, OUTPUT);
//     pinMode(LED_G, OUTPUT);
//     pinMode(LED_B, OUTPUT);

//     Heater::Begin();
//     Serial.print(millis()); //вывод текущего времени
//     Serial.print(F(" : Enter command > "));
// }

// void loop()
// {
//     if (Serial.available())
//     {
//         //отчищаем буфер и записываем в него строку
//         pCommand.bufClean();
//         pCommand.bufLength = Serial.readBytes((byte *)(pCommand.buf), pCommand.bufMaxLength);

//         if (pCommand.isFind("help"))
//         {
//             Serial.print(F("help"));
//             help();
//         }
//         else if (pCommand.isFind("state"))
//         {
//             Serial.print(F("state"));
//             state();
//         }
//         else if (pCommand.isFind("setGT"))
//         {
//             Serial.print(F("setGT"));
//             int GT;
//             if (pCommand.findInt(&GT))
//                 if (GT > 5 || GT < -5) //проверка выхода за диапазон
//                     Serial.println(F("error setGT: going out of range "));
//                 else
//                     Heater::GT = GT * Heater::dev; //если проверка пройдена, выводим результат
//             else
//                 Serial.println(F("error setGT ")); //число не обнаружено
//         }
//         else if (pCommand.isFind("setERR")) // setERR 2.6
//         {
//             Serial.println(F("setERR"));
//             int ERR;
//             if (pCommand.findFloatHowInt(&ERR))
//                 if (ERR > 4 * Heater::dev || ERR < -4 * Heater::dev) //проверка выхода за диапазон
//                     Serial.println(F("error setERR: going out of range "));
//                 else
//                     Heater::ERR = ERR; //если проверка пройдена, выводим результат
//             else
//                 Serial.println(F("error setERR ")); //число не обнаружено
//         }
//         else if (pCommand.isFind("ON"))
//         {
//             //включаем встроенный всетодиод
//             digitalWrite(LED_BUILTIN, HIGH);
//             Serial.println(F("Heater ON"));
//             Heater::SetWorkStatus(1);
//         }
//         else if (pCommand.isFind("OFF"))
//         {
//             //выключаем встроенный всетодиод
//             digitalWrite(LED_BUILTIN, LOW);
//             Serial.println(F("Heater OFF"));
//             Heater::SetWorkStatus(0);
//         }
//     }

//     // обработчик кнопки
//     boolean buttonIsUp = !digitalRead(job_status_bt);
//     if (!buttonWasUp && buttonIsUp)
//     {
//         delay(10);
//         buttonIsUp = !digitalRead(job_status_bt);
//         if (buttonIsUp)
//         {
//             Heater::SetWorkStatus(!Heater::isWork);
//             state();
//         }
//     }
//     // запоминаем последнее состояние кнопки
//     buttonWasUp = buttonIsUp;

//     // считывание показания датчика температуры и потенциометра
//     Heater::SetTc(analogRead(setings_pot));
//     Heater::Update();
//     // установка состояния RGB светодиода
//     if (Heater::isWork)
//         if (Heater::GetTt() <= (Heater::GetTc() - Heater::GT))
//         {
//             Heater::Switch(1);
//             rgbLedOn(1, 0, 0);
//         }
//         else if (Heater::GetTt() >= Heater::GetTc())
//         {
//             Heater::Switch(0);
//             rgbLedOn(0, 0, 1);
//         }
//         else
//             rgbLedOn(0, 1, 0);
//     else
//         rgbLedOn(0, 0, 0);

//     delay(10);
// }

// void yield()
// {
//     static long time;
//     static long pastTime;
//     time = millis(); // текущее время

//     // повтор каждые 3 секунды
//     if (time - pastTime >= 3000)
//     {
//         state(); // вывод статуса

//         pastTime = time;
//     }
// }

// void help()
// {
//     Serial.println(F("\nThe following commands are described:"));
//     Serial.println(F(" state - Heater current state"));
//     Serial.println(F(" setGT - set hysteresis parameters "));
//     Serial.println(F(" setERR - set the value of the added error"));
//     Serial.println(F(" ON - turn on Heater"));
//     Serial.println(F(" OFF - turn off Heater"));
//     Serial.println(F(" help - help information"));
// }

// void state()
// {
//     Serial.println(F("\nState:"));
//     Serial.println("T = " + String((float)Heater::_Tdht / (float)Heater::dev));
//     Serial.println("H = " + String((float)Heater::_Hdht / (float)Heater::dev));
//     Serial.println("Tc = " + String((float)Heater::_Tc / (float)Heater::dev));
//     Serial.println("GT = " + String((float)Heater::GT / (float)Heater::dev));
//     Serial.println("ERR = " + String((float)Heater::ERR / (float)Heater::dev));
//     if (Heater::isHeated)
//         Serial.println(F("Heated = on"));
//     else
//         Serial.println(F("Heated = off"));
//     if (Heater::isWork)
//         Serial.println(F("Heater is Work"));
//     else
//         Serial.println(F("Heater is not Work"));
// }

// /// установка нужного цвета
// void rgbLedOn(boolean R, boolean G, boolean B)
// {
//     digitalWrite(LED_R, R);
//     digitalWrite(LED_G, G);
//     digitalWrite(LED_B, B);
// }

// // установить статус работы нагревателя (если setStatus == false, но не менять значение статуса)
// void Heater::SetWorkStatus(boolean status)
// {
//     Heater::isWork = status;
//     digitalWrite(work_status_led, status);
//     Heater::Switch(Heater::isHeated);
// }

// // включить или выключить нагрев
// void Heater::Switch(boolean heat)
// {
//     //нагрев регулируется только при включённом устройстве
//     digitalWrite(heater_out, heat && Heater::isWork);
//     Heater::isHeated = heat && Heater::isWork;
// }

// // выключаем устройство, если есть ошибка
// void Heater::SetErrorStatus(boolean status)
// {
//     static boolean pastIsWork;

//     if (status != Heater::isError)
//     {
//         if (status)
//         {
//             // запоминаем предыдущее состояние
//             pastIsWork = Heater::isWork;
//             Heater::SetWorkStatus(false);
//         }
//         else
//         {
//             Heater::SetWorkStatus(pastIsWork);
//         }
//     }
//     Heater::isError = status;
// }
