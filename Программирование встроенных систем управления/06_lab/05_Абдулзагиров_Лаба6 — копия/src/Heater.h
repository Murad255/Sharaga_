#pragma once
#include <Arduino.h>

#include <DHT.h>
#include <Adafruit_Sensor.h> // требуется для бибилиотеки DHT

#define DHTPIN 4
//#define heater_out 12
#define work_status_led 8
#define setings_pot A0


// пространство имён нагревателя (вместо синглетон класса)
namespace Heater
{
    DHT dht(DHTPIN, DHT11);

    const int dev = 10; // точность значений - 1 числа после запятой
    int _Tdht = 0;      // показания датчика температуры
    int _Hdht = 0;      // показания датчика влажности
    int _Tc = 0;
    const int Tmin = 10 * dev;
    const int Tmax = 30 * dev;

    int GT = 2 * dev;
    int ERR = 0;

    boolean isWork = 1;   // статус работы устройства
    boolean isHeated = 0; // статус работы нагревателя
    boolean isError = 0;  // true, если есть ошибки в работе

    void Begin()
    {
        //pinMode(heater_out, OUTPUT);
        pinMode(work_status_led, OUTPUT);
        digitalWrite(work_status_led, 1);
        pinMode(setings_pot, INPUT);

        dht.begin();
    }

    // увеличить Tc на 1 градус
    void UpTc()
    {
		if ((_Tc+dev)<=Tmax)
        _Tc =_Tc+dev;
    }

    // уменьшить Tc на 1 градус
	void DownTc()
    {
		if ((_Tc-dev)>=Tmin)
        _Tc =_Tc-dev;
    }

    int GetTt() { return _Tdht; }

    int GetTc() { return _Tc; }

    // установить статус работы нагревателя
    void SetWorkStatus(boolean);

    // установить статус ошибки
    void SetErrorStatus(boolean status);

    // включить или выключить нагрев
    void Switch(boolean);

    void Update()
    {
        _Tc = map(analogRead(setings_pot), 0, 1023, Tmin, Tmax);

        float h = dht.readHumidity();    //Измеряем влажность
        float t = dht.readTemperature(); //Измеряем температуру
        if (isnan(h) || isnan(t))
        { //Проверка. Если не удается считать показания,выводится «Ошибка считывания», и программа завершает работу
            Serial.println("Error read DHT11");
            SetErrorStatus(true);
        }
        else
        {
            SetErrorStatus(false);
            _Tdht = t * dev;
            _Hdht = h * dev;
        }
    }

}

// установить статус работы нагревателя (если setStatus == false, но не менять значение статуса)
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
    //digitalWrite(heater_out, heat && Heater::isWork);
    Heater::isHeated = heat && Heater::isWork;
}

// выключаем устройство, если есть ошибка
void Heater::SetErrorStatus(boolean status)
{
    static boolean pastIsWork;

    if (status != Heater::isError)
    {
        if (status)
        {
            // запоминаем предыдущее состояние
            pastIsWork = Heater::isWork;
            Heater::SetWorkStatus(false);
        }
        else
        {
            Heater::SetWorkStatus(pastIsWork);
        }
    }
    Heater::isError = status;
}
