#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define NUM_LAB 5    // Номер лабораторной работы
// Функция вывода стартового экрана
// Входной параметр - номер примера
void msgStart(uint8_t ex)
{
	Serial.print(F("\n"));
	Serial.print(F("Laboratory work "));Serial.println(NUM_LAB);
	Serial.print(F("Example "));Serial.println(ex);
	Serial.print(F("Build firmware "));Serial.print(__TIME__); Serial.print(" ");Serial.println(__DATE__);
	Serial.print(F("Microcontroller frequency [Mhz] "));Serial.println(F_CPU/1000000);
    extern int __heap_start, *__brkval; 
    int v; 
    int fr = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
    Serial.print(F("Free ram: ")); Serial.println(fr);
	Serial.print(F("Start code ----->\n"));
}
LiquidCrystal_I2C lcd(0x27,16,2);  // Установить настройки дисплея адрес 0x27 размер 16х2 символа
/*
// Вывод напряжения на резисторе (напряжение на входе АЦП) НЕ ОПТИМИЗИРОВАНО
#define VCC 5.0
#define TICK  (VCC/1023.0)
void setup() {
    Serial.begin(115200);
    msgStart(2);
    pinMode(A0, INPUT);
    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Voltage A0:");    
}

void loop() {
char buf[6];
	uint16_t adc=0;
    adc = analogRead(A0);
    Serial.println(((float)adc)*TICK);
    dtostrf(((float)adc)*TICK,4, 2, buf);
    lcd.setCursor(12,0);
    lcd.print(buf);   
    delay(200);
}
*/

/*
// Вывод напряжения на резисторе (напряжение на входе АЦП) ОПТИМИЗИРОВАНО
#define VCC 5.0
#define TICK  (VCC/1023.0)
void setup() {
    Serial.begin(115200);
    msgStart(2);
    pinMode(A0, INPUT);
    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Voltage A0:");    
}

void loop() {
char buf[6];
	uint16_t adc=0, adc_old=2048; // 2048 для вывода первого значения
	
    adc = analogRead(A0);
    if (adc!=adc_old){
    adc_old=adc;	
    Serial.println(((float)adc_old)*TICK);
    dtostrf(((float)adc_old)*TICK,4, 2, buf);
    lcd.setCursor(12,0);
    lcd.print(buf);   
    } 
    delay(50);
}
*/

/*
// Ввод дробного числа от -10 до + 30
#define MIN  -100 
#define MAX   300 
void setup() {
    Serial.begin(115200);
    msgStart(2);
    pinMode(A0, INPUT);
    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Input:");    
}

void loop() {
char buf[6];
float t;
	uint16_t adc=0, adc_old=2048; // 2048 для вывода первого значения
	
    adc = analogRead(A0);
    if (adc!=adc_old){
    adc_old=adc;	
    t=(float)map(adc, 0, 1023, MIN, MAX)/10.0,1;
    Serial.println(t);
    dtostrf(t,4, 1, buf);
    lcd.setCursor(7,0);
    lcd.print("      ");   // Стереть
    lcd.setCursor(7,0);
    lcd.print(buf);   
    } 
    delay(50);
}
*/

// Настраиваемое фото реле
// Простейшее фотореле (управление светодиодом D13) Порог задается резистором на A0
#define D13 13
uint16_t adc = 0;
uint16_t level = 512;
uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};

void setup() {
    Serial.begin(115200);
    msgStart(2);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(D13, OUTPUT);
    lcd.init();                      // Инициализация дисплея
    lcd.backlight();
    lcd.createChar(0, bell);         // Установить спец символ
    lcd.setCursor(0,0);
    lcd.print("Level:");
    lcd.setCursor(0,1);
    lcd.print("Light:");
        
}

void loop() {
uint16_t adc_old = 2048;
uint16_t level_old = 2048;	
	level = analogRead(A0);
    adc = analogRead(A1);
    if ((adc!=adc_old)||(level!=level_old)){ // Оптимизация
    adc_old=adc;
    level_old=level;
    // Вывод информации на дисплей
    lcd.setCursor(7,0);
    lcd.print("      ");
    lcd.setCursor(7,0);
    lcd.print(level);
    lcd.setCursor(7,1) ;
    lcd.print("      ");
    lcd.setCursor(7,1) ;
    lcd.print(adc);    
    if(adc<level){         
           digitalWrite(D13,HIGH);
           Serial.println("ON");
           lcd.setCursor(15, 0);
           lcd.write(0);    // вывести спец символ
    }else{ digitalWrite(D13,LOW);
           Serial.println("OFF");
           lcd.setCursor(15, 0);
           lcd.write(32);    // стереть спец символ

    }
    // Вывод информации на дисплей
    lcd.setCursor(7,0);
    lcd.print("      ");
    lcd.setCursor(7,0);
    lcd.print(level);
    lcd.setCursor(7,1) ;
    lcd.print("      ");
    lcd.setCursor(7,1) ;
    lcd.print(adc);    
    	
    }
    // вывод информации в порт всегда для отслеживания 
    Serial.print("Level: "); Serial.print(level);
    Serial.print(" Sensor: "); Serial.print(adc); Serial.print(" Led D13 ");
    
    delay(100);
} 

 
