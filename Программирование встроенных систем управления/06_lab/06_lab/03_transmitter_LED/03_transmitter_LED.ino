// Управление светодиодом через радиоканал
// Передатчик
#include <RH_ASK.h>

#define D13_LED  13  // светодиод отпраки пакета
#define D12_LED  12  // светодиод нажатие кнопки
#define D2_KEY   2   // кнопка

RH_ASK driver(2000, 8, 7, 0); // Инициализация передатчика
uint8_t key;  // Кнопка

void setup()
{
  Serial.begin(115200);	 
  Serial.println("\n\n------------ START TRAMSMITTER --------------");
  if (!driver.init()) Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  pinMode(D12_LED, OUTPUT);
  pinMode(D2_KEY, INPUT);
  Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
  Serial.print("Sizeof key:");Serial.println(sizeof(key));
}

void loop()
{
    key=digitalRead(D2_KEY);                     // Прочитать кнопку
    digitalWrite(D12_LED, key);                  // Установить светодиод в нужное состояние 
    digitalWrite(D13_LED, HIGH);                 // В начале передачи включить светодиод
    driver.send((uint8_t * )&key, sizeof(key));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);                  // В конце передачи выключить светодиод 
    delay(1000);
    
}
