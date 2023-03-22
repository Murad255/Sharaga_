#define HEADER "X="
void setup() {
int x=32;	
Serial.begin(115200);  // Инициализация порта	
	outputX(x);
	x--;  
	Serial.print("\n");
	outputX(x);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void outputX(uint8_t x)
{
 Serial.print("X="); Serial.print(x); Serial.println(" DEC");
 Serial.print("X="); Serial.print(x,HEX); Serial.println(" HEX");
 Serial.print("X="); Serial.print(x,BIN); Serial.println(" BIN");
// Serial.print(F("X=")); Serial.print(x); Serial.println(F(" DEC"));
// Serial.print(F("X=")); Serial.print(x,HEX); Serial.println(F(" HEX"));
// Serial.print(F("X=")); Serial.print(x,BIN); Serial.println(F(" BIN")); 
// Serial.print(F(HEADER)); Serial.print(x); Serial.println(F(" DEC"));
// Serial.print(F(HEADER)); Serial.print(x,HEX); Serial.println(F(" HEX"));
// Serial.print(F(HEADER)); Serial.print(x,BIN); Serial.println(F(" BIN")); 
}



/*
#define TYPE 2 // 0,1,2 - условная компиляция

#if TYPE == 2
#define HEADER "X="
#endif

void setup() {
int x=32;	
Serial.begin(115200);  // Инициализация порта	
Serial.print("TYPE=");	Serial.println(TYPE);
#if TYPE > 2 or TYPE < 0	
  Serial.print("Error TYPE, stop.\n");
  exit;
#else
	outputX(x);
	x--;  
	Serial.print("\n");
	outputX(x);
#endif
}

void loop() {
  // put your main code here, to run repeatedly:

}

void outputX(uint8_t x)
{
#if TYPE == 0
 Serial.print("X="); Serial.print(x); Serial.println(" DEC");
 Serial.print("X="); Serial.print(x,HEX); Serial.println(" HEX");
 Serial.print("X="); Serial.print(x,BIN); Serial.println(" BIN");
#elif TYPE == 1 
 Serial.print(F("X=")); Serial.print(x); Serial.println(F(" DEC"));
 Serial.print(F("X=")); Serial.print(x,HEX); Serial.println(F(" HEX"));
 Serial.print(F("X=")); Serial.print(x,BIN); Serial.println(F(" BIN")); 
#elif TYPE == 2 
 Serial.print(F(HEADER)); Serial.print(x); Serial.println(F(" DEC"));
 Serial.print(F(HEADER)); Serial.print(x,HEX); Serial.println(F(" HEX"));
 Serial.print(F(HEADER)); Serial.print(x,BIN); Serial.println(F(" BIN")); 
#endif
}
*/
