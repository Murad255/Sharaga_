// Пример передачи данных по радиоканалу, формирование пакета передачи, чтение датчика DHT11
// Вывод на экран LCD 1602
// Для увеличения надежности можно уменьшить скорость передачи с 2000 до 1000
// Приемник
#include <RH_ASK.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define D12_LED  12  // светодиод нажатие кнопки
#define ID_TRANS    0x1   // Идентификатор передатчика (Адрес)

LiquidCrystal_I2C lcd(0x27,16,2);  // Установить настройки дисплея адрес 0x27 размер 16х2 символа
RH_ASK driver(2000, 7, 8, 0);      // СКОРОСТЬ
struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    uint16_t temperature; // Температура DHT11
    uint16_t humidity;    // Влажность   DHT11
    char text[10];        // Текстовое сообщение
} *myPocket;

void setup()
{
    Serial.begin(115200);	 
    if (!driver.init())
    Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    Serial.print("Sizeof myPocket:");Serial.println(sizeof(packet));
    if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");  
  
    pinMode(D12_LED, OUTPUT);
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("ADC=");
//    lcd.print("Pock:");
//    lcd.setCursor(9,0);

    lcd.setCursor(0,1);
    lcd.print("T=");
    lcd.setCursor(9,1);
    lcd.print("H=");
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
 //  driver.printBuffer("Got:", buf, buflen);
  Serial.print("Bad received packets : "); Serial.println(driver.rxBad());
//   
   Serial.print(" Len: "); Serial.print(buflen);
   Serial.print(" id: ");  Serial.print(myPocket->id);
   Serial.print(" key: "); Serial.print(myPocket->key);
   Serial.print(" adc: "); Serial.print(myPocket->adc);
   Serial.print(" num: "); Serial.print(myPocket->num);
   Serial.print(" text: ");Serial.println((char*)myPocket->text); 
   digitalWrite(D12_LED, myPocket->key); 
   lcd.setCursor(12,0);  lcd.print("     ");
   lcd.setCursor(12,0);  lcd.print(myPocket->num);
   lcd.setCursor(4,0);   lcd.print("    ");
   lcd.setCursor(4,0);   lcd.print(myPocket->adc);  

   lcd.setCursor(3,1);   lcd.print("      ");
   lcd.setCursor(3,1);   lcd.print((float)myPocket->temperature/100.0);
   lcd.setCursor(12,1);  lcd.print("      ");
   lcd.setCursor(12,1);  lcd.print((float)myPocket->humidity/100.0);  
  
    }
}


/*
// Вывод на экран LCD 1602
// Чтение данных организовано более правильно в чтение уходит только при наличии пакета 
#include <RH_ASK.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define D12_LED  12  // светодиод нажатие кнопки

LiquidCrystal_I2C lcd(0x27,16,2);  // Установить настройки дисплея адрес 0x27 размер 16х2 символа
RH_ASK driver(2000, 7, 8, 0);
struct packet
{
    uint8_t id=11;
    uint8_t key;
    int num=0;
    uint16_t adc;
    uint16_t temperature;
    uint16_t humidity;
    char text[10];
} *myPocket;

void setup()
{
    Serial.begin(115200);	 
    if (!driver.init())
    Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    pinMode(D12_LED, OUTPUT);
    lcd.init();                     
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("ADC=");
    lcd.setCursor(0,1);
    lcd.print("T=");
    lcd.setCursor(9,1);
    lcd.print("H=");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    
if (driver.available())
{
  
   if (driver.recv(buf, &buflen)) // Non-blocking
     {
	   myPocket=(packet*)buf;   
	  //  driver.printBuffer("Got:", buf, buflen);
	   Serial.print("Bad received packets : "); Serial.println(driver.rxBad());
	   Serial.print(" Len: "); Serial.print(buflen);
	   Serial.print(" id: ");  Serial.print(myPocket->id);
	   Serial.print(" key: "); Serial.print(myPocket->key);
	   Serial.print(" adc: "); Serial.print(myPocket->adc);
	   Serial.print(" num: "); Serial.print(myPocket->num);
	   Serial.print(" text: ");Serial.println((char*)myPocket->text); 
	   digitalWrite(D12_LED, myPocket->key); 
       lcd.setCursor(12,0);  lcd.print("     ");
       lcd.setCursor(12,0);  lcd.print(myPocket->num);
	   lcd.setCursor(4,0);   lcd.print("    ");
	   lcd.setCursor(4,0);   lcd.print(myPocket->adc);  
	
	   lcd.setCursor(3,1);   lcd.print("      ");
	   lcd.setCursor(3,1);   lcd.print((float)myPocket->temperature/100.0);
	   lcd.setCursor(12,1);  lcd.print("      ");
	   lcd.setCursor(12,1);  lcd.print((float)myPocket->humidity/100.0);  
    }  
  }
}

*/
