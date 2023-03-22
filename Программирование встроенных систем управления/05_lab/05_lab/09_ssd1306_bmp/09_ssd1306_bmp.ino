#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define NUM_LAB 5    // Номер лабораторной работы
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     3 // Reset pin # (or -1 if sharing Arduino reset pin)
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
// Растровые картинки,  конвертор https://javl.github.io/image2cpp/
//static const uint8_t Image1[] = {
static const PROGMEM uint8_t Image1[] = {
// 'Станкин', 128x64px
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x30, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x38, 0x3f, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x3c, 0x18, 0x00, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x3f, 0x10, 0x00, 0x00, 0x03, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xf8, 0xfc, 0x3f, 0x83, 0xf0, 0x00, 0x0e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xe0, 0x1c, 0x3f, 0xc3, 0xfb, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xe3, 0xfb, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0x80, 0x3f, 0xe3, 0xfb, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xf0, 0x3f, 0xe3, 0xfb, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xfc, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xfc, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xfd, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x83, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x03, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0x03, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0x03, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xf8, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xf1, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xe3, 0xc3, 0xfc, 0x3f, 0xe3, 0xfb, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc7, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x8f, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x1f, 0xc3, 0xfc, 0x3f, 0x80, 0x00, 0x3c, 0x7f, 0xc7, 0xfe, 0x3f, 0xe6, 0x3f, 0xff, 0xff, 
0xff, 0x3f, 0xc3, 0xfc, 0x3c, 0x00, 0x00, 0x30, 0x73, 0xc7, 0x7c, 0x37, 0x86, 0x3c, 0xff, 0xff, 
0xfe, 0x7f, 0xc3, 0xfc, 0x38, 0x00, 0x00, 0x60, 0x63, 0xc6, 0x70, 0x67, 0x06, 0x3c, 0x7f, 0xff, 
0xfc, 0xff, 0xc3, 0xfc, 0x30, 0x7f, 0x1f, 0xc0, 0x43, 0xc4, 0x60, 0xc6, 0x06, 0x3c, 0x7f, 0xff, 
0xf9, 0xff, 0xc3, 0xfc, 0x31, 0xff, 0x1f, 0x80, 0x43, 0xc4, 0x01, 0xc4, 0x06, 0x3c, 0x7f, 0xff, 
0xfb, 0xff, 0xc3, 0xfc, 0x31, 0xff, 0x1f, 0x04, 0x40, 0x04, 0x03, 0xc0, 0x06, 0x00, 0x7f, 0xff, 
0xf3, 0xff, 0xc3, 0xfc, 0x31, 0xff, 0x1e, 0x0c, 0x40, 0x04, 0x03, 0xc0, 0x46, 0x00, 0x7f, 0xff, 
0xf7, 0xff, 0xc3, 0xfc, 0x31, 0xff, 0x1c, 0x1c, 0x40, 0x04, 0x01, 0xc0, 0xc6, 0x00, 0x7f, 0xff, 
0xef, 0xff, 0xc3, 0xfc, 0x30, 0xff, 0x18, 0x40, 0x43, 0xc4, 0x20, 0xc3, 0xc6, 0x3c, 0x7f, 0xff, 
0xcf, 0xff, 0xc3, 0xfc, 0x38, 0x3f, 0x18, 0x80, 0x43, 0xc4, 0x30, 0xc7, 0xc0, 0x3c, 0x7f, 0xff, 
0xdf, 0xff, 0xc3, 0xfc, 0x38, 0x1f, 0x19, 0x80, 0x43, 0xc4, 0x78, 0xcf, 0xc0, 0x3c, 0x7f, 0xff, 
0xdf, 0xff, 0xc3, 0xfc, 0x3e, 0x1f, 0x1b, 0xfc, 0x43, 0xc4, 0x7e, 0xdf, 0xc0, 0x3c, 0x7f, 0xff, 
0xbf, 0xff, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xbf, 0xff, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xbf, 0xff, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 
0x7f, 0xff, 0xc3, 0xfc, 0x30, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x7f, 0xff, 0xc3, 0xfc, 0x30, 0x44, 0x00, 0x48, 0x1b, 0x0c, 0x92, 0x5a, 0x00, 0x44, 0x3f, 0xff, 
0x7f, 0xff, 0xc3, 0xfc, 0x32, 0x4c, 0xa0, 0xc9, 0x1b, 0x0c, 0x92, 0x5a, 0x1a, 0x48, 0x3f, 0xff, 
0x7f, 0xff, 0xc3, 0xfc, 0x3e, 0x93, 0x5b, 0x5b, 0xfb, 0x25, 0x12, 0x4a, 0x4f, 0xd3, 0xff, 0xff, 
0x7f, 0xff, 0xc3, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc3, 0xfc, 0x3b, 0x7f, 0xbf, 0xff, 0xed, 0xfe, 0xc7, 0xff, 0x6d, 0xfd, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfa, 0x28, 0x10, 0x50, 0x92, 0x24, 0xe4, 0x84, 0x92, 0x28, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfa, 0x28, 0x10, 0x50, 0x03, 0x24, 0xe4, 0x80, 0x13, 0x29, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xae, 0xf7, 0xed, 0xbf, 0xef, 0xb7, 0x4d, 0xfd, 0xff, 0xff, 
0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfb, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0x3f, 0xff, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

static const PROGMEM uint8_t Image2[] = {
// 'arduino', 128x64px
0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 
0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 
0xff, 0x80, 0x00, 0x7f, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xf8, 0x00, 0x01, 0xff, 
0xff, 0x00, 0x03, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0xff, 
0xfe, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x7f, 
0xfc, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x1f, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x3f, 
0xf8, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x1f, 
0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x07, 0xe0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 
0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 
0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x01, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 
0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xf8, 0x3f, 0xff, 0xf0, 0x03, 
0xc0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x3f, 0xff, 0xf8, 0x03, 
0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x3f, 0xff, 0xf8, 0x01, 
0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x01, 
0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x01, 
0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x03, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xfc, 0x01, 
0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x07, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x07, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x01, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x01, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x01, 
0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x3f, 0xff, 0xf8, 0x01, 
0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x7f, 0xff, 0xf8, 0x03, 
0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x03, 
0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x01, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 
0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0x80, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 
0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0x07, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 
0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 
0xf8, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x00, 0x1f, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x1f, 
0xfc, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x7f, 
0xfe, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0xff, 
0xff, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x00, 0x01, 0xff, 
0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x01, 0xe0, 0x00, 0x03, 0xff, 
0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 
0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
0xff, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 
0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xfb, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x7f, 
0xff, 0x07, 0xfc, 0x00, 0x7f, 0x00, 0x3f, 0xc7, 0xf8, 0xf8, 0x00, 0xfc, 0x3f, 0xcf, 0xe0, 0x0f, 
0xfe, 0x03, 0xfc, 0x78, 0x3f, 0x3e, 0x0f, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x1f, 0xcf, 0x87, 0x87, 
0xfe, 0x63, 0xfc, 0x7e, 0x3f, 0x3f, 0xc7, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x1f, 0xcf, 0x1f, 0xe3, 
0xfe, 0x73, 0xfc, 0x7e, 0x3f, 0x3f, 0xc7, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x0f, 0xcf, 0x1f, 0xf3, 
0xfc, 0x71, 0xfc, 0x7e, 0x3f, 0x3f, 0xe3, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x4f, 0xce, 0x3f, 0xf1, 
0xfc, 0xf9, 0xfc, 0x7e, 0x3f, 0x3f, 0xe3, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x67, 0xce, 0x3f, 0xf1, 
0xf8, 0xf8, 0xfc, 0x01, 0xff, 0x3f, 0xe3, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x63, 0xce, 0x3f, 0xf1, 
0xf9, 0xf8, 0xfc, 0x01, 0xff, 0x3f, 0xe3, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x73, 0xce, 0x3f, 0xf1, 
0xf9, 0xfc, 0x7c, 0x78, 0xff, 0x3f, 0xe7, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x79, 0xce, 0x3f, 0xf1, 
0xf0, 0xf8, 0x7c, 0x7c, 0x7f, 0x3f, 0xc7, 0xc7, 0xf8, 0xff, 0x8f, 0xfc, 0x78, 0xce, 0x3f, 0xf3, 
0xf0, 0x00, 0x7c, 0x7e, 0x7f, 0x3f, 0xc7, 0xc7, 0xf9, 0xff, 0x8f, 0xfc, 0x7c, 0x0f, 0x1f, 0xe3, 
0xe3, 0xfc, 0x3c, 0x7e, 0x3f, 0x3f, 0x8f, 0xe7, 0xf1, 0xff, 0x8f, 0xfc, 0x7e, 0x0f, 0x0f, 0xe7, 
0xe7, 0xfe, 0x3c, 0x7e, 0x3f, 0x1c, 0x1f, 0xe1, 0xe3, 0xff, 0x87, 0xfc, 0x7e, 0x0f, 0x83, 0x8f, 
0xc7, 0xfe, 0x3c, 0x7f, 0x1f, 0x01, 0xff, 0xf8, 0x0f, 0xf8, 0x00, 0xfc, 0x7f, 0x0f, 0xf0, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

// ПРИМЕРЫ ===========================================================
#define D2          2
#define BEEP        5
void setup() {
    Serial.begin(115200);
    msgStart(8);
    pinMode(D2, INPUT); // По умолчани все gpio установлены как входы, но желательно прямо указывать что это вход
    pinMode(BEEP, OUTPUT);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.println(utf8rus("  Пример вывода"));
    display.println(utf8rus("Пример растрового"));
    display.println(utf8rus("  изображения"));
    display.println("");
    display.println("");
    display.println(utf8rus("Смена картинки"));
    display.println(utf8rus("нажатие кнопки D2"));
    display.display();
    while(digitalRead(D2)) {};
    delay(1000);
}
boolean buttonWasUp = true;  // была ли кнопка отпущена?
boolean ImageChange = false;  // что выводить

void loop()
{
  boolean buttonIsUp = digitalRead(D2);
  if (buttonWasUp && !buttonIsUp) {
    delay(10);
    buttonIsUp = digitalRead(D2);
    if (!buttonIsUp) {  // если она всё ещё нажата...
      ImageChange = !ImageChange;
      beep();
      display.clearDisplay();     
      if(ImageChange)  display.drawBitmap(0, 0, Image1, 128, 64, 1); else display.drawBitmap(0, 0, Image2, 128, 64, 1);
      display.display();
      Serial.print(F("Red led state: "));Serial.println(ImageChange);
    }
  }
  buttonWasUp = buttonIsUp;// запоминаем последнее состояние кнопки для новой итерации
}

// Звук нажатия кнопки
void beep(){
  digitalWrite(BEEP, HIGH);
  delay(50);
  digitalWrite(BEEP, LOW);
}
