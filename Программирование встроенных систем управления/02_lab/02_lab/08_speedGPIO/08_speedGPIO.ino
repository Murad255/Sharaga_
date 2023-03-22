// D13 - Вход
byte pin13mask = (1 << 5);
#define D13_SET_OUTPUT      DDRB  |=  pin13mask // Устанавливаем пин D13 в режим OUTPUT
#define D13_SET_INPUT       DDRB  &= ~pin13mask // Устанавливаем пин D13 в режим INPUT
#define D13_WRITE_HIGH      PORTB |=  pin13mask // Устанавливаем бит отвечающий за пин D13 в HIGH, остальные пины не трогаем
#define D13_WRITE_LOW       PORTB &= ~pin13mask // Устанавливаем бит отвечающий за пин D13 в LOW, остальные пины не трогаем
#define D13_READ            bitRead(PORTB, 5) // Команда чтения 5-го бита - соответствует пину D13
// D12 - Выход
byte pin12mask = (1 << 4);
#define D12_SET_OUTPUT      DDRB  |=  pin13mask // Устанавливаем пин D12 в режим OUTPUT
#define D12_SET_INPUT       DDRB  &= ~pin13mask // Устанавливаем пин D12 в режим INPUT
#define D12_WRITE_HIGH      PORTB |=  pin13mask // Устанавливаем бит отвечающий за пин D12 в HIGH, остальные пины не трогаем
#define D12_WRITE_LOW       PORTB &= ~pin13mask // Устанавливаем бит отвечающий за пин D12 в LOW, остальные пины не трогаем
#define D12_READ            bitRead(PORTB, 4)   // Команда чтения 4-го бита - соответствует пину D12

unsigned long _time;
String strToOut = "";
int count=10000;

void setup() {
 Serial.begin(115200); // будем выводить информацию о тестировании
 Serial.println("\nStart test direct control GPIO AVR328\n");
 D12_SET_OUTPUT; // Пин 12 в режим OUTPUT
 D13_SET_INPUT;  // Пин 13 в режим INPUT
}

void loop() {
  testDWrite();
  testDRead();
  delay(5000);
}

//=========================================================
void testDWrite() {
  _time = micros();
  for (int i = 0; i < count; i++) {
  D12_WRITE_HIGH; // Зажигаем светодиод
  D12_WRITE_LOW;  // Выключаем светодиод
  }
  showResult ("digitalWrite()", _time, count*2 ); // Итераций в 2 раза больше т.к. в цикле два раза вызывается функция digitalWrite
}
//=========================================================
void testDRead() {
  _time = micros();
  int k = 0;
  for (int i = 0; i < count; i++) {
  k=D13_READ;
  }
  showResult ("digitalRead()", _time, count );
}

//=========================================================
void showResult (String func, long timeStart, int iter) {
  unsigned long timeTotal = micros() - _time;
  unsigned long time1 = timeTotal / iter;
//  float time1 = ((float)timeTotal)/((float)iter); // вывод во флоат

  strToOut = func + ". Total time: " + String(timeTotal) + " microsec, AVG time: " + String(time1) + " microseconds. (iterations " + String(iter) + ")";
  Serial.println(strToOut);
}
