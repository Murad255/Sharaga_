#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Установить настройки дисплея адрес 0x27 размер 16х2 символа



// Авто прокрутка 
/* Autoscroll() noAutoscroll()
 * Функция включает автоматическую прокрутку текста на LCD. Это значит, что при выводе каждого нового символа, 
 * все предыдущие символы будут сдвигаться на одну позицию. Если установлен режим вывода текста слева-направо 
 * (по умолчанию), то прокрутка будет осуществляться влево; если установлен режим справа-налево, то прокрутка 
 * будет осуществляться вправо. Таким образом, каждый новый символ будет выводится в одной и той же позиции LCD.
 */

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Hello, Arduino!");
  delay(2000);
}

void loop() {
  lcd.clear();  // Очистить экран
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
   lcd.print(thisChar);
   delay(500);
  }

  lcd.setCursor(16,1); // Курсор на 16.1
  lcd.autoscroll();   // Включить автоскролинг
 
  for (int thisChar = 0; thisChar < 10; thisChar++) { // Строка для прокручивания
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  
  // clear screen for the next loop:
  lcd.clear();
}

/*
// Курсор
void setup() {
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, world:");
}

void loop() {
  // Turn off the cursor:
  lcd.noCursor();
  delay(500);
   // Turn on the cursor:
  lcd.cursor();
  delay(500);
}
*/
/*
// Включение выключение дисплея не подсветки! (мигающая надпись)
void setup() {
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, world!");
}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
   // Turn on the display:
  lcd.display();
  delay(500);
}
*/
/*
// Включение выключение дисплея не подсветки! (мигающая подсветка)
void setup() {
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, world!");
}

void loop() {
 lcd.noBacklight();
 delay(1000);
 lcd.backlight();
 delay(1000);
}
*/
/*
void setup() {
  lcd.init();                     
  lcd.backlight();	
  lcd.begin(16, 1);
  lcd.print("hello, world!");
  delay(1000);
}
void loop() {
  // scroll 13 positions (string length) to the left 
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight(); 
    // wait a bit:
    delay(150);
  }
  
    // scroll 16 positions (display length + string length) to the left
    // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }
  
  // delay at the end of the full loop:
  delay(1000);

}
*/
