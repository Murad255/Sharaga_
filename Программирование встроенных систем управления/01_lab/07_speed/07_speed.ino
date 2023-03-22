#define NUM 65000  // число операций в тесте
#define SER_MS Serial.println(F(" ms")); // вывести в консоль ms и перевести строку

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);  // Инициализация порта
Serial.println(F("Start test")); 
uint32_t time;

//int8_t  x1=2,y1=0;  
//int16_t x2=2,y2=0;  
//int32_t x3=2,y3=0;  
//float   x4=4.56, y4=2.12; 

volatile int8_t  x1=2,y1=2;  
volatile int16_t x2=2,y2=2;  
volatile int32_t x3=2,y3=2;  
volatile float   x4=4.564567, y4=0.126789; 
 
uint16_t i;

time = millis();
for(i=0;i<NUM;i++) y1=y1+x1;
Serial.print(F("Addition uint8_t: "));Serial.print(millis()-time); SER_MS;

time = millis();
for(i=0;i<NUM;i++) y2=y2+x2;
Serial.print(F("Addition uint16_t: "));Serial.print(millis()-time); SER_MS;

time = millis();
for(i=0;i<NUM;i++) y3=y3+x3;
Serial.print(F("Addition uint32_t: "));Serial.print(millis()-time); SER_MS;

time = millis();
for(i=0;i<NUM;i++) y4=y4+x4;
Serial.print(F("Addition float: "));Serial.print(millis()-time); SER_MS;

 
time = millis();
for(i=0;i<NUM;i++) y1=y1*x1;
Serial.print(F("Multiplication uint8_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y2=y2*x2;
Serial.print(F("Multiplication uint16_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y3=y3*x3;
Serial.print(F("Multiplication uint32_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y4=y4*x4;
Serial.print(F("Multiplication float: "));Serial.print(millis()-time); SER_MS; 


time = millis();
for(i=0;i<NUM;i++) y1=y1/x1;
Serial.print(F("Division uint8_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y2=y2/x2;
Serial.print(F("Division uint16_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y3=y3/x3;
Serial.print(F("Division uint32_t: "));Serial.print(millis()-time); SER_MS; 

time = millis();
for(i=0;i<NUM;i++) y4=y4/x4;
Serial.print(F("Division float: "));Serial.print(millis()-time); SER_MS; 

Serial.print(F("Summary: "));Serial.print(millis()); SER_MS; 


}

void loop() {


}
