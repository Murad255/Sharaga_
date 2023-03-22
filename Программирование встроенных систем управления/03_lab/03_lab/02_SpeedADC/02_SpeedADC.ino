// Скорость ADC
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


// Использование analogRead
#define NUM 1000
uint16_t adc;
uint32_t time;
void setup() {
		//analogReference(DEFAULT); // DEFAULT INTERNAL использовать Vcc как AREF
		Serial.begin(115200);
		msgStart(2);
}

void loop() {
		time = micros();
		for (int i=0;i<NUM;i++)
		    adc = analogRead(A3); // Считываем полученное значение
		time = (micros()-time);
		Serial.print("ADC = "); Serial.print(adc); 
		Serial.print(" Average time (mks)= "); Serial.println(time/NUM);
		delay (500);
}


/*
// использование прямого обращения к регистрам avr
#define NUM 1000
uint16_t adc;
uint32_t time;
void SetupADC()
{
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0); //разрешаем АЦП, прескалер АЦП ставим 16 (по даташиту на Atmega)
}

inline unsigned int ReadADC(byte Chan)
{
  const byte ADMUXMask = (0 << ADLAR) | (0 << REFS1) | (1 << REFS0); // опорное напряжение  ARef=AVcc
  const byte ADSCMask = 1 << ADSC;
  ADMUX = ADMUXMask | (Chan & B0111);
  ADMUX = ADMUX;// задержка на переключение мультиплексора
  ADMUX = ADMUX;// задержка на переключение мультиплексора
  ADCSRA |= 1 << ADSC;// Запускаем АЦП
  while (ADCSRA & ADSCMask) {}; // ждем конца преобразования
  return (ADCL | (ADCH << 8)); // возвращаем результат
}

void setup() {
	  Serial.begin(115200);
	  msgStart(2);
	  pinMode(13,OUTPUT);
	  SetupADC();
}
void loop()
{
		PORTB |= 1<<5; // устанавливаем единицу на D13, Во время теста светодиод горит
		time = micros();
		for (int i=0;i<NUM;i++)
		    adc = ReadADC(0); // Считываем полученное значение
		time = (micros()-time);
		PORTB &= 0x11011111; // устанавливаем D13 в 0 тест закончен
		Serial.print("ADC = "); Serial.print(adc); 
		Serial.print(" Average time (mks)= "); Serial.println(time/NUM);
		delay (500);
}
*/

/*
// Еще один вариант увеличения скорости чтения ацп 
#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup() {
int start ;
int i ;

#if FASTADC
// set prescale to 16
sbi(ADCSRA,ADPS2) ;
cbi(ADCSRA,ADPS1) ;
cbi(ADCSRA,ADPS0) ;
#endif

Serial.begin(115200) ;
Serial.print("ADCTEST: ") ;
start = millis() ;
for (i = 0 ; i < 10000 ; i++)
analogRead(0) ;
Serial.print((millis() - start)/10); Serial.println(" mks (10000 calls)") ;

}

void loop() {
}

*/