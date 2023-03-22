// Пример передачи данных по радиоканалу, формирование пакета передачи, чтение датчика DHT11
// Передатчик


// Использование стандартной библиотеки DHT.h
// период чтения DHT должен быть не меньше 2.5 сек иначе будут ошибки
#include <RH_ASK.h>
#include "DHT.h"

#define D13_LED  13       // светодиод отпраки пакета
#define D12_LED  12       // светодиод нажатие кнопки
#define D2_KEY   2        // кнопка
#define DHTPIN   4        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11
#define ID_TRANS    0x1   // Идентификатор передатчика (Адрес)

RH_ASK driver(2000, 8, 7, 0);
DHT dht(DHTPIN, DHTTYPE);

struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    uint16_t temperature; // Температура DHT11
    uint16_t humidity;    // Влажность   DHT11
    char text[10];        // Текстовое сообщение
} myPocket;

void setup()
{
  Serial.begin(115200);	 
  Serial.println("\n\n------------ START TRAMSMITTER --------------"); 
  if (!driver.init())   Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  pinMode(D12_LED, OUTPUT);
  pinMode(D2_KEY, INPUT);
  Serial.print("Sizeof myPocket:");Serial.println(sizeof(myPocket));
  
  Serial.println("Start ----------------------");
  
  dht.begin();
}

void loop()
{
	
    myPocket.num++;
    strcpy(myPocket.text,"hello");
    myPocket.key=digitalRead(D2_KEY);
    myPocket.adc = analogRead(A0);

    float t=dht.readTemperature();
    float h=dht.readHumidity();
    Serial.print(F("Temperature=")); Serial.print(t); Serial.print(F("C° Humidity=")); Serial.print(h);Serial.println(F("%"));
    myPocket.humidity    = (int)(100.0*h);
    myPocket.temperature = (int)(100.0*t);
    
    digitalWrite(D12_LED, myPocket.key); 
    digitalWrite(D13_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    driver.send((uint8_t * )&myPocket, sizeof(myPocket));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);    // turn the LED off by making the voltage LOW
    delay(3000);                   // период чтения DHT должен быть не меньше 2.5 сек иначе будут ошибки
}


/*
// Использование стандартной библиотеки DHT.h
// период чтения DHT должен быть не меньше 2.5 сек иначе будут ошибки
// передатчик работает с периодом TIME, а чтение DHT происходит с периодом TIME_DHT 
// Для увеличения надежности можно уменьшить скорость передачи с 2000 до 1000
#include <RH_ASK.h>
#include "DHT.h"

#define D13_LED   13       // светодиод отпраки пакета
#define D12_LED   12       // светодиод нажатие кнопки
#define D2_KEY    2        // кнопка
#define DHTPIN    4        // Digital pin connected to the DHT sensor
#define DHTTYPE   DHT11    // DHT 11
#define ID_TRANS  0x1      // Идентификатор передатчика (Адрес)
#define TIME_SEND 1000     // Период передачи пакета
#define TIME_DHT  3000     // Период чтения датчика DHT
#define TIME_     100      // Минимальный квант времени шедуллера




RH_ASK driver(2000, 8, 7, 0);  // СКОРОСТЬ
DHT dht(DHTPIN, DHTTYPE);

struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    uint16_t temperature; // Температура DHT11 в СОТЫХ градуса
    uint16_t humidity;    // Влажность   DHT11 в СОТЫХ процента
    char text[10];        // Текстовое сообщение
} myPocket;

void setup()
{
  Serial.begin(115200);	 
  Serial.println("\n\n------------ START TRAMSMITTER --------------"); 
  if (!driver.init())   Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  pinMode(D12_LED, OUTPUT);
  pinMode(D2_KEY, INPUT);
  Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
  Serial.print("Sizeof myPocket:");Serial.println(sizeof(packet));
  if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");  
  
  Serial.println("Start ----------------------");
  
  dht.begin();
  delay(100);
  myPocket.temperature=(int)(100.0*dht.readTemperature()); // Прочитать данные с датчика, что бы первый пакет уходил с данными
  myPocket.humidity = (int)(100.0*dht.readHumidity());
  if ((myPocket.temperature==0)&&(myPocket.humidity==0)) strcpy(myPocket.text,"Err"); else strcpy(myPocket.text,"Ok");  // Контроль на ошибку чтения

}

uint32_t _time=0, _time_dht=0;  // переменные для шидуллера
void loop()
{
//uint32_t _time=0, _time_dht=0; // Не правильно, компилятор выкидывет 

if  (millis()-_time > TIME_SEND)  // Передача пакета
    {	
    _time=millis();	         // Запомнить время
    myPocket.num++ ;
    myPocket.key=digitalRead(D2_KEY);     // Чтение кнопки
    myPocket.adc = analogRead(A0);        // Чтение АЦП
    digitalWrite(D12_LED, myPocket.key);  // установка светодиода в зависимости от кнопки
    digitalWrite(D13_LED, HIGH);          // turn the LED on (HIGH is the voltage level)
    driver.send((uint8_t * )&myPocket, sizeof(myPocket));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);           // turn the LED off by making the voltage LOW
    Serial.print(_time); Serial.println(F(": Send pocket . . .")); 
    }
  
if  (millis()-_time_dht > TIME_DHT)  // Чтение датчика
    {	
    _time_dht=millis();	         // Запомнить время
    myPocket.temperature=(int)(100.0*dht.readTemperature()); // Прочитать данные с датчика, что бы первый пакет уходил с данными
    myPocket.humidity = (int)(100.0*dht.readHumidity());
    if ((myPocket.temperature==0)&&(myPocket.humidity==0)) strcpy(myPocket.text,"Err"); else strcpy(myPocket.text,"Ok");  // Контроль на ошибку чтения
    Serial.print(_time_dht); Serial.print(F(": Temperature=")); Serial.print((float)myPocket.temperature/100.0); Serial.print(F("C° Humidity=")); Serial.print((float)myPocket.humidity/100.0);Serial.println(F("%"));
    }
      
    delay(TIME_);              // Не большая задержка (квант времени)
}
