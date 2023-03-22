#include <Arduino.h>
/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №6
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */
#include "Heater.h" // код нагревателя
#include "Parser.h" // код нагревателя

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#include <RH_ASK.h>

#define baudRate 9600 // Скорость COM порта

#define D13_LED 13 // светодиод отпраки пакета
#define D12_LED 12 // светодиод нажатие кнопки
#define D2_KEY 2   // кнопка

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 2 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OFFSET_DOWN 16
#define OFFSET_RIGHT 50

#define DATA_SENT_LED_PIN 12

#define down_tc_bt 2
#define up_tc_bt 3

boolean downBtWasUp = true; // была ли кнопка отпущена?
boolean upBtWasUp = true;

RH_ASK driver(2000, 8, 7, 0); // Инициализация передатчика
boolean transminOn = true;

struct TxData
{
    uint8_t id = 5;
    uint8_t pakskageNumbers = 0;
    uint8_t SentPeriod = 4;
    uint8_t Tt = 0;
    uint8_t Tc = 0;
};

TxData tData;

void UpdateDisplay();
void CheckSerialPortCommand();
void help();
void state();
void info();

void setup()
{
    Serial.begin(baudRate);
    pinMode(DATA_SENT_LED_PIN, OUTPUT);

    pinMode(down_tc_bt, INPUT_PULLUP);
    pinMode(up_tc_bt, INPUT_PULLUP);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    //Инициализируем передатчик
    if (!driver.init())
    {
        Serial.println(F("RF init failed!"));
        while (true)
        {
            delay(1);
        }
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
    display.setCursor(0, OFFSET_DOWN * 2);
    display.println("F =");
    display.setCursor(0, OFFSET_DOWN * 3);
    display.println("N =");
    display.display();
    delay(2000);
    help();
}

void loop()
{
    Heater::Update();         // обновление показаний датчика
    CheckSerialPortCommand(); // обработка команд из Serial интерфейса
    UpdateDisplay();          // вывод данных на дисплей

    /// обработчик кнопки down
    boolean downBtIsUp = !digitalRead(down_tc_bt);
    if (!downBtWasUp && downBtIsUp && tData.SentPeriod < 12)
    {
        delay(10);
        downBtIsUp = !digitalRead(down_tc_bt);
        if (downBtIsUp)
            tData.SentPeriod++;
    }
    /// обработчик кнопки up
    boolean upBtIsUp = !digitalRead(up_tc_bt);
    if (!upBtWasUp && upBtIsUp && tData.SentPeriod > 1)
    {
        delay(10);
        upBtIsUp = !digitalRead(up_tc_bt);
        if (upBtIsUp)
            tData.SentPeriod--;
    }
    // запоминаем последнее состояние кнопки
    downBtWasUp = downBtIsUp;
    upBtWasUp = upBtIsUp;

    // передача данных

    long time = millis(); // текущее время
    static long pastTime;

    if (time - pastTime >= tData.SentPeriod * 1000 && transminOn)
    {
        tData.Tt = Heater::_Tdht / Heater::dev;
        tData.Tc = Heater::_Tc / Heater::dev;
        digitalWrite(DATA_SENT_LED_PIN, HIGH);
        // Передаём данные
        driver.send((uint8_t *)&tData, sizeof(tData));
        // Ждем пока передача будет окончена
        driver.waitPacketSent();
        digitalWrite(DATA_SENT_LED_PIN, LOW);

        tData.pakskageNumbers++;
        pastTime = time;
    }

    delay(100);
}

void UpdateDisplay()
{

    char buf[6];
    char bufTc[6];

    // преобразовние из значений в строки
    dtostrf((float)Heater::GetTt() / (float)Heater::dev, 4, 2, buf);
    dtostrf((float)Heater::GetTc() / (float)Heater::dev, 4, 2, bufTc);

    // вывод значения температуры
    display.fillRect(OFFSET_RIGHT, 0, 80, 20, SSD1306_BLACK); // Стереть прошлое изображение
    display.setCursor(OFFSET_RIGHT, 0);
    display.println(buf);

    // вывод значения порога
    display.fillRect(OFFSET_RIGHT, OFFSET_DOWN, 80, 20, SSD1306_BLACK);
    display.setCursor(OFFSET_RIGHT, OFFSET_DOWN);
    display.println(bufTc);

    // вывод  периода передачи
    display.fillRect(OFFSET_RIGHT, OFFSET_DOWN * 2, 40, 20, SSD1306_BLACK);
    display.setCursor(OFFSET_RIGHT, OFFSET_DOWN * 2);
    display.println(tData.SentPeriod);

    // вывод номера пакета
    display.fillRect(OFFSET_RIGHT, OFFSET_DOWN * 3, 40, 20, SSD1306_BLACK);
    display.setCursor(OFFSET_RIGHT, OFFSET_DOWN * 3);
    display.println(tData.pakskageNumbers);

    display.display();
}

void CheckSerialPortCommand()
{
    if (Serial.available())
    {
        //отчищаем буфер и записываем в него строку
        // pCommand.bufClean();
        Parser pCommand;
        pCommand.bufLength = Serial.readBytes((byte *)(pCommand.buf), pCommand.bufMaxLength);

        if (pCommand.isFind("help"))
        {
            Serial.println(F("help"));
            help();
        }
        else if (pCommand.isFind("state"))
        {
            Serial.println(F("state"));
            state();
        }
        if (pCommand.isFind("info"))
        {
            Serial.println(F("info"));
            info();
        }
        else if (pCommand.isFind("setTime")) // setTime 4
        {
            Serial.println(F("setTime"));
            int Time;
            if (pCommand.findInt(&Time))
                if (Time >= 1 && Time <= 12) //проверка выхода за диапазон
                    tData.SentPeriod = (uint8_t)Time;
                else
                    Serial.println(F("error setTime: going out of range "));
            else
                Serial.println(F("error setGT ")); //число не обнаружено
        }
        else if (pCommand.isFind("setID")) // setID 2
        {
            Serial.println(F("setID"));
            int ID;
            if (pCommand.findInt(&ID))
                if (ID >= 0 && ID <= 100) //проверка выхода за диапазон
                    tData.id = (uint8_t)ID;
                else
                    Serial.println(F("error setID: going out of range "));
            else
                Serial.println(F("error setID ")); //число не обнаружено
        }
        else if (pCommand.isFind("ON"))
        {
            //выключаем передачу данных
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println(F("Transmit ON"));
            transminOn = true;
        }
        else if (pCommand.isFind("OFF"))
        {
            //включаем передачу данных
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println(F("Transmit OFF"));
            transminOn = false;
        }
    }
}

void help()
{
    Serial.println(F("\nThe following commands are described:"));
    Serial.println(F(" state - Heater current state"));
    Serial.println(F(" setTime - set the transmition period values "));
    Serial.println(F(" setID - set the id value"));
    Serial.println(F(" ON - turn on data transmetion"));
    Serial.println(F(" OFF - turn off data transmetion"));
    Serial.println(F(" help - help information"));
    Serial.println(F(" info - print info about developers"));
}

void state()
{
    Serial.println(F("\nState:"));
    Serial.println("Tt = " + String((float)Heater::GetTt() / (float)Heater::dev));
    Serial.println("Tc = " + String((float)Heater::GetTc() / (float)Heater::dev));
    Serial.println("id = " + String(tData.id));
    Serial.println("N = " + String(tData.pakskageNumbers));
    Serial.println("F = " + String(tData.SentPeriod));
}

void info()
{
    Serial.println(F("\n interpreter version 1.0.4"));
    Serial.println(F(" author: \t Murad255"));
    Serial.println(F(" https://github.com/Murad255"));
    Serial.println(F(" bitcoin wallet: \t**********"));
    Serial.print(F(" firmware time: \t"));
    Serial.println(__DATE__);
    Serial.print(F(" firmware data: \t"));
    Serial.println(__TIME__);
}
