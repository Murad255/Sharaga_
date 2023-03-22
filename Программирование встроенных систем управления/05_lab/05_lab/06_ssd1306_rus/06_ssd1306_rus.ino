#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

unsigned char i1,i2,c3;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     2 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){                 
 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.cp437(true);
 
}

void loop() {
  TEST_display_1();
  delay(10000);
  TEST_display_2();
  delay(10000);
  TEST_display_3();
  delay(8000);
  TEST_display_4();
  delay(4000);
}

void TEST_display_1()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  
  for(i1=0; i1<8; i1++) {
    for(i2=0; i2<16; i2++) {
      c3=i1*16+i2;
      if(c3 == 0x0A || c3 == 0x0D) display.print(" ");
      else display.write(c3);
    }
    display.println("");
  }
  display.display();
}

void TEST_display_2()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  
  for(i1=8; i1<16; i1++) {
    for(i2=0; i2<16; i2++)
      display.write(i1*16+i2);
    display.println("");
  }
  display.display();
}

void TEST_display_3()
{
  display.clearDisplay(); 
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(utf8rus("АБВГДЕЖЗИЙКЛМНОП"));
  display.println(utf8rus("РСТУФХЦЧШЩЪЫЬЭЮЯ"));
  display.println(utf8rus("абвгдежзийклмноп"));
  display.println(utf8rus("рстуфхцчшщъыьэюя"));
 //  display.println(utf8rus("Ёё123ABCabc!@#\xBC\xBD"));
//  display.println(utf8rus("10\x83 10\x8A\x82 10\x81\x80 2\x85"));

  display.display();  
}

void TEST_display_4()
{
  display.clearDisplay(); 
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.setTextSize(1);
  display.println(utf8rus("Размер шрифта 1"));

  display.setTextSize(2);
  display.println(utf8rus("Размер 2"));

  display.setTextSize(3);
  display.println(utf8rus("Разм 3"));

  display.display();  
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
