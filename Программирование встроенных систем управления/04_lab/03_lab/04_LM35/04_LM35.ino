// Терморезистор LM35 на ADC
#define NUM_LAB 3    // Номер лабораторной работы
#define LM35 A2      // куда прицеплен датчик температуры
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


// Вывод числа отсчетов для LM35
uint16_t adc = 2;
void setup() {
    Serial.begin(115200);
    msgStart(3);
    analogReference(INTERNAL); // 1.1 вольта
    pinMode(LM35, INPUT);
}

void loop() {
    adc = analogRead(LM35);
    Serial.println(adc);
    delay(1000);
} 

/*
// Вывод температуры LM35
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(4);
    //pinMode(LM35, INPUT);   // Не обязательно, т.к. установлен по умолчанию
     analogReference(INTERNAL);
}

void loop() {
    adc = analogRead(LM35);
    
    Serial.print(F("Temperature LM35 (C⁰)")); Serial.println((float)adc/9.31,1);
    delay(1000);
} 

*/

/*
float temp;
int tempPin = 2;
void setup()
{
   Serial.begin(115200);
   pinMode(LM35, INPUT);
   analogReference(INTERNAL);
}

void loop()
{
int adc;
  adc = analogRead(LM35);
  //temp = temp * 0.48828125;
  temp = ((float) adc * 1.1 / 1024 ) / 0.01;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}

*/