// Простейшая работа с кнопками

// Определение куда подключены кнопки
#define D2  2
#define D3  3

// Простое нажатие на кнопку D2 (обработка в лоб)
void setup() {
   Serial.begin(115200);
  pinMode(D2, INPUT); // По умолчани все gpio установлены как входы, но желательно прямо указывать что это вход
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(D2);
  Serial.print(F("Key D2 state: ")); Serial.println(buttonState);
  delay(200);        // delay in between reads for stability
}



/*
// Простая обработка двух кнопок d2 d3 (в лоб)
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonStateD2 = digitalRead(D2);
  int buttonStateD3 = digitalRead(D3);
  // print out the state of the button:
//  if((!buttonStateD2)&&(!buttonStateD3)) Serial.println("Double press key D2+D3");  else {// Обработка двойного нажатия
 
  Serial.print(F("Key D2 state: ")); Serial.print(buttonStateD2); Serial.print(F(" ,key D3 state: ")); Serial.println(buttonStateD3);
  
//  }
  delay(200);        // delay in between reads for stability
}
*/



/*
// Выявление дребезка контактов на кнопке D2
#define NUM 200
int buttonStateOld;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(D2, INPUT);
  buttonStateOld=1;  // Кнопка не нажата
   Serial.println(F("\n<------ START ------->"));
}

// the loop routine runs over and over again forever:
void loop() {
byte temp[NUM];	
  // read the input pin:
  int buttonState = digitalRead(D2);
  if (buttonStateOld!=buttonState)
  {
  for (int i=0;i<NUM;i++) temp[i]=digitalRead(D2); // накопление данных
  if(!buttonState) Serial.print(F("Key D2 push on state: ")); else Serial.print(F("Key D2 push off state: "));
  for (int i=0;i<NUM;i++)
   { Serial.print(temp[i]);Serial.print(F(", ")); }
  Serial.print(F("\n"));
  buttonStateOld=buttonState;	
  }
  delay(100);        // delay in between reads for stability
}

*/

/*
// Программный способ подавления дребезга кнопок
void setup() {
  Serial.begin(115200);
  pinMode(D2, INPUT);
  Serial.println(F("\n<------ START ------->"));
}

int currentValue, prevValue;
void loop() {
  currentValue = digitalRead(D2);
  if (currentValue != prevValue) // Что-то изменилось, здесь возможна зона неопределенности
  {
    delay(10);// Делаем задержку
    currentValue = digitalRead(D2);   // А вот теперь спокойно считываем значение, считая, что нестабильность исчезла
  }

  prevValue = currentValue;
  Serial.print(F(">="));  Serial.println(currentValue);
}
*/
