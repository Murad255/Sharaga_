void setup() {
  // put your setup code here, to run once:
int x1;
short int x2;
long int x3;
unsigned int x4;
boolean x5;
float x6;
double x7;
byte x8;
char x9;


 Serial.begin(115200);  // Инициализация порта
 Serial.println(F("\tArduino UNO types of variables")); 
 Serial.print(F("int x1: ")); Serial.println(sizeof(x1)); 
 Serial.print(F("short int x2: ")); Serial.println(sizeof(x2)); 
 Serial.print(F("long int x3: ")); Serial.println(sizeof(x3)); 
 Serial.print(F("unsigned int x4: ")); Serial.println(sizeof(x4)); 
 Serial.print(F("boolean x5: ")); Serial.println(sizeof(x5)); 
 Serial.print(F("float x6: ")); Serial.println(sizeof(x6)); 
 Serial.print(F("double x7: ")); Serial.println(sizeof(x7)); 
 Serial.print(F("byte x8: ")); Serial.println(sizeof(x8)); 
 Serial.print(F("char x9: ")); Serial.println(sizeof(x9)); 
 
 Serial.println(F("\n\tSpecial types of variables in microcontrollers")); 
int8_t m1;
uint8_t m2;
int16_t m3;
uint16_t m4;
int32_t m5;
uint32_t m6;
 Serial.print(F("int8_t m1: ")); Serial.println(sizeof(m1)); 
 Serial.print(F("uint8_t m2: ")); Serial.println(sizeof(m2)); 
 Serial.print(F("int16_t m3: ")); Serial.println(sizeof(m3)); 
 Serial.print(F("uint16_t m4: ")); Serial.println(sizeof(m4)); 
 Serial.print(F("int32_t m5: ")); Serial.println(sizeof(m5)); 
 Serial.print(F("uint23_t m6: ")); Serial.println(sizeof(m6)); 


 Serial.println(F("\n\tStrings in Arduino")); 
 char buf1[]="0123456789";  // массив символов
 Serial.print(F("Char[] buf1: ")); Serial.print(buf1);  Serial.print(F(" sizeof(buf1)= ")); Serial.print(sizeof(buf1)); Serial.print(F(" strlen(buf1)= ")); Serial.println(strlen(buf1));  
 char buf2[]="Россия";  // массив символов
 Serial.print(F("Char[] buf2: ")); Serial.print(buf2);  Serial.print(F(" sizeof(buf2)= ")); Serial.print(sizeof(buf2)); Serial.print(F(" strlen(buf2)= ")); Serial.println(strlen(buf2));  

/*
// UTF-8 Кодировка
// https://i.voenmeh.ru/kafi5/Kam.loc/inform/UTF-8.htm
uint8_t i;
byte b;
Serial.print(F("buf2: "));
for (i=0;i<strlen(buf2);i++) 
//for (i=0;i<sizeof(buf2);i++) 
     { Serial.print(" 0x"); b=buf2[i]; Serial.print(b,HEX);}
//     { Serial.print(" 0x"); Serial.print((byte)buf2[i],HEX);}
Serial.print(F("\n"));
*/
    
 // STRING -----------------
 //String buf3="9876543210";  // класс строка
 //Serial.print(F("String buf3: ")); Serial.print(buf3);  Serial.print(F(" sizeof(buf3)= ")); Serial.print(sizeof(buf3)); Serial.print(F(" buf3.length()= ")); Serial.println(buf3.length());  

 

}

void loop() {
  // put your main code here, to run repeatedly:

}
