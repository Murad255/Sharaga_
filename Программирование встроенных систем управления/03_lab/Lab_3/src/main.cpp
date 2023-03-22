#include <Arduino.h>
/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №3
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */

#include "Parser.h" //созданный для парсинга класс

#define baudRate 9600 // Скорость COM порта
//#define DEBUG

#define heater_out 12
#define work_status_led 13

#define LED_R 9
#define LED_G 10
#define LED_B 11

#define temp_LM35pin A2
#define setings_pot A0
#define job_status_bt 2

Parser pCommand;            // объект класса для храниения и распознавания строки
boolean buttonWasUp = true; // была ли кнопка отпущена?

// пространство имён нагревателя (вместо синглетон класса)
namespace Heater
{
    const int dev = 10;  // точность значений - 1 числа после запятой
    int _Tt = 0;            // показания датчика   
    int _Tc = 0;
    const int Tmin = 2*dev;
    const int Tmax = 35*dev;

    int GT = 2*dev;
    int ERR = 0;

    boolean isWork = 1;
    boolean isHeated = 0;

    void Begin()
    {
        pinMode(heater_out, OUTPUT);
        pinMode(work_status_led, OUTPUT);
        pinMode(temp_LM35pin, INPUT);
        pinMode(setings_pot, INPUT);

        pinMode(job_status_bt, INPUT_PULLUP);
        digitalWrite(work_status_led, 1);
    }

    void SetTt(int temp)
    {
        //  if (temp>=Tmin && temp<= Tmax)
        _Tt = map(temp, 0, 1023, Tmin, Tmax) + ERR; // для потенциометра!
    }
    int GetTt() { return _Tt; }

    void SetTc(int temp)
    {
        // if (temp>=Tmin && temp<= Tmax)
        _Tc = map(temp, 0, 1023, Tmin, Tmax);
    }
    int GetTc() { return _Tc; }

    // установить статус работы нагревателя
    void SetWorkStatus(boolean);

    // включить или выключить нагрев
    void Switch(boolean);
}

//прототипы функций
void help();
void state();
void rgbLedOn(boolean R, boolean G, boolean B); // установка нужного цвета

void setup()
{
    //Устанавливаем режимы работы пинов как выходы
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(baudRate); //инициализируем последовательный порт и устанавливаем скорость 9600
    help();                 // вывод помощи

    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);

    Heater::Begin();
    Serial.print(millis()); //вывод текущего времени
    Serial.print(F(" : Enter command > "));
}

void loop()
{
    if (Serial.available())
    {
        //отчищаем буфер и записываем в него строку
        pCommand.bufClean();
        pCommand.bufLength = Serial.readBytes((byte *)(pCommand.buf), pCommand.bufMaxLength);

        if (pCommand.isFind("help"))
        {
            Serial.print(F("help"));
            help();
        }
        else if (pCommand.isFind("state"))
        {
            Serial.print(F("state"));
            state();
        }
        else if (pCommand.isFind("setGT"))
        {
            Serial.print(F("setGT"));
            int GT;
            if (pCommand.findInt(&GT))
                if (GT > 5 || GT < -5) //проверка выхода за диапазон
                    Serial.println(F("error setGT: going out of range "));
                else
                    Heater::GT = GT * Heater::dev; //если проверка пройдена, выводим результат
            else
                Serial.println(F("error setGT ")); //число не обнаружено
        }
        else if (pCommand.isFind("setERR"))  // setERR 2.6
        {
            Serial.println(F("setERR"));
            int ERR;
            if (pCommand.findFloatHowInt(&ERR))
                if (ERR > 4*Heater::dev || ERR < -4*Heater::dev) //проверка выхода за диапазон
                    Serial.println(F("error setERR: going out of range "));
                else
                    Heater::ERR = ERR; //если проверка пройдена, выводим результат
            else
                Serial.println(F("error setERR ")); //число не обнаружено
        }
        else if (pCommand.isFind("ON"))
        {
            //включаем встроенный всетодиод
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println(F("Heater ON"));
            Heater::SetWorkStatus(1);
        }
        else if (pCommand.isFind("OFF"))
        {
            //выключаем встроенный всетодиод
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println(F("Heater OFF"));
            Heater::SetWorkStatus(0);
        }
    }

    // обработчик кнопки
    boolean buttonIsUp = !digitalRead(job_status_bt);
    if (!buttonWasUp && buttonIsUp)
    {
        delay(10);
        buttonIsUp = !digitalRead(job_status_bt);
        if (buttonIsUp)
        { 
            Heater::SetWorkStatus(!Heater::isWork);
            state();
        }
    }
    // запоминаем последнее состояние кнопки
    buttonWasUp = buttonIsUp;

    // считывание показания датчика температуры и потенциометра
    Heater::SetTt(analogRead(temp_LM35pin));
    Heater::SetTc(analogRead(setings_pot));

    // установка состояния RGB светодиода
    if (Heater::isWork)
        if (Heater::GetTt() <= (Heater::GetTc() - Heater::GT))
        {
            Heater::Switch(1);
            rgbLedOn(1, 0, 0);
        }
        else if (Heater::GetTt() >= Heater::GetTc())
        {
            Heater::Switch(0);
            rgbLedOn(0, 0, 1);
        }
        else
            rgbLedOn(0, 1, 0);
    else
        rgbLedOn(0, 0, 0);

    delay(10);

}

void yield()
{
    static long time;
    static long pastTime;
        time = millis(); // текущее время

    // повтор каждые 3 секунды
    if (time - pastTime >= 3000){
        state(); // вывод статуса

        pastTime=time;
    }
}

void help()
{
    Serial.println(F("\nThe following commands are described:"));
    Serial.println(F(" state - Heater current state"));
    Serial.println(F(" setGT - set hysteresis parameters "));
    Serial.println(F(" setERR - set the value of the added error"));
    Serial.println(F(" ON - turn on Heater"));
    Serial.println(F(" OFF - turn off Heater"));
    Serial.println(F(" help - help information"));
}

void state()
{
    Serial.println(F("\nState:"));
    Serial.println("Tt = " + String((float)Heater::_Tt / (float)Heater::dev));
    Serial.println("Tc = " + String((float)Heater::_Tc / (float)Heater::dev));
    Serial.println("GT = " + String((float)Heater::GT / (float)Heater::dev));
    Serial.println("ERR = " + String((float)Heater::ERR / (float)Heater::dev));
    if (Heater::isHeated)
        Serial.println(F("Heated = on"));
    else
        Serial.println(F("Heated = off"));
    if (Heater::isWork)
        Serial.println(F("Heater is Work"));
    else
        Serial.println(F("Heater is not Work"));
}

/// установка нужного цвета
void rgbLedOn(boolean R, boolean G, boolean B)
{
    digitalWrite(LED_R, R);
    digitalWrite(LED_G, G);
    digitalWrite(LED_B, B);
}

// установить статус работы нагревателя
void Heater::SetWorkStatus(boolean status)
{
    Heater::isWork = status;
    digitalWrite(work_status_led, status);
    Heater::Switch(Heater::isHeated);
}

// включить или выключить нагрев
void Heater::Switch(boolean heat)
{
    //нагрев регулируется только при включённом устройстве
    digitalWrite(heater_out, heat && Heater::isWork);
    Heater::isHeated = heat && Heater::isWork;
}