// Управление светодиодом через радиоканал
// Приемник
#include <RH_ASK.h>

#define D12_LED  12  // светодиод нажатие кнопки

RH_ASK driver(2000, 7, 8, 0);  // Инициализация приемника сравниваем с передатчиком
uint8_t key;                   // Кнопка
void setup()
{
    Serial.begin(115200);	 
    Serial.println("\n\n------------ START RESEIVER --------------");	 
    if (!driver.init())    Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
    pinMode(D12_LED, OUTPUT);
}

void loop()
{
    uint8_t buflen = sizeof(key);
   
   for(;;) 
    if (driver.recv(&key, &buflen)) // Non-blocking
     {
	
//	driver.printBuffer("Got:", buf, buflen);// Отладка
   Serial.print(" Got: "); Serial.print(" len: "); Serial.print(buflen);
   Serial.print(" key: ");   Serial.println(key);
   digitalWrite(D12_LED, key); 
   
    }
}
