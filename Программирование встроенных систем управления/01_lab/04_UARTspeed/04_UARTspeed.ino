void setup() {
// Serial.begin(9600);  // Инициализация порта	
Serial.begin(115200);  // Инициализация порта
    Serial.print(F("Millis=")); Serial.println(millis());
Serial.print(F("Start . . .\n"));
}

void loop() {
int i;
for(i=0;i<128;i++)	
		{
		Serial.print(i);	
		Serial.println(F(" >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"));
		}
		
  Serial.print(F("Millis=")); Serial.println(millis());
while(1);  
}

/*
#define PRINT_MILLIS

#ifdef PRINT_MILLIS
   #define OUTPUT_MILLIS Serial.print(F("Millis=")); Serial.println(millis());
#endif
void setup() {
  // put your setup code here, to run once:
// Serial.begin(9600);  // Инициализация порта	
 Serial.begin(115200);  // Инициализация порта
#ifdef PRINT_MILLIS
   Serial.println(F("\n#define PRINT_MILLIS"));
#endif
 
#ifndef PRINT_MILLIS
    Serial.print(F("Millis=")); Serial.println(millis());
#else
    OUTPUT_MILLIS;
#endif
Serial.print(F("Start . . .\n"));
}

void loop() {
int i;
for(i=0;i<128;i++)	
		{
		Serial.print(i);	
		Serial.println(F(" >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"));
		}
		
#ifndef PRINT_MILLIS
    Serial.print(F("Millis=")); Serial.println(millis());
#else
    OUTPUT_MILLIS;
#endif
while(1); 
} */
