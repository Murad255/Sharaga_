void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);  // Инициализация порта
char buf[64];
Serial.println(F("Used function Serial.print")); 
Serial.print(F("Millis=")); Serial.println(millis());

// использование функции printf
//Serial.println(F("Used function printf"));
//sprintf(buf,"Millis=%d",millis());   // Константы строки в оперативке
//sprintf_P(buf,"Millis=%d",millis()); // также переносит константы в память программ
//Serial.println(buf);

/*
// Вывод float
float x=1.23456;
Serial.println(F("Serial.println(x) ")); Serial.println(x,3); 
//sprintf(buf,"sprintffloat x=%f",x); // не выводит float!
//Serial.println(buf);
			// Вывод float с использованием функции dtostrf
			//char* dtostrf(double data, signed char width, unsigned char prec, char *string)
			//data – это конвертируемая переменная;
			//width – число значащих разрядов (длина получаемого символьного значения;);
			//prec – число разрядов после запятой;
			//char* string – указатель на строку (имя массива) где будет результат.
//dtostrf(x, 6, 4, buf);  // выводим в строку buf 2 разряда до, 4 разряда после запятой
//Serial.print("float x="); Serial.println(buf);
*/
}

void loop() {
  // put your main code here, to run repeatedly:

}
