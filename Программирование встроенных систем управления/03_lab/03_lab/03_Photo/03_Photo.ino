// Фоторезистор на ADC
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


// Вывод числа отсчетов для фоторезистора
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(3);
    pinMode(A1, INPUT);
}

void loop() {
    adc = analogRead(A1);
    Serial.println(adc);
    delay(1000);
} 

/*
// Простейшее фотореле (управление светодиодом D13) С постоянным порогом
#define D13 13
#define LEVEL 500
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(3);
    pinMode(A1, INPUT);
    pinMode(D13, OUTPUT);
}

void loop() {
    adc = analogRead(A1);
    Serial.print("Sensor: "); Serial.print(adc); Serial.print(" Led D13 ");
    if(adc<LEVEL){         
           digitalWrite(D13,HIGH);
           Serial.println("ON");
    }else{ digitalWrite(D13,LOW);
           Serial.println("OFF");
    }
    delay(1000);
} 
*/

/*
// Простейшее фотореле (управление светодиодом D13) Порог задается резистором на A0
#define D13 13
uint16_t adc = 0;
uint16_t level = 512;
void setup() {
    Serial.begin(115200);
    msgStart(3);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(D13, OUTPUT);
}

void loop() {
	level = analogRead(A0);
    adc = analogRead(A1);
    Serial.print("Level: "); Serial.print(level);
    Serial.print(" Sensor: "); Serial.print(adc); Serial.print(" Led D13 ");
    if(adc<level){         
           digitalWrite(D13,HIGH);
           Serial.println("ON");
    }else{ digitalWrite(D13,LOW);
           Serial.println("OFF");
    }
    delay(1000);
} 
*/
/*
// Простейшее фотореле (управление светодиодом D13) Порог задается резистором на A0
#define D9 9
uint16_t adc = 0;
void setup() {
    Serial.begin(115200);
    msgStart(3);
    pinMode(A1, INPUT);
    pinMode(D9, OUTPUT);
}

void loop() {
    adc = analogRead(A1);
    Serial.print(" Sensor: "); Serial.println(adc); 
    analogWrite(D9,map(adc,0,1024,0,255));   // Полный диапазон
//    analogWrite(D9,map(adc,100,900,0,100)); // Сокращенный диапазон для более динамического изменения
//    analogWrite(D9,map(adc,100,900,100,0)); // Инвертирование реакции чем темнее тем ярче LED на чем ярче тем ярче LED
  
    delay(100);
} 
*/