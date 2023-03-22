int pinIn    = 13; // Пин проверки входа
int pinOut   = 12; // Пин проверки выхода

unsigned long _time;
String strToOut = "";
int count=10000;  //число итераций теста

void setup() {
  Serial.begin(115200); // будем выводить информацию о тестировании
  Serial.println("\nStart test function Arduino GPIO\n");
  pinMode(pinOut, OUTPUT);
  pinMode(pinIn, INPUT);
}

void loop() {
  testDWrite(pinOut);
  testDRead(pinIn);
  delay(5000);
}

//=========================================================
void testDWrite(int pin) {
  _time = micros();
  for (int i = 0; i < count; i++) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin, LOW);
  }
  showResult ("digitalWrite()", _time, count*2 ); // Итераций в 2 раза больше т.к. в цикле два раза вызывается функция digitalWrite
}
//=========================================================
void testDRead(int pin) {
  _time = micros();
  int k = 0;
  for (int i = 0; i < count; i++) {
    k = digitalRead(pin);
  }
  showResult ("digitalRead()", _time, count );
}

//=========================================================
void showResult (String func, long timeStart, int iter) {
  unsigned long timeTotal = micros() - _time;
  unsigned long time1 = timeTotal / iter;
 // float time1 = ((float)timeTotal)/((float)iter); // вывод во флоат

  strToOut = func + ". Total time: " + String(timeTotal) + " microsec, AVG time: " + String(time1) + " microseconds. (iterations " + String(iter) + ")";
  Serial.println(strToOut);
}
