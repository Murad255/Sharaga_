// Переменный резистор на ADC
#define NUM_LAB 3    // Номер лабораторной работы
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


// Вывод числа отсчетов
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(1);
    pinMode(A0, INPUT);
}

void loop() {
    adc = analogRead(A0);
    Serial.println(adc);
    delay(1000);
}

/*
// Вывод напряжения на резисторе (напряжение на входе АЦП)
#define VCC 5.0
#define TICK  (VCC/1023.0)
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(1);
//    pinMode(A0, INPUT);
}

void loop() {
    adc = analogRead(A0);
    Serial.println(((float)adc)*TICK);
    delay(1000);
}
*/

/*
// Ввод целого числа от 0 до 102
#define MAX  100 
#define TICK (1023/100)       // Правильно
//#define TICK 1023/100         // Ошибка
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(1);
    pinMode(A0, INPUT);
}

void loop() {
    adc = analogRead(A0);
    Serial.println(adc/TICK);
    delay(1000);
}
*/

/*
// Ввод целого числа в диапазоне -20 +30
#define MIN  -20 
#define MAX  30 
#define TICK (1023/100)       // Правильно
//#define TICK 1023/100         // Ошибка
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(1);
    pinMode(A0, INPUT);
}

void loop() {
    adc = analogRead(A0);
    Serial.println(map(adc, 0, 1023, MIN, MAX));
    delay(1000);
}
*/


/*
// Ввод дробного числа в диапазоне -20.0 +30.0 с точностью до десятых
#define MIN  -200 
#define MAX  300 
//#define TICK (1023/100)       // Правильно
#define TICK 1023/100         // Ошибка
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(1);
    pinMode(A0, INPUT);
}

void loop() {
    adc = analogRead(A0);
    Serial.println(((float)map(adc, 0, 1023, MIN, MAX))/10.0,1);
    delay(1000);
}

*/