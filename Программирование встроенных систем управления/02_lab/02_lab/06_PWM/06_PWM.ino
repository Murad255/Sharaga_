
// ШИМ поддерживается Нано/Уно пины D3, D5, D6, D9, D10, D11.

#define RED_LED     9
#define BLUE_LED    10
#define GREEN_LED   11


// ШИМ на Голубой светодиод
void setup() {
  pinMode(BLUE_LED, OUTPUT);   
}
void loop() {
	 analogWrite(BLUE_LED, 10);
while(1);
}


/*
// Задейстовать три канала шим и выводить случайные значения, ограничить яркость канала 50 еденицами
void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);  
  pinMode(GREEN_LED, OUTPUT);     
}
void loop() {
	 analogWrite(RED_LED, random(0,50));
	 analogWrite(BLUE_LED, random(0,50));
	 analogWrite(GREEN_LED, random(0,50));
delay(500);
}
*/


/*
// Простейший ШИМ на красный светодиод, с изменением яркости в цикле
// Визуально видна нелинейная характеристика яркости светодиода
void setup() {
  pinMode(RED_LED, OUTPUT);  
}
void loop() {
  for(int i=0;i<=255;i++)
  {
  analogWrite(RED_LED, i);
  delay(30);
  }
}
*/


/*
// Управление яркостью светодиода с консоли
char buffer[16];
void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); 
  Serial.println(F("Enter the brightness value:")); 
}

void loop() {
  int index; 
  while (Serial.available()) {
    index = Serial.readBytesUntil('\n', buffer, 15);                    // чтение до 15 символов
    buffer[index] = '\0';                                               // конец строки
 
//    Serial.print(F("Input string > ")); Serial.println(buffer);         // вывод полученной строки
    int n = atoi(buffer);                                               // конвертация в челое число
    if ((n<0)||(n>255))
       Serial.println(F("Invalid value!"));
    else {   
    Serial.print(F("Set brightness > ")); Serial.println(n);
    analogWrite(RED_LED, n); 
    }
    buffer[0] = '\0';                                                   // очистка буфера
  }
}
*/
