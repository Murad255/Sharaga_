#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define NUM_LAB 5    // Номер лабораторной работы
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     2 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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

// Перекодировка на лету  UTF-8 в Windows-1251 
String utf8rus(String source)
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
return target;
}
// ПРИМЕРЫ ===========================================================
/*
// Вывод напряжения на резисторе (напряжение на входе АЦП) на ssd1306 
#define VCC 5.0
#define TICK  (VCC/1023.0)
void setup() {
    Serial.begin(115200);
    msgStart(8);
    pinMode(A0, INPUT);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.println(utf8rus("Напряжение"));
    display.display();
}

void loop() {
char buf[6];
    uint16_t adc=0, adc_old=2048; // 2048 для вывода первого значения
    adc = analogRead(A0);
    if (adc!=adc_old){
	    adc_old=adc;	
	    Serial.println(((float)adc_old)*TICK);
	    dtostrf(((float)adc_old)*TICK,4, 2, buf);
	    display.fillRect(30,20,60,20,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(30,20);
	    display.println(buf);
	    display.display();
    } 
    delay(50);
}
*/
/*
// Вывод напряжения на резисторе (напряжение на входе АЦП) на ssd1306 + аналоговая шкала
#define VCC 5.0
#define TICK  (VCC/1023.0)
void setup() {
	uint8_t i;
    Serial.begin(115200);
    msgStart(8);
    pinMode(A0, INPUT);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.println(utf8rus("Напряжение"));
    // Шкала отсчеты
    for (i=0;i<32;i++)
       {
       if(i%8==0) display.drawFastVLine(i*4, 45, 8,SSD1306_WHITE);	
       else        display.drawFastVLine(i*4, 45, 4,SSD1306_WHITE);
       }    
    display.display();
}

void loop() {
char buf[6];
    uint16_t adc=0, adc_old=2048; // 2048 для вывода первого значения
    adc = analogRead(A0);
    if (adc!=adc_old){
	    adc_old=adc;	
	    Serial.println(((float)adc_old)*TICK);
	    dtostrf(((float)adc_old)*TICK,4, 2, buf);
	    display.fillRect(30,20,60,20,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(30,20);
	    display.println(buf);
	    // Шкала линия
	    display.fillRect(0,40,128,4,SSD1306_BLACK);  // Стереть статарую шкалу
	    display.fillRect(0,40,map(adc,0,1023,0,128),4,SSD1306_WHITE);  // Стереть нарисовать новую шкалу

        display.display();	    
	    
    } 
    delay(50);
}
*/
/*
// Настраиваемое фото реле с выводом на экран ssd1306
// Простейшее фотореле (управление светодиодом D13) Порог задается резистором на A0
#define D13 13
uint16_t adc = 0;
uint16_t level = 512;
void setup() {
	uint8_t i;
    Serial.begin(115200);
    msgStart(8);
    pinMode(A0, INPUT);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(utf8rus("Фото дат."));
    display.setCursor(0,63-16);
    display.print(utf8rus("Уровень"));    
    // Шкала отсчеты
    for (i=0;i<32;i++)
       {
       if(i%8==0) display.drawFastVLine(i*4, 40, 6,SSD1306_WHITE);	
       else       display.drawFastVLine(i*4, 40, 3,SSD1306_WHITE);
       }    
    display.display();
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
	    display.fillRect(40,18,60,20,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(40,18);
	    display.print(adc_old);
	    display.fillRect(85,63-16,50,16,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(85,63-16);
	    display.print(level_old);

	    
	    // Шкала линия
	    display.fillRect(0,35,128,4,SSD1306_BLACK);  // Стереть статарую шкалу
	    display.fillRect(0,35,map(adc,0,1023,0,128),4,SSD1306_WHITE);  // Стереть нарисовать новую шкалу
        display.fillRect(110,18,16,16,SSD1306_BLACK);  // Стереть прошлое изображение для символа D13
	       
    if(adc<level){         
           digitalWrite(D13,HIGH);
           Serial.println("ON");
           display.setCursor(110,18);
           display.write(0x02);
           
    }else{ digitalWrite(D13,LOW);
           Serial.println("OFF");
           display.setCursor(110,18);
           display.write(0x07);

    }
           display.display();           
    
    }
    // вывод информации в порт всегда для отслеживания 
    Serial.print("Level: "); Serial.print(level);
    Serial.print(" Sensor: "); Serial.print(adc); Serial.print(" Led D13 ");
    
    delay(100);
} 
*/

// Настраиваемое фото реле с выводом на экран ssd1306 ИСПОЛЬЗОВАНИЕ РАЗНЫХ РАЗМЕРОВ ШРИФТА
// Простейшее фотореле (управление светодиодом D13) Порог задается резистором на A0
#define D13 13
uint16_t adc = 0;
uint16_t level = 512;
void setup() {
	uint8_t i;
    Serial.begin(115200);
    msgStart(8);
    pinMode(A0, INPUT);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(utf8rus("Фото дат."));
    display.setTextSize(1);
    display.setCursor(0,63-12);
    display.print(utf8rus("Порог включения"));    
    // Шкала отсчеты
    for (i=0;i<32;i++)
       {
       if(i%8==0) display.drawFastVLine(i*4, 40, 6,SSD1306_WHITE);	
       else       display.drawFastVLine(i*4, 40, 3,SSD1306_WHITE);
       }    
    display.display();
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
        display.setTextSize(2);
	    display.fillRect(40,18,60,20,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(40,18);
	    display.print(adc_old);
	    display.setTextSize(1);
	    display.fillRect(95,63-12,50,16,SSD1306_BLACK);  // Стереть прошлое изображение
	    display.setCursor(95,63-12);
	    display.print(level_old);

	    
	    // Шкала линия
	    display.fillRect(0,35,128,4,SSD1306_BLACK);  // Стереть статарую шкалу
	    display.fillRect(0,35,map(adc,0,1023,0,128),4,SSD1306_WHITE);  // Стереть нарисовать новую шкалу
	    
        display.fillRect(110,10,21,21,SSD1306_BLACK);  // Стереть прошлое изображение для символа D13
	    display.setTextSize(3);   
    if(adc<level){         
           digitalWrite(D13,HIGH);
           Serial.println("ON");
           display.setCursor(110,10);
           display.write(0x02);
           
    }else{ digitalWrite(D13,LOW);
           Serial.println("OFF");
           display.setCursor(110,10);
           display.write(0x07);

    }
           display.display();           
    
    }
    // вывод информации в порт всегда для отслеживания 
    Serial.print("Level: "); Serial.print(level);
    Serial.print(" Sensor: "); Serial.print(adc); Serial.print(" Led D13 ");
    
    delay(100);
} 
