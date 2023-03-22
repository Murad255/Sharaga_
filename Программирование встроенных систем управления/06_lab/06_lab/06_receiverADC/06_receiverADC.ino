// Пример передачи данных по радиоканалу, формирование пакета передачи
// Приемник


// Пример прием и разбор  пакета
#include <RH_ASK.h>

#define D12_LED     12    // светодиод нажатие кнопки
#define ID_TRANS    0x1   // Идентификатор передатчика (Адрес)

RH_ASK driver(2000, 7, 8, 0); // Инициализация приемника сравниваем с передатчиком

struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    char text[10];        // Текстовое сообщение
} *myPocket;              // Указатель!!!

void setup()
{
    Serial.begin(115200);	 
    Serial.println("\n\n------------ START RESEIVER --------------");	
    if (!driver.init())     Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    Serial.print("Sizeof myPocket:");Serial.println(sizeof(packet));
    if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");
    pinMode(D12_LED, OUTPUT);
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
   
   for(;;) 
    if (driver.recv(buf, &buflen)) // Non-blocking
     {
   myPocket=(packet*)buf;   
   driver.printBuffer("Got:", buf, buflen);  // Отладка
   Serial.print(" Got: "); Serial.print(" len: "); Serial.print(buflen);
   Serial.print(" id: ");  Serial.print(myPocket->id);
   Serial.print(" key: "); Serial.print(myPocket->key);
   Serial.print(" adc: "); Serial.print(myPocket->adc);
   Serial.print(" num: "); Serial.print(myPocket->num);
   Serial.print(" text: ");Serial.println((char*)myPocket->text); 
   digitalWrite(D12_LED, myPocket->key); 
   
    }
}

/*
// Пример прием и разбор  пакета + Вывод на экран LCD 1602
#include <RH_ASK.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define D12_LED     12              // светодиод нажатие кнопки
#define ID_TRANS    0x1             // Идентификатор передатчика (Адрес)

RH_ASK driver(2000, 7, 8, 0);       // Инициализация приемника сравниваем с передатчиком
LiquidCrystal_I2C lcd(0x27,16,2);   // Установить настройки дисплея адрес 0x27 размер 16х2 символа

struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;             // Идентификатор передатчика (адрес передатчика)
    uint8_t key;                     // Кнопка
    int num=0;                       // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;                    // Значение АЦП
    char text[10];                   // Текстовое сообщение
} *myPocket;  

void setup()
{
    Serial.begin(115200);
    Serial.println("\n\n------------ START RESEIVER --------------");		 
    if (!driver.init())     Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    Serial.print("Sizeof myPocket:");Serial.println(sizeof(myPocket));
    if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");  
    pinMode(D12_LED, OUTPUT);

    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Packet:");
    lcd.setCursor(0,1);
    lcd.print("ADC=");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
   
   for(;;) 
    if (driver.recv(buf, &buflen)) // Non-blocking
     {
   myPocket=(packet*)buf;   
	// Message with a good checksum received, dump it.
//	driver.printBuffer("Got:", buf, buflen);
   Serial.print(" Got: "); Serial.print(" len: "); Serial.print(buflen);
   Serial.print(" id: ");  Serial.print(myPocket->id);
   Serial.print(" key: "); Serial.print(myPocket->key);
   Serial.print(" adc: "); Serial.print(myPocket->adc);
   Serial.print(" num: "); Serial.print(myPocket->num);
   Serial.print(" text: ");Serial.println((char*)myPocket->text); 
   digitalWrite(D12_LED, myPocket->key); 
   lcd.setCursor(7,0);
   lcd.print(myPocket->num);
   lcd.setCursor(4,1);
   lcd.print(myPocket->adc);  
   
    }
}
*/

/*
// Пример прием и разбор  пакета + Вывод на экран LCD 1602
// Прием только от ID=0x01 (при множестве передатчиков)
#include <RH_ASK.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define D12_LED     12              // светодиод нажатие кнопки
#define ID_TRANS    0x1             // Идентификатор передатчика (Адрес)

RH_ASK driver(2000, 7, 8, 0);       // Инициализация приемника сравниваем с передатчиком
LiquidCrystal_I2C lcd(0x27,16,2);   // Установить настройки дисплея адрес 0x27 размер 16х2 символа

struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;             // Идентификатор передатчика (адрес передатчика)
    uint8_t key;                     // Кнопка
    int num=0;                       // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;                    // Значение АЦП
    char text[10];                   // Текстовое сообщение
} *myPocket;  

void setup()
{
    Serial.begin(115200);
    Serial.println("\n\n------------ START RESEIVER --------------");		 
    if (!driver.init())     Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    Serial.print("Sizeof myPocket:");Serial.println(sizeof(packet));
    if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");  
    pinMode(D12_LED, OUTPUT);

    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Packet:");
    lcd.setCursor(0,1);
    lcd.print("ADC=");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
   
   for(;;) 
    if (driver.recv(buf, &buflen)) // Non-blocking
     {
   myPocket=(packet*)buf;   
	// Message with a good checksum received, dump it.
	driver.printBuffer("Got:", buf, buflen);
    Serial.print(" Got: "); Serial.print(" len: "); Serial.print(buflen);
    Serial.print(" id: ");  Serial.print(myPocket->id);
    Serial.print(" key: "); Serial.print(myPocket->key);
    Serial.print(" adc: "); Serial.print(myPocket->adc);
    Serial.print(" num: "); Serial.print(myPocket->num);
    Serial.print(" text: ");Serial.println((char*)myPocket->text); 
   digitalWrite(D12_LED, myPocket->key); 
   lcd.setCursor(7,0);
   lcd.print(myPocket->num);
   lcd.setCursor(4,1);
   lcd.print(myPocket->adc);  
   lcd.setCursor(9,1);
   lcd.print(myPocket->text);  
   
    }
}
*/
