void setup() {
 Serial.begin(9600);  // Инициализация порта	
// Serial.begin(115200);  // Инициализация порта	

Serial.print("Hello world!");       // Вывод без переноса строки
//Serial.println("Hello world!");     // Перенос строки функцией println
//Serial.print("Hello world!\n");     // Перенос строки символом
//Serial.print("\"Hello world!\"\n"); // Вывод кавычек 
//Serial.print("Hello world!\\\n");   // Вывод слеша
//Serial.print("\tHello world!\n");     // Табуляция
//Serial.print("Привет мир на русском!\n"); // Вывод на русском (не всегда работатет, винды)
Serial.println("<-------END---------->");
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}
