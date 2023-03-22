// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>

#define D13_LED  13
RH_ASK driver(2000, 8, 7, 0); // Инициализация передатчика
char text[10]="\0x00";        // Буфер для передачи текстового сообщения

void setup()
{
  Serial.begin(115200);	 
  Serial.println("\n\n------------ START TRAMSMITTER --------------");
  if (!driver.init())   Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
  Serial.print("Sizeof data pocket:");Serial.println(sizeof(text));
}

void loop()
{   
	strcpy(text,"Hello!");
    digitalWrite(D13_LED, HIGH);   // В начале передачи включить светодиод
    driver.send((uint8_t * )&text, sizeof(text));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);    // В конце передачи выключить светодиод 
    delay(1000);
    
}
