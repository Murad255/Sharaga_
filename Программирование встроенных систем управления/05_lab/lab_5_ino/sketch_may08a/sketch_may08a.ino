/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №3
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */



/*
  Класс для поиска и  возврата значения после ключевого слова.
  Для поиска требуется в буфер buf записать строку и
  в bufLength указать её длину, и затем вызвать нужный метод.
*/

class Parser
{
private:
  char findBuf[100];

public:
  static const int bufMaxLength = 100; // максимальное число символов
  char buf[bufMaxLength];        // буфер строки поиска
  int bufLength;             // длина заданной строки

  int findSymbol(const char findContext); // возвращает индекс искомого символа, если не найден, то -1
  int findStr(const char *findContext); // возвращает индекс искомой строки, если не найден, то -1
  bool isFind(const char *findContext); // возвращает true, если искомая строка найдена, иначе false
  bool findInt(int *result);        // считывает значение int от -32760 до 32760
//  bool findFloat(float *result);      // считывает значение float до 2х знаков после запятой
  bool findFloatHowInt(int *result);    // считывание значения float с возвратом его в виде int переменной со сдвигом на 1 число
//  bool findStr8(char *findStr8);      // считывает первые 8 символов после команды setStr
  void bufClean();            //отчистка буфера
};

// String Parser::findTextXML( String str, String findContext)
// {
//  int find1 = str.indexOf("<" + findContext + ">");
//  int find2 = str.indexOf("</" + findContext + ">");
//  if ((find1 < 1) || (find2 < 1))
//    return "";
//  String findStr = "";
//  for (int i = find1 + ("<" + findContext + ">").length(); i < find2; i++)
//  {
//    findStr += str[i];
//  }
//  return findStr;
// }

///отчистка буфера
void Parser::bufClean()
{
  //посимвольно зануляем символы в буфере
  for (int i = 0; i < bufMaxLength; i++)
    buf[i] = 0;
}

/* поиск  символа findContext в строке
 * возвращает индекс найденого символа, иначе -1 */
int Parser::findSymbol(const char findContext)
{
  //проверяем каждый символ
  for (int i = 0; i < bufLength; i++)
  {
    // при нахождении возвращаем индекс
    if (findContext == Parser::buf[i])
      return i;
  }
  return -1;
}

/* поиск строки в буфере
 * аналог indexOf, возвращает -1, если строка не найдена,
 * или индекс первого символа найденной строки */
int Parser::findStr(const char *findContext)
{
  // проверяем буфер до
  for (int i = 0; i < bufLength - (int)strlen(findContext) + 1; i++)
  {
    // копируем равную по длинне с искомой строку из буфера
    // со сдвигом на i символов во временный буфер
    strncpy(findBuf, &buf[i], (int)strlen(findContext));
    //обозначаем конец
    findBuf[(int)strlen(findContext)] = 0;
    // если строки равны, то возвращаем её индекс в буфере
    if (strcmp(findContext, findBuf) == 0)
      return i;
  }
  return -1; // если не найдена
}

// bool Parser::findStr8(char *findContext)
// {
//  // int mult = 1;
//  // const int naxNum = 6;
//  // char *strNum[naxNum];
//  int start;    // начальный индекс
//  int cNum = 0; // индекс записи
//  // начинаем поиск с пробела
//  start = findSymbol(' ') + 1;

//  for (int i = 0; i < 8; i++) // cNum <= 8; i++)
//  {
//    char c = buf[start + i];
//    // проверка, это латинский символ или число
//    if ((c >= '0' && c <= '9') ||
//      (c >= 'a' && c <= 'z') ||
//      (c >= 'A' && c <= 'Z'))
//    {
//      // записываем во временный буфер и сдвигаем индекс
//      findContext[cNum] = c;
//      cNum++;
//    }
//  }
//  findContext[cNum] = 0; //обозначаем конец
//  return 1;
// }

///возвращает true если строка найдена
bool Parser::isFind(const char *findContext)
{
  if (findStr(findContext) >= 0)
    return true;
  else
    return false;
}

/* считывает значение int от -32760 до 32760
 * если найдено значение, то возвращиет true
 * результат возвращает через ссылку result */
bool Parser::findInt(int *result)
{
  int mult = 1;     //множитель для отрицательного числа
  const int naxNum = 6; //предел для int16
  // char *strNum[naxNum];
  int start;   // начальный индекс
  int num = 0; // индекс записи
  // начинаем поиск с пробела или знака -
  if ((start = findSymbol('-')) >= 0)
  {
    mult = -1; // полученное число в конце сделаем отрицательным
    ++start;
  }
  else
  {
    start = findSymbol(' ') + 1;
  }

  int i = 0;
  //продолжаем поиск со старта до конца буфера
  while (buf[start + i] != 0) //(( i < naxNum) &&(buf[start + i]!=0))
  {
    // определяем, число ли это
    int n = buf[start + i] - '0';
    if (n >= 0 && n <= 9)
    {
      if (num >= 3276) // проверка на выход за пределы int16
        return 0;
      num *= 10; // десятичный сдвиг влево текущего значения
      num += n;  // в конец прибавляем число
    }
    //если следующий символ не пробел (его пропускаем), то выходим из цикла
    else if (buf[start + i] != ' ')
      break;

    i++;
  }
  if (!i)
    return 0;  // если не было цифр
  num *= mult;   // при необходимости делаем отрицательным
  *result = num; // присваиваем ссылку на число
  return 1;
}

// /* считывает значение float до 2х знаков после запятой
//  * если найдено значение, то возвращиет true
//  * результат возвращает через ссылку result  */
// bool Parser::findFloat(float *result)
// {
//  int mult = 1;
//  const int naxNum = 6;
//  char *strNum[naxNum];
//  int start;
//  float num1 = 0; // число до запятой
//  float num2 = 0; // число после запятой
//  float fNum = 0;
//  // начинаем поиск с пробела или знака -
//  if ((start = findSymbol('-')) >= 0)
//  {
//    mult = -1;
//    ++start;
//  }
//  else
//  {
//    start = findSymbol(' ') + 1;
//  }

//  //находим целое число
//  int i = 0;
//  while (buf[start + i] != 0)
//  {
//    int n = buf[start + i] - '0';
//    if (n >= 0 && n <= 9)
//    {
//      if (num1 >= 3276)
//        return 0;
//      num1 *= 10;
//      num1 += n;
//    }
//    // выходим из цикла при достижении запятой, точки или пробела
//    else if (
//      buf[start + i] != ' ' ||
//      buf[start + i] != '.' ||
//      buf[start + i] != ',')
//    {
//      break;
//    }

//    i++;
//  }

//  // находим дробь
//  // если найдена точка иля запятая, отмечаем начало дробной части
//  if ((start = findSymbol('.')) >= 0)
//    ++start;
//  else if ((start = findSymbol(',')) >= 0)
//    ++start;
//  // если не найдена точка или запятая, возвращаем найденное число
//  else
//  {
//    num1 *= mult;
//    *result = num1;
//    return 1;
//  }

//  i = 0;
//  int dev = 1; // делитель дробной части
//  while ((i < naxNum) && (buf[start + i] != 0))
//  {
//    int n = buf[start + i] - '0';
//    if (n >= 0 && n <= 9)
//    {
//      dev *= 10;
//      num2 *= 10;
//      num2 += n;
//    }
//    else if (buf[start + i] != ' ')
//      break;

//    i++;
//  }
//  // делим целое число на делитель для получения дробной части
//  num2 /= dev;
//  fNum = num1 + num2; // складываем целую и дробную части
//  fNum *= mult;
//  *result = fNum;
//  return 1;
// }


/* считывает значение float до 1 знаков после запятой
 * с возвратом его в виде int переменной со сдвигом на 1 число (регулируется до 2)
 * если найдено значение, то возвращиет true
 * результат возвращает через ссылку result */
bool Parser::findFloatHowInt(int *result)
{
  int mult = 1;
  const int naxNum = 6;
  char *strNum[naxNum];
  int start;
  int num1 = 0; // число до запятой
  int num2 = 0; // число после запятой
  int fNum = 0;
  // начинаем поиск с пробела или знака -
  if ((start = findSymbol('-')) >= 0)
  {
    mult = -1;
    ++start;
  }
  else
  {
    start = findSymbol(' ') + 1;
  }

  //находим целое число
  int i = 0;
  while (buf[start + i] != 0)
  {
    int n = buf[start + i] - '0';
    if (n >= 0 && n <= 9)
    {
      if (num1 >= 3276)
        return 0;
      num1 *= 10;
      num1 += n;
    }
    // выходим из цикла при достижении запятой, точки или пробела
    else if (
      buf[start + i] != ' ' ||
      buf[start + i] != '.' ||
      buf[start + i] != ',')
    {
      break;
    }

    i++;
  }

  // находим дробь
  // если найдена точка иля запятая, отмечаем начало дробной части
  if ((start = findSymbol('.')) >= 0)
    ++start;
  else if ((start = findSymbol(',')) >= 0)
    ++start;
  // если не найдена точка или запятая, возвращаем найденное число
  else
  {
    num1 *= mult;
    *result = num1;
    return 1;
  }

  i = 0;
  int dev = 1; // делитель дробной части
  const int accuracy = 10;
  while ((i < naxNum) && (buf[start + i] != 0))
  {
    int n = buf[start + i] - '0';
    // для увеличения точности поставить dev<=100
    if (n >= 0 && n <= 9 && dev<=accuracy)
    {
      dev *= 10;
      num2 *= 10;
      num2 += n;
    }
    else if (buf[start + i] != ' ')
      break;

    i++;
  }
  // делим целое число на делитель для получения дробной части
  //num2 /= dev;
  fNum = num1*accuracy + num2*accuracy/dev; // складываем целую и дробную части
  fNum *= mult;
  *result = fNum;
  Serial.println("RGB led state: red");

  return 1;
}

#include <DHT.h>
#include <Adafruit_Sensor.h> // требуется для бибилиотеки DHT

#define DHTPIN 4
#define heater_out 12
#define work_status_led 13


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
        pinMode(heater_out, OUTPUT);
        pinMode(work_status_led, OUTPUT);
        digitalWrite(work_status_led, 1);

        dht.begin();
    }

    void UpTc()
    {
    if ((_Tc+dev)<=Tmax)
        _Tc =_Tc+dev;
    }

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
    digitalWrite(heater_out, heat && Heater::isWork);
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


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     3 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SIZE_POINTS     20 


namespace Display{

  int _Td=0,_Tc=0; 
  int points[SIZE_POINTS];

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  

  // ссылка на метод для логирования 
  void (*Log)(const char*);


  String utf8rus(String source);
  void Begin(void (*logFunctin)(const char*) );
  void  Update();

}

void Display::Begin(void (*logFunctin)(const char*) ){

  Log = logFunctin;

//  points = new Queue<int>();

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }

  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();

  // uint8_t i;
  // // msgStart(8);
  //  pinMode(A0, INPUT);

  //  display.cp437(true);
  //  display.clearDisplay();
  //  display.setTextColor(WHITE);
  //  display.setTextSize(2);
  //  display.setCursor(0,0);
  //  display.println(utf8rus("Напряжение"));
  //  // Шкала отсчеты
  //  for (i=0;i<32;i++)
  //  {
  //  if(i%8==0) display.drawFastVLine(i*4, 45, 8,SSD1306_WHITE); 
  //  else        display.drawFastVLine(i*4, 45, 4,SSD1306_WHITE);
  //  }    
  //  display.display();
}

String Display::utf8rus(String source)
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

void  Display::Update(){
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print(F("Hello, world!"));
 display.display();

}

#define baudRate 9600 // Скорость COM порта
//#define DEBUG


#define LED_R 9
#define LED_G 10
#define LED_B 11

#define down_tc_bt 2
#define up_tc_bt 5

Parser pCommand;            // объект класса для храниения и распознавания строки
boolean downBtWasUp = true; // была ли кнопка отпущена?
boolean upBtWasUp = true;

//прототипы функций
void ComCommandHandler();
void help();
void state();
void rgbLedOn(boolean R, boolean G, boolean B); // установка нужного цвета

// void Log(const char*  str){
//   Serial.println(str);
// }
void setup()
{
    //Устанавливаем режимы работы пинов как выходы
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(baudRate); //инициализируем последовательный порт и устанавливаем скорость 9600
    help();                 // вывод помощи

    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(down_tc_bt, INPUT_PULLUP);
  pinMode(up_tc_bt, INPUT_PULLUP);

    
   if(! Display::display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64 !!!!!!!!!!!!!!!!!!!!! Aдрес !!!!!!!!!!!
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
    Display::display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  Display::display.clearDisplay();

  // Draw a single pixel in white
  Display::display.drawPixel(10, 10, SSD1306_WHITE);


    Heater::Begin();
  // просто передаём ссылку на метод, отправляющий строку в консоль
//  Display::Begin( [](const char*  str){Serial.println(str);}); 
  
    Serial.print(millis()); //вывод текущего времени
    Serial.print(F(" : Enter command > "));
}

void loop()
{

  ComCommandHandler();

    // обработчик кнопки
    boolean downBtIsUp = !digitalRead(down_tc_bt);
    if (!downBtWasUp && downBtIsUp)
    {
        delay(10);
        downBtIsUp = !digitalRead(down_tc_bt);
        if (downBtIsUp)
        {
            Heater::DownTc();
      state();
        }
    }

  // обработчик кнопки
    boolean upBtIsUp = !digitalRead(up_tc_bt);
    if (!upBtWasUp && upBtIsUp)
    {
        delay(10);
        upBtIsUp = !digitalRead(up_tc_bt);
        if (upBtIsUp)
        {
            Heater::UpTc();
            state();
        }
    }

    // запоминаем последнее состояние кнопки
    downBtWasUp = downBtIsUp;
    upBtWasUp = upBtIsUp;

    // считывание показания датчика температуры и потенциометра
    Heater::Update();
    Display::Update();

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

// void yield()
// {
//     static long time;
//     static long pastTime;
//     time = millis(); // текущее время

//     // повтор каждые 3 секунды
//     if (time - pastTime >= 3000)
//     {
//         state(); // вывод статуса
//         pastTime = time;
//     }
// }


void ComCommandHandler(){
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
        else if (pCommand.isFind("setERR")) // setERR 2.6
        {
            Serial.println(F("setERR"));
            int ERR;
            if (pCommand.findFloatHowInt(&ERR))
                if (ERR > 4 * Heater::dev || ERR < -4 * Heater::dev) //проверка выхода за диапазон
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
    Serial.println("T = " + String((float)Heater::_Tdht / (float)Heater::dev));
    Serial.println("H = " + String((float)Heater::_Hdht / (float)Heater::dev));
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
