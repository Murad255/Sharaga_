#include <Arduino.h>
/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №5
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */
#include "Heater.h" // код нагревателя

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 2 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OFFSET_DOWN 16
#define OFFSET_RIGHT 50

#define BUZER_PIN 5
#define BUZER_TIME 100 //50
#define HEAT_LED_PIN 13

#define down_tc_bt 2
#define up_tc_bt 3

boolean downBtWasUp = true; // была ли кнопка отпущена?
boolean upBtWasUp = true;

void setup()
{
    Serial.begin(115200);
    pinMode(A0, INPUT);
    pinMode(HEAT_LED_PIN, OUTPUT);
    pinMode(BUZER_PIN, OUTPUT);

    pinMode(down_tc_bt, INPUT_PULLUP);
    pinMode(up_tc_bt, INPUT_PULLUP);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }
    Heater::Begin();
    Heater::_Tc = 290; // начальное значение порога

    // инициялизация дисплея SSD1306
    display.cp437(true);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("Tt =");
    display.setCursor(0, OFFSET_DOWN);
    display.println("Tc =");
    display.setCursor(0, OFFSET_DOWN*2);
    display.println("GT =");
    display.setCursor(0, OFFSET_DOWN*3);
    display.println("Heat");
    display.drawCircle(SCREEN_WIDTH-10,SCREEN_HEIGHT-10,7,SSD1306_WHITE);
    display.display();
}

void loop()
{

    /// обновление показаний датчика 
    Heater::Update();
    static uint8_t mode = 0;
    if (Heater::isWork)
        if (Heater::GetTt() <= (Heater::GetTc() - Heater::GT) && mode != 1)
        {
            mode = 1;
            tone(BUZER_PIN, 5000, BUZER_TIME);
            Heater::Switch(1);
        }
        else if (Heater::GetTt() >= Heater::GetTc() && mode != 2)
        {
            mode = 2;
            tone(BUZER_PIN, 5000, BUZER_TIME);
            Heater::Switch(0);
        }

    /// вывод данных на дисплей
    char buf[6];
    char bufTc[6];
    char bufGT[6];

    int Td = 0, Td_old;
    Td = Heater::GetTt();
    if (Td != Td_old)
    {
        Td_old = Td;
        // преобразовние из значений в строки
        Serial.println((float)Td / (float)Heater::dev);
        dtostrf((float)Td / (float)Heater::dev, 4, 2, buf);
        dtostrf((float)Heater::GetTc() / (float)Heater::dev, 4, 2, bufTc);
        dtostrf((float)Heater::GT/ (float)Heater::dev, 4, 2, bufGT);

        // вывод значения температуры
        display.fillRect(OFFSET_RIGHT, 0, 80, 20, SSD1306_BLACK); // Стереть прошлое изображение
        display.setCursor(OFFSET_RIGHT, 0);
        display.println(buf);

        // вывод значения порога
        display.fillRect(OFFSET_RIGHT, OFFSET_DOWN, 80, 20, SSD1306_BLACK);
        display.setCursor(OFFSET_RIGHT, OFFSET_DOWN);
        display.println(bufTc);

        // вывод значения гистерезиса
        display.fillRect(OFFSET_RIGHT, OFFSET_DOWN*2, 40, 20, SSD1306_BLACK);
        display.setCursor(OFFSET_RIGHT, OFFSET_DOWN*2);
        display.println(bufGT);

        // вывод статуса работы нагревателя и закрашиваем круг в углу
        display.fillRect(OFFSET_RIGHT+10, OFFSET_DOWN*3, 40, 20, SSD1306_BLACK);
        display.setCursor(OFFSET_RIGHT+10, OFFSET_DOWN*3);
        if (Heater::isHeated){
            display.println("on");
            display.fillCircle(SCREEN_WIDTH-10,SCREEN_HEIGHT-10,6,SSD1306_WHITE);
        }
        else{
            display.println("off");
            display.fillCircle(SCREEN_WIDTH-10,SCREEN_HEIGHT-10,6,SSD1306_BLACK );
        }

        display.display();
    }



    /// обработчик кнопки down
    boolean downBtIsUp = !digitalRead(down_tc_bt);
    if (!downBtWasUp && downBtIsUp)
    {
        delay(10);
        downBtIsUp = !digitalRead(down_tc_bt);
        if (downBtIsUp)
        {
            Heater::DownTc();
            // state();
        }
    }
    /// обработчик кнопки up
    boolean upBtIsUp = !digitalRead(up_tc_bt);
    if (!upBtWasUp && upBtIsUp)
    {
        delay(10);
        upBtIsUp = !digitalRead(up_tc_bt);
        if (upBtIsUp)
        {
            Heater::UpTc();
            // state();
        }
    }

    // запоминаем последнее состояние кнопки
    downBtWasUp = downBtIsUp;
    upBtWasUp = upBtIsUp;

    delay(50);
}

void yield()
{
    static boolean ledIsLight = false;

    static long time;
    static long pastTime;
    time = millis(); // текущее время

    // повтор 2 раза в секунду
    if (time - pastTime >= 250)
    {
        // переключаем светодиод при включении нагрева
        if (Heater::isHeated && !ledIsLight)
        {
            digitalWrite(HEAT_LED_PIN, HIGH);
            ledIsLight = true;
        }
        else
        {
            digitalWrite(HEAT_LED_PIN, LOW);
            ledIsLight = false;
        }

        pastTime = time;
    }
}