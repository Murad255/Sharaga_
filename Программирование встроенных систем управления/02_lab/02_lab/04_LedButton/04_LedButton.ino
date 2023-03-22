// Взаимодействие кнопки и светодиода


#define D2  2
#define D3  3

#define RED_LED     12
#define BLUE_LED    13

#define RED_LED_ON   digitalWrite(RED_LED, HIGH)  // Убрал точки с запятой так удобнее
#define RED_LED_OFF  digitalWrite(RED_LED, LOW)

#define BLUE_LED_ON   digitalWrite(BLUE_LED, HIGH)
#define BLUE_LED_OFF  digitalWrite(BLUE_LED, LOW)



// Нажатие на кнопку D2 (зажигает красный светодиод)
void setup() {
  Serial.begin(115200);
  pinMode(D2, INPUT); 
  pinMode(RED_LED, OUTPUT);
  Serial.println(F("\n<------ START ------->"));
}
// the loop routine runs over and over again forever:
void loop() {
  int buttonState = digitalRead(D2);
  if(buttonState) RED_LED_OFF;  else RED_LED_ON;
  Serial.print(F("Key D2 state: ")); Serial.println(buttonState);
  delay(200);        // delay in between reads for stability
}


/*
// Работа двух кнопок на два светодиода c ИНВЕРТИРОВАНИЕМ, двойное нажатие - пищалка
#define BEEP  5
#define BEEP_ON   digitalWrite(BEEP, HIGH)
#define BEEP_OFF  digitalWrite(BEEP, LOW)
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);  
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BEEP, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonStateD2 = digitalRead(D2);
  int buttonStateD3 = digitalRead(D3);
  if((!buttonStateD2)&&(!buttonStateD3)) // Обработка двойного нажатия
  { 
  	Serial.println("Double press key D2+D3");
  	BEEP_ON; 
  	} 
 
  else {
  Serial.print(F("Key D2 state: ")); Serial.print(buttonStateD2); Serial.print(F(" ,key D3 state: ")); Serial.println(buttonStateD3);
  if (buttonStateD2) RED_LED_ON; else RED_LED_OFF;
  if (buttonStateD3) BLUE_LED_ON; else BLUE_LED_OFF;
  BEEP_OFF;
  }

  delay(200);        // delay in between reads for stability
}
*/
