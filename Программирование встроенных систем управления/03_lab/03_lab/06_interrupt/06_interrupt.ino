// использование прерываний в Arduino
/*
 * Версия кода опроса АЦП с прерыванием, нужно сделать следующие действия: 
 * 1. Mы должны разрешить прерывания, установив бит ADIE в регистре ADCSRA. 
 * 2. Команда sei() необязательна, достаточно установить ADIE, чтобы разрешить это прерывание. 
 * 3. Обработчик прерывания. Обратите внимание, что мы стараемся делать как можно меньше в ISR. 
 * Если к входу ничего не подключено, то контакт плавающий, и вы получите случайный результат. 
 * Подключите вход к GND, и вы должны увидеть 0, а при подключении к 5V должно отображаться 1023.
 */
 
#define NUM_LAB  3    // Номер лабораторной работы
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

// Простейшее прерывание от кнопки - получаем триггер кнопку
#define D13 13
#define D2 2 // Кнопка между цифровым пином 2 и GND
volatile byte state = LOW;

void setup() {
  pinMode(D13, OUTPUT);
  pinMode(D2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D2), blink, FALLING); // Инициализация прерывания от кнопки D2, обработчик blink(), на падающем фронте
}

void loop() {
  digitalWrite(D13, state);
}

void blink() {
  state = !state;
}

/*
// Прерывание от кнопки - подсчет числа нажатий и каждый 3 нажатие подача звукового сигнала
#define LED 13             // Светодиод
#define KEY 2               // Кнопка между цифровым пином 2 и GND
#define BEEP 5             // где висит пищалка       
volatile boolean state = false;
volatile boolean old   = false;
volatile uint16_t count = 0;


void setup() {
  Serial.begin (115200);
  msgStart(6);
  pinMode(LED, OUTPUT);
  pinMode(BEEP, OUTPUT);
  pinMode(KEY, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(KEY), blink, FALLING);
  Serial.println("Press KEY D2");  
}

void loop() {
  if(old!=state)
  {
  old=state;	  	
  digitalWrite(LED, state);
  if (count%3==0) beep();
  Serial.print("Count="); Serial.println(count);
  }
}

void blink() {
  state = !state;
  count++;
}

void beep() {
	digitalWrite(BEEP, HIGH);
	delay(20);
	digitalWrite(BEEP, LOW);
	Serial.println("Beep . . .");
}

*/


/*
// Прерывание АЦП
//#include <avr/io.h>

volatile bool converted;
volatile bool newValue;
volatile int value;

void setup()
{
  Serial.begin (115200);
  msgStart(6);

  //  ADC Setup
  ADCSRA = 0b10001111;      // C1:: Enable ADC & Interrupt, pre-scaler = 128
  ADMUX  = 0b01000000;      // C2:: Use AVCC and A0 as input to ADC
  sei();                    // C3:: Set global interrupt flag

  converted = true;
  newValue = false;
}

void loop()
{
  if (newValue) {
    newValue = false;
    Serial.println (value);
    delay(500);             // C5:: give you time to see the ouput
  }
  
  if (converted) {
    ADCSRA |= bit(ADSC) | bit(ADIE);   // C4:: start converting voltage on A0
    converted = false;
  }
}

ISR(ADC_vect)
{
  value = ADC;
  converted = true;
  newValue = true;
}
*/

/*
// Простейший осцилограф (запоминание значений в массиве и выдача его в порт)
// Смотреть использую встроеный в ардуино плоттер (пункт меню ИНСТРУМЕНТЫ) скорость 115200
#define KEY  2               // Кнопка обновления экрана
const byte adcPin = 1;      // Что исследуем
const int MAX_RESULTS = 512;
volatile uint16_t results [MAX_RESULTS];
volatile int resultNumber;

void setup ()
  {
  Serial.begin (115200);
  Serial.println ();

  // reset Timer 1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  TCCR1B = bit (CS11) | bit (WGM12);  // CTC, prescaler of 8
  TIMSK1 = bit (OCIE1B);
  OCR1A = 39;    
  OCR1B = 39;   // 20 uS - sampling frequency 50 kHz

  ADCSRA =  bit (ADEN) | bit (ADIE) | bit (ADIF);   // turn ADC on, want interrupt on completion
  ADCSRA |= bit (ADPS2);  // Prescaler of 16
//  ADCSRA |= (1 << ADPS1) | (1 << ADPS0);    // 8 prescaler for 153.8 KHz
  ADMUX = bit (REFS0) | (adcPin & 7);
  ADCSRB = bit (ADTS0) | bit (ADTS2);  // Timer/Counter1 Compare Match B
  ADCSRA |= bit (ADATE);   // turn on automatic triggering

}

// ADC complete ISR
ISR (ADC_vect)
{
    results[resultNumber++] = ADC;
    if(resultNumber == MAX_RESULTS)
    {
      ADCSRA = 0;  // turn off ADC
    }
} 

EMPTY_INTERRUPT (TIMER1_COMPB_vect);


void loop () {

  while (resultNumber < MAX_RESULTS)
    { }

  for (int i = 0; i < MAX_RESULTS; i++)
  {
    Serial.println (results [i]);
  }
  
  while(digitalRead(KEY)) {}; //ждем кнопки продолжения

  resultNumber = 0; 
  ADCSRA =  bit (ADEN) | bit (ADIE) | bit (ADIF)| bit (ADPS2) | bit (ADATE);   
   // turn ADC back on

 
}
*/