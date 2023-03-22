#define D12  12
#define D13  13


// Попеременное мигание двумя светодиодами
void setup() {
   pinMode(D12, OUTPUT);
   pinMode(D13, OUTPUT);

}
void loop() {
  digitalWrite(D12, HIGH);  
  digitalWrite(D13, LOW);  
  delay(500);                       
  digitalWrite(D12, LOW);    
  digitalWrite(D13, HIGH);    
  delay(500);                 
}


/*
// Использование адекватных названий для обозначения gpio
// Возможно инвертирование сигналов для их большей адекватности
#define RED_LED     12
#define BLUE_LED    13

#define RED_LED_ON   digitalWrite(RED_LED, HIGH);
#define RED_LED_OFF  digitalWrite(RED_LED, LOW);

#define BLUE_LED_ON   digitalWrite(BLUE_LED, HIGH);
#define BLUE_LED_OFF  digitalWrite(BLUE_LED, LOW);


void setup() {
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);

}
void loop() {
  RED_LED_ON
  BLUE_LED_OFF
  delay(200);
  RED_LED_OFF
  BLUE_LED_ON
  delay(200);                 
}
*/

/*
//  использоване функции millis()
#define RED_LED      12
#define RED_LED_ON   digitalWrite(RED_LED, HIGH);
#define RED_LED_OFF  digitalWrite(RED_LED, LOW);
#define TIME         1000
uint32_t old_time;
uint8_t st;

void setup() {
   Serial.begin(115200);	
   pinMode(RED_LED, OUTPUT);
   old_time=millis();
   st=0;  // светодиод не горит
  Serial.println(F("\n<------ START ------->"));
}
void loop() {

  if(millis()-old_time>TIME) // Пора мигать светодиодом
  {
  old_time=millis();	
  Serial.print(old_time);
  if(st) {st=0;RED_LED_OFF; Serial.println(F(" Red led OFF")); }
  else {st=1;RED_LED_ON; Serial.println(F(" Red led ON"));}	
  
  }
  delay(1);
  // тут лежит код пользователя
}
*/

/*
// Трехцветный светодиод
#define TIME      1000  // Время показа цвета

#define RED_LED     9
#define BLUE_LED    10
#define GREEN_LED   11

#define RED_LED_ON   digitalWrite(RED_LED, HIGH);
#define RED_LED_OFF  digitalWrite(RED_LED, LOW);

#define BLUE_LED_ON   digitalWrite(BLUE_LED, HIGH);
#define BLUE_LED_OFF  digitalWrite(BLUE_LED, LOW);

#define GREEN_LED_ON   digitalWrite(GREEN_LED, HIGH);
#define GREEN_LED_OFF  digitalWrite(GREEN_LED, LOW);

void setup() {
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
   pinMode(GREEN_LED, OUTPUT);

}
void loop() {
  RED_LED_ON
  delay(TIME);
  RED_LED_OFF
  BLUE_LED_ON
  delay(TIME);
  BLUE_LED_OFF
  GREEN_LED_ON
  delay(TIME);
  RED_LED_ON
  BLUE_LED_ON
  GREEN_LED_OFF
  delay(TIME);
  RED_LED_ON
  BLUE_LED_OFF
  GREEN_LED_ON
  delay(TIME);
  RED_LED_OFF
  BLUE_LED_ON
  GREEN_LED_ON
  delay(TIME);
  RED_LED_ON
  BLUE_LED_ON
  GREEN_LED_ON
  delay(TIME);
  RED_LED_OFF
  BLUE_LED_OFF
  GREEN_LED_OFF
 
}
*/
/*
// Beeper (пищалка)
#define BEEP  5
void setup() {
   pinMode(BEEP, OUTPUT);
}
void loop() {
  digitalWrite(BEEP, HIGH);  
  delay(50);                       
  digitalWrite(BEEP, LOW);    
  delay(500);                 
}
*/
