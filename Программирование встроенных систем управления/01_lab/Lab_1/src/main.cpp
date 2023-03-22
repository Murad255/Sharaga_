#include <Arduino.h>
/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №1
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */

#include "Parser.h" //созданный для парсинга класс

#define baudRate 9600 // Скорость COM порта
#define redLed 10     // светодиод, управляемый через setLed
//#define DEBUG

// help — экран помощи
// command1 — отображение в консоли введенной команды command1
// time - отображение в консоли результата вызова функции millis()
// setInt — ввод целого числа от -100 до +200 с выводом ошибки или введенного числа
// setStr — ввод строки до 8 символов с отображение введенной строки (только латинские
// setFloat — ввод дробного числа от -30 до +50 с точностью 2 десятичных разряда
// буквы и цифры), вывод ошибки
// info — вывод скорости порта

Parser pCommand; // объект класса для храниения и распознавания строки

//прототипы функций
void help(void);
void reboot(void);
void send_time(void);
void command1(void);
void info(void);

void setup()
{
    //Устанавливаем режимы работы пинов как выходы
    pinMode(redLed, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(baudRate); //инициализируем последовательный порт и устанавливаем скорость 9600
    help();                 // вывод помощи
    Serial.print(millis()); //вывод текущего времени
    Serial.print(F(" : Enter command > "));
}

void loop()
{
    if (Serial.available())
    {
        delay(400); //чтобы все данные успели передаться
        //отчищаем буфер и записываем в него строку
        pCommand.bufClean();
        pCommand.bufLength = Serial.readBytes((byte *)(pCommand.buf), pCommand.bufMaxLength);

#pragma region вывод отладочной информации
#ifdef DEBUG
        Serial.println("bufLength " + String(pCommand.bufLength));
        Serial.println("findStr " + String(pCommand.findStr("setInt")));
        Serial.println("strcmp " + String(strcmp("setInt", pCommand.buf)));
        Serial.println(pCommand.findSymbol(' '));
#endif
#pragma endregion

        //проверяем, какая команда введена
        if (pCommand.isFind("reboot"))
        {
            Serial.println(F("Reset arduino UNO"));
            reboot();
        }
        else if (pCommand.isFind("help"))
        {
            Serial.print(F("help"));
            help();
        }
        else if (pCommand.isFind("info"))
        {
            Serial.print(F("info"));
            info();
        }
        else if (pCommand.isFind("command1"))
        {
            Serial.print(F("command1"));
            command1();
        }
        else if (pCommand.isFind("time"))
        {
            Serial.println(F("time"));
            send_time();
        }
        else if (pCommand.isFind("led_on"))
        {
            //включаем встроенный всетодиод
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println(F("Led ON"));
        }
        else if (pCommand.isFind("led_off"))
        {
            //выключаем встроенный всетодиод
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println(F("Led OFF"));
        }

        /////task realization/////

        else if (pCommand.isFind("setInt"))
        {
            Serial.println(F("setInt command"));
            int res;                         //буфер для хранения результата
            if (pCommand.findInt(&res))      //если было найдено какое либо число int
                if (res > 200 || res < -100) //проверка выхода за диапазон
                    Serial.println(F("error setInt: going out of range "));
                else
                    Serial.println(res); //если проверка пройдена, выводим результат
            else
                Serial.println(F("error setInt ")); //число не обнаружено
        }

        else if (pCommand.isFind("setFloat"))
        {
            Serial.println(F("setFloat command"));
            float res;                         //буфер для хранения результата
            if (pCommand.findFloat(&res))      //если было найдено какое либо число float
                if (res > 50.0 || res < -30.0) //проверка выхода за диапазон
                    Serial.println(F("error setFloat: going out of range "));
                else
                    Serial.println(res); //если проверка пройдена, выводим результат
            else
                Serial.println(F("error setFloat ")); //число не обнаружено
        }
        else if (pCommand.isFind("setLed"))
        {
            Serial.println(F("setLed command"));
            int res; //буфер для хранения результата
            // было ли найдено какое либо число int в пределах от 0 до 255
            if (pCommand.findInt(&res) && (res >= 0 && res <= 255))
            {
                Serial.println(res);      //вывод результата
                analogWrite(redLed, res); //установка ШИМ сигнала
            }
            else
                Serial.println(F("error setInt "));
        }
        // setStr abc53tf
        else if (pCommand.isFind("setStr"))
        {
            Serial.println(F("setStr command"));
            char res[8];                //буфер для хранения результата
            if (pCommand.findStr8(res)) //если строка была найдена
                Serial.println(res);    //вывод результата
            else
                Serial.println(F("error setInt "));
        }
        else
        {
            Serial.println(F("Invalid command"));
        }
        Serial.print(millis());
        Serial.print(F(" : Enter command > "));
    }
}

void help(void)
{
    Serial.println(F("\nThe following commands are described:"));
    Serial.println(F(" time - send millis()"));
    Serial.println(F(" info - versions of the interpreter, the author of the development"));
    Serial.println(F(" reboot - reboot "));
    Serial.println(F(" help - show command list"));
    Serial.println(F(" led_off - led (pin d13) off"));
    Serial.println(F(" led_on - led (pin d13) on"));
    Serial.println(F(" /////task realization/////"));
    Serial.println(F(" setInt - parsing Int value"));
    Serial.println(F(" setFloat - parsing Float value"));
    Serial.println(F(" setLed - set 10 (red led) PWM output light value"));
    Serial.println(F(" setStr  - entering a string of up to 8 characters"));
}

void reboot(void)
{
    asm volatile("  jmp 0");
}

void send_time(void)
{
    Serial.print(F("Time (msec) "));
    Serial.println(millis());
}

void command1(void)
{
    //что-то выполняем
    Serial.print(F("execute command1"));
}

void info(void)
{
    Serial.println(F("\n interpreter version 1.0.4"));
    Serial.println(F(" author: \t Murad255"));
    Serial.println(F(" https://github.com/Murad255"));
    Serial.println(F(" bitcoin wallet: \t**********"));
}
