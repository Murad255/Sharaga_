// Использование функции yield()
// Один светодиод мигает с частотой 1 гц второй в функции yield() с частотой 5 гц
#define led1 13
#define led2 12

unsigned long timing; // Переменная для хранения точки отсчета
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop() {
  digitalWrite(led1, 1);
  delay(1000);
  digitalWrite(led1, 0);
  delay(1000);
}
void yield() {

 if (millis() - timing > 200){ 
  timing = millis(); 
  digitalWrite(led2, !digitalRead(led2));
 }
// delay(5); // рекурсия все падает из-за переполнения стека
}
