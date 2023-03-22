// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module

#include <RH_ASK.h>

RH_ASK driver(2000, 7, 8, 0);   // Инициализация приемника сравниваем с передатчиком
char text[10]="\0x00";          // Буфер для передачи текстового сообщения


void setup()
{
    Serial.begin(115200);
    Serial.println("\n\n------------ START RESEIVER --------------");		 
    if (!driver.init())     Serial.println("init failed");
    Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];  // буфер приема
    uint8_t buflen = sizeof(buf);
   
   for(;;) 
    if (driver.recv(buf, &buflen)) // Non-blocking
     {
    strcpy(text,buf);
	driver.printBuffer("Got:", buf, buflen); // Вывод содержания буфера приема
    Serial.print(" Got: "); Serial.print(" len: "); Serial.print(buflen);
    Serial.print(" text: "); Serial.println((char*)text); 
     }
}
