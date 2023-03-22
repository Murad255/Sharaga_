
// Кнопка триггер
// определить момент «клика» несколько сложнее, чем факт того, что кнопка сейчас просто нажата.
#define BUTTON_PIN  2
#define LED_PIN     12

boolean buttonWasUp = true;  // была ли кнопка отпущена?
boolean ledEnabled = false;  // включен ли свет?

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println(F("\n<------ START ------->"));
}

void loop()
{
// Для определения клика мы сначала понимаем, отпущена ли кнопка прямо сейчас...
  boolean buttonIsUp = digitalRead(BUTTON_PIN);

  // ...если «кнопка была отпущена и (&&) не отпущена сейчас»...
  if (buttonWasUp && !buttonIsUp) {
    // ...может это «клик», а может и ложный сигнал (дребезг),
    // возникающий в момент замыкания/размыкания пластин кнопки,
    // поэтому даём кнопке полностью «успокоиться»...
    delay(10);
    // ...и считываем сигнал снова
    buttonIsUp = digitalRead(BUTTON_PIN);
    if (!buttonIsUp) {  // если она всё ещё нажата...
      // ...это клик! Переворачиваем сигнал светодиода
      ledEnabled = !ledEnabled;
      digitalWrite(LED_PIN, ledEnabled);
      Serial.print(F("Red led state: "));Serial.println(ledEnabled);
    }
  }

  // запоминаем последнее состояние кнопки для новой итерации
  buttonWasUp = buttonIsUp;
}


/*
// Кнопка триггер + звук нажатия кнопки
#define BUTTON_PIN  2
#define LED_PIN     12
#define BEEP        5
boolean buttonWasUp = true;  // была ли кнопка отпущена?
boolean ledEnabled = false;  // включен ли свет?

void setup()
{
  Serial.begin(115200);
  pinMode(BEEP, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println(F("\n<------ START ------->"));
}

void loop()
{
  boolean buttonIsUp = digitalRead(BUTTON_PIN);

  if (buttonWasUp && !buttonIsUp) {
    delay(10);
    buttonIsUp = digitalRead(BUTTON_PIN);
    if (!buttonIsUp) {  // если она всё ещё нажата...
      ledEnabled = !ledEnabled;
      beep();
      digitalWrite(LED_PIN, ledEnabled);
      Serial.print(F("Red led state: "));Serial.println(ledEnabled);
    }
  }

  // запоминаем последнее состояние кнопки для новой итерации
  buttonWasUp = buttonIsUp;
}

void beep(){
  digitalWrite(BEEP, HIGH);
  delay(50);
  digitalWrite(BEEP, LOW);
}
*/
